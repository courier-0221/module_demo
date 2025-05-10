#include "Scheduler.h"

Scheduler* Scheduler::GetThis()
{
    return SchedulerInfo::t_scheduler;
}

Fiber* Scheduler::GetMainFiber()
{
    return SchedulerInfo::t_scheduler_fiber;
}

Scheduler::Scheduler(size_t threadSize, bool use_caller, std::string name)
    : _name(std::move(name))
{
    assert(threadSize > 0);
    if (use_caller)
    {
        // 实例化此类的线程作为 master fiber
        Fiber::GetThis();
        --threadSize;
        
        // 确保该线程下只有一个调度器
        assert(GetThis() == nullptr);
        SchedulerInfo::t_scheduler = this;
       
        //创建子协程，并将当前子协程标记为调度器正在调度的
        m_root_fiber = std::make_shared<Fiber>(std::bind(&Scheduler::run, this));
        SchedulerInfo::t_scheduler_fiber = m_root_fiber.get();
        
        m_root_thread_id = CurrentThread::tid();
        m_thread_id_list.push_back(m_root_thread_id);
    }
    else
    {
        m_root_thread_id = -1;
    }
    m_thread_count = threadSize;
}

Scheduler::~Scheduler()
{
    std::cout << "Scheduler::~Scheduler()" << std::endl;
    assert(m_auto_stop);
    if (GetThis() == this)
    {
        SchedulerInfo::t_scheduler = nullptr;
    }
}

void Scheduler::start()
{
    std::cout << "Scheduler::start()" << std::endl;
    {
        MutexLockGuard lock(_mutex);
        if (!_stopping)
        {
            // 调度器已经开始工作
            std::cout << "Scheduler already started" << std::endl;
            return;
        }
        _stopping = false;
        
        assert(m_thread_list.empty());
        m_thread_list.resize(m_thread_count);
        for (size_t i = 0; i < m_thread_count; i++)
        {
            m_thread_list[i] = std::make_shared<Thread>(std::bind(&Scheduler::run, this),
                _name + "_" + std::to_string(i));
            m_thread_id_list.push_back(m_thread_list[i]->gettid());
            m_thread_list[i]->start();
        }
    }
}

void Scheduler::stop()
{
    std::cout << "Scheduler::stop() begin" << std::endl;
    m_auto_stop = true;
    // 实例化调度器时的参数 use_caller 为 true, 并且指定线程数量为 1 时
    // 说明只有当前一条主线程在执行，简单等待执行结束即可
    if (m_root_fiber && m_thread_count == 0 &&
        (m_root_fiber->finish() || m_root_fiber->getState() == Fiber::INIT))
    {
        _stopping = true;
        if (onStop())
            return;
    }

    _stopping = true;
    for (size_t i = 0; i < m_thread_count; i++)
    {
        tickle();
    }
    if (m_root_fiber)
    {
        tickle();
        if (!isStop())
        {
            m_root_fiber->call();
        }
    }

    // join 所有子线程
    {
        for (auto& thread : m_thread_list)
        {
            thread->join();
        }
        m_thread_list.clear();
    }
    
    //
    if (onStop())
    {
        return;
    }
    std::cout << "Scheduler::stop() end" << std::endl;
}

bool Scheduler::isStop()
{
    //调用过 Scheduler::stop()，并且任务列表没有新任务，也没有正在执行的协程，说明调度器已经彻底停止
    return m_auto_stop && m_task_list.empty() && m_active_thread_count == 0;
}

void Scheduler::run()
{
    std::cout << "Scheduler::run() being threadid=" << CurrentThread::tid() << std::endl;
    
    //初始化每个线程中的调度器变量t_scheduler，将它指向当前调度器（所有线程共用同一个Scheduler）
    SchedulerInfo::t_scheduler = this;
    //use_caller判断，如果使用了use_caller会在实例化Scheduler时将m_root_thread_id初始化，并创建主+子fiber
    //所以这里通过判定m_root_thread_id是否和调用run方法的线程id是否为同一个线程来判定实例化Schduler时是否指定了use_caller
    //如果不相等说明执行run()的线程不存在master fiber需要创建，同时初始化调用run方法线程中的t_scheduler_fiber变量
    if (CurrentThread::tid() != m_root_thread_id)
    {
        SchedulerInfo::t_scheduler_fiber = Fiber::GetThis().get();
        std::cout << "Scheduler::run() has not master fiber, now create it!!! threadid=" << CurrentThread::tid() << " t_scheduler_fiber " << SchedulerInfo::t_scheduler_fiber << std::endl;
    }
    
    //创建一个idle协程，当调度任务都完成之后执行它
    auto idleFiber = std::make_shared<Fiber>(std::bind(&Scheduler::onIdle, this));

    Task task;
    while (true)
    {
        task.reset();

        //1.从协程队列中取出一个需要处理的协程任务
        bool tickle_me = false;
        {
            MutexLockGuard lock(_mutex);
            //std::cout << "run threadid=" << CurrentThread::tid() << " m_task_list= " << m_task_list.size() << std::endl;
            auto iter = m_task_list.begin();
            while (iter != m_task_list.end())
            {
                //判定协程是否在指定的线程上执行，如果不是在tickle出去通知给下一个线程
                if ((*iter)->threadid != -1 && (*iter)->threadid != CurrentThread::tid())
                {
                    ++iter;
                    tickle_me = true;
                    continue;
                }
                
                //如果正在执行也不处理
                if ((*iter)->fiber && (*iter)->fiber->getState() == Fiber::EXEC)
                {
                    ++iter;
                    continue;
                }

                task = **iter;
                ++m_active_thread_count;
                m_task_list.erase(iter);
                break;
            }
        }
        
        //如果不处理的条件满足，通知给下一个线程
        if (tickle_me)
        {
            tickle();
        }
        
        //2.执行
        
        //方式一：function 协程处理函数
        if (task.callback)
        {
            // 如果是 callback 任务，为其构造成fiber
            task.fiber = std::make_shared<Fiber>(std::move(task.callback));
            task.callback = nullptr;
        }
        
        //方式二：fiber实例对象
        if (task.fiber && !task.fiber->finish())
        {
            //切换协程执行
            task.fiber->swapIn();
            --m_active_thread_count;

            //协程切换回来后，如果协程是就绪状态说明还没处理将其继续添加到任务队列
            Fiber::State fiberStatus = task.fiber->getState();
            if (fiberStatus == Fiber::READY)
            {
                schedule(std::move(task.fiber), task.threadid);
            }
            //其他情况给上挂起状态
            else if (fiberStatus != Fiber::EXCEPTION && fiberStatus != Fiber::TERM)
            {
                task.fiber->_state = Fiber::HOLD;
            }
            task.reset();
        }
        //方式三：fiber或者回调都没有，使用idle协程来处理
        else
        {
            if (idleFiber->finish())
            {
                break;
            }

            //切换协程执行
            ++m_idle_thread_count;
            idleFiber->swapIn();
            --m_idle_thread_count;

            //协程切换回来时判断状态
            if (idleFiber->getState() != Fiber::TERM && idleFiber->getState() != Fiber::EXCEPTION)
            {
                idleFiber->_state = Fiber::HOLD;
            }
        }
    }
    std::cout << "Scheduler::run() end" << std::endl;
}
