#include <iostream>
#include <string.h>
using namespace std;

class mystring
{
public:
    mystring() : _pdata(nullptr), _size(0) {}
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

#if 1
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
#endif

    //move 赋值操作符
    mystring& operator=(mystring && obj) noexcept
    {
        printf("operator= &&!\n");
    
        //&obj为取地址符
        //先判定下当前对象和传参是不是指向同一个内容，如果是的话就不用操作了
        if (this != &obj)
        {
            //将本对象原来的指针内存释放
            delete[] _pdata;

            //本对象窃取数据内容
            _size = obj._size;
            _pdata = obj._pdata;
            
            //旧对象的对指针需要clear
            obj._size = 0;
            obj._pdata = nullptr;
        }
        return *this;
    }

    ~mystring()
    {
        printf("destory!\n");
        delete[] _pdata;
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

int main(void)
{
    mystring apple = "Apple";
    mystring dest;
    
    printf("Apple: ");
    apple.printData();
    printf("Dest: ");
    dest.printData();
    
    //dest = apple;    //没有实现赋值操作符，所以这里会报错
    dest = std::move(apple);

    printf("Apple: ");
    apple.printData();
    printf("Dest: ");
    dest.printData();

    // 移动构造函数，如果把移动构造函数注释掉则调用拷贝构造函数，如果不注释掉移动构造函数则std::move有效调用移动构造
    mystring tmp = std::move(dest);
    printf("Apple: ");
    apple.printData();
    printf("Dest: ");
    dest.printData();
    printf("Tmp: ");
    tmp.printData();

    return 0;
}