#include <stdio.h>
#include <memory>
#include <string>
#include <map>
#include <iostream>
using namespace std;

class Stock
{
public:
	Stock(const string &key) : _key(key)
	{ cout << "Stock(string)" << endl; }
	
	~Stock(){ cout << "~Stock()" << endl; }
private:
	string _key;
};

class StockFactory
{
public:
	//version 2
	shared_ptr<Stock> get(const string &key)
	{
		shared_ptr<Stock> pStock;
		weak_ptr<Stock> wkStock = _stocks[key];
		pStock = wkStock.lock();
		if (!pStock)
		{
			pStock.reset(new Stock(key));
			wkStock = pStock;
		}
		return pStock;
	}
public:
	map<string, shared_ptr<Stock>> _stocks;
};

namespace version2
{
class StockFactory
{
public:
	shared_ptr<Stock> get(const string& key)
	{
		shared_ptr<Stock> pStock;
		weak_ptr<Stock>& wkStock = _stocks[key];
		printf("wkStock.%p\n", wkStock);
		pStock = wkStock.lock();
		if (!pStock)
		{
			printf("new Stock\n");
			pStock.reset(new Stock(key));
			wkStock = pStock;
		}
		return pStock;
	}

public:
	map<string, weak_ptr<Stock> > _stocks;
};

void func(StockFactory &sf)
{
	shared_ptr<Stock> pdd = sf.get("pdd");
	cout << " pdd " << pdd.use_count() << endl;
}

}



int main(void)
{
#if 0
	StockFactory sf;
	{
		shared_ptr<Stock> pdd = sf.get("pdd");
		cout << " pdd " << pdd.use_count() << endl;
	}
	cout << " sf._stocks.size =  " << sf._stocks.size() << endl;
	
	auto it = sf._stocks.find("pdd");
	if (it == sf._stocks.end())
	{
		cout << "not find" << endl;
	}
	else
	{
		cout << "find" << endl;
	}
#endif
#if 0
	version2::StockFactory sf2;
	{
		shared_ptr<Stock> pdd = sf2.get("pdd");
		cout << " pdd " << pdd.use_count() << endl;
	}
	cout << " sf._stocks.size =  " << sf2._stocks.size() << endl;
	
	auto it = sf2._stocks.find("pdd");
	if (it == sf2._stocks.end())
	{
		cout << "not find" << endl;
	}
	else
	{
		cout << "find" << endl;
	}
#endif
	shared_ptr<Stock> tmp1(new Stock("tmp"));
	cout << " tmp1 " << tmp1.use_count() << endl;
	weak_ptr<Stock> tmpwp = tmp1;
	shared_ptr<Stock> tmp2 = tmpwp.lock();
	//cout << " tmp1 " << tmp1.use_count() << endl;
	cout << " tmp2 " << tmp2.use_count() << endl;
	
	

	return 0;
} 