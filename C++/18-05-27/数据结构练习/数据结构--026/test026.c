#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*
题目：
	有一个由大小写组成的字符串，现在需要对他进行修改，将其中的所有小写字母排在大写字母的前面
开辟足够少的空间，时间复杂度O（n）
分析：
	参考练习数据结构--023的解题过程
*/

int mystrlen(const char *str)
{
	return (assert(str), (*str ? (mystrlen(str + 1) + 1) : 0));
}


char *str_proc(char *str)
{
	if (str == NULL){
		return NULL;
	}
	char *begin = str, *end = str + mystrlen(str) - 1, *ret = str;
	while (begin < end){
		if ((*begin >= 'a') && (*begin <= 'z')){
			begin++;
			continue;
		}

		if ((*end >= 'A') && (*end <= 'Z')){
			end--;
			continue;
		}
		char tmp = *begin;
		*begin = *end;
		*end = tmp;
	}
	return ret;
}


int main(void)
{
	char buf[] = "aBcDeFgHiGkLmN";
	printf("%s\n", str_proc(buf));



	system("pause");
	return 0;
}