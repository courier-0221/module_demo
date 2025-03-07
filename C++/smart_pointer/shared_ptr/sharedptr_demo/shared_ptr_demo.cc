#include <memory>
#include <iostream>
#include <atomic>
using namespace std;

/*
要求
1.不考虑删除器和空间配置器
2.不考虑弱引用
3.考虑引用计数器的线程安全
4.提出测试案例
*/


/*
接口包括：
a.构造函数
b.析构函数
c.拷贝构造函数  std::shared_ptr<int> p2 = p1;
d.赋值运算符
e.移动构造函数
f.移动赋值运算符    std::shared_ptr<int> p2 = std::move(p1);
g.解引用 箭头运算符
    *p = 10;      operator*()重载   T& operator*() const
    p->show()     operator->()重载  T* operator->() const
h.引用计数、原始指针、重置指针  use_count()/get()/reset()
*/


/*
实现：
1.引用计数管理：
    只有当 ref_count 变为 0 时，才释放 ptr。
    防止误操作导致的双重释放问题。
2.拷贝控制：
    拷贝构造：共享已有的 ptr，增加 ref_count。
    赋值运算符：先释放旧资源，再拷贝新资源，避免内存泄漏。
3.移动语义：
    移动构造：转移所有权，原对象清空。
    移动赋值：避免不必要的 ref_count 增减，提高性能。
*/


/*
接口细节：
1.有参构造函数需要 explicit 修饰
2.拷贝构造函数和赋值运算符需要 const T & 常引用、
3.移动构造函数和移动赋值运算符需要 noexcept 修饰
4.只读接口用 const 修饰
*/

/*
内存细节：
1.fetch_add 采用 std::memory_order_releaxed
2.fetch_sub 采用 std::memory_order_acq_rel
3.load 采用 std::memory_order_acquire
*/


//测试class
class TestClass {
public:
    TestClass() { cout<<"TestClass"<<endl; }
    ~TestClass() { cout<<"~TestClass"<<endl; }
};



//正常功能体验
namespace NormalFunc {

void test() {
    shared_ptr<TestClass> p1(new TestClass());
    std::shared_ptr<TestClass> p2 = p1;  // 共享同一对象

    std::cout << "p1 use_count: " << p1.use_count() << std::endl; // 输出 2
    std::cout << "p2 use_count: " << p2.use_count() << std::endl; // 输出 2

    p2.reset();  // p2 释放引用，但 p1 仍然存在
    std::cout << "p1 use_count after p2.reset(): " << p1.use_count() << std::endl; // 输出 1
}

};




//自定义实现 非线程安全
namespace SharedPtrNoThreadSafe { 

template <typename T>
class SharedPtr {
private:
    T* ptr;              // 指向共享资源的指针
    int* ref_count;      // 指向引用计数的指针，所有对象共享，使用变量的话就每个对象各自有各自的

    void release() {
        if (ref_count) {
            (*ref_count)--;
            if (*ref_count == 0) {
                delete ptr;
                delete ref_count;
                ptr = nullptr;
                ref_count = nullptr;
            }
        }
    }

public:
    // 默认构造
    SharedPtr() : ptr(nullptr), ref_count(nullptr) {}

    // 构造函数
    explicit SharedPtr(T* p) : ptr(p), ref_count(new int(1)) {}

    // 拷贝构造函数
    SharedPtr(const SharedPtr& other) : ptr(other.ptr), ref_count(other.ref_count) {
        if (ref_count) {
            (*ref_count)++;
        }
    }

    // 赋值运算符
    SharedPtr& operator=(const SharedPtr& other) {
        if (this != &other) {
            release();
            ptr = other.ptr;
            ref_count = other.ref_count;
            if (ref_count) {
                (*ref_count)++;
            }
        }
        return *this;
    }

    // 移动构造函数（转移所有权）
    SharedPtr(SharedPtr&& other) noexcept : ptr(other.ptr), ref_count(other.ref_count) {
        other.ptr = nullptr;
        other.ref_count = nullptr;
    }

    // 移动赋值运算符
    SharedPtr& operator=(SharedPtr&& other) noexcept {
        if (this != &other) {
            release();
            ptr = other.ptr;
            ref_count = other.ref_count;
            other.ptr = nullptr;
            other.ref_count = nullptr;
        }
        return *this;
    }

    // 解引用操作
    T& operator*() const { return *ptr; }

