#include <stdio.h>

// 栈空间数组越界，valgrind不能发现，很神奇

int main(void)
{
    char x[10]; 
    x[11] = 'a';

    return 0;
}

/*
valgrind --tool=memcheck --leak-check=full ./4_mem_coverage 
==55534== Memcheck, a memory error detector
==55534== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==55534== Using Valgrind-3.20.0 and LibVEX; rerun with -h for copyright info
==55534== Command: ./4_mem_coverage
==55534== 
*** stack smashing detected ***: <unknown> terminated
==55534== 
==55534== Process terminating with default action of signal 6 (SIGABRT)
==55534==    at 0x4E82E87: raise (raise.c:51)
==55534==    by 0x4E847F0: abort (abort.c:79)
==55534==    by 0x4ECD836: __libc_message (libc_fatal.c:181)
==55534==    by 0x4F78B30: __fortify_fail_abort (fortify_fail.c:33)
==55534==    by 0x4F78AF1: __stack_chk_fail (stack_chk_fail.c:29)
==55534==    by 0x10869D: main (4.mem_coverage.c:11)
==55534== 
==55534== HEAP SUMMARY:
==55534==     in use at exit: 0 bytes in 0 blocks
==55534==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==55534== 
==55534== All heap blocks were freed -- no leaks are possible
==55534== 
==55534== For lists of detected and suppressed errors, rerun with: -s
==55534== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
Makefile:25: recipe for target 'run_4' failed
make: *** [run_4] Aborted (core dumped)

结果：
    不能发现
*/