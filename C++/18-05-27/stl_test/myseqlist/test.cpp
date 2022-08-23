#include <iostream>
using namespace std;

#include "seqlist.cpp"

struct student
{
	char name[12];
	int age;
	int sex;
};

int main(void)
{
	int i = 0;
	student	tmp,
		st1 = { "aaa", 21, 1 },
		st2 = { "bbb", 22, 0 },
		st3 = { "ccc", 23, 1 },
		st4 = { "ddd", 24, 0 },
		st5 = { "eee", 25, 1 };

	seqlist<student> list(10);
	list.insert(st1, 0);
	list.insert(st2, 0);
	list.insert(st3, 0);
	list.insert(st4, 0);
	list.insert(st5, 0);

	cout << "list length is: " << list.len() << endl;
	list.transf();
	//for (i = 0; i < list.len(); i++){
	//	list.get(i, tmp);
	//	cout << "student info: " << tmp.age << endl;
	//}

	list.del(2, tmp);
	cout << "delete student info: " << tmp.age << endl;


	system("pause");
	return 0;
}