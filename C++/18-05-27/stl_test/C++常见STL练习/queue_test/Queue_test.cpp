#include <iostream>
#include <queue>
using namespace std;

//five

/*�Ƚ��ȳ�����*/
/*
��vector����֮���ܶ�

//��ʼ��			ֻ����ͨ��ʼ����copy����
//���ݴ�ȡ����		��Ϊback��front����
//����				��
//�������			ֻ��puqh����
//ɾ������			ֻ��pop����
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