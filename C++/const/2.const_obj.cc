#include <iostream>
#include <string>
using namespace std;

//基础版本，没有引入常对象
namespace base
{
class Student
{
public:
    Student(int age, string name)
    {
        _age = age;
        _name = name;
    }

    void showInfo()
    {
        printf("name=%s age=%d\n", _name.c_str(), _age);
    }

private:
    string _name;
    int _age;
};

void test()
{
    Student stu1(18, "zhangsan");
    stu1.showInfo();
}
}

// 常对象，只能调用常方法
namespace constObj
{
class Student
{
public:
    Student(int age, string name)
    {
        _age = age;
        _name = name;
    }

    void showInfo() const;
    void calltest() { printf("calltest\n"); }

private:
    string _name;
    int _age;
};

void Student::showInfo() const
{
    printf("name=%s age=%d\n", _name.c_str(), _age);
}

void test()
{
    const Student stu1(18, "zhangsan");
    stu1.showInfo();
    //stu1.calltest();    // err 常对象，不能调用该对象的非const成员函数
}
}


// 延伸，非常对象调用常方法测试是否可行
namespace extend
{
class Student
{
public:
    Student(int age, string name)
    {
        _age = age;
        _name = name;
    }

    void showInfo() const;
    void calltest() { printf("calltest\n"); }

private:
    string _name;
    int _age;
};

void Student::showInfo() const
{
    printf("name=%s age=%d\n", _name.c_str(), _age);
}

void test()
{
    Student stu1(18, "zhangsan");
    stu1.showInfo();
    stu1.calltest();
}
}

int main(void)
{
    //base::test();
    //constObj::test();
    extend::test(); //普通对象可以调用常函数
    return 0;
}