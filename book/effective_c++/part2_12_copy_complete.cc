#include <iostream>
#include <string>
using namespace std;

// 错误使用，没有调用到基类的copy构造和赋值操作符
namespace v1
{
void logCall(const std::string& funcName)
{
    printf("%s\n", funcName.c_str());
}
class Customer
{
public:
    Customer() = default;
    ~Customer() = default;
    Customer(const Customer& rhs);
    Customer& operator=(const Customer& rhs);
private:
    std::string name;
};

Customer::Customer(const Customer& rhs) : name(rhs.name)   //使用初始化列表
{
    logCall("Customer copy constructor");
}

Customer& Customer::operator=(const Customer& rhs)
{
    logCall("Customer copy assignment operator");
    name = rhs.name;    //拷贝数据
    return *this;       //返回*this，见第10章
}


class PriorityCustomer : public Customer
{
public:
    PriorityCustomer() = default;
    ~PriorityCustomer() = default;
    PriorityCustomer(const PriorityCustomer& rhs);
    PriorityCustomer& operator=(const PriorityCustomer& rhs);
private:
    int priority;
};

PriorityCustomer::PriorityCustomer(const PriorityCustomer& rhs)
  :priority(rhs.priority)   //使用初始化列表来构造该类的数据成员
{           
    logCall("PriorityCustomer copy constructor");  
}

PriorityCustomer& PriorityCustomer::operator=(const PriorityCustomer& rhs)
{
    logCall("PriorityCustomer copy assignment operator");
    priority = rhs.priority;          //拷贝该类的数据成员
    return *this;
}

void test(void)
{
    PriorityCustomer p1;
    PriorityCustomer p2;
    p1 = p2;
    PriorityCustomer p3 = p2;
}
}

// 正确使用，调用到基类的copy构造和赋值操作符
namespace v2
{
void logCall(const std::string& funcName)
{
    printf("%s\n", funcName.c_str());
}
class Customer
{
public:
    Customer() = default;
    ~Customer() = default;
    Customer(const Customer& rhs);
    Customer& operator=(const Customer& rhs);
private:
    std::string name;
};

Customer::Customer(const Customer& rhs) : name(rhs.name)   //使用初始化列表
{
    logCall("Customer copy constructor");
}

Customer& Customer::operator=(const Customer& rhs)
{
    logCall("Customer copy assignment operator");
    name = rhs.name;    //拷贝数据
    return *this;       //返回*this，见第10章
}


class PriorityCustomer : public Customer
{
public:
    PriorityCustomer() = default;
    ~PriorityCustomer() = default;
    PriorityCustomer(const PriorityCustomer& rhs);
    PriorityCustomer& operator=(const PriorityCustomer& rhs);
private:
    int priority;
};

PriorityCustomer::PriorityCustomer(const PriorityCustomer& rhs)
  :priority(rhs.priority), Customer(rhs)   //使用初始化列表来构造该类的数据成员
{           
    logCall("PriorityCustomer copy constructor");  
}

PriorityCustomer& PriorityCustomer::operator=(const PriorityCustomer& rhs)
{
    logCall("PriorityCustomer copy assignment operator");
    Customer::operator=(rhs);
    priority = rhs.priority;          //拷贝该类的数据成员
    return *this;
}

void test(void)
{
    PriorityCustomer p1;
    PriorityCustomer p2;
    p1 = p2;
    PriorityCustomer p3 = p2;
}
}

int main(void)
{
    //v1::test();
    v2::test();
    return 0;
}