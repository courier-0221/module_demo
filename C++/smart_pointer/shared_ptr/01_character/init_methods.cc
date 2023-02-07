#include <iostream>
#include <memory>
#include <string>
#include <string.h>
using namespace std;

// shared_ptr 构造函数时explicit，不可以进行隐式类型转换，必须直接初始化的方式

// 使用构造函数来初始化
void init_method_1(void)
{
    //shared_ptr<int> pi1 = new int(200); //error，智能指针是explicit，不可以进行隐式类型转换，必须直接初始化形式
    shared_ptr<int> pi2(new int(100)); //裸指针初始化，pi指向一个值为100的int型数据，有参构造函数
    shared_ptr<int> pi3 = shared_ptr<int>(new int(100));// 拷贝构造函数
}

// 使用make_shared初始化
void init_method_2(void)
{
    shared_ptr<int> p1 = make_shared<int>(100);
    shared_ptr<string> p2 = make_shared<string>(5, 'a'); //类似于string mystr(5, 'a')
    shared_ptr<int> p3 = make_shared<int>();//默认初值为0，cout<< (*p3.get()) << endl;
}

// 使用shared_ptr的reset方式进行初始化
void init_method_3(void)
{
    shared_ptr<int> p1;
    p1.reset(new int(10));
}

int main(void)
{
    init_method_1();
    init_method_2();
    init_method_3();
    return 0;
}