#include "observer.h"

/*****************************************
 * 0.1的问题
 * 不确定observer是否存活，如果observer析构掉了这样在observable中调用update的话容易造成程序崩溃
 * 
 * 解决方案
 * observer在析构函数中解注册
 * 同时加入互斥锁做一点点线程安全的机制
******************************************/

// 被观察者 苹果线下店
class MacBook : public Observable {
public:
    explicit MacBook(const string &data) : _data(data) {}

    // 到货
    void arrival(const string &data) {
        _data = data;
        notify();
    }

public:
    string _data;
};

class Observer1 : public Observer {
public:
    Observer1(MacBook* data):_data(data) {}

    void update() override {
        cout << "Observer1:";
        cout << _data->_data.c_str();
        cout << endl;
    }

private:
    MacBook* _data;
};

class Observer2 : public Observer {
public:
    Observer2(MacBook* data):_data(data) {}

    void update() override {
        cout << "Observer2:";
        cout << _data->_data.c_str();
        cout << endl;
    }

private:
    MacBook* _data;
};

class Observer3 : public Observer {
public:
    Observer3(MacBook* data):_data(data) {}

    void update() override {
        cout << "Observer3:";
        cout << _data->_data.c_str();
        cout << endl;
    }

private:
    MacBook* _data;
};

int main(void)
{
    MacBook m2pro("20 sets will be delivered 2022.08.31");

    Observer1 observer1(&m2pro);
    Observer2 observer2(&m2pro);
    Observer3 observer3(&m2pro);

    //observer1.observe(&m2pro);
    //observer2.observe(&m2pro);
    //observer3.observe(&m2pro);
    m2pro.register_(&observer1);
    m2pro.register_(&observer2);
    m2pro.register_(&observer3);

    m2pro.arrival("20 sets will be delivered 2022.08.31");

    return 0;
}