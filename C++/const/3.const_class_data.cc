#include <iostream>
#include <string>
using namespace std;

//类中的const数据成员使用构造函数的初始化列表来初始化 

class Student
{
public:
    Student(int age, string name)
        : _age(age)
        , _name(name)
    {}

    void showInfo()
    {
        printf("name=%s age=%d\n", _name.c_str(), _age);
    }

private:
    const string _name;
    int _age;
};

void test()
{
    Student stu1(18, "zhangsan");
    stu1.showInfo();
}

int main(void)
{
    test();

    return 0;
}