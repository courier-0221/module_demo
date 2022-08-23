#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<functional>
#include <queue>
using namespace std;

//seven

/*先进先出容器*/
//最大值优先级队列、最小值优先级队列,把最大值或者最小值放在队列的最前面

/*
与queue相比类成员方法比较少

//初始化			
//数据存取操作		五
//遍历				无
//插入操作			只有puqh方法
//删除操作			只有pop方法
*/


int main(int argc,char *argv[])
{
	priority_queue<int> p1; // 默认是最大值优先级队列
	//priority_queue<int, vector<int>, less<int>> p1; // 相当于这样写
	priority_queue<int, vector<int>, greater<int> > p2; // 最小值优先级队列

	p1.push(34);
	p1.push(56);
	p1.push(2);
	p1.push(6);
	p1.push(1);

	cout << "p1 top:" << p1.top() << endl;
	while (p1.size() > 0){
		cout << "pop :" << p1.top() << endl;
		p1.pop();
	}
	cout << "size" << p1.size() << endl;


	cout << endl;

	p2.push(34);
	p2.push(56);
	p2.push(2);
	p2.push(6);
	p2.push(1);

	cout << "p2 top:" << p2.top() << endl;
	while (p2.size() > 0){
		cout << "pop :" << p2.top() << endl;
		p2.pop();
	}
	cout << "size" << p2.size() << endl;

	system("pause");
	return 0;
}
