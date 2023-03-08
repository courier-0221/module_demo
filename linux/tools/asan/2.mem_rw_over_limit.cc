// 详细demo https://zhuanlan.zhihu.com/p/360135083

#include <vector>
#include <iostream>

// 内存读写超过限制

//export ASAN_OPTIONS=halt_on_error=0:use_sigaltstack=0:detect_leaks=1:malloc_context_size=15:log_path=/home/xos/asan.log:suppressions=$SUPP_FILE
//ASAN_OPTIONS=${ASAN_OPTIONS}:verbosity=0:handle_segv=1:allow_user_segv_handler=1:detect_stack_use_after_return=1:fast_unwind_on_fatal=1:fast_unwind_on_check=1:fast_unwind_on_malloc=1:quarantine_size=4194304

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
