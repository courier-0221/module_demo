#include <stdio.h>
#include <memory>
#include <string>
#include <iostream>
using namespace std;

class Stock
{
public:
	string _key;
};

void func_no_reference(shared_ptr<Stock> p1)
{
	cout << " func_no_reference " << p1.use_count() << endl;
}

void func_use_reference(shared_ptr<Stock> &p1)
{
	cout << " func_use_reference " << p1.use_count() << endl;
}

//shared_ptr做函数参数时，
//使用引用传递参数，不会涉及到copy，不会涉及到修改引用计数
//不使用引用传递参数会涉及到copy，涉及到修改引用计数

int main(void)
{
	shared_ptr<Stock> spStock(new Stock);
	cout << " main " << spStock.use_count() << endl;
	
	//func_no_reference(spStock);
	//cout << " main " << spStock.use_count() << endl;
	
	func_use_reference(spStock);
	cout << " main " << spStock.use_count() << endl;
	
	return 0;
} 