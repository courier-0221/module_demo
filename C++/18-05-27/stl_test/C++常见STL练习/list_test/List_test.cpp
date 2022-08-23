#include <iostream>
#include <list>
using namespace std;

//six

/*
与vector相似之处很多

//初始化			同vector
//数据存取操作		变为back和front方法
//遍历				迭代器方法
//插入操作			同vector，有insert和push_back,push_front
//删除操作			同vector，有easer和pop_back,pop_front
*/

int main(void)
{
	list<int> list1;

	list1.push_back(1);
	list1.push_back(2);
	list1.push_back(3);
	list1.push_back(4);
	list1.push_back(5);
	list1.push_back(6);
	list1.push_front(0);

	list1.back() = 1000;
	list1.front() = 1000;

	{
		cout <<"list 遍历" << endl;
		for (list<int>::iterator it = list1.begin(); it != list1.end(); it++){
			cout << *it << "  " << endl;
		}
		cout << "size :" << list1.size() << endl;
		cout << endl;
	}

	cout << "list insert" << endl;
	list1.insert(list1.end() , 7);

	cout << "list erase" << endl;
	list1.erase(list1.begin());

	{
		cout << "list 遍历" << endl;
		for (list<int>::iterator it = list1.begin(); it != list1.end(); it++){
			cout << *it << "  " << endl;
		}
		cout << "size :" << list1.size() << endl;
		cout << endl;
	}

	while (list1.size() > 0){
		cout << "pop_back :" << list1.back() << endl;
		list1.pop_back();
	}
	cout << "size :" << list1.size() << endl;

	system("pause");
	return 0;
}