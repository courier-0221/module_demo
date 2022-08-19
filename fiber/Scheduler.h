#ifndef _SCHEDULER_H
#define _SCHEDULER_H

#include "Fiber.h"
#include "Thread.h"
#include "Mutex.h"
#include <atomic>
#include <list>
#include <memory>
#include <unistd.h>
#include <utility>
#include <vector>
#include <sys/syscall.h>
#include <iostream>

//协程调度器
class Scheduler
{
private:
    //任务类    等待分配线程执行的任务，可以是 Fiber 或 std::function
    struct Task
    {
        using ptr = std::shared_ptr<Task>;
        using TaskFunc = std::function<void()>;

        Fiber::ptr fiber;   //任务类型1 fiber
        TaskFunc callback;  //任务类型2 callback
        long threadid;      //任务要绑定执行线程的id

        Task() : threadid(-1) {}
        Task(const Task& rhs) = default;
        //Fiber
        Task(Fiber::ptr f, long tid)
            : fiber(std::move(f))
            , threadid(tid)
            {}
        //fcuntion
        Task(const TaskFunc& cb, long tid)
            : callback(cb)
            , threadid(tid)
            {}
        Task(TaskFunc&& cb, long tid)
            : callback(std::move(cb))
            , threadid(tid) 
            {}
        Task& operator=(const Task& rhs) = default;
        void reset()
        {
            fiber = nullptr;
            callback = nullptr;
            threadid = -1;
        }
    };

public: //内部类型、静态方法、友元声明
    friend class Fiber;
    using ptr = std::shared_ptr<Scheduler>;
    //获取当前协程的调度器
    static Scheduler* GetThis();
    //获取调度器正在处理的协程
    static Fiber* GetMainFiber();

public: //实例方法
    //use_caller 是否将 Scheduler 实例化所在的线程作为 master fiber
    explicit Scheduler(size_t threadSize, bool use_caller = true, std::string name = "");
    virtual ~Scheduler();

    void start();   //开始
    void stop();    //结束
    
    virtual bool isStop();  //scheduler是否停止了

    //添加任务 单个任务 thread-safe
    template <typename Executable>
    void schedule(Executable&& exec, long threadid = -1, bool priority = false)
    {
        bool needTickle = false;
        {
            MutexLockGuard lock(_mutex);
            //std::forward
            needTickle = scheduleNonBlock(std::forward<Executable>(exec), threadid, priority);
        }
        
        //唤醒
        if (needTickle)
        {
            tickle();
        }
    }

    //添加任务 多个任务 thread-safe
    template <typename InputIterator>
    void schedule(InputIterator begin, InputIterator end)
    {
        bool needTickle = false;
        {
            MutexLockGuard lock(_mutex);
            while (begin != end)
            {
                needTickle = scheduleNonBlock(*begin) || needTickle;
                ++begin;
            }
        }

        //唤醒
        if (needTickle)
        {
            tickle();
        }
    }

protected:
    void run();
    virtual void tickle()
    {
        //std::cout << "Scheduler::tickle() threadid=" << CurrentThread::tid() << std::endl;
    }
    //调度器停止时的回调函数，返回调度器当前是否处于停止工作的状态
    virtual bool onStop() { return isStop(); }
    //调度器空闲时的回调函数
    virtual void onIdle()
    {
        while (!isStop())
        {
            Fiber::YieldToHold();
        }
        return;
    }

private:
    /**
     * @brief 添加任务 non-thread-safe
     * @param Executable 模板类型必须是 std::unique_ptr<Fiber> 或者 std::function
     * @param exec Executable 的实例
     * @param threadid 任务要绑定执行线程的 id
     * @param priority 是否优先调度，单个任务添加时可以跟上来指定
     * @return 是否是空闲状态下的第一个新任务
     * */
    template <typename Executable>
    bool scheduleNonBlock(Executable&& exec, long threadid = -1, bool priority = false)
    {
        bool needTickle = m_task_list.empty();
        //std::forward
        auto task = std::make_shared<Task>(std::forward<Executable>(exec), threadid);
        if (task->fiber || task->callback)
        {
            if (priority)
            {
                m_task_list.push_front(std::move(task));
            }
            else
            {
                m_task_list.push_back(std::move(task));
            }
        }
        return needTickle;
    }

protected:
    const std::string _name;
    //主线程 id，仅在 use_caller 为 true 时会被设置有效线程 id
    long m_root_thread_id = 0;
    //线程 id 列表
    std::vector<long> m_thread_id_list;
    //有效线程数量
    size_t m_thread_count = 0;
    //活跃线程数量
    std::atomic_uint64_t m_active_thread_count = {0};
    //空闲线程数量
    std::atomic_uint64_t m_idle_thread_count = {0};
    //执行停止状态
    bool _stopping = true;
    //是否自动停止
    bool m_auto_stop = false;

private:
    MutexLock _mutex;
    //负责调度的协程，仅在类实例化参数中 use_caller 为 true 时有效
    Fiber::ptr m_root_fiber;
    //线程对象列表
    std::vector<Thread::ptr> m_thread_list;
    //任务集合
    std::list<Task::ptr> m_task_list;
};

//线程局部变量
namespace SchedulerInfo
{
//当前线程的协程调度器
static thread_local Scheduler* t_scheduler = nullptr;
//协程调度器正在调度协程
static thread_local Fiber* t_scheduler_fiber = nullptr;
}   //namespace SchedulerInfo


#endif
