#include <iostream>
#include <pthread.h>
#include <assert.h>
using namespace std;

//g++ singelton_lanhan_linux.cc -lpthread

template<typename T>
class Singleton
{
public:
    Singleton() = delete;
    ~Singleton() = delete;
    static T& GetInstance()
    {
        pthread_once(&ponce_, &Singleton::init);
        assert(value_ != NULL);
        return *value_;
    }

private:
    static void init()
    {
        value_ = new T();
        ::atexit(destroy);
    }
    static void destroy()
    {
        typedef char T_must_be_complete_type[sizeof(T) == 0 ? -1 : 1];
        T_must_be_complete_type dummy; (void) dummy;
        delete value_;
        value_ = NULL;
        printf("call destroy\n");
    }

private:
    static pthread_once_t ponce_;
    static T*             value_;
};
template<typename T>
pthread_once_t Singleton<T>::ponce_ = PTHREAD_ONCE_INIT;
template<typename T>
T* Singleton<T>::value_ = NULL;


class singetonTest
{
public:
    void print(std::string str)
	{
		std::cout << str << std::endl;
	}
};

int main()
{
    Singleton<singetonTest>::GetInstance().print("1234");
	Singleton<singetonTest>::GetInstance().print("aaaa");
	Singleton<singetonTest>::GetInstance().print("bbbb");
 
    return 0;
}