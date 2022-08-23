#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


/*
题目：
	输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
	句子中单词以空格符隔开。为简单起见，标点符号和普通字母一样处理。
	例如输入“I am a student.”，则输出“student. a am I”。
思路：
	翻转2次字符串，（1）先翻转整个字符串 （2）在翻转句子中的单词
*/

int mystrlen(const char *str)
{
	return (assert(str), (*str) ? (mystrlen(str + 1) + 1) : 0);
}

char *over(char *str, int begin, int end)
{
	if (str == NULL){
		return NULL;
	}
	if (begin > end){
		return str;
	}

	while (end >= begin){
		char tmp = *(str + begin);
		*(str + begin) = *(str + end);
		*(str + end) = tmp;
		end--;
		begin++;
	}
	return str;
}

char *revstr(char *str)
{
	if (str == NULL){
		return NULL;
	}
	int len = mystrlen(str);
	int begin = 0, end = len - 1,i = 0;

	//1、先翻转整个字符串
	over(str, begin, end);


	//2、反转句中的单词
	int count = 0;
	begin = 0, end = 0;
	for (i = 0; i < len; i++){
		count++;
		if ((str[i] == ' ') || (str[i + 1] == 0)){
			begin = i - count + 1;
			end = i - 1;
			count = 0;
			over(str, begin, end);
		}	
	}


	return str;
}



int main(void)
{
	char str[] = "I am a student.";
	revstr(str);

	printf("%s\n", str);
	//printf("%d\n", mystrlen(str));

	system("pause");
	return 0;
}
