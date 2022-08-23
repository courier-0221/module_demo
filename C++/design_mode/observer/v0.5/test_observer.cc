#include "observer.h"

/*****************************************
 * 0.3的问题
 * 观察者Observer析构的时候不会主动地去被观察者Observable中解注册自己，导致轻微的内存泄漏
 * 
 * 解决方案
 * observer在析构函数中解注册
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
    shared_ptr<MacBook> m2pro = make_shared<MacBook>("20 sets will be delivered 2022.08.31");

    shared_ptr<Observer1> observer1 = make_shared<Observer1>(m2pro.get());
    shared_ptr<Observer2> observer2 = make_shared<Observer2>(m2pro.get());
    shared_ptr<Observer3> observer3 = make_shared<Observer3>(m2pro.get());

    m2pro->register_(observer1);
    m2pro->register_(observer2);
    m2pro->register_(observer3);

    m2pro->arrival("20 sets will be delivered 2022.08.31");

    return 0;
}