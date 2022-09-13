#include <iostream>
#include <vector>
using namespace std;

class Widget
{
public:
    ~Widget() throw(int)
    {
        throw 100;
    }
};

// v被调用析构函数时，析构的每一个Widget都会抛出一个异常，多个异常堆积，但是C++最多只能同时处理一个异常，这会会自动调用std::terminate()函数导致程序崩溃
void doSomething()
{
    Widget w1, w2, w3;
    std::vector<Widget> v;
    v.push_back(w1);
    v.push_back(w2);
    v.push_back(w3);
}

int main()
{
    doSomething();
    return 0;
}