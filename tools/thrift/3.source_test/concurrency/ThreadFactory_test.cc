#include <thrift/Thrift.h>
#include <thrift/thrift-config.h>
#include <thrift/concurrency/Thread.h>
#include <thrift/concurrency/ThreadFactory.h>
#include <thrift/concurrency/Monitor.h>
#include <thrift/concurrency/Mutex.h>

#include <assert.h>
#include <iostream>
#include <vector>

using std::shared_ptr;
using namespace apache::thrift::concurrency;
using namespace apache::thrift;

/**
 * ThreadFactoryTests class
 *
 * @version $Id:$
 */
class ThreadFactoryTests {

public:
  /**
   * 创建 N 个线程
   */
  class ReapNTask : public Runnable {

  public:
    ReapNTask(Monitor& monitor, int& activeCount) : _monitor(monitor), _count(activeCount) {}

    void run() override {
      Synchronized s(_monitor);
      
      // 线程处理函数 对活跃线程数量-- 当为0时通知主线程
      // std::cout << "\t\t\t_count: " << _count << std::endl;
      if (--_count == 0) {
        _monitor.notify();
      }
    }

    Monitor& _monitor;
    int& _count;
  };

  bool reapNThreads(int loop = 1, int count = 10) {

    ThreadFactory threadFactory = ThreadFactory();
    shared_ptr<Monitor> monitor(new Monitor);

    for (int lix = 0; lix < loop; lix++) {

      int activeCount = 0;  // 活跃线程数量

      std::vector<shared_ptr<Thread> > threads;
      int tix;

      // 创建线程，每个线程都有各自的Runnable, activeCount传递的是引用，count个线程共用这个变量，start()前每个线程中的activeCount都等于count
      for (tix = 0; tix < count; tix++) {
        try {
          ++activeCount;
          threads.push_back(
              threadFactory.newThread(shared_ptr<Runnable>(new ReapNTask(*monitor, activeCount))));
        } catch (SystemResourceException& e) {
          std::cout << "\t\t\tfailed to create " << lix* count + tix << " thread " << e.what()
                    << std::endl;
          throw;
        }
      }

      // 启动线程
      tix = 0;
      for (std::vector<shared_ptr<Thread> >::const_iterator thread = threads.begin();
           thread != threads.end();
           tix++, ++thread) {

        try {
          (*thread)->start();
        } catch (SystemResourceException& e) {
          std::cout << "\t\t\tfailed to start  " << lix* count + tix << " thread " << e.what()
                    << std::endl;
          throw;
        }
      }

      // 活跃线程个数为0时退出while, 创建的第一个线程activeCount=1,如果它先执行后面
      {
        Synchronized s(*monitor);
        while (activeCount > 0) {
          monitor->wait(1000);
        }
      }
    }

    std::cout << "\t\t\tSuccess!" << std::endl;
    return true;
  }

  /**
   * 同步
   */

  class SynchStartTask : public Runnable {

  public:
    enum STATE { UNINITIALIZED, STARTING, STARTED, STOPPING, STOPPED };

    SynchStartTask(Monitor& monitor, volatile STATE& state) : _monitor(monitor), _state(state) {}

    // 线程处理函数 根据传入的线程状态做处理
    void run() override {
      {
        Synchronized s(_monitor);
        if (_state == SynchStartTask::STARTING) {
          // 3.STARTED
          _state = SynchStartTask::STARTED;
          _monitor.notify();
        }
      }

      // 等待主线程进行notify
      {
        Synchronized s(_monitor);
        while (_state == SynchStartTask::STARTED) {
          _monitor.wait();
        }

        if (_state == SynchStartTask::STOPPING) {
          _state = SynchStartTask::STOPPED;
          _monitor.notifyAll();
        }
      }
    }

  private:
    Monitor& _monitor;
    volatile STATE& _state;
  };

