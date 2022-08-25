
#include <iostream>
using namespace std;

// 产品基类
class Fruit
{
public:
	virtual void SayName() = 0;
    virtual ~Fruit() {}
};

//工厂基类
class AbstractFactory
{
public:
	virtual Fruit* CreateBanana() = 0;
	virtual Fruit* CreateApple() = 0;
    virtual ~AbstractFactory() {}
};

// 水果产品派生类
class NorthBanana : public Fruit
{
public:
	virtual void SayName()
	{
		cout << "我是北方香蕉" << endl;
	}
};

class NorthApple : public Fruit
{
public:
	virtual void SayName()
	{
		cout << "我是北方苹果" << endl;
	}
};

class SourthBanana : public Fruit
{
public:
	virtual void SayName()
	{
		cout << "我是南方香蕉" << endl;
	}
};

class SourthApple : public Fruit
{
public:
	virtual void SayName()
	{
		cout << "我是南方苹果" << endl;
	}
};

//工厂派生类
class NorthFacorty : public AbstractFactory
{
	virtual Fruit* CreateBanana()
	{
		return new NorthBanana;
	}
	virtual Fruit* CreateApple()
	{
		return new NorthApple;
	}
};

class SourthFacorty : public AbstractFactory
{
	virtual Fruit* CreateBanana()
	{
		return new SourthBanana;
	}
	virtual Fruit* CreateApple()
	{
		return new SourthApple;
	}
};


int main()
{
	Fruit *fruit = NULL;
	AbstractFactory *af = NULL;

	///--------------
	af = new SourthFacorty;
	fruit = af->CreateApple();
	fruit->SayName();
	delete fruit;
	fruit = af->CreateBanana();
	fruit->SayName();
	delete fruit;

	///------
	af = new NorthFacorty;
	fruit = af->CreateApple();
	fruit->SayName();
	delete fruit;
	fruit = af->CreateBanana();
	fruit->SayName();
	delete fruit;

	delete af;

	return 0;
}