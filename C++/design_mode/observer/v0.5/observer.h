#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include <memory>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include "mutex.h"

using namespace std;

class Observable;

// 观察者
class Observer
{
public:
    virtual ~Observer();
    virtual void update() = 0;

public:
    //Observable* subject_;
    std::weak_ptr<Observable> subject_;
};

// 被观察者
class Observable : public enable_shared_from_this<Observable>
{
public: 
    using ObserverList = std::vector<std::weak_ptr<Observer>>;
    
    Observable(): observers_(new ObserverList) {}
    
    void register_(const weak_ptr<Observer> &x);
    void unregister();
    void notify();

private:
    shared_ptr<ObserverList> observers_;
    MutexLock mutex_;   // 锁住observers_
};




Observer::~Observer()
{
    //派生类析构结束
    auto p = subject_.lock();
    if (p) {
        p->unregister();
    }
}

// cow的读取方
void Observable::notify()
{
    shared_ptr<ObserverList> ob;
    {
        MutexLockGuard lockGuard(mutex_);
        ob = observers_;
    }
    
    for (auto iter = ob->begin(); iter != ob->end();  iter++) {
        auto p = iter->lock();
        if (p) {
            p->update();
        }
    }
}

// cow的写入方
void Observable::register_(const weak_ptr<Observer> &x)
{
    {
        MutexLockGuard lockGuard(mutex_);
        if (!observers_.unique()) {
            observers_.reset(new ObserverList(*observers_));
        }
        observers_->push_back(x);
    }
    
    auto p = x.lock();
    if (p) {
        //p->subject_ = std::shared_ptr<Observable>(this);        //FATAL
        //FATAL的原因是使用 this指针 初始化了一个shared_ptr，
        //当register_执行结束后 this指针 初始化的shared_ptr会被释放掉，其他位置在用observable时会出现访问空指针的情况使程序崩溃。
        p->subject_ = shared_from_this();
    }
}

// cow的写入方
void Observable::unregister() {
    MutexLockGuard lockGuard(mutex_);
    if (!observers_.unique()) {
            observers_.reset(new ObserverList(*observers_));
    }

    for (auto iter = observers_->begin(); iter != observers_->end(); ) {
        if (iter->expired()) {
            iter = observers_->erase(iter);
        } else {
            ++iter;
        }
    }
}

#endif