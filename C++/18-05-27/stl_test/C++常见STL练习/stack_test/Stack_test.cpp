#include <iostream>
#include <stack>
using namespace std;

//four

/*先进后出容器*/

/*
与vector相似之处很多	

//初始化			只有普通初始化和copy构造
//数据存取操作		变为top方法了
//遍历				无
//插入操作			先进后出结构，自然少了insert方法，只有push方法
//删除操作			只有pop方法
*/

int main(void)
{
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	cout << "size:" << s.size() << endl << "top :" << s.top() << endl;

	while (s.size() > 0){
		cout <<"pop:" << s.top() << endl;
		s.pop();
	}

	system("pause");
	return 0;
}