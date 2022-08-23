#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
using namespace std;

//nine

/*
	һ�� map ��һ����ֵ�����У��� (key,value)�ԡ����ṩ���� key �Ŀ��ټ���������
	map �� key ֵ��Ψһ��,�����е�Ԫ�ذ�һ���� ˳�� ���С�Ԫ�ز�������ǰ�����
		������룬���Բ���ָ������λ�á�
*/


//ʵ��map�Ĵ��������\ɾ��Ԫ�غͱ�������
void main01(void)
{
	map<int, string> map1;		//map<T1,T2> mapTT;
	
	//����ĵ�һ�ַ���
	pair<map<int, string>::iterator,bool> mypair1 = map1.insert(pair<int, string>(1, "student1"));
	if (mypair1.second == true){
		cout << "insert  true" << endl;
	}
	else{
		cout << "insert  false" << endl;
	}
	//����ĵڶ��ַ���
	pair<map<int, string>::iterator, bool> mypair2 = map1.insert(make_pair(4, "student4"));
	if (mypair2.second == true){
		cout << "insert  true" << endl;
	}
	else{
		cout << "insert  false" << endl;
	}
	//����ĵ����ַ���
	pair<map<int, string>::iterator, bool> mypair3 = map1.insert(map<int, string>::value_type(3, "student3"));
	if (mypair3.second == true){
		cout << "insert  true" << endl;
	}
	else{
		cout << "insert  false" << endl;
	}
	//����ĵ����ַ���
	map1[2] = "student2";		//��key�Ѿ����ڣ����޸�


	//����
	for (map<int, string>::iterator it = map1.begin(); it != map1.end(); ++it){
		cout << it->first << "\t" <<it->second << endl;
	}

	//ɾ��
	while (!map1.empty()){
		map<int, string>::iterator it = map1.begin();
		cout <<"delete" << it->first << "\t" << it->second << endl;
		map1.erase(it);
	}
}


//map����
void main02()
{

}

int main(void)
{
	//ʵ��map�Ĵ��������\ɾ��Ԫ�غͱ�����������
	main01();

	system("pause");
	return 0;
}