#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

//two


//vector ��ʼ��
int main01()
{
	//1		��ͨ��ʼ��
	vector <int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	cout << "v1��β��Ԫ��" << v1.back() << endl;

	//2		vector(n,elem); // ���캯���� n �� elem ����������
	vector <int> v2(3, 9);
	cout << "v2��β��Ԫ��" << v2.back() << endl;

	//3		vector(beg,end); // ���캯���� [beg, end)�����е�Ԫ�ؿ���������ע�������������ҿ�������
	vector <int> v3(v1.begin(), v1.end());
	cout << "v3��β��Ԫ��" << v3.back() << endl;

	//4		vector(const vector &vec); // �������캯��
	vector <int> v4 = v1;
	cout << "v4��β��Ԫ��" << v4.back() << endl;
	return 0;
}

//vector�����ݴ�ȡ����
int main02(void)
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	cout << "�����С" << v.size() << endl;

	//1��ʹ��front��back����������ֵ���Ե���ֵ
	v.front() = 9;
	v.back() = 9;

	//2��ʹ��at���������鷽ʽ
	v.at(1) = 9;
	v[2] = 9;



	while (v.size() > 0){
		cout << "β��Ԫ��" << v.back() << endl;
		v.pop_back();
	}
	cout << "�����С" << v.size() << endl;

	return 0;
}


//vector ����		vector���ܵ���ֵʹ��Ҳ�ܵ���ֵʹ��
int main03()
{
	//1	ʹ�����鷽ʽ		���������������
	cout << "ʹ�����鷽ʽ����" << endl;
	vector<int> v(10);		//��ǰ���ڴ�׼����	��Ĭ�ϳ�ʼ��Ϊ0
	int i = 0;
	for (i = 0; i < 10; i++){
		v[i] = i;
	}

	for (i = 0; i < 10; i++){
		printf("%d\t", v[i]);
	}


	//2	ʹ�õ�������ʽ
	cout << "ʹ�õ�������ʽ����" << endl;
	vector<int> v2(10);

	for (i = 0; i < 10; i++){
		v2[i] = i + 1;
	}

	for (vector<int>::iterator it = v2.begin(); it < v2.end(); it++){
		cout << *it << "  ";
	}


	return 0;
}

//push_back ǿ������
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

//����������	���������
int main05()
{
	vector<int> v(10);
	cout << "size :" << v.size() << endl;
	for (int i = 0; i < v.size(); i++){
		v[i] = i + 1;
	}
	//1������
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << "  ";
	}

	cout << endl;

	//2������
	for(vector<int>::reverse_iterator rit = v.rbegin(); rit != v.rend(); ++rit) 
	{
		cout << *rit << "  ";
	}
	return 0;
}

//�������
int main06()
{
	vector<int> v(9);
	for (int i = 0; i < 9; i++){
		v[i] = i + 1;
	}
	//1��push_back����
	cout << "push_back��������10" << endl;
	v.push_back(10);

	//2��vector.insert(pos, elem); // �� pos λ�ò���һ�� elem Ԫ�صĿ����� ���������ݵ�λ�á�
	cout << "insert��������11" << endl;
	v.insert(v.end(), 11);

	//3��vector.insert(pos, n, elem); // �� pos λ�ò��� n �� elem ���ݣ��޷���ֵ��
	cout << "insert��������3��12" << endl;
	v.insert(v.end(), 3,12);

	//4��vector.insert(pos, beg, end); // �� pos λ�ò��� [beg,end) ��������ݣ��޷���ֵ
	cout << "insert��������[beg,end)" << endl;
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

//ɾ������
int main07()
{
	vector<int> v(10);
	for (int i = 0; i < 10; i++){
		v[i] = i + 1;
	}

	//1������ɾ��
	cout << "����ɾ�� ɾ��[0,3)" << endl;
	v.erase(v.begin(), v.begin() + 3);
	{
		for (int i = 0; i < v.size(); i++){
			printf("%d\t", v[i]);
		}
		cout << endl;
	}

	//2��ָ��λ��ɾ��
	cout << "ָ��λ��ɾ�� ɾ���ʼԪ��" << endl;
	v.erase(v.begin());
	{
		for (int i = 0; i < v.size(); i++){
			printf("%d\t", v[i]);
		}
		cout << endl;
	}
	

	//3��pop_back����

	//4������Ԫ�ص�ֻɾ��
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
	//vector ��ʼ������
	//main01();

	//vector�����ݴ�ȡ����
	//main02();

	//vector ��������
	//main03();

	//push_back ǿ������
	//main04();

	//�������������
	//main05();

	//�����������
	//main06();

	//ɾ����������
	//main07();


	system("pause");
	return 0;
}