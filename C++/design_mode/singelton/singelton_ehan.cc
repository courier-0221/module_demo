#include <iostream>
#include <string>

using namespace std;

class singleton
{
public:
	static singleton* GetInstance()
	{
		return _instance;
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

	static singleton* _instance;
};

singleton* singleton::_instance = new singleton;

int main()
{
	singleton::GetInstance()->print("1234");
	singleton::GetInstance()->print("aaaa");
	singleton::GetInstance()->print("bbbb");

	singleton *p1 = singleton::GetInstance();
	singleton *p2 = singleton::GetInstance();

	if (p1 == p2)
	{
		std::cout << "是同一个对象" << std::endl;
	}
	else
	{
		std::cout << "不是同一个对象" << std::endl;
	}

    return 0;
}