// 详细demo https://zhuanlan.zhihu.com/p/360135083

#include <iostream>

int g_tmp;

int main()
{
    static int s_tmp;
    int x;
    if (x == 0)
    {
        std::cout << "X is zero" << std::endl;
    }
    return 0;
}

// 使用局部未初始化的变量  asan不可以检测出
// 使用全局变量或静态变量未初始化的变量  asan不可以检测出   目前测试结果

// 运行时加该选项
// ASAN_OPTIONS=check_initialization_order=true ./1_not_init_mem
