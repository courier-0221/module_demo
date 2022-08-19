#ifndef THREAD_H
#define THREAD_H

#include <unistd.h>
#include <sys/syscall.h>
#include <pthread.h>
#include <sys/prctl.h>
#include <functional>
#include <iostream>
#include <memory>
using namespace std;

namespace CurrentThread
{
    extern __thread int t_cachedTid;
    inline void cacheTid()
    {
        t_cachedTid = static_cast<int>(::syscall(SYS_gettid));  //获取内核线程ID
    }
    inline int tid()
    {
        if (t_cachedTid == 0)
        {
            cacheTid();
        }
        return t_cachedTid;
    }
}//namespace CurrentThread

class Thread
{
public:
    typedef std::shared_ptr<Thread> ptr;
    typedef std::function<void ()> ThreadFunc;
    explicit Thread(const ThreadFunc& func, const string& name = string());
    ~Thread();
    void start();
    int join();
    pid_t gettid() { return static_cast<pid_t>(::syscall(SYS_gettid)); }
    void setAutoDelete(bool autoDelete) {_autoDelete = autoDelete;}
    static void* ThreadRoutine(void* arg);
private:
    void Run();
    void setDefaultName();
    bool _started;  //线程是否创建开始执行
    bool _joined;   //调用join时析构中将不在detach
    bool _autoDelete;
    ThreadFunc _func;
    string _name;
    pthread_t _pthreadId;
};

#endif
