#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*
题目：
	已知一个字符串,比如asderwsde,寻找其中的一个子字符串比如sde 的个数,如果没有返回0,有的话返回子字符串的个数
*/

char *mystrstr(const char *str, const char *sub_str)
{
	if ((str == NULL) || (sub_str == NULL)){
		return NULL;
	}

	while (*str != 0){
		
		char *str_bak = str, *sub_str_bak = sub_str;
		int find = 1;
		char *ret = str_bak;
		while (*sub_str_bak != 0){
			if (*str_bak++ == *sub_str_bak++){
//				str_bak++;
//				sub_str_bak++;
			}
			else{
				find = 0;
				break;
			}
		}
		if (find == 1){
			return ret;
		}
		str++;
	}
	return NULL;
}

int mystrlen(const char *str)
{
	return (assert(str), (*str ? (mystrlen(str + 1) + 1) : 0));
}


int sub_str_count(const char *str, const char *sub_str)
{
	if ((str == NULL) || (sub_str == NULL)){
		return -1;
	}

	char *tmp = mystrstr(str, sub_str), *now = tmp;
	int count = 0, sublen = mystrlen(sub_str);
	if (tmp != NULL){
		while (tmp != NULL){
			now = tmp + sublen;
			tmp = mystrstr(now, sub_str);	
			count++;
		}
	}

	return count;
}



int main(void)
{
	
	//printf("%d\n", sub_str_count("asderwsde", "sde"));
	printf("%d\n", sub_str_count("asderwsdeghjgfsdefhgsdesde", "sde"));


	system("pause");
	return 0;
}