#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define error(str) #str 

typedef struct MyStruct
{
	char* p;
	int length;	//´æ´¢¶Ñ¿Õ¼äÄÚ´æ´óÐ¡
}mystring;

/**********************************************
	×Ö·û´®µÄÏà¹Ø²Ù×÷
	1¡¢Ôö¼Ó
		Î²²¿Ôö¼Ó£¬£¨×Ö·û£¬×Ö·û´®£©
			backaddchar
			backaddstring
		ÈÎÒâÎ»ÖÃÔö¼Ó£¨×Ö·û£¬×Ö·û´®£©
			addchar
			addstring
	2¡¢²éÕÒ
		²éÕÒ×Ö·û£¬²éÕÒ×Ö·û´®
			findfirstchar		--->	strchr
			findfirststring		--->	strstr
	3¡¢É¾³ý
		É¾³ý£¨×Ö·û£¬×Ö·û´®£©
			deletefirstchar
			deletefirststring
	4¡¢ÐÞ¸Ä
		ÐÞ¸Ä£¨×Ö·û£¬×Ö·û´®Ìæ»»£©
			changefirstchar
			changefirststring
************************************************/
void *mystring_create(void);
void mystring_destroy(void *str);
void mystring_init(void *str, char *copystring);
void mystring_print(void *str);
void backaddchar(void *str, char ch);
void backaddstring(void *str, char *string);
char *findfirstchar(void *str, const char ch);
char *findfirststring(void *str, const char *string);
void deletefirstchar(void *str, const char ch);
char *delete_all_char(char *str, char ch);
void deletefirststring(void *str, const char *string);
void addchar(void *str, char ch, int pos);
void addstring(void *str, char *string, char *pos);
void changefirstchar(void *str, const char oldchar, const char newchar);
void changefirststring(void *str, char *const oldstring, char *const newstring);




/***************************************************
<string.h>¿âº¯ÊýµÄÒ»Ì×ÊµÏÖº¯Êý
1¡¢mystrlen
2¡¢mystrcpy
3¡¢mystrcat
4¡¢mystrchr
5¡¢mystrstr
****************************************************/
int  mystrlen(const char* str);
char *mystrcpy(char* dst, const char* src);
char *mystrcat(char* dst, const char* src);
char *mystrchr(const char* dst, const char ch);
char *mystrstr(const char* const dst, const char *string);
