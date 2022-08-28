#include <iostream>
using namespace std;

int main(void)
{
    const int a = 10;
    int const b = 20;

    //const int c;  //err const常量定义时必须初始化
    //a = 100;      //err const常量定义后不允许修改

    printf("a = %d b = %d\n", a, b);

    return 0;
}