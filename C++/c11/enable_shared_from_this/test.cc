#include <iostream>
#include <memory>
using namespace std;

// 即使同一个指针初始化两个 shared_ptr 得到的也是两个 shared_ptr 对象
namespace base
{
void test(void)
{
    int* pA = new int;
    shared_ptr<int> p1(pA);
    shared_ptr<int> p2(pA);
    printf("p1.use_count.%ld\t p1.use_count.%ld\n", p1.use_count(), p2.use_count());
}
}

// 和 base 中的效果一样，this初始化的shared_ptr 和 new base得到的shared_ptr 是两个
namespace bad
{
class base
{
public:
    shared_ptr<base> get_sharedptr()
    {
        return shared_ptr<base>(this);
    }
};

void test(void)
{
    shared_ptr<base> p1(new base());
    shared_ptr<base> p2 = p1->get_sharedptr();
    printf("p1.use_count.%ld\t p1.use_count.%ld\n", p1.use_count(), p2.use_count());
}
}

// shared_from_this() 返回的是 this 的 shared_ptr版本，用来初始化p2，p1和p2指向同一个内容
namespace good
{
class base : public enable_shared_from_this<base>
{
public:
    shared_ptr<base> get_sharedptr()
    {
        return shared_from_this();
    }
};

void test(void)
{
    shared_ptr<base> p1(new base());
    shared_ptr<base> p2 = p1->get_sharedptr();
    printf("p1.use_count.%ld\t p1.use_count.%ld\n", p1.use_count(), p2.use_count());
}
}

int main(void)
{
    //base::test();
    //bad::test();
    good::test();
    
    return 0;
}