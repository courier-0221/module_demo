#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
题目：
	输入一个表示整数的字符串，把该字符串转换成整数并输出。
	例如输入字符串"345"，则输出整数345。
*/


int str_to_num(const char *str)
{
	if (str == NULL){
		return - 1;
	}

	int result = 0;
	char *strbak = str;
	while (*strbak != 0){
		if (*strbak >= '0' && *strbak <= '9'){
			result *= 10;
			result += (*strbak - 48);
		}
		strbak++;
	}

	return result;
}

int main(void)
{

	printf("%d\n", str_to_num("123"));

	system("pause");
	return 0;
}