#define  _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <iterator>
using namespace std;

//one

//初始化
int main01()
{
	string s1 = "hello world";
	string s2 = s1;			//通过拷贝构造函数来初始化			
	string s3("value");		//通过带参构造函数来初始化
	string s4(10, 'a');		//通过带参构造函数来初始化
	
	cout << s2 << endl << s3 << endl << s4 << endl;


	string s5;
	while (cin >> s5)  //这里可以输入“  hello world  ”测试，发现只读取有效字符到遇到空格结束
	{
		cout << s5 << endl;
	}
	return 0;
}

//string 的遍历
int main02()
{
	string s1 = "123456";
	int i = 0;
	//1、数组方式
	for (i = 0; i < s1.length(); i++){
		cout << s1[i] << " ";
	}

	printf("\n");

	//2、迭代器方式
	for (string::iterator it = s1.begin(); it != s1.end(); it++){
		cout << *it << " ";
	}

	cout << endl;

	//3、使用at方法
	for (i = 0; i < s1.length(); i++){
		cout << s1.at(i) << " ";		//可以抛异常
	}

	return 0;
}


//字符指针和string的转换
int main03(void)
{
	string s = "12345";
	printf("%s\n", s.c_str());		// 返回一个以 '\0' 结尾的字符串的首地址

	return 0;
}

//把 string 拷贝到 char* 指向的内存空间
int main04()
{
	string s = "123456";
	char buf[128] = {0};
	s.copy(buf, 4, 0);		//int copy(char *s, int n, int pos=0) const;
	cout << buf << endl;
	return 0;
}

//字符串连接
int main05()
{
	//方式1，使用类中重载过得+运算符
	string s1 = "123";
	string s2 = "456";

	s1 = s1 + s2;
	cout << s1 << endl;

	//方式2，使用append方法
	string s3 = "789";
	string s4 = "abc";

	s3.append(s4);
	cout << s3 << endl;

	return 0;
}

//字符串的查找和替换
int main06(void)
{
	string s = "wang shi ru yan ,wu chu ji dian";

	cout << s << endl;

	//案例1：查找出s中有多少个空格
	int local = s.find(' ', 0);
			//int find((char c)  (const char *s)  (const string &s),int pos=0) const;
	while (local != string::npos){
		cout << local << endl;
		local += 1;
		local = s.find(' ', local);
	}

	//案例2：找出s中所有的空格并替换成两个空格
	//string &replace(int pos, int n, const char *s);
	// 删除从 pos 开始的 n 个字符，然后在 pos 处插入串 s
	local = s.find(' ', 0);
	while (local != string::npos){
		s.replace(local, 1, "  ");
		local += 2;
		local = s.find(' ', local);
	}
	
	cout << s << endl;

	return 0;
}

//截断(区间删除)和插入
int main07()
{
	string s = "wang shi ru yan ,!!!";
	cout << s << endl;
	//插入
		//string &insert(int pos, const char *s);
	s.insert(s.length(), "wu chu ji dian");
	cout <<" after insert :  " << s << endl;

	//删除
		//string &erase(int pos=0, int n=npos);
	int index = s.find('!', 0);
	s.erase(index, 3);
	cout << " after erase :  " << s << endl;

	return 0;
}


int main(void)
{
	//初始化测试
	//main01();
	
	//遍历测试
	//main02();

	//字符指针和string的转换测试
	//main03();

	//把 string 拷贝到 char* 指向的内存空间测试
	//main04();

	//字符串连接测试
	//main05();

	//字符串的查找和替换测试
	//main06();

	//截断(区间删除)和插入测试
	main07();

	system("pause");
	return 0;
}