#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

//two


//vector 初始化
int main01()
{
	//1		普通初始化
	vector <int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	cout << "v1的尾部元素" << v1.back() << endl;

	//2		vector(n,elem); // 构造函数将 n 个 elem 拷贝给本身。
	vector <int> v2(3, 9);
	cout << "v2的尾部元素" << v2.back() << endl;

	//3		vector(beg,end); // 构造函数将 [beg, end)区间中的元素拷贝给本身。注意该区间是左闭右开的区间
	vector <int> v3(v1.begin(), v1.end());
	cout << "v3的尾部元素" << v3.back() << endl;

	//4		vector(const vector &vec); // 拷贝构造函数
	vector <int> v4 = v1;
	cout << "v4的尾部元素" << v4.back() << endl;
	return 0;
}

//vector的数据存取操作
int main02(void)
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	cout << "数组大小" << v.size() << endl;

	//1、使用front和back方法，返回值可以当左值
	v.front() = 9;
	v.back() = 9;

	//2、使用at方法和数组方式
	v.at(1) = 9;
	v[2] = 9;



	while (v.size() > 0){
		cout << "尾部元素" << v.back() << endl;
		v.pop_back();
	}
	cout << "数组大小" << v.size() << endl;

	return 0;
}


//vector 遍历		vector既能当左值使用也能当右值使用
int main03()
{
	//1	使用数组方式		重载了数组操作符
	cout << "使用数组方式遍历" << endl;
	vector<int> v(10);		//提前把内存准备好	，默认初始化为0
	int i = 0;
	for (i = 0; i < 10; i++){
		v[i] = i;
	}

	for (i = 0; i < 10; i++){
		printf("%d\t", v[i]);
	}


	//2	使用迭代器方式
	cout << "使用迭代器方式遍历" << endl;
	vector<int> v2(10);

	for (i = 0; i < 10; i++){
		v2[i] = i + 1;
	}

	for (vector<int>::iterator it = v2.begin(); it < v2.end(); it++){
		cout << *it << "  ";
	}


	return 0;
}

//push_back 强化记忆
int main04()
{
	vector<int> v(10);
	v.push_back(1000);
	v.push_back(2000);

	cout << "size :" << v.size() << endl;

	for (int i = 0; i < v.size(); i++){
		cout << v[i] << "  " << endl;
	}
	return 0;
}

//迭代器种类	正向和逆向
int main05()
{
	vector<int> v(10);
	cout << "size :" << v.size() << endl;
	for (int i = 0; i < v.size(); i++){
		v[i] = i + 1;
	}
	//1、正向
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << "  ";
	}

	cout << endl;

	//2、逆向
	for(vector<int>::reverse_iterator rit = v.rbegin(); rit != v.rend(); ++rit) 
	{
		cout << *rit << "  ";
	}
	return 0;
}

//插入操作
int main06()
{
	vector<int> v(9);
	for (int i = 0; i < 9; i++){
		v[i] = i + 1;
	}
	//1、push_back方法
	cout << "push_back方法插入10" << endl;
	v.push_back(10);

	//2、vector.insert(pos, elem); // 在 pos 位置插入一个 elem 元素的拷贝， 返回新数据的位置。
	cout << "insert方法插入11" << endl;
	v.insert(v.end(), 11);

	//3、vector.insert(pos, n, elem); // 在 pos 位置插入 n 个 elem 数据，无返回值。
	cout << "insert方法插入3个12" << endl;
	v.insert(v.end(), 3,12);

	//4、vector.insert(pos, beg, end); // 在 pos 位置插入 [beg,end) 区间的数据，无返回值
	cout << "insert方法插入[beg,end)" << endl;
	vector<int> tmp(5);
	for (int i = 0; i < 5; i++){
		tmp[i] = i + 1;
	}
	v.insert(v.end(), tmp.begin(),tmp.end());
	

	{
		for (int i = 0; i < v.size(); i++){
			printf("%d\t", v[i]);
		}
		cout << endl;
	}

	return 0;
}

//删除操作
int main07()
{
	vector<int> v(10);
	for (int i = 0; i < 10; i++){
		v[i] = i + 1;
	}

	//1、区间删除
	cout << "区间删除 删除[0,3)" << endl;
	v.erase(v.begin(), v.begin() + 3);
	{
		for (int i = 0; i < v.size(); i++){
			printf("%d\t", v[i]);
		}
		cout << endl;
	}

	//2、指定位置删除
	cout << "指定位置删除 删除最开始元素" << endl;
	v.erase(v.begin());
	{
		for (int i = 0; i < v.size(); i++){
			printf("%d\t", v[i]);
		}
		cout << endl;
	}
	

	//3、pop_back方法

	//4、根据元素的只删除
	v[1] = 100; v[2] = 100; v[3] = 100;
	for (vector<int>::iterator it = v.begin(); it != v.end(); ){
	
		if (*it == 100){
			it = v.erase(it);
		}
		else{
			it++;
		}
	}
	v.erase(v.begin());
	{
		for (int i = 0; i < v.size(); i++){
			printf("%d\t", v[i]);
		}
		cout << endl;
	}

	return 0;
}



int main(void)
{
	//vector 初始化测试
	//main01();

	//vector的数据存取操作
	//main02();

	//vector 遍历测试
	//main03();

	//push_back 强化测试
	//main04();

	//迭代器种类测试
	//main05();

	//插入操作测试
	//main06();

	//删除操作测试
	//main07();


	system("pause");
	return 0;
}