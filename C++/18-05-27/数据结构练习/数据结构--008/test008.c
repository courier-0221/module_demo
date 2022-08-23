#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
题目：
	定义字符串的左旋转操作：把字符串前面的若干个字符移动到字符串的尾部，如把字符串abcdef
	左旋转2位得到字符串cdefab。
请实现字符串左旋转的函数，要求对长度为n的字符串操作的时间复杂度为O(n)，空间复杂度为O(1)。
*/

int mystrlen(const char *str)
{
	return (assert(str), (*str ? (mystrlen(str + 1) + 1) : 0));
}


char *left_one_step(char *str,int len)
{
	if (str == NULL){
		return NULL;
	}
	int i = 0;
	char first = str[0];
	for(i = 0; i < len; i++){
		str[i] = str[i + 1];
	}
	str[--i] = first;

	return str;
}

char *left_n_step(char *str, int len ,int num)
{
	while (num--){
		str = left_one_step(str, len);
		
	}
	return str;
}

int main(void)
{
	char buf[] = "1234567";
	int len = mystrlen(buf);
	printf("左移位之后的效果：%s\n", left_n_step(buf, len, 3));

	system("pause");
	return 0;
}