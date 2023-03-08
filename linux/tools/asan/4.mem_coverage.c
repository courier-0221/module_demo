// 详细demo https://zhuanlan.zhihu.com/p/360135083

#include <stdio.h>

// 栈空间数组越界，asan可以发现

int main(void)
{
    char x[10]; 
    x[11] = 'a';

    return 0;
}