    // 指针访问操作
    T* operator->() const { return ptr; }

    // 获取原始指针
    T* get() const { return ptr; }

    // 获取引用计数
    int use_count() const { return ref_count ? *ref_count : 0; }

    // 重置当前指针
    void reset(T* p = nullptr) {
        release();
        if (p) {
            ptr = p;
            ref_count = new int(1);
        } else {
            ptr = nullptr;
            ref_count = nullptr;
        }
    }

    // 析构函数
    ~SharedPtr() {
        release();
    }
};

void test() {
    SharedPtr<TestClass> p1(new TestClass());
    SharedPtr<TestClass> p2 = p1;  // 共享同一对象

    std::cout << "p1 use_count: " << p1.use_count() << std::endl; // 输出 2
    std::cout << "p2 use_count: " << p2.use_count() << std::endl; // 输出 2

    p2.reset();  // p2 释放引用，但 p1 仍然存在
    std::cout << "p1 use_count after p2.reset(): " << p1.use_count() << std::endl; // 输出 1
}
};



//自定义实现 线程安全
namespace SharedPtrYesThreadSafe { 

template <typename T>
class SharedPtr {
private:
    T* ptr;              // 指向共享资源的指针
    std::atomic<std::size_t>* ref_count;      // 指向引用计数的指针，所有对象共享，使用变量的话就每个对象各自有各自的

    void release() {
        // fetch_sub(1, std::memory_order_acq_rel) 原子性地将 ref_count 减 1，并返回原来的值。
        if (ref_count && ref_count->fetch_sub(1, std::memory_order_acq_rel) == 1) {
            delete ptr;
            delete ref_count;
        }
    }

public:
    // 默认构造
    SharedPtr() : ptr(nullptr), ref_count(nullptr) {}

    // 构造函数
    explicit SharedPtr(T* p) : ptr(p), ref_count(nullptr) {
        if (p) {
            ref_count = new std::atomic<size_t>(1);
        }
    }

    // 拷贝构造函数
    SharedPtr(const SharedPtr& other) : ptr(other.ptr), ref_count(other.ref_count) {
        if (ref_count) {
            ref_count->fetch_add(1, std::memory_order_relaxed);
        }
    }

    // 赋值运算符
    SharedPtr& operator=(const SharedPtr& other) {
        if (this != &other) {
            release();
            ptr = other.ptr;
            ref_count = other.ref_count;
            if (ref_count) {
                ref_count->fetch_add(1, std::memory_order_relaxed);
            }
        }
        return *this;
    }

    // 移动构造函数（转移所有权）
    SharedPtr(SharedPtr&& other) noexcept : ptr(other.ptr), ref_count(other.ref_count) {
        other.ptr = nullptr;
        other.ref_count = nullptr;
    }

    // 移动赋值运算符
    SharedPtr& operator=(SharedPtr&& other) noexcept {
        if (this != &other) {
            release();
            ptr = other.ptr;
            ref_count = other.ref_count;
            other.ptr = nullptr;
            other.ref_count = nullptr;
        }
        return *this;
    }

    // 解引用操作
    T& operator*() const { return *ptr; }

    // 指针访问操作
    T* operator->() const { return ptr; }

    // 获取原始指针
    T* get() const { return ptr; }

    // 获取引用计数
    int use_count() const { return ref_count ? ref_count->load(std::memory_order_acquire) : 0; }

    // 重置当前指针
    void reset(T* p = nullptr) {
        release();
        if (p) {
            ptr = p;
            ref_count = new std::atomic<size_t> (1);
        } else {
            ptr = nullptr;
            ref_count = nullptr;
        }
    }

    // 析构函数
    ~SharedPtr() {
        release();
    }
};

void test() {
    SharedPtr<TestClass> p1(new TestClass());
    SharedPtr<TestClass> p2 = p1;  // 共享同一对象

    std::cout << "p1 use_count: " << p1.use_count() << std::endl; // 输出 2
    std::cout << "p2 use_count: " << p2.use_count() << std::endl; // 输出 2

    p2.reset();  // p2 释放引用，但 p1 仍然存在
    std::cout << "p1 use_count after p2.reset(): " << p1.use_count() << std::endl; // 输出 1
}
};



int main(void) {
    NormalFunc::test();
    SharedPtrNoThreadSafe::test();
    SharedPtrYesThreadSafe::test();
    
    return 0;
}

