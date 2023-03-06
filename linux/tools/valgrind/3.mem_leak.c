#include <stdlib.h>
#include <memory.h>

int main()
{
    int *array = (int*)malloc(sizeof(int));
    return 0;
}

// 内存越界访问

/*
valgrind --tool=memcheck --leak-check=full ./3_mem_leak 
==46275== Memcheck, a memory error detector
==46275== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==46275== Using Valgrind-3.20.0 and LibVEX; rerun with -h for copyright info
==46275== Command: ./3_mem_leak
==46275== 
==46275== 
==46275== HEAP SUMMARY:
==46275==     in use at exit: 4 bytes in 1 blocks
==46275==   total heap usage: 1 allocs, 0 frees, 4 bytes allocated
==46275== 
==46275== 4 bytes in 1 blocks are definitely lost in loss record 1 of 1
==46275==    at 0x4C330C5: malloc (vg_replace_malloc.c:393)
==46275==    by 0x10865B: main (3.mem_leak.cc:6)
==46275== 
==46275== LEAK SUMMARY:
==46275==    definitely lost: 4 bytes in 1 blocks
==46275==    indirectly lost: 0 bytes in 0 blocks
==46275==      possibly lost: 0 bytes in 0 blocks
==46275==    still reachable: 0 bytes in 0 blocks
==46275==         suppressed: 0 bytes in 0 blocks
==46275== 
==46275== For lists of detected and suppressed errors, rerun with: -s
==46275== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)


错误提示
==46275== 4 bytes in 1 blocks are definitely lost in loss record 1 of 1
==46275==    at 0x4C330C5: malloc (vg_replace_malloc.c:393)
==46275==    by 0x10865B: main (3.mem_leak.cc:6)
*/