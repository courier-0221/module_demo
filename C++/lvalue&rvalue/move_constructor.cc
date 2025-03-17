#include <iostream>
using namespace std;

/*
cpp11移动构造函数
介绍
拷贝构造函数
赋值运算法符
移动构造函数
移动赋值运算符
调用时机
*/


class mystring {
private:
    char* _pdata;
    int _size;

public:
    mystring() :_pdata(nullptr), _size(0) {}
    mystring(const char* str) {
        printf("[mystring(const char* str)]\n");
        _size = strlen(str);
        _pdata = new char[_size];
        strncpy(_pdata, str, _size);
    }
    ~mystring() {
        _size = 0;
        if (_pdata) { delete[] _pdata; _pdata = nullptr; }
    }

    // 拷贝构造
    mystring(const mystring & obj) {
        printf("[mystring(const mystring & obj)]\n");
        _size = obj._size;
        _pdata = new char[_size];
        strncpy(_pdata, obj._pdata, _size);
    }

    mystring& operator=(const mystring & obj) {
        printf("[mystring& operator=(const mystring & obj)]\n");
        if (this == &obj) {
            return *this;
        }

        if (_pdata) {delete[] _pdata; _pdata = nullptr;}
        _pdata = new char[obj._size];
        _size = obj._size;
        strncpy(_pdata, obj._pdata, _size);

        return *this;
    }

    mystring(mystring && obj) :_pdata(obj._pdata), _size(obj._size){
        printf("[mystring(mystring && obj)]\n");
        obj._pdata = nullptr;
        obj._size = 0;
    }

    mystring& operator=(mystring && obj) {
        printf("[mystring& operator=(mystring && obj)]\n");
        if (this == &obj) 
            return *this;

        if (_pdata) {delete[] _pdata; _pdata = nullptr;}
        _size = obj._size;
        _pdata = obj._pdata;

        obj._pdata = nullptr;
        obj._size = 0;

        return *this;
    }
};

mystring CreateString(const char* str) {
    mystring ret(str);
    return ret;
}

void test() {
    // 有参构造函数
    mystring s1 = "zhangsan";
    // 拷贝构造函数
    mystring s2 = s1;
    mystring s3;
    // 赋值运算符
    s3 = s1;

    // 移动构造函数
    mystring s4 = move(s1);

    mystring s5;
    // 移动赋值运算符
    s5 = move(s2);

    // 移动构造
    mystring s6 = CreateString("lisi");
}

int main(void) {
    test();

    return 0;
}