#include <iostream>
#include <queue>
using namespace std;

//five

/*先进先出容器*/
/*
与vector相似之处很多

//初始化			只有普通初始化和copy构造
//数据存取操作		变为back和front方法
//遍历				无
//插入操作			只有puqh方法
//删除操作			只有pop方法
*/

int main(void)
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);

	cout << "size:" << q.size() << endl << "back:" << q.back() << endl << "front:" << q.front() << endl;

	

	while (q.size() > 0){
		cout << "pop:" << q.front() << endl;
		q.pop();
	}

	system("pause");
	return 0;
}