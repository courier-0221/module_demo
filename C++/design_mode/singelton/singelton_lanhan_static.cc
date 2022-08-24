#include <iostream>
#include <string>
using namespace std;

/***********************
 * C++11规定了local static在多线程条件下的初始化行为，要求编译器保证了内部静态变量的线程安全性。
 * 在C++11标准下，《Effective C++》提出了一种更优雅的单例模式实现，使用函数内的 local static 对象。
 * 这样，只有当第一次访问getInstance()方法时才创建实例。这种方法也被称为Meyers' Singleton。
 * C++0x之后该实现是线程安全的，C++0x之前仍需加锁。 
************************/

class singleton
{
public:
	static singleton& GetInstance()
	{
		static singleton once;
		return once;
	}

	void print(std::string str)
	{
		std::cout << str << std::endl;
	}

private:
	singleton()
	{
		std::cout << "singelton" << std::endl;
	}
	~singleton() = default;
	singleton(const singleton& obj){}
	singleton& operator=(const singleton &obj){}
};

int main()
{
	singleton::GetInstance().print("1234");
	singleton::GetInstance().print("aaaa");
	singleton::GetInstance().print("bbbb");

    return 0;
}