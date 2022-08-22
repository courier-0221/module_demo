#ifndef _OBSERVER_H_
#define _OBSERVER_H_

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
    void register_(Observer* x);
    void unregister(Observer* x);
    void notify();

private:
    vector<Observer*> observers_;
    MutexLock mutex_;   // 锁住observers_
};




Observer::~Observer()
{
    subject_->unregister(this);
}

void Observable::register_(Observer* x)
{
    MutexLockGuard lockGuard(mutex_);
    observers_.push_back(x);
    x->subject_ = this;     //被观察者的指针给上观察者，用于观察者析构时从被观察者列表中删除自己
}

void Observable::unregister(Observer* x)
{
    MutexLockGuard lockGuard(mutex_);
    vector<Observer*>::iterator it = find(observers_.begin(), observers_.end(), x);
    if (it != observers_.end()) {
        swap(*it, observers_.back());
        observers_.pop_back();
    }
}

void Observable::notify()
{
    MutexLockGuard lockGuard(mutex_);
    for (Observer* x : observers_) {
        if (x) {
            x->update();
        }
    }
}



#endif