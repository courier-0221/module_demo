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
    void register_(const weak_ptr<Observer> &x);
    void unregister();
    void notify();

private:
    //vector<Observer*> observers_;
    vector<weak_ptr<Observer>> observers_;    
    // 这里没有用shared_ptr的原因是  如果使用了shared_ptr观察者的指针就算都析构干净了这里还是1，不会被析构掉
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

void Observable::register_(const weak_ptr<Observer> &x)
{
    MutexLockGuard lockGuard(mutex_);
    observers_.push_back(x);
    auto p = x.lock();
    if (p) {
        //p->subject_ = std::shared_ptr<Observable>(this);        //FATAL
        //FATAL的原因是使用 this指针 初始化了一个shared_ptr，
        //当register_执行结束后 this指针 初始化的shared_ptr会被释放掉，其他位置在用observable时会出现访问空指针的情况使程序崩溃。
        p->subject_ = shared_from_this();
    }
}

void Observable::notify()
{
    MutexLockGuard lockGuard(mutex_);
    for (auto iter = observers_.begin(); iter != observers_.end();  ) {
        auto p = iter->lock();
        if (p) {
            p->update();
            ++iter;
        } else {
            //weak_ptr失效，所指向的对象已经析构了，则进行删除操作
            iter = observers_.erase(iter);
        }
    }
}

void Observable::unregister() {
    MutexLockGuard lockGuard(mutex_);
    for (auto iter = observers_.begin(); iter != observers_.end(); ) {
        if (iter->expired()) {
            iter = observers_.erase(iter);
        } else {
            ++iter;
        }
    }
}



#endif