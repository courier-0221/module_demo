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
valgrind --tool=memcheck --leak-check=full ./6_double_free 
==52504== Memcheck, a memory error detector
==52504== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==52504== Using Valgrind-3.20.0 and LibVEX; rerun with -h for copyright info
==52504== Command: ./6_double_free
==52504== 
==52504== Invalid free() / delete / delete[] / realloc()
==52504==    at 0x4C359AF: free (vg_replace_malloc.c:884)
==52504==    by 0x1087F7: main (6.double_free.cc:9)
==52504==  Address 0x5b85c80 is 0 bytes inside a block of size 10 free'd
==52504==    at 0x4C359AF: free (vg_replace_malloc.c:884)
==52504==    by 0x1087EB: main (6.double_free.cc:8)
==52504==  Block was alloc'd at
==52504==    at 0x4C330C5: malloc (vg_replace_malloc.c:393)
==52504==    by 0x1087DB: main (6.double_free.cc:7)
==52504== 
==52504== 
==52504== HEAP SUMMARY:
==52504==     in use at exit: 0 bytes in 0 blocks
==52504==   total heap usage: 2 allocs, 3 frees, 72,714 bytes allocated
==52504== 
==52504== All heap blocks were freed -- no leaks are possible
==52504== 
==52504== For lists of detected and suppressed errors, rerun with: -s
==52504== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)


错误提示：
==52504== Invalid free() / delete / delete[] / realloc()
==52504==    at 0x4C359AF: free (vg_replace_malloc.c:884)
==52504==    by 0x1087F7: main (6.double_free.cc:9)
==52504==  Address 0x5b85c80 is 0 bytes inside a block of size 10 free'd
==52504==    at 0x4C359AF: free (vg_replace_malloc.c:884)
==52504==    by 0x1087EB: main (6.double_free.cc:8)
==52504==  Block was alloc'd at
==52504==    at 0x4C330C5: malloc (vg_replace_malloc.c:393)
==52504==    by 0x1087DB: main (6.double_free.cc:7)

*/