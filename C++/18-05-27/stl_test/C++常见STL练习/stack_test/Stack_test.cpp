#include <iostream>
#include <stack>
using namespace std;

//four

/*�Ƚ��������*/

/*
��vector����֮���ܶ�	

//��ʼ��			ֻ����ͨ��ʼ����copy����
//���ݴ�ȡ����		��Ϊtop������
//����				��
//�������			�Ƚ�����ṹ����Ȼ����insert������ֻ��push����
//ɾ������			ֻ��pop����
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