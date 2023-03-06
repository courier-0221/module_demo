#include <stdio.h>

// 栈空间数组越界，valgrind不能发现，很神奇

int main(void)
{
    char xx[50];
    for (int ii = 0; ii < 50; ++ii) 
    {
        xx[ii] = ii;
    }
    strncpy(xx + 20, xx, 20);//ok
    strncpy(xx + 20, xx, 21);//overlap

    return 0;
}


/*
valgrind --tool=memcheck --leak-check=full ./4_mem_coverage 
==47558== Memcheck, a memory error detector
==47558== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==47558== Using Valgrind-3.20.0 and LibVEX; rerun with -h for copyright info
==47558== Command: ./4_mem_coverage
==47558== 
==47558== 
==47558== HEAP SUMMARY:
==47558==     in use at exit: 0 bytes in 0 blocks
==47558==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==47558== 
==47558== All heap blocks were freed -- no leaks are possible
==47558== 
==47558== For lists of detected and suppressed errors, rerun with: -s
==47558== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)


结果：
    不能发现
*/