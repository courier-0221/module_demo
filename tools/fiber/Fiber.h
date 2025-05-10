#ifndef _FIBER_H_
#define _FIBER_H_

#include "Exception.h"

#include <sys/syscall.h>
#include <unistd.h>
#include <memory>
#include <functional>
#include <ucontext.h>
#include <iostream>
#include <atomic>
#include <cerrno>
#include <cstring>

class Scheduler;

//协程类
class Fiber : public std::enable_shared_from_this<Fiber>
{
    friend class Scheduler;
public:
    using ptr = std::shared_ptr<Fiber>;
    using FiberFunc = std::function<void()>;

    // 协程状态，用于调度
    enum State
    {
        INIT,     // 初始化
        READY,    // 预备
        HOLD,     // 挂起
        EXEC,     // 执行
        TERM,     // 结束
        EXCEPTION // 异常
    };

private:
    // 创建 master fiber,主要获取上下文到Fiber类中,子协程后续会切回到主协程
    Fiber();

public:
    //创建新协程 其中分配了栈空间
    explicit Fiber(FiberFunc callback, size_t stack_size = 0);
    ~Fiber();
    // 更换协程执行函数
    void reset(FiberFunc callback);
    // 换入协程，该方法通常 master fiber 调用
    void swapIn();
    // 挂起协程，该方法通常 master fiber 调用
    void swapOut();
    // 获取协程 id
    uint64_t getID() const { return _id; }
    // 获取协程状态
    State getState() const { return _state; }

    // 判断协程是否执行结束
    bool finish() const noexcept;
    // 换入协程，将调用时的上下挂起到保存到线程局部变量中
    void call();
    // 挂起协程，保存当前上下文到协程对象中，从线程局部变量恢复执行上下文
    void back();

public:
    // 获取当前正在执行的 fiber 的智能指针，如果不存在，则在当前线程上创建 master fiber
    static Fiber::ptr GetThis();
    // 设置当前 fiber
    static void SetThis(Fiber* fiber);
    // 挂起当前协程，转换为 READY 状态，等待下一次调度
    static void YieldToReady();
    // 挂起当前协程，转换为 HOLD 状态，等待下一次调度
    static void YieldToHold();
    // 获取存在的协程数量
    static uint64_t TotalFibers();
    // 获取当前协程 id
    static uint64_t GetFiberID();
    // 协程入口函数
    static void MainFunc();

private:
    uint64_t    _id;            // 协程 id
    uint64_t    _stackSize;     // 协程栈大小
    State       _state;         // 协程状态
    ucontext_t  _ctx;           // 协程上下文
    void*       _stack;         // 协程栈空间指针
    FiberFunc   _callback;      // 协程执行函数
};

namespace std
{
    typedef atomic<std::uint64_t> atomic_uint64_t;
}

namespace FiberInfo
{
// 协程栈大小配置项
#define FIBER_STACK_SIZE   (128*1024)

// 最后一个协程的 id
static std::atomic_uint64_t s_fiber_id = {0};
// 存在的协程数量
static std::atomic_uint64_t s_fiber_count = {0};

// 当前线程正在执行的协程
static thread_local Fiber* t_fiber = nullptr;
// 当前线程的主协程
static thread_local Fiber::ptr t_master_fiber = {0};
} // namespace FiberInfo


#endif
