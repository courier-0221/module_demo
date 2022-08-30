#include <iostream>
#include <string.h>
using namespace std;

//编译时需要使用如下命令取消编译器做的优化
//g++ 2.example_rvalue_reference.cc -fno-elide-constructors

namespace base
{
class mystring
{
public:
    mystring() = default;
    mystring(const char* str)
    {
        printf("created!\n");
        _size = ::strlen(str);
        _pdata = new char[_size];
        ::memcpy(_pdata, str, _size);
    }

    //copy构造
    mystring(const mystring & obj)
    {
        printf("copied!\n");
        _size = obj._size;
        _pdata = new char[_size];
        ::memcpy(_pdata, obj._pdata, _size);
    }

    ~mystring()
    {
        printf("destory!\n");
        delete _pdata;
        _pdata = nullptr;
    }

    void printData()
    {
        for (int i = 0; i < _size; i++)
            printf("%c", _pdata[i]);
        printf("\n");
    }

private:
    char* _pdata;
    int _size;
};

class Entity
{
public:
    //有参构造函数 使用常引用做参数
    Entity(const mystring &name) : _name(name) {}

    //copy构造函数
    //Entity(const Entity & obj) {}

    void printName() { _name.printData(); }
private:
    mystring _name;
};

void test()
{
    Entity entity("zhangsan");
    entity.printName();
}

//输出
/*
created!        //test func中 用"zhangsan"构造一个临时的mystring对象
copied!         //Entity有参构造函数中_name(name)，显示调用拷贝构造函数
destory!        //test func中 用"zhangsan"构造一个临时的mystring对象析构
zhangsan        
destory!        //test func调用结束 entity 作用域消失 _name 析构
*/

//目的：使用移动语义来做到不调用mystring的拷贝构造函数，来减少内存分配
}

namespace moveOptimization
{
class mystring
{
public:
    mystring() = default;
    mystring(const char* str)
    {
        printf("created!\n");
        _size = ::strlen(str);
        _pdata = new char[_size];
        ::memcpy(_pdata, str, _size);
    }

    //copy构造
    mystring(const mystring & obj)
    {
        printf("copied!\n");
        _size = obj._size;
        _pdata = new char[_size];
        ::memcpy(_pdata, obj._pdata, _size);
    }

    //move构造
    mystring(mystring && obj) noexcept
    {
        printf("moved!\n");
        //只需要重新指向
        _size = obj._size;
        _pdata = obj._pdata;
        
        //旧对象的对指针需要clear
        obj._size = 0;
        obj._pdata = nullptr;
    }

    ~mystring()
    {
        printf("destory!\n");
        delete _pdata;
        _pdata = nullptr;
    }

    void printData()
    {
        for (int i = 0; i < _size; i++)
            printf("%c", _pdata[i]);
        printf("\n");
    }

private:
    char* _pdata;
    int _size;
};

class Entity
{
public:
    //有参构造函数 使用常引用做参数
    Entity(const mystring & name) : _name(name) { printf("Entity(const mystring & name)\n"); }

    //右值引用构造函数 使用右值引用做参数
    Entity(mystring && name) : _name(name) { printf("Entity(mystring && name)\n"); }

    //copy构造函数
    //Entity(const Entity & obj) {}

    void printName() { _name.printData(); }
private:
    mystring _name;
};

void test()
{
    Entity entity("zhangsan");
    entity.printName();
}

//输出
/*
created!        //test func中 用"zhangsan"构造一个临时的mystring对象
copied!         //Entity有参构造函数中_name(name)，显示调用拷贝构造函数
Entity(mystring && name)
destory!        //test func中 用"zhangsan"构造一个临时的mystring对象析构
zhangsan        
destory!        //test func调用结束 entity 作用域消失 _name 析构
*/

//疑问：
//这里看到明明调用了Entity右值引用为参数的构造函数，为什么还调用了mystring的 copy构造函数？

}

namespace moveOptimizationV2
{
class mystring
{
public:
    mystring() = default;
    mystring(const char* str)
    {
        printf("created!\n");
        _size = ::strlen(str);
        _pdata = new char[_size];
        ::memcpy(_pdata, str, _size);
    }

    //copy构造
    mystring(const mystring & obj)
    {
        printf("copied!\n");
        _size = obj._size;
        _pdata = new char[_size];
        ::memcpy(_pdata, obj._pdata, _size);
    }

    //move构造
    mystring(mystring && obj) noexcept
    {
        printf("moved!\n");
        //只需要重新指向
        _size = obj._size;
        _pdata = obj._pdata;
        
        //旧对象的对指针需要clear
        obj._size = 0;
        obj._pdata = nullptr;
    }

    ~mystring()
    {
        printf("destory!\n");
        delete _pdata;
        _pdata = nullptr;
    }

    void printData()
    {
        for (int i = 0; i < _size; i++)
            printf("%c", _pdata[i]);
        printf("\n");
    }

private:
    char* _pdata;
    int _size;
};

class Entity
{
public:
    //有参构造函数 使用常引用做参数
    Entity(const mystring & name) : _name(name) { printf("Entity(const mystring & name)\n"); }

    //右值引用构造函数 使用右值引用做参数
    //Entity(mystring && name) : _name((mystring&&)name) { printf("Entity(mystring && name)\n"); }
    Entity(mystring && name) : _name(std::move(name)) { printf("Entity(mystring && name)\n"); }

    //copy构造函数
    //Entity(const Entity & obj) {}

    void printName() { _name.printData(); }
private:
    mystring _name;
};

void test()
{
    Entity entity("zhangsan");
    entity.printName();
}

//输出
/*
created!        //test func中 用"zhangsan"构造一个临时的mystring对象
moved!          //Entity有参构造函数中_name(std::move(name))，调用move构造函数
Entity(mystring && name)
destory!        //test func中 用"zhangsan"构造一个临时的mystring对象析构
zhangsan        
destory!        //test func调用结束 entity 作用域消失 _name 析构
*/

}

int main(void)
{
    //base::test();
    //moveOptimization::test();
    moveOptimizationV2::test();
    
    return 0;
}