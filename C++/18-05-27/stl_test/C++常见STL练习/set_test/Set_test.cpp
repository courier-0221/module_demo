#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<functional>
#include <set>
#include <memory>
using namespace std;

//eight

/*
����	Ԫ��Ψһ���Զ�����Ĭ��������Ǵ�С���󣩲��ܰ���[]��ʽ����Ԫ��
*/


//�������Ͳ���
void main01(void)
{
	//��ʼ��
	set<int> set1;	//Ĭ�������С����
	//set<int,less<int> > set1;	//�ȼ�������д
	set<int,greater<int> > set2;	//�Ӵ�С

	//����
	set1.insert(1);
	set1.insert(4);
	set1.insert(2);
	set1.insert(3);
	set1.insert(4);

	//����
	for (set<int>::iterator it = set1.begin(); it != set1.end(); it++){
		cout << *it << "  ";
	}
	cout << endl;
	//ɾ��
	while (set1.size() > 0){
		set<int>::iterator it = set1.begin();
		cout << "delete:" << *it << "  ";
		set1.erase(set1.begin());
	}

}


//�Զ����������͵ıȽϴ�С
class student
{
public :
	student(int _age, char *_name){
		this->age = _age;
		strcpy(this->name, _name);
	}

public:
	int age;
	char name[64];
};

//�Ƚϴ�С�ķº���		����ṹ����Ӧ�����غ������ò�����Ҳ���� ��()��
struct Funcstudent
{
	bool operator() (const student &left, const student &right)
	{
		if (left.age < right.age){
			return true;
		}
		else{
			return false;
		}
	}

};

void main02(void)
{
	student
		s1(12, "123"),
		s2(34, "dg"),
		s3(4, "fghfgfgbhfg"),
		s4(57, "6756"),
		s5(8, "4162"),
		s6(4, "fghfgfgbhfg");


	set<student, Funcstudent> set1;
	set1.insert(s1);
	set1.insert(s2);
	set1.insert(s3);
	set1.insert(s4);
	set1.insert(s5);
	set1.insert(s6);

	for (set<student>::iterator it = set1.begin(); it != set1.end(); it++){
		cout << it->age << "   " << it->name << endl;
	}

}


//pair��ʹ��		insert�ķ���ֵ��pair���͵ģ������ж��Ƿ���óɹ���
void main03(void)
{
	set<int,less<int> > set1;
	set1.insert(3);
	set1.insert(4);
	set1.insert(2);
	set1.insert(6);
	pair<set<int, less<int> >::iterator, bool> p1 = set1.insert(3);
	if (p1.second == true){
		cout << "insert 3 true" << endl;
	}
	else{
		cout << "insert 3 false" << endl;
	}
	

	//����
	for (set<int>::iterator it = set1.begin(); it != set1.end(); it++){
		cout << *it << "  ";
	}
	cout << endl;
	//ɾ��
	while (set1.size() > 0){
		set<int>::iterator it = set1.begin();
		cout << "delete:" << *it << "  ";
		set1.erase(set1.begin());
	}
}



//���Һ���
void main04(void)
{
	//set.find(elem); // ���� elem Ԫ�أ�����ָ�� elem Ԫ�صĵ�������
	//set.count(elem); // ����������ֵΪ elem ��Ԫ�ظ������� set ��˵��Ҫô�� 0��Ҫ
												//ô�� 1���� multiset ��˵��ֵ���ܴ��� 1��
	//set.lower_bound(elem); // ���ص�һ�� >=elem Ԫ�صĵ�������
	//set.upper_bound(elem); // ���ص�һ�� >elem Ԫ�صĵ�������
	//set.equal_range(elem); // ������������ elem ��ȵ������޵���������������
												//���Ǳ����䣬�����ǿ����䣬��[beg, end)
}

class a
{
public:
	void printa()
	{
		cout << "aaa" << endl;
	}

	void printb()
	{
		cout << "bbb" << endl;
	}

	void printb() = delete;

};

int main(void)
{

	//�������Ͳ�������
	//main01();

	//�Զ����������͵ıȽϴ�С����
	//main02();

	//pair��ʹ�ò���
	//main03();

	//auto_ptr<int> p1(new int);
	//auto_ptr<int> p2(p1);

	//*p1 = 20;

	a a1;
	a1.printa();

	unique_ptr<int> p1(new int);

	system("pause");
	return 0;
}