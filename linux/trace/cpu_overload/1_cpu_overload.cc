#include <thread>
#include <atomic>
#include <vector>

/*
定位过程

1.定位进程
top -c     -c 显示进程完整信息

2.定位线程
top -H -p <pid>     -H 启用线程模式
                    -p 指定进程
                    -H -p 特定进程下所有线程的详细信息

3.查看线程堆栈
gdb -p <pid> -ex "thread apply all bt" -ex "detach" -ex "quit" > stack_dump.log

4.查看日志
*/

/*
cpu过高的原因
1.代码逻辑问题
    a.死循环，循环退出逻辑错误
    b.算法复杂度高
2.多线程并发
    a.锁的粒度太大或者有竞争，（忙等待持续占用cpu）
3.频繁内存分配释放，缓存未命中。    容易造成内存碎片化严重，分配内存时搜索合适内存块会更耗时。
4.频繁的系统调用。 上下文切换：涉及保存和恢复CPU寄存器、堆栈等状态，消耗cpu周期。
*/


void busy_task() {
    while (true) {
        // 无阻塞操作，持续消耗cpu
    }
}

void slow_algorithm() {
    for (long i = 0; i <10000000000L; i++) {
        volatile int x = i*i;   // 避免编译器优化
    }
}

int main() {
    std::vector<std::thread> threads;
    threads.emplace_back(busy_task);
    threads.emplace_back(slow_algorithm);

    for (auto&t : threads) {
        t.join();
    }

    return 0;
}