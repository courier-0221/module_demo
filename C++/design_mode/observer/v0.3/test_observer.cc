#include "observer.h"

/*****************************************
 * 0.2的问题
 * observer中保存的observable的指针，如果observable析构了，observer中保存的observable指针会非常危险
 * 在observer的析构函数中解注册没有意义，因为观察者是基类，各种派生类集成这观察者基类，解注册在观察者基类的析构中操作，派生类早就析构了
 * 广泛加锁，效率低下
 * 如果observer的update方法中调用了register_方法导致程序本能崩溃（如果有锁还会存在嵌套锁）
 * 
 * 解决方案
 * 使用智能指针
 * 
 * 该版本目前只添加，不关心观察者从被观察者列表中删除的动作
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