// 详细demo https://zhuanlan.zhihu.com/p/360135083

#include <memory.h>
#include <iostream>
using namespace std;

// 动态内存管理，使用完的内存pp已经被删除了，但是pp又重新使用了起来，然后又释放了一次

int main(void)
{
    char *pp = static_cast<char *>(malloc(10));
    char *ppt = pp;
    for (int iii = 0; iii < 10; ++iii) 
    {    
        pp[iii] = 'z';
    }
    delete pp;
    pp[1] = 'a';
    free(ppt);

    return 0;
}


/*

*/