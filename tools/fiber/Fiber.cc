#include "Fiber.h"
#include "Scheduler.h"
class MallocStackAllocator 
{
public:
    static void* Alloc(size_t size)
    {
        return malloc(size);
    }

    static void Dealloc(void* vp, size_t size)
    {
        return free(vp);
    }
};

using StackAllocator = MallocStackAllocator;

Fiber::Fiber()
    : _id(0)
    , _stackSize(0)
    , _state(INIT)
    , _ctx()
    , _stack(nullptr)
    , _callback()
{
    //设置当前线程正在执行的协程
    SetThis(this);
    // 获取上下文对象的副本
    if (getcontext(&_ctx))
    {
        throw Exception(std::string(::strerror(errno)));
    }
    // 存在的协程数量++
    ++FiberInfo::s_fiber_count;
    std::cout << "Fiber::Fiber to create master fiber，threadid = " << ::syscall(SYS_gettid) << " fiberid = " << _id << std::endl;
}

Fiber::Fiber(FiberFunc callback, size_t stack_size)
    : _id(++FiberInfo::s_fiber_id)
    , _stackSize(stack_size)
    , _state(INIT)
    , _ctx()
    , _stack(nullptr)
    , _callback(std::move(callback))
{
    if (_stackSize == 0)
    {
        _stackSize = FIBER_STACK_SIZE;
    }
    // 获取上下文对象的副本
    if (getcontext(&_ctx))
    {
        throw Exception(std::string(::strerror(errno)));
    }
    // 给上下文对象分配分配新的栈空间内存
    _stack = StackAllocator::Alloc(_stackSize);
    _ctx.uc_link = nullptr;
    _ctx.uc_stack.ss_sp = _stack;
    _ctx.uc_stack.ss_size = _stackSize;
    // 给新的上下文绑定入口函数
    makecontext(&_ctx, &Fiber::MainFunc, 0);
    // 存在的协程数量++
    ++FiberInfo::s_fiber_count;
    std::cout << "Fiber::Fiber to create new fiber，threadid = " << ::syscall(SYS_gettid) << " fiberid = " << _id << std::endl;
}

Fiber::~Fiber()
{
    std::cout << "Fiber::~Fiber to destory fiber，threadid = " << ::syscall(SYS_gettid) << " fiberid = " << _id << std::endl;
    // 存在栈，说明是子协程，释放申请的协程栈空间
    if (_stack)
    {
        // 只有子协程未被启动或者执行结束，才能被析构，否则属于程序错误
        assert(_state == INIT || _state == TERM || _state == EXCEPTION);
        StackAllocator::Dealloc(_stack, _stackSize);
    }
    // 否则是主协程
    else
    {
        // 主协程不存在执行函数
        assert(!_callback);
        if (FiberInfo::t_fiber == this)
        {
            SetThis(nullptr);
        }
    }
    --FiberInfo::s_fiber_count;
}

void Fiber::reset(FiberFunc callback)
{
    assert(_stack);
    assert(_state == INIT || _state == TERM || _state == EXCEPTION);
    _callback = std::move(callback);
    if (getcontext(&_ctx))
    {
        throw Exception(std::string(::strerror(errno)));
    }
    _ctx.uc_link = nullptr;
    _ctx.uc_stack.ss_sp = _stack;
    _ctx.uc_stack.ss_size = _stackSize;
    makecontext(&_ctx, &Fiber::MainFunc, 0);
    _state = INIT;
}

void Fiber::swapIn()
{
    assert(_state != EXEC); //只有协程是等待执行的状态才能被换入
    SetThis(this);
    _state = EXEC;
    // 挂起 master fiber，切换到当前 fiber
    // if (swapcontext(&(FiberInfo::t_master_fiber->_ctx), &_ctx))
    if (swapcontext(&(Scheduler::GetMainFiber()->_ctx), &_ctx))
    {
        throw Exception(std::string(::strerror(errno)));
    }
}

void Fiber::swapOut()
{
    assert(_stack);
    SetThis(FiberInfo::t_master_fiber.get());
    // 挂起当前 fiber，切换到 master fiber
    // if (swapcontext(&_ctx, &(FiberInfo::t_master_fiber->_ctx)))
    if (swapcontext(&_ctx, &(Scheduler::GetMainFiber()->_ctx)))
    {
        throw Exception(std::string(::strerror(errno)));
    }
}

void Fiber::call()
{
    assert(FiberInfo::t_master_fiber && "当前线程不存在主协程");
    assert(_state != EXEC); //只有协程是等待执行的状态才能被换入
    SetThis(this);
    _state = EXEC;
    if (swapcontext(&(FiberInfo::t_master_fiber->_ctx), &_ctx))
    {
        throw Exception(std::string(::strerror(errno)));
    }
}

void Fiber::back()
{
    assert(FiberInfo::t_master_fiber && "当前线程不存在主协程");
    assert(_stack);
    SetThis(FiberInfo::t_master_fiber.get());
    if (swapcontext(&_ctx, &(FiberInfo::t_master_fiber->_ctx)))
    {
        throw Exception(std::string(::strerror(errno)));
    }
}

bool Fiber::finish() const noexcept
{
    return (_state == TERM || _state == EXCEPTION);
}

uint64_t Fiber::GetFiberID()
{
    if (NULL != FiberInfo::t_fiber)
    {
        return FiberInfo::t_fiber->getID();
    }
    return 0;
}

uint64_t Fiber::TotalFibers()
{
    return FiberInfo::s_fiber_count;
}

void Fiber::SetThis(Fiber* fiber)
{
    FiberInfo::t_fiber = fiber;
}

Fiber::ptr Fiber::GetThis()
{
    if (nullptr != FiberInfo::t_fiber)
    {
        //当前指向的协程
        return FiberInfo::t_fiber->shared_from_this();
    }
    else
    {
        // 当 FiberInfo::t_fiber 是 nullptr 时，说明该线程不存在 master fiber，构造主协程
        FiberInfo::t_master_fiber.reset(new Fiber());
        assert(FiberInfo::t_fiber == FiberInfo::t_master_fiber.get());
        return FiberInfo::t_master_fiber->shared_from_this();
    }
}

void Fiber::YieldToReady()
{
    Fiber::ptr cur = GetThis();
    cur->_state = READY;
    cur->swapOut();
}

void Fiber::YieldToHold()
{
    Fiber::ptr cur = GetThis();
    cur->_state = HOLD;
    cur->swapOut();
}

void Fiber::MainFunc()
{
    Fiber::ptr cur = GetThis();

    try
    {
        cur->_callback();
        cur->_callback = nullptr;
        cur->_state = TERM;     //调度完成
    }
    catch (std::exception& ex)
    {
        cur->_state = EXCEPTION;
        std::cout << "Fiber Except: " << ex.what() << " fiberid=" << cur->getID() << std::endl;
    }
    catch (...)
    {
        cur->_state = EXCEPTION;
        std::cout << "Fiber Except" << " fiberid=" << cur->getID() << std::endl;
    }

    //执行完在切换回主协程
    //当调用完协程处理函数时需要swapOut调度回主协程，协程Fiber实例的对象是通过智能指针管理的在调用GetThis时将指针计数+1
    //GetThis获取到的Fiber智能指针是在其协程栈上的，为了对资源做回收现拿到裸指针然后再将智能指针清空，通过裸指针调度回主协程
    auto rawPtr = cur.get();
    cur.reset();
    rawPtr->swapOut();
}
