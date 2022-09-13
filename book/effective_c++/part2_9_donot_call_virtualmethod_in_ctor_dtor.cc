#include <iostream>
using namespace std;
// 基类的构造函数中调用纯虚函数编译时会报错误，undefined reference to `v1::base::logPrint()'
namespace v1
{
class base
{
public:
    base()
    {
        logPrint();     // warning,pure virtual ‘virtual void v1::base::logPrint()’ called from constructor 
    }
    virtual void logPrint() = 0;
};
class son : public base
{
public:
    son() = default;
    void logPrint()
    {
        printf("son\n");
    }
};
void test()
{
    son s1;
}
}
// 将虚函数装到非虚函数中调用，ctor中调用该非虚函数，编译无问题，运行时程序会崩溃
namespace v2
{
class base
{
public:
    base()
    {
        init();
    }
    void init(){logPrint();}
    virtual void logPrint() = 0;
};
class son : public base
{
public:
    son() = default;
    void logPrint()
    {
        printf("son\n");
    }
};
void test()
{
    son s1;
}
}

int main(void)
{
    //v1::test();
    v2::test();
    return 0;
}