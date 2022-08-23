#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


/*
题目：
	字符串移位包含的问题, s1是否可以由s2移位后得到
*/

int mystrlen(const char *str)
{
	return (assert(str), (*str ? (mystrlen(str + 1) + 1) : 0));
}

int mystrcmp(const char *s1, const char *s2)
{
	if (mystrlen(s1) != mystrlen(s2)){
		return -1;
	}
	int ret = 0;
	while (*s1 != 0){
		ret += (*s1 - *s2);
		s1++;
		s2++;
	}
	return ret;
}

int is_rotate_str(char *des, char *src)
{
	if ((des == NULL) && (src == NULL)){
		exit(-1);
	}
	int len = mystrlen(des), i = 0,j = 0;

	for (j = 0; j < len; j++){
		char first = des[0];
		for (i = 0; i < len; i++){
			des[i] = des[i + 1];
		}
		des[len - 1] = first;
		if (mystrcmp(des, src) == 0){
			return 1;
		}
		//printf("%s\n", des);
	}
	
	return 0;
}


int main(void)
{
	char buf1[] = "asdfghj", buf2[] = "dfghjas";
	printf("%d\n", is_rotate_str(buf1, buf2));

	system("pause");
	return 0;
}