  bool synchStartTest() {

    Monitor monitor;

    // 1.UNINITIALIZED
    SynchStartTask::STATE state = SynchStartTask::UNINITIALIZED;

    shared_ptr<SynchStartTask> task
        = shared_ptr<SynchStartTask>(new SynchStartTask(monitor, state));

    ThreadFactory threadFactory = ThreadFactory();

    shared_ptr<Thread> thread = threadFactory.newThread(task);

    if (state == SynchStartTask::UNINITIALIZED) {

      // 2.STARTING
      state = SynchStartTask::STARTING;

      thread->start();
    }

    // wait一道保障，如果这里先执行了那么run中的  STARTED 位置会notify，这里再向下执行
    {
      Synchronized s(monitor);
      while (state == SynchStartTask::STARTING) {
        monitor.wait();
      }
    }

    // state = STARTED
    assert(state != SynchStartTask::STARTING);
    
    // 
    {
      Synchronized s(monitor);

      try {
        monitor.wait(100);
      } catch (TimedOutException&) {
      }

      if (state == SynchStartTask::STARTED) {
        // 4.
        state = SynchStartTask::STOPPING;

        monitor.notify();
      }

      while (state == SynchStartTask::STOPPING) {
        monitor.wait();
      }
    }

    assert(state == SynchStartTask::STOPPED);

    bool success = true;

    std::cout << "\t\t\t" << (success ? "Success" : "Failure") << "!" << std::endl;

    return true;
  }

  /**
   * 条件变量超时测试 测试实际的超时和理论值差值，单位ms，ms级别的测试
   */

  bool monitorTimeoutTest(int64_t count = 1000, int64_t timeout = 2) {

    Monitor monitor;

    int64_t startTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();

    for (int64_t ix = 0; ix < count; ix++) {
      {
        Synchronized s(monitor);
        try {
          monitor.wait(timeout);
        } catch (TimedOutException&) {
        }
      }
    }

    int64_t endTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();

  bool success = (endTime - startTime) >= (count * timeout);

    std::cout << "\t\t\t" << (success ? "Success" : "Failure")
              << ": minimum required time to elapse " << count * timeout
              << "ms; actual elapsed time " << endTime - startTime << "ms"
              << std::endl;

    return success;
  }


  /*
  *  批量创建线程
  */

  class FloodTask : public Runnable {
  public:
    FloodTask(const size_t id, Monitor& mon) : _id(id), _mon(mon) {}
    ~FloodTask() override {
      if (_id % 10000 == 0) {
		Synchronized sync(_mon);
        std::cout << "\t\tthread " << _id << " done" << std::endl;
      }
    }

    void run() override {
      if (_id % 10000 == 0) {
		Synchronized sync(_mon);
        std::cout << "\t\tthread " << _id << " started" << std::endl;
      }
    }
    const size_t _id;
    Monitor& _mon;
  };

  bool floodNTest(size_t loop = 1, size_t count = 100000) {

    bool success = false;
    Monitor mon;
	
    for (size_t lix = 0; lix < loop; lix++) {

      ThreadFactory threadFactory = ThreadFactory();
      threadFactory.setDetached(true);  // 该线程工厂出来的线程都是detached的

      for (size_t tix = 0; tix < count; tix++) {

        try {
          // 创建并启动线程
          shared_ptr<FloodTask> task(new FloodTask(lix * count + tix, mon));
          shared_ptr<Thread> thread = threadFactory.newThread(task);
          thread->start();

        } catch (TException& e) {

          std::cout << "\t\t\tfailed to start  " << lix* count + tix << " thread " << e.what()
                    << std::endl;

          return success;
        }
      }

      Synchronized sync(mon);
      std::cout << "\t\t\tflooded " << (lix + 1) * count << " threads" << std::endl;
      success = true;
    }

    return success;
  }
};


int main(void)
{
    ThreadFactoryTests tft;
    //tft.reapNThreads();
    //tft.synchStartTest();
    //tft.monitorTimeoutTest();
    tft.floodNTest();

    return 0;
}