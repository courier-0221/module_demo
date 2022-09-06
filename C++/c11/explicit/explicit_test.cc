#include <iostream>
using namespace std;

namespace bad
{
class MyInt
{
public:
	MyInt(int num)
	{
		_dNum = num;
	}
	MyInt(const MyInt& objMyInt)
	{
		_dNum = objMyInt.getMyInt();
	}
	int getMyInt() const
	{
		return _dNum;
	}
private:
	int _dNum;
};

void test()
{
    MyInt objMyInt = 11;		//不会编译报错
	MyInt objMyInt1 = objMyInt;	//不会编译报错
}
}

namespace good
{
class MyInt
{
public:
	explicit MyInt(int num)
	{
		_dNum = num;
	}
	explicit MyInt(const MyInt& objMyInt)
	{
		_dNum = objMyInt.getMyInt();
	}
	int getMyInt() const
	{
		return _dNum;
	}
private:
	int _dNum;
};

void test()
{
    MyInt objMyInt = 11;		//编译报错
	MyInt objMyInt1 = objMyInt;	//编译报错
}
}

int main()
{
    bad::test();
    good::test();
	return 0;
}