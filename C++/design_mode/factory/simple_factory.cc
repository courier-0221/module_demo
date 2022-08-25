
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

class Banana : public Fruit
{
public:
	void sayName()
	{
		cout << "我是香蕉...." << endl;
	}
};

class Apple : public Fruit
{
public:
	void sayName()
	{
		cout << "我是苹果...." << endl;
	}
};

//工厂
class Factory
{
public:
	Fruit *CreateProduct(const string &p)
	{
        if (p.compare("banana") == 0) {
			return new Banana;	 
		} else if (p.compare("apple") == 0) {
			return new Apple;
		} else {
			printf("不支持\n" ) ;
			return NULL;
		}
	}
};


int main()
{
	Factory *f = new Factory;

	Fruit *fruit = NULL;


	//工厂生产 香蕉
	fruit = f->CreateProduct("banana");
	fruit->sayName();
	delete fruit;

    //工厂生产 苹果
	fruit = f->CreateProduct("apple");
	fruit->sayName();
	delete fruit;

	delete f;

	return 0;
}