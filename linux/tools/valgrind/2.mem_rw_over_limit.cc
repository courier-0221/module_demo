#include <vector>
#include <iostream>

// 内存读写超过限制

void vector_rw_overlimit(void)
{
    std::vector<int> v(10, 0);
    std::cout << v[10] << std::endl;
}

void malloc_mem_rw_overlimit(void)
{
    int len = 5;
    int *pt = static_cast<int *>(malloc(len * sizeof(int)));
    int *p = pt;
    printf("pt.%p\n", pt);
    for (int i = 0; i < len; ++i)
    {    
        p++;    //此时p指向了申请内存的尾端
    }
    printf("p.%p\n", p);
    *p = 5;     //写入非法
    printf("*p == %d\n", *p);   //读取非法
    free(pt);
}

int main()
{
    vector_rw_overlimit();
    malloc_mem_rw_overlimit();
    
    return 0;
}


/*
valgrind --tool=memcheck --leak-check=full ./2_mem_rw_over_limit 
==51315== Memcheck, a memory error detector
==51315== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==51315== Using Valgrind-3.20.0 and LibVEX; rerun with -h for copyright info
==51315== Command: ./2_mem_rw_over_limit
==51315== 
==51315== Invalid read of size 4
==51315==    at 0x108C0B: vector_rw_overlimit() (2.mem_rw_over_limit.cc:9)
==51315==    by 0x108D3E: main (2.mem_rw_over_limit.cc:30)
==51315==  Address 0x5b85ca8 is 0 bytes after a block of size 40 alloc'd
==51315==    at 0x4C33833: operator new(unsigned long) (vg_replace_malloc.c:434)
==51315==    by 0x1092D3: __gnu_cxx::new_allocator<int>::allocate(unsigned long, void const*) (new_allocator.h:111)
==51315==    by 0x109240: std::allocator_traits<std::allocator<int> >::allocate(std::allocator<int>&, unsigned long) (alloc_traits.h:436)
==51315==    by 0x109191: std::_Vector_base<int, std::allocator<int> >::_M_allocate(unsigned long) (stl_vector.h:172)
==51315==    by 0x10907E: std::_Vector_base<int, std::allocator<int> >::_M_create_storage(unsigned long) (stl_vector.h:187)
==51315==    by 0x108F1E: std::_Vector_base<int, std::allocator<int> >::_Vector_base(unsigned long, std::allocator<int> const&) (stl_vector.h:138)
==51315==    by 0x108E11: std::vector<int, std::allocator<int> >::vector(unsigned long, int const&, std::allocator<int> const&) (stl_vector.h:297)
==51315==    by 0x108BED: vector_rw_overlimit() (2.mem_rw_over_limit.cc:8)
==51315==    by 0x108D3E: main (2.mem_rw_over_limit.cc:30)
==51315== 
0
pt.0x5b86130
p.0x5b86144
==51315== Invalid write of size 4
==51315==    at 0x108D08: malloc_mem_rw_overlimit() (2.mem_rw_over_limit.cc:23)
==51315==    by 0x108D43: main (2.mem_rw_over_limit.cc:31)
==51315==  Address 0x5b86144 is 0 bytes after a block of size 20 alloc'd
==51315==    at 0x4C330C5: malloc (vg_replace_malloc.c:393)
==51315==    by 0x108CAD: malloc_mem_rw_overlimit() (2.mem_rw_over_limit.cc:15)
==51315==    by 0x108D43: main (2.mem_rw_over_limit.cc:31)
==51315== 
==51315== Invalid read of size 4
==51315==    at 0x108D12: malloc_mem_rw_overlimit() (2.mem_rw_over_limit.cc:24)
==51315==    by 0x108D43: main (2.mem_rw_over_limit.cc:31)
==51315==  Address 0x5b86144 is 0 bytes after a block of size 20 alloc'd
==51315==    at 0x4C330C5: malloc (vg_replace_malloc.c:393)
==51315==    by 0x108CAD: malloc_mem_rw_overlimit() (2.mem_rw_over_limit.cc:15)
==51315==    by 0x108D43: main (2.mem_rw_over_limit.cc:31)
==51315== 
*p == 5
==51315== 
==51315== HEAP SUMMARY:
==51315==     in use at exit: 0 bytes in 0 blocks
==51315==   total heap usage: 4 allocs, 4 frees, 73,788 bytes allocated
==51315== 
==51315== All heap blocks were freed -- no leaks are possible
==51315== 
==51315== For lists of detected and suppressed errors, rerun with: -s
==51315== ERROR SUMMARY: 3 errors from 3 contexts (suppressed: 0 from 0)



错误提示
1.非法读
Invalid read of size 4表示越界读取 4 个字节，这个操作出现在main.cpp文件的第 7 行。


2.非法读
==51315== Invalid read of size 4
==51315==    at 0x108D12: malloc_mem_rw_overlimit() (2.mem_rw_over_limit.cc:24)
==51315==    by 0x108D43: main (2.mem_rw_over_limit.cc:31)
==51315==  Address 0x5b86144 is 0 bytes after a block of size 20 alloc'd
==51315==    at 0x4C330C5: malloc (vg_replace_malloc.c:393)
==51315==    by 0x108CAD: malloc_mem_rw_overlimit() (2.mem_rw_over_limit.cc:15)
==51315==    by 0x108D43: main (2.mem_rw_over_limit.cc:31)


3.非法写
==51315== Invalid read of size 4
==51315==    at 0x108D12: malloc_mem_rw_overlimit() (2.mem_rw_over_limit.cc:24)
==51315==    by 0x108D43: main (2.mem_rw_over_limit.cc:31)
==51315==  Address 0x5b86144 is 0 bytes after a block of size 20 alloc'd
==51315==    at 0x4C330C5: malloc (vg_replace_malloc.c:393)
==51315==    by 0x108CAD: malloc_mem_rw_overlimit() (2.mem_rw_over_limit.cc:15)
==51315==    by 0x108D43: main (2.mem_rw_over_limit.cc:31)
*/