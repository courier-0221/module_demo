#include <iostream>
using namespace std;

//编译时需要使用如下命令取消编译器做的优化
//g++ rvalue_reference.cc -fno-elide-constructors

namespace rvalueReferenceV1
{
class Stack
{
public:
    // 构造
    Stack(int size = 1000) 
	    :_size(size), _top(0)
    {
	    cout << "Stack(int)" << endl;
	    _pstack = new int[size];
    }
	
    // 析构
    ~Stack()
    {
        cout << "~Stack()" << endl;
        delete[]_pstack;
        _pstack = nullptr;
    }
	
    // 拷贝构造
    Stack(const Stack &src)
	    :_size(src._size), _top(src._top)
    {
        cout << "Stack(const Stack&)" << endl;
        _pstack = new int[src._size];
        for (int i = 0; i < _top; ++i) {
            _pstack[i] = src._pstack[i];
        }
    }
	
    // 赋值重载
    Stack& operator=(const Stack &src)
    {
        cout << "operator=" << endl;
        if (this == &src)
            return *this;

        delete[]_pstack;

        _size = src._size;
        _top = src._top;
        _pstack = new int[src._size];
        for (int i = 0; i < _top; ++i) {
            _pstack[i] = src._pstack[i];
        }
        return *this;
    }

    int getSize() 
    {
	    return _size;
    }
private:
    int *_pstack;
    int _top;
    int _size;
};

Stack GetStack(Stack &stack)
{
    Stack tmp(stack.getSize());
    return tmp;
}

void test()
{
    Stack s;
    s = GetStack(s);
}

//输出：
/*
Stack(int)             // 构造s
Stack(int)             // 构造tmp
Stack(const Stack&)    // tmp拷贝构造main函数栈帧上的临时对象
~Stack()               // tmp析构
operator=              // 临时对象赋值给s
~Stack()               // 临时对象析构
~Stack()               // s析构
*/
}


namespace rvalueReferenceV2
{
class Stack
{
public:
    // 构造
    Stack(int size = 1000) 
	    :_size(size), _top(0)
    {
	    cout << "Stack(int)" << endl;
	    _pstack = new int[size];
    }
	
    // 析构
    ~Stack()
    {
        cout << "~Stack()" << endl;
        delete[]_pstack;
        _pstack = nullptr;
    }
	
    // 拷贝构造
    Stack(const Stack &src)
	    :_size(src._size), _top(src._top)
    {
        cout << "Stack(const Stack&)" << endl;
        _pstack = new int[src._size];
        for (int i = 0; i < _top; ++i) {
            _pstack[i] = src._pstack[i];
        }
    }
	
    // 赋值重载
    Stack& operator=(const Stack &src)
    {
        cout << "operator=" << endl;
        if (this == &src)
            return *this;

        delete[]_pstack;

        _size = src._size;
        _top = src._top;
        _pstack = new int[src._size];
        for (int i = 0; i < _top; ++i) {
            _pstack[i] = src._pstack[i];
        }
        return *this;
    }

    // 带右值引用参数的拷贝构造函数
    Stack(Stack &&src)
        :_size(src._size), _top(src._top)
    {
        cout << "Stack(Stack&&)" << endl;

        /*此处没有重新开辟内存拷贝数据，把src的资源直接给当前对象，再把src置空*/
        _pstack = src._pstack;  
        src._pstack = nullptr;
    }

    // 带右值引用参数的赋值运算符重载函数
    Stack& operator=(Stack &&src)
    {
        cout << "operator=(Stack&&)" << endl;

        if(this == &src)
            return *this;
            
        delete[]_pstack;

        _size = src._size;
        _top = src._top;

        /*此处没有重新开辟内存拷贝数据，把src的资源直接给当前对象，再把src置空*/
        _pstack = src._pstack;
        src._pstack = nullptr;

        return *this;
    }

    int getSize() 
    {
	    return _size;
    }
private:
    int *_pstack;
    int _top;
    int _size;
};

Stack GetStack(Stack &stack)
{
    Stack tmp(stack.getSize());
    return tmp;
}

void test()
{
    Stack s;
    s = GetStack(s);
}

//输出：
/*
Stack(int)             // 构造s
Stack(int)             // 构造tmp
Stack(Stack&&)         // 调用带右值引用的拷贝构造函数，直接将tmp的资源给临时对象
~Stack()               // tmp析构
operator=(Stack&&)     // 调用带右值引用的赋值运算符重载函数，直接将临时对象资源给s
~Stack()               // 临时对象析构
~Stack()               // s析构
*/
}

int main()
{
    //rvalueReferenceV1::test();
    rvalueReferenceV2::test();

    return 0;
}