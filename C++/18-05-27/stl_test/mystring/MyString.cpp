#include "MyString.h"


MyString::MyString(const char *str)
{
	if (str == NULL){
		mydata = new char[1];
		if (mydata == NULL){
			printf("new error\n");
			exit(-1);
		}
		*mydata = 0;
	}
	else{
		int len = strlen(str);
		mydata = new char[len + 1];
		if (mydata == NULL){
			printf("new error\n");
			exit(-1);
		}
		strcpy(mydata, str);
	}
}

MyString::MyString(const MyString &other)
{
	int len = strlen(other.mydata);
	mydata = new char[len + 1];
	strcpy(mydata, other.mydata);
}

MyString& MyString::operator=(const MyString &other)
{
	if (this == &other){
		return *this;
	}
	delete[] mydata;
	int len = strlen(other.mydata);
	mydata = new char[len + 1];
	strcpy(mydata, other.mydata);

	return *this;
}

MyString::~MyString()
{
	delete [] mydata;
}


void MyString::print(void)
{
	cout << this->mydata << endl;
}