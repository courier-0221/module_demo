#include <iostream>
int main()
{
    int x;
    if (x == 0)
    {
        std::cout << "X is zero" << std::endl;
    }
    return 0;
}

// 使用未初始化的变量

/*
valgrind --tool=memcheck --leak-check=full ./1_not_init_mem 
==44909== Memcheck, a memory error detector
==44909== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==44909== Using Valgrind-3.20.0 and LibVEX; rerun with -h for copyright info
==44909== Command: ./1_not_init_mem
==44909== 
==44909== Conditional jump or move depends on uninitialised value(s)
==44909==    at 0x1088C6: main (1.not_init_mem.cc:5)
==44909== 
X is zero
==44909== 
==44909== HEAP SUMMARY:
==44909==     in use at exit: 0 bytes in 0 blocks
==44909==   total heap usage: 2 allocs, 2 frees, 73,728 bytes allocated
==44909== 
==44909== All heap blocks were freed -- no leaks are possible
==44909== 
==44909== Use --track-origins=yes to see where uninitialised values come from
==44909== For lists of detected and suppressed errors, rerun with: -s
==44909== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)


错误提示位置
==44909== Conditional jump or move depends on uninitialised value(s)
==44909==    at 0x1088C6: main (1.not_init_mem.cc:5)

*/