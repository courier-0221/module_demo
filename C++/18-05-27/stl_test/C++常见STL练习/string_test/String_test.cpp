#define  _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iterator>
using namespace std;

//one

//��ʼ��
int main01()
{
	string s1 = "hello world";
	string s2 = s1;			//ͨ���������캯������ʼ��			
	string s3("value");		//ͨ�����ι��캯������ʼ��
	string s4(10, 'a');		//ͨ�����ι��캯������ʼ��
	
	cout << s2 << endl << s3 << endl << s4 << endl;


	string s5;
	while (cin >> s5)  //����������롰  hello world  �����ԣ�����ֻ��ȡ��Ч�ַ��������ո����
	{
		cout << s5 << endl;
	}
	return 0;
}

//string �ı���
int main02()
{
	string s1 = "123456";
	int i = 0;
	//1�����鷽ʽ
	for (i = 0; i < s1.length(); i++){
		cout << s1[i] << " ";
	}

	printf("\n");

	//2����������ʽ
	for (string::iterator it = s1.begin(); it != s1.end(); it++){
		cout << *it << " ";
	}

	cout << endl;

	//3��ʹ��at����
	for (i = 0; i < s1.length(); i++){
		cout << s1.at(i) << " ";		//�������쳣
	}

	return 0;
}


//�ַ�ָ���string��ת��
int main03(void)
{
	string s = "12345";
	printf("%s\n", s.c_str());		// ����һ���� '\0' ��β���ַ������׵�ַ

	return 0;
}

//�� string ������ char* ָ����ڴ�ռ�
int main04()
{
	string s = "123456";
	char buf[128] = {0};
	s.copy(buf, 4, 0);		//int copy(char *s, int n, int pos=0) const;
	cout << buf << endl;
	return 0;
}

//�ַ�������
int main05()
{
	//��ʽ1��ʹ���������ع���+�����
	string s1 = "123";
	string s2 = "456";

	s1 = s1 + s2;
	cout << s1 << endl;

	//��ʽ2��ʹ��append����
	string s3 = "789";
	string s4 = "abc";

	s3.append(s4);
	cout << s3 << endl;

	return 0;
}

//�ַ����Ĳ��Һ��滻
int main06(void)
{
	string s = "wang shi ru yan ,wu chu ji dian";

	cout << s << endl;

	//����1�����ҳ�s���ж��ٸ��ո�
	int local = s.find(' ', 0);
			//int find((char c)  (const char *s)  (const string &s),int pos=0) const;
	while (local != string::npos){
		cout << local << endl;
		local += 1;
		local = s.find(' ', local);
	}

	//����2���ҳ�s�����еĿո��滻�������ո�
	//string &replace(int pos, int n, const char *s);
	// ɾ���� pos ��ʼ�� n ���ַ���Ȼ���� pos �����봮 s
	local = s.find(' ', 0);
	while (local != string::npos){
		s.replace(local, 1, "  ");
		local += 2;
		local = s.find(' ', local);
	}
	
	cout << s << endl;

	return 0;
}

//�ض�(����ɾ��)�Ͳ���
int main07()
{
	string s = "wang shi ru yan ,!!!";
	cout << s << endl;
	//����
		//string &insert(int pos, const char *s);
	s.insert(s.length(), "wu chu ji dian");
	cout <<" after insert :  " << s << endl;

	//ɾ��
		//string &erase(int pos=0, int n=npos);
	int index = s.find('!', 0);
	s.erase(index, 3);
	cout << " after erase :  " << s << endl;

	return 0;
}


int main(void)
{
	//��ʼ������
	//main01();
	
	//��������
	//main02();

	//�ַ�ָ���string��ת������
	//main03();

	//�� string ������ char* ָ����ڴ�ռ����
	//main04();

	//�ַ������Ӳ���
	//main05();

	//�ַ����Ĳ��Һ��滻����
	//main06();

	//�ض�(����ɾ��)�Ͳ������
	main07();

	system("pause");
	return 0;
}