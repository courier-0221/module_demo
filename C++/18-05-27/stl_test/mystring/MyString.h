#pragma once
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
class MyString
{
public:
	MyString(const char *str = NULL);
	MyString(const MyString &other);	//copy构造函数
	~MyString();

	MyString& operator=(const MyString &other);	//等号操作符
	void print(void);
	
private:
	char *mydata;
};

