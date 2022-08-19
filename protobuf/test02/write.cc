#include "family.pb.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
 
using namespace std;
 
int main()
{
	Family  family;
	Person* person;

	person = family.add_person();
	person->set_age(25);
	person->set_name("John");

	person = family.add_person();
	person->set_age(40);
	person->set_name("Tony");

	int size = family.person_size();

	printf("size : %d \r\n", size);
	for(int i = 0; i<size; i++)
	{
		Person psn=family.person(i);
		cout <<"Name :"<<psn.name()<<", age: "<<psn.age()<<endl;
	}
	
	google::protobuf::ShutdownProtobufLibrary();

	return 0;
}