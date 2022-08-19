#include "animal.pb.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
 
using namespace std;
using namespace TEXT;
 
int main()
{
	ZOO hzzoo;
	ZOO_animal* ani;
	hzzoo.set_zooname("hangzhouZoo");
	hzzoo.set_addr("xihu");
	hzzoo.set_age(10);
	
	ani = hzzoo.add_animals();
	ani->set_animaltype("daxiang");
	ani->set_count(5);
	
	ani = hzzoo.add_animals();
	ani->set_animaltype("xiongmao");
	ani->set_count(3);
	
	ani = hzzoo.add_animals();
	ani->set_animaltype("bailingniao");
	ani->set_count(50);
	
	ani = hzzoo.add_animals();
	ani->set_animaltype("mangshe");
	ani->set_count(13);
 
	int size = hzzoo.animals_size();
 
	cout << "size : " << size << endl;
	for(int i = 0; i<size; i++)
	{
		ZOO_animal a = hzzoo.animals(i);
		cout <<"animalType :"<<a.animaltype() << ", count: "<<a.count()<<endl;
	}
	
	//序列化
	string buf;
	hzzoo.SerializeToString(&buf);
	cout << "serializebuf: " << buf << endl;
	
	//解析
	ZOO hzzooparse;
	hzzooparse.ParseFromString(buf);
	cout << "zooname: " << hzzooparse.zooname() << " addr: " << hzzooparse.addr() << " age: " << hzzooparse.age() << endl;
	
	size = hzzooparse.animals_size();
 
	cout << "size : " << size << endl;
	for(int i = 0; i<size; i++)
	{
		ZOO_animal a = hzzooparse.animals(i);
		cout <<"animalType :"<<a.animaltype() << ", count: "<<a.count()<<endl;
	}
	
	return 0;
}