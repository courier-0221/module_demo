#include <iostream>
#include <string>
using namespace std;

//测试常函数和非常函数对const和非const类成员变量的修改情况
namespace const_function_test1
{
class Student
{
public:
    Student(int age, string name)
        : _age(age)
        , _name(name)
    {}

    void showInfoNonConst()
    {
        // 非const成员函数，可以引用const和非const得成员数据，可以修改非const成员数据，但是不能修改const成员数据。
        _age = 23;
        //_name = "zhangsan2";      // err 不允许修改
        printf("showInfoNonConst name=%s age=%d\n", _name.c_str(), _age);
    }

    void showInfoHasConst() const
    {
        // const成员函数，可以引用const和非const得成员数据，但不能修改const和非const的成员数据。
        //_age = 23;                // err 不允许修改
        //_name = "zhangsan2";      // err 不允许修改
        printf("showInfoHasConst name=%s age=%d\n", _name.c_str(), _age);
    }

private:
    const string _name;
    int _age;
};

void test()
{
    Student stu1(18, "zhangsan");
    stu1.showInfoHasConst();
    stu1.showInfoNonConst();
}
}

//测试常函数和非常函数对非const类成员变量的修改情况，非const类成员变量加mutable
namespace const_function_test2
{
class Student
{
public:
    Student(int age, string name)
        : _age(age)
        , _name(name)
    {}

    void showInfoNonConst()
    {
        // 非const成员函数，可以引用const和非const得成员数据，可以修改非const成员数据，但是不能修改const成员数据。
        _age = 23;
        //_name = "zhangsan2";      // err 不允许修改
        printf("showInfoNonConst name=%s age=%d\n", _name.c_str(), _age);
    }

    void showInfoHasConst() const
    {
        // const成员函数，可以引用const和非const得成员数据，但不能修改const和非const的成员数据。
        _age = 24;                  // sucess 加上mutable就可以修改了
        //_name = "zhangsan2";      // err 不允许修改
        printf("showInfoHasConst name=%s age=%d\n", _name.c_str(), _age);
    }

private:
    const string _name;
    mutable int _age;
};

void test()
{
    Student stu1(18, "zhangsan");
    stu1.showInfoHasConst();
    stu1.showInfoNonConst();
}
}

//测试常函数不能调用非const成员函数，如果想要调用，需要将非const成员函数加上const修饰。
namespace const_function_test3
{
class Student
{
public:
    Student(int age, string name)
        : _age(age)
        , _name(name)
    {}

    void showInfoNonConst()
    {
        printf("showInfoNonConst name=%s age=%d\n", _name.c_str(), _age);
    }

    void showInfoHasConst() const
    {
        setAgeHasConst(15);
        //setAgeNonConst(15); // err 不能调用非const成员函数，如果想要调用，需要将非const成员函数加上const修饰。
        printf("showInfoHasConst name=%s age=%d\n", _name.c_str(), _age);
    }

    void setAgeNonConst(int age)
    {
        _age = age;
    }

    void setAgeHasConst(int age) const
    {
        _age = age;
    }

private:
    const string _name;
    mutable int _age;
};

void test()
{
    Student stu1(18, "zhangsan");
    stu1.showInfoHasConst();
    stu1.showInfoNonConst();
}
}

int main(void)
{
    //const_function_test1::test();
    //const_function_test2::test();
    const_function_test3::test();

    return 0;
}