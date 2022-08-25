#include <iostream>
#include <string>
using namespace std;

namespace Ehan
{
class Singelton
{
public:
    static Singelton* GetInstance()
    {
         return _instanse;
    }

    void print(string str)
    {
        printf("%s\n", str.c_str());
    }

private:
    Singelton() {}
    ~Singelton() {}
    Singelton(const Singelton&) {}
    Singelton& operator=(const Singelton&) {}

private:
    static Singelton* _instanse;
};

Singelton* Singelton::_instanse = new(Singelton);

void test(void)
{
    Singelton::GetInstance()->print("1111");
    Singelton::GetInstance()->print("2222");
    Singelton::GetInstance()->print("3333");

    Singelton* p1 = Singelton::GetInstance();
    Singelton* p2 = Singelton::GetInstance();

    if (p1 != p2)
    {
        printf("不是同一个对象\n");
    }
    else
    {
        printf("是同一个对象\n");
    }
}

}

namespace EhanTemplate
{
template<class T>
class Singelton
{
public:
    static T* GetInstance()
    {
         return _instanse;
    }

private:
    Singelton() {}
    ~Singelton() {}
    Singelton(const Singelton&) {}
    Singelton& operator=(const Singelton&) {}

private:
    static T* _instanse;
};

template<class T>
T* Singelton<T>::_instanse = new(T);

class singeltonTest
{
public:
    void print(string str)
    {
        printf("%s\n", str.c_str());
    }
};

void test(void)
{
    Singelton<singeltonTest>::GetInstance()->print("1111");
    Singelton<singeltonTest>::GetInstance()->print("2222");
    Singelton<singeltonTest>::GetInstance()->print("3333");

    singeltonTest* p1 = Singelton<singeltonTest>::GetInstance();
    singeltonTest* p2 = Singelton<singeltonTest>::GetInstance();

    if (p1 != p2)
    {
        printf("不是同一个对象\n");
    }
    else
    {
        printf("是同一个对象\n");
    }
}

}

namespace LanhanStandTemplate
{
template<class T>
class Singelton
{
public:
    static T& GetInstance()
    {

        static T once;
        return once;
    }

private:
    Singelton() {}
    ~Singelton() {}
    Singelton(const Singelton &){}
    Singelton& operator=(const Singelton&) {}
};

class singeltonTest
{
public:
    void print(string str)
    {
        printf("%s\n", str.c_str());
    }
};

void test(void)
{
    Singelton<singeltonTest>::GetInstance().print("1111");
    Singelton<singeltonTest>::GetInstance().print("2222");
    Singelton<singeltonTest>::GetInstance().print("3333");
}

}

namespace LanhanStand
{
class Singelton
{
public:
    static Singelton& GetInstance()
    {

        static Singelton once;
        return once;
    }

    void print(string str)
    {
        printf("%s\n", str.c_str());
    }

private:
    Singelton() {}
    ~Singelton() {}
    Singelton(const Singelton &){}
    Singelton& operator=(const Singelton&) {}
};

void test(void)
{
    Singelton::GetInstance().print("1111");
    Singelton::GetInstance().print("2222");
    Singelton::GetInstance().print("3333");
}

}

namespace LanhanOnce
{
class Singelton
{
public:
    static Singelton* GetInstance()
    {
        pthread_once(&_once, &Singelton::init);
        return _instance;
    }

    void print(string str)
    {
        printf("%s\n", str.c_str());
    }

private:
    static void init()
    {
        _instance = new(Singelton);
        ::atexit(destory);
    }

    static void destory()
    {
        delete _instance;
        _instance = nullptr;
        printf("call destroy\n");
    }

private:
    Singelton() {}
    ~Singelton() {}
    Singelton(const Singelton &) {}
    Singelton& operator=(const Singelton &) {}

private:
    static pthread_once_t _once;
    static Singelton* _instance;
};

pthread_once_t Singelton::_once = PTHREAD_ONCE_INIT;
Singelton* Singelton::_instance = nullptr;

void test(void)
{
    Singelton::GetInstance()->print("1111");
    Singelton::GetInstance()->print("2222");
    Singelton::GetInstance()->print("3333");
    
    Singelton* p1 = Singelton::GetInstance();
    Singelton* p2 = Singelton::GetInstance();

    if (p1 != p2)
    {
        printf("不是同一个对象\n");
    }
    else
    {
        printf("是同一个对象\n");
    }
}
}

namespace LanhanOnceTemplate
{
template<class T>
class Singelton
{
public:
    static T* GetInstance()
    {
        pthread_once(&_once, &Singelton::init);
        return _instance;
    }

private:
    static void init()
    {
        _instance = new(T);
        ::atexit(destory);
    }

    static void destory()
    {
        delete _instance;
        _instance = nullptr;
        printf("call destroy\n");
    }

private:
    Singelton() {}
    ~Singelton() {}
    Singelton(const Singelton &) {}
    Singelton& operator=(const Singelton &) {}

private:
    static pthread_once_t _once;
    static T* _instance;
};

template<class T>
pthread_once_t Singelton<T>::_once = PTHREAD_ONCE_INIT;
template<class T>
T* Singelton<T>::_instance = nullptr;

class singeltonTest
{
public:
    void print(string str)
    {
        printf("%s\n", str.c_str());
    }
};

void test(void)
{
    Singelton<singeltonTest>::GetInstance()->print("1111");
    Singelton<singeltonTest>::GetInstance()->print("2222");
    Singelton<singeltonTest>::GetInstance()->print("3333");
    
    singeltonTest* p1 = Singelton<singeltonTest>::GetInstance();
    singeltonTest* p2 = Singelton<singeltonTest>::GetInstance();

    if (p1 != p2)
    {
        printf("不是同一个对象\n");
    }
    else
    {
        printf("是同一个对象\n");
    }
}
}


int main(void)
{
    //Ehan::test();
    //EhanTemplate::test();
    //LanhanStand::test();
    //LanhanStandTemplate::test();
    //LanhanOnce::test();
    LanhanOnceTemplate::test();
    
    return 0;
}