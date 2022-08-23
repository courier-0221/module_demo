#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


/*
题目：
	实现字符串反转
*/

int mystrlen(const char *str)
{
	return (assert(str), (*str) ? (mystrlen(str + 1) + 1) : 0);
}

void str_over(char *str)
{
	if (str == NULL){
		exit(-1);
	}
	char *strbak = str;
	int len = mystrlen(str);
	int begin = 0, end = len - 1;

	while (end > begin){
		char tmp = *(str + begin);
		*(str + begin) = *(str + end);
		*(str + end) = tmp;
		end--;
		begin++;
	}

}



int main(void)
{
	char str[] = "12345678";
	str_over(str);

	printf("%s\n", str);

	system("pause");
	return 0;
}
