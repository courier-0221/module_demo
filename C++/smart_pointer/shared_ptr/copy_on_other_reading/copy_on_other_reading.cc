#include "mutex.h"
#include <vector>
#include <memory>
#include <assert.h>
#include <stdio.h>

using namespace std;

class Foo
{
public:
    void doit() const;
    //Foo() { printf("Foo()\n"); }
    //~Foo() { printf("~Foo()\n"); }
};

typedef vector<Foo> FooList;
typedef shared_ptr<FooList> FooListPtr;
FooListPtr g_foos;
MutexLock mutex;

//写
void post(const Foo& f)
{
    printf("post\n");
    MutexLockGuard lock(mutex);
    // 如果不是数据的唯一拥有者，对 g_foos 重新分配一块内存，原来的内存给其他的操作用这里指读取操作，读取操作用完后引用计数会-1，最终释放掉
    if (!g_foos.unique())
    {
        g_foos.reset(new FooList(*g_foos));
        printf("copy the whole list\n");
    }
    assert(g_foos.unique());
    g_foos->push_back(f);
}

//读取
void traverse()
{
    FooListPtr foos;
    {
        MutexLockGuard lock(mutex);
        foos = g_foos;      // g_foos 引用计数+1
        assert(!g_foos.unique());
    }

    for (std::vector<Foo>::const_iterator it = foos->begin();
        it != foos->end(); ++it)
    {
        it->doit(); // 读的同时做下写操作
    }
    //traverse()函数调用结束， foos 作为栈上变量离开作用域，自然析构，原数据对象的引用计数 也就是g_foos -1。
}

void Foo::doit() const
{
    Foo f;
    post(f);
}

int main()
{
    g_foos.reset(new FooList);
    
    //1.写
    Foo f;
    post(f);
    
    //2.读
    traverse();

    return 0;
}
