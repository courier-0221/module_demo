#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<functional>
#include <queue>
using namespace std;

//seven

/*�Ƚ��ȳ�����*/
//���ֵ���ȼ����С���Сֵ���ȼ�����,�����ֵ������Сֵ���ڶ��е���ǰ��

/*
��queue������Ա�����Ƚ���

//��ʼ��			
//���ݴ�ȡ����		��
//����				��
//�������			ֻ��puqh����
//ɾ������			ֻ��pop����
*/


int main(int argc,char *argv[])
{
	priority_queue<int> p1; // Ĭ�������ֵ���ȼ�����
	//priority_queue<int, vector<int>, less<int>> p1; // �൱������д
	priority_queue<int, vector<int>, greater<int> > p2; // ��Сֵ���ȼ�����

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
