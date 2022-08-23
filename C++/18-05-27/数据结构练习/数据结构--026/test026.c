#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*
��Ŀ��
	��һ���ɴ�Сд��ɵ��ַ�����������Ҫ���������޸ģ������е�����Сд��ĸ���ڴ�д��ĸ��ǰ��
�����㹻�ٵĿռ䣬ʱ�临�Ӷ�O��n��
������
	�ο���ϰ���ݽṹ--023�Ľ������
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