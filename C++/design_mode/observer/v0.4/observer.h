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
    Observable* subject_;
};

// 被观察者
class Observable
{
public:
    void register_(weak_ptr<Observer> x);
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
}

void Observable::register_(weak_ptr<Observer> x)
{
    MutexLockGuard lockGuard(mutex_);
    observers_.push_back(x);
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



#endif