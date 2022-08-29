#include <iostream>
#include <string>
using namespace std;

void printName(string & name)
{
    printf("[lvalue] name.%s\n", name.c_str());
}

void printName(string && name)
{
    printf("[rvalue] name.%s\n", name.c_str());
}

int main(void)
{
    string fristName = "zhang";
    string lastName = "san";
    string fullName = fristName + lastName;

    printName(fullName);                //等价于 string &name = fullName;       左值引用变量
    printName(fristName + lastName);    //等价于 string && name = "zhangsan";   右值引用临时数据

    return 0;
}