#include <iostream>
#include <deque>
using namespace std;

//three

//deque ��˫������ ���� vector �ǵ��˵ġ�
//��vector����ֻ�������ģ���������п���������ͷ�������ɾ��Ԫ�صķ���

/*
���б�vector����ķ�����
	deque.push_back(elem); // ������β�����һ������
	deque.push_front(elem); // ������ͷ������һ������
	deque.pop_back(); // ɾ���������һ������
	deque.pop_front(); // ɾ��������һ������
����ķ��������϶������滻
��
	//��ʼ��
	//���ݴ�ȡ����
	//����
	//�������
	//ɾ������
�����Բο�vector
����ֻʵ��һ��push_front��pop_front����
*/


int  main(void)
{
	deque<int> d(10);
	for (int i = 0; i < d.size(); i++){
		d[i] = i + 2;
	}
	//ͷ�������β������
	d.push_front(1);
	d.push_front(0);
	d.push_back(12);
	d.push_back(13);

	//���ݵĴ洢
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
