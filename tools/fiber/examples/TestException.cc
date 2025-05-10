#include "Exception.h"
#include <unistd.h>
#include <iostream>

void fn(int count)
{
    if (count <= 0)
    {
        throw Exception("fn 递归结束");
    }
    fn(count - 1);
}

void throw_system_error()
{
    if (write(0xffff, nullptr, 0) == -1)
    {
        throw SystemError("傻逼");
    }

}

void test01()
{
	std::cout << "test01" << std::endl;
	throw Exception("test01");
}

void test02()
{
	test01();
}

void test03()
{
	test02();
}

void test04()
{
	test03();
}

int main()
{
    try
    {
        fn(10);
    }
    catch (const Exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << e.stackTrace() << std::endl;
    }

    try
    {
        throw_system_error();
    }
    catch (const SystemError& e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << e.stackTrace() << std::endl;
    }
	
	try
	{
		test04();
	}
	catch (const Exception& e)
	{
		std::cerr << e.what() << std::endl;
        std::cerr << e.stackTrace() << std::endl;
	}

    return 0;
}
