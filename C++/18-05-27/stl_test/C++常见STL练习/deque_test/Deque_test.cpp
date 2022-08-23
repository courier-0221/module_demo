#include <iostream>
#include <deque>
using namespace std;

//three

//deque 是双端数组 ，而 vector 是单端的。
//与vector类似只不过这个模板类里面有可以在数组头部插入和删除元素的方法

/*
其中比vector多出的方法有
	deque.push_back(elem); // 在容器尾部添加一个数据
	deque.push_front(elem); // 在容器头部插入一个数据
	deque.pop_back(); // 删除容器最后一个数据
	deque.pop_front(); // 删除容器第一个数据
其余的方法基本上都可以替换
像
	//初始化
	//数据存取操作
	//遍历
	//插入操作
	//删除操作
都可以参考vector
这里只实现一下push_front和pop_front方法
*/


int  main(void)
{
	deque<int> d(10);
	for (int i = 0; i < d.size(); i++){
		d[i] = i + 2;
	}
	//头部插入和尾部插入
	d.push_front(1);
	d.push_front(0);
	d.push_back(12);
	d.push_back(13);

	//数据的存储
	d[5] = 1000;
	d.at(8) = 1000;

	{
		for (deque<int>::iterator it = d.begin(); it != d.end();it++){
			cout << *it  << endl;
		}
		cout <<"size:"<< d.size() <<endl;
	}

	system("pause");
	return 0;
}
