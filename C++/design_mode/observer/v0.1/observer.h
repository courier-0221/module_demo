#ifndef _OBSERVER_H_
#define _OBSERVER_H_

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Observable;

// 观察者
class Observer
{
public:
    virtual void update() = 0;
};

// 被观察者
class Observable
{
public:
    void register_(Observer* x);
    void notify();

private:
    vector<Observer*> observers_;
};



void Observable::register_(Observer* x)
{
    observers_.push_back(x);
}

void Observable::notify()
{
    for (Observer* x : observers_) {
        if (x) {
            x->update();
        }
    }
}



#endif