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
	MyString(const MyString &other);	//copy���캯��
	~MyString();

	MyString& operator=(const MyString &other);	//�ȺŲ�����
	void print(void);
	
private:
	char *mydata;
};

