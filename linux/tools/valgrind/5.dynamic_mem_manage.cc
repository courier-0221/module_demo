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
valgrind --tool=memcheck --leak-check=full ./5_dynamic_mem_manage 
==48840== Memcheck, a memory error detector
==48840== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==48840== Using Valgrind-3.20.0 and LibVEX; rerun with -h for copyright info
==48840== Command: ./5_dynamic_mem_manage
==48840== 
==48840== Mismatched free() / delete / delete []
==48840==    at 0x4C36181: operator delete(void*, unsigned long) (vg_replace_malloc.c:947)
==48840==    by 0x10888B: main (5.dynamic_mem_manage.cc:15)
==48840==  Address 0x5b85c80 is 0 bytes inside a block of size 10 alloc'd
==48840==    at 0x4C330C5: malloc (vg_replace_malloc.c:393)
==48840==    by 0x10884B: main (5.dynamic_mem_manage.cc:9)
==48840== 
==48840== Invalid write of size 1
==48840==    at 0x108894: main (5.dynamic_mem_manage.cc:16)
==48840==  Address 0x5b85c81 is 1 bytes inside a block of size 10 free'd
==48840==    at 0x4C36181: operator delete(void*, unsigned long) (vg_replace_malloc.c:947)
==48840==    by 0x10888B: main (5.dynamic_mem_manage.cc:15)
==48840==  Block was alloc'd at
==48840==    at 0x4C330C5: malloc (vg_replace_malloc.c:393)
==48840==    by 0x10884B: main (5.dynamic_mem_manage.cc:9)
==48840== 
==48840== Invalid free() / delete / delete[] / realloc()
==48840==    at 0x4C359AF: free (vg_replace_malloc.c:884)
==48840==    by 0x1088A2: main (5.dynamic_mem_manage.cc:17)
==48840==  Address 0x5b85c80 is 0 bytes inside a block of size 10 free'd
==48840==    at 0x4C36181: operator delete(void*, unsigned long) (vg_replace_malloc.c:947)
==48840==    by 0x10888B: main (5.dynamic_mem_manage.cc:15)
==48840==  Block was alloc'd at
==48840==    at 0x4C330C5: malloc (vg_replace_malloc.c:393)
==48840==    by 0x10884B: main (5.dynamic_mem_manage.cc:9)
==48840== 
==48840== 
==48840== HEAP SUMMARY:
==48840==     in use at exit: 0 bytes in 0 blocks
==48840==   total heap usage: 2 allocs, 3 frees, 72,714 bytes allocated
==48840== 
==48840== All heap blocks were freed -- no leaks are possible
==48840== 
==48840== For lists of detected and suppressed errors, rerun with: -s
==48840== ERROR SUMMARY: 3 errors from 3 contexts (suppressed: 0 from 0)


3处错误
1.
==48840== Mismatched free() / delete / delete []
==48840==    at 0x4C36181: operator delete(void*, unsigned long) (vg_replace_malloc.c:947)
==48840==    by 0x10888B: main (5.dynamic_mem_manage.cc:15)
==48840==  Address 0x5b85c80 is 0 bytes inside a block of size 10 alloc'd
==48840==    at 0x4C330C5: malloc (vg_replace_malloc.c:393)
==48840==    by 0x10884B: main (5.dynamic_mem_manage.cc:9)


2.
==48840== Invalid write of size 1
==48840==    at 0x108894: main (5.dynamic_mem_manage.cc:16)
==48840==  Address 0x5b85c81 is 1 bytes inside a block of size 10 free'd
==48840==    at 0x4C36181: operator delete(void*, unsigned long) (vg_replace_malloc.c:947)
==48840==    by 0x10888B: main (5.dynamic_mem_manage.cc:15)
==48840==  Block was alloc'd at
==48840==    at 0x4C330C5: malloc (vg_replace_malloc.c:393)
==48840==    by 0x10884B: main (5.dynamic_mem_manage.cc:9)


3.
==48840== Invalid free() / delete / delete[] / realloc()
==48840==    at 0x4C359AF: free (vg_replace_malloc.c:884)
==48840==    by 0x1088A2: main (5.dynamic_mem_manage.cc:17)
==48840==  Address 0x5b85c80 is 0 bytes inside a block of size 10 free'd
==48840==    at 0x4C36181: operator delete(void*, unsigned long) (vg_replace_malloc.c:947)
==48840==    by 0x10888B: main (5.dynamic_mem_manage.cc:15)
==48840==  Block was alloc'd at
==48840==    at 0x4C330C5: malloc (vg_replace_malloc.c:393)
==48840==    by 0x10884B: main (5.dynamic_mem_manage.cc:9)
*/