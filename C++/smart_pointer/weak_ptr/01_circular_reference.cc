#include <iostream>
#include <memory>


void weak_ptr_example() {
    std::weak_ptr<int> weak;
    {
        std::shared_ptr<int> shared = std::make_shared<int>(10);
        weak = shared;  // `weak_ptr` 绑定 `shared_ptr`

        std::cout << "shared.use_count() = " << shared.use_count() << std::endl;

        if (std::shared_ptr<int> locked = weak.lock()) {
            std::cout << "资源存在：" << *locked << std::endl;
        }
    }  // `shared_ptr` 离开作用域，资源释放

    if (std::shared_ptr<int> locked = weak.lock()) {
        std::cout << "资源仍然可用：" << *locked << std::endl;
    } else {
        std::cout << "资源已释放" << std::endl;
    }
}


namespace BadExample {

/*
为什么 A 和 B 的析构函数没有被调用？
1.a 和 b 都是 shared_ptr，创建时 use_count = 1。
2.a->ptrB = b，b 的引用计数变成 2。
3.b->ptrA = a，a 的引用计数变成 2。
4.离开 main() 函数时，a 和 b 仍然有相互引用，它们的 use_count 永远不会降到 0，所以不会触发析构函数！
*/

struct B;  // 先声明 B
struct A {
    std::shared_ptr<B> ptrB;
    ~A() { std::cout << "A 销毁" << std::endl; }
};

struct B {
    std::shared_ptr<A> ptrA;
    ~B() { std::cout << "B 销毁" << std::endl; }
};

void test() {
    auto a = std::make_shared<A>();
    auto b = std::make_shared<B>();
    
    a->ptrB = b;
    b->ptrA = a;  // 形成循环引用
    std::cout << "a.use_count() = " << a.use_count() << std::endl;
    std::cout << "b.use_count() = " << b.use_count() << std::endl;

    return;  // ❌ `A` 和 `B` 永远不会被销毁（内存泄漏）
}

};


namespace GoodExample {

/*
为什么这样能正确析构？
1.b->ptrA 是 weak_ptr，不会增加 a 的 use_count。
2.a 释放后，b->ptrA.lock() 获取不到 a，b 也能正确释放。
*/

struct B;  // 先声明 B
struct A {
    std::shared_ptr<B> ptrB;
    ~A() { std::cout << "A 销毁" << std::endl; }
};

struct B {
    std::weak_ptr<A> ptrA;  // 使用 `weak_ptr` 代替 `shared_ptr`
    ~B() { std::cout << "B 销毁" << std::endl; }
};

void test() {
    auto a = std::make_shared<A>();
    auto b = std::make_shared<B>();
    
    a->ptrB = b;
    b->ptrA = a;  // `weak_ptr` 不增加引用计数
    std::cout << "a.use_count() = " << a.use_count() << std::endl;
    std::cout << "b.use_count() = " << b.use_count() << std::endl;

    /*
    output:
    a.use_count() = 1
    b.use_count() = 2
    */

    return;  // ✅ `A` 和 `B` 都能正确释放
}
};


int main() {
    weak_ptr_example();
    BadExample::test();
    GoodExample::test();
    return 0;
}
