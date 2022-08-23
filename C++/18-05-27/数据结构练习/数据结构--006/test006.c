#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
题目：
	在一个字符串中找到第一个只出现一次的字符。如输入abaccdeff，则输出b。
思路：
	先顺序遍历字符串，再把每次遍历的得到的字符，在整个字符串中查找
*/
int mystrlen(const char *str)
{
	return (assert(str), (*str ? (mystrlen(str + 1) + 1) : 0));
}

//在@str中查找@c,会过滤掉@num所在的字符
char *mystrchr(const char *str, char ch,int num)
{
	if (str == NULL){
		return NULL;
	}
	char *strbak = str;
	int i = 0, len = mystrlen(str);
	for (i = 0; i < len;i++){
		if (i == num){
			strbak++;
			continue;
		}
		if (*strbak == ch){
			return strbak;
		}
		strbak++;
	}
	
	return NULL;
}

char find_once_char_in_str(const char *str)
{
	if (str == NULL){
		exit(-1);
	}
	int i = 0, len = mystrlen(str);
	char *strbak = str;
	for (i = 0; i < len;){
		if (mystrchr(strbak, strbak[i], i) != NULL){
			i++;
		}
		else{
			return str[i];
		}
	}
	return 0;
}


int main(void)
{
	
	char *str = "aabadccdebff7e";
	printf("---> %c\n", find_once_char_in_str(str));

	system("pause");
	return 0;
}