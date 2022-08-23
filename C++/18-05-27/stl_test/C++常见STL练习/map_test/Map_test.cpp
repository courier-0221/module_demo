#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
using namespace std;

//nine

/*
	一个 map 是一个键值对序列，即 (key,value)对。它提供基于 key 的快速检索能力。
	map 中 key 值是唯一的,集合中的元素按一定的 顺序 排列。元素插入过程是按排序
		规则插入，所以不能指定插入位置。
*/


//实现map的创建，添加\删除元素和遍历操作
void main01(void)
{
	map<int, string> map1;		//map<T1,T2> mapTT;
	
	//插入的第一种方法
	pair<map<int, string>::iterator,bool> mypair1 = map1.insert(pair<int, string>(1, "student1"));
	if (mypair1.second == true){
		cout << "insert  true" << endl;
	}
	else{
		cout << "insert  false" << endl;
	}
	//插入的第二种方法
	pair<map<int, string>::iterator, bool> mypair2 = map1.insert(make_pair(4, "student4"));
	if (mypair2.second == true){
		cout << "insert  true" << endl;
	}
	else{
		cout << "insert  false" << endl;
	}
	//插入的第三种方法
	pair<map<int, string>::iterator, bool> mypair3 = map1.insert(map<int, string>::value_type(3, "student3"));
	if (mypair3.second == true){
		cout << "insert  true" << endl;
	}
	else{
		cout << "insert  false" << endl;
	}
	//插入的第四种方法
	map1[2] = "student2";		//若key已经存在，则修改


	//遍历
	for (map<int, string>::iterator it = map1.begin(); it != map1.end(); ++it){
		cout << it->first << "\t" <<it->second << endl;
	}

	//删除
	while (!map1.empty()){
		map<int, string>::iterator it = map1.begin();
		cout <<"delete" << it->first << "\t" << it->second << endl;
		map1.erase(it);
	}
}


//map查找
void main02()
{

}

int main(void)
{
	//实现map的创建，添加\删除元素和遍历操作测试
	main01();

	system("pause");
	return 0;
}