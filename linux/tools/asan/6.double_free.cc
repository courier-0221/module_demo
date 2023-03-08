// 详细demo https://zhuanlan.zhihu.com/p/360135083

#include <iostream>

// 多次释放

int main(void)
{
    char *repeat = static_cast<char *>(malloc(10));
    free(repeat);
    free(repeat);
    return 0;
}

/*
目前asan测不出来

*/