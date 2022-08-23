#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<functional>
#include <set>
#include <memory>
using namespace std;

//eight

/*
集合	元素唯一，自动排序（默认情况下是从小到大）不能按照[]方式插入元素
*/


//基本类型操作
void main01(void)
{
	//初始化
	set<int> set1;	//默认情况从小到大
	//set<int,less<int> > set1;	//等价于这样写
	set<int,greater<int> > set2;	//从大到小

	//插入
	set1.insert(1);
	set1.insert(4);
	set1.insert(2);
	set1.insert(3);
	set1.insert(4);

	//遍历
	for (set<int>::iterator it = set1.begin(); it != set1.end(); it++){
		cout << *it << "  ";
	}
	cout << endl;
	//删除
	while (set1.size() > 0){
		set<int>::iterator it = set1.begin();
		cout << "delete:" << *it << "  ";
		set1.erase(set1.begin());
	}

}


//自定义数据类型的比较大小
class student
{
public :
	student(int _age, char *_name){
		this->age = _age;
		strcpy(this->name, _name);
	}

public:
	int age;
	char name[64];
};

//比较大小的仿函数		这个结构里面应该重载函数调用操作符也就是 “()”
struct Funcstudent
{
	bool operator() (const student &left, const student &right)
	{
		if (left.age < right.age){
			return true;
		}
		else{
			return false;
		}
	}

};

void main02(void)
{
	student
		s1(12, "123"),
		s2(34, "dg"),
		s3(4, "fghfgfgbhfg"),
		s4(57, "6756"),
		s5(8, "4162"),
		s6(4, "fghfgfgbhfg");


	set<student, Funcstudent> set1;
	set1.insert(s1);
	set1.insert(s2);
	set1.insert(s3);
	set1.insert(s4);
	set1.insert(s5);
	set1.insert(s6);

	for (set<student>::iterator it = set1.begin(); it != set1.end(); it++){
		cout << it->age << "   " << it->name << endl;
	}

}


//pair的使用		insert的返回值是pair类型的，用来判断是否调用成功的
void main03(void)
{
	set<int,less<int> > set1;
	set1.insert(3);
	set1.insert(4);
	set1.insert(2);
	set1.insert(6);
	pair<set<int, less<int> >::iterator, bool> p1 = set1.insert(3);
	if (p1.second == true){
		cout << "insert 3 true" << endl;
	}
	else{
		cout << "insert 3 false" << endl;
	}
	

	//遍历
	for (set<int>::iterator it = set1.begin(); it != set1.end(); it++){
		cout << *it << "  ";
	}
	cout << endl;
	//删除
	while (set1.size() > 0){
		set<int>::iterator it = set1.begin();
		cout << "delete:" << *it << "  ";
		set1.erase(set1.begin());
	}
}



//查找函数
void main04(void)
{
	//set.find(elem); // 查找 elem 元素，返回指向 elem 元素的迭代器。
	//set.count(elem); // 返回容器中值为 elem 的元素个数。对 set 来说，要么是 0，要
												//么是 1。对 multiset 来说，值可能大于 1。
	//set.lower_bound(elem); // 返回第一个 >=elem 元素的迭代器。
	//set.upper_bound(elem); // 返回第一个 >elem 元素的迭代器。
	//set.equal_range(elem); // 返回容器中与 elem 相等的上下限的两个迭代器。上
												//限是闭区间，下限是开区间，如[beg, end)
}

class a
{
public:
	void printa()
	{
		cout << "aaa" << endl;
	}

	void printb()
	{
		cout << "bbb" << endl;
	}

	void printb() = delete;

};

int main(void)
{

	//基本类型操作测试
	//main01();

	//自定义数据类型的比较大小测试
	//main02();

	//pair的使用测试
	//main03();

	//auto_ptr<int> p1(new int);
	//auto_ptr<int> p2(p1);

	//*p1 = 20;

	a a1;
	a1.printa();

	unique_ptr<int> p1(new int);

	system("pause");
	return 0;
}