
#include <iostream>
#include <string>
using namespace std;

// 产品基类
class Fruit
{
public:
	virtual void sayName() = 0;
    virtual ~Fruit() {}
};

// 工厂基类
class Factory 
{
public:
	virtual Fruit *CreateProduct() = 0;
    virtual ~Factory() {}
};


//水果产品派生类
class Banana : public Fruit
{
public:
	void  sayName()
	{
		cout << "我是香蕉" << endl;
	}
};

class Apple : public Fruit
{
public:
	void  sayName()
	{
		cout << "我是苹果" << endl;
	} 
};


//工厂派生来
class BananaFactory :public Factory
{
public:
	virtual Fruit *CreateProduct()
	{
		return new Banana;
	}
};

class AppleFactory :public Factory
{
public:
	virtual Fruit *CreateProduct()
	{
		return new Apple;
	}
};

//////////////////////////////////////////////////////////////////////////
//添加新的产品

class Pear : public Fruit
{
public:
	virtual void sayName()
	{
		cout << "我是梨子" << endl;
	}
};

class PearFactory : public Factory
{
public:
	virtual Fruit *CreateProduct()
	{
		return new Pear;
	}
};



int main()
{
	Factory	*factory = NULL;
	Fruit *fruit = NULL;

	//香蕉
	factory = new BananaFactory;
	fruit = factory->CreateProduct();
	fruit->sayName();

	delete fruit;
	delete factory;


	//Pear 
	factory = new PearFactory;
	fruit = factory->CreateProduct();
	fruit->sayName();

	delete fruit;
	delete factory;


	return 0;
}