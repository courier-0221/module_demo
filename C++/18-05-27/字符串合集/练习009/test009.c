#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>


/*
题目：
	给定字符串A和B,输出A和B中的最大公共子串。
	比如A="aocdfe" B="pmcdfa" 则输出"cdf"
返回值：
	成功：返回1
	失败：返回0
思路：
	输入字串一：aocdfe  字串二：pmcdfa
	下面为寻找的方法

		第一轮： aocdfe aocdf aocd aoc ao a        
		第二轮： ocdfe ocdf ocd oc o
		第三轮： cdfe cdf cd c
		第四轮： dfe df d
		第五轮： fe f
		第六轮： e
*/

char *mystrcpy(char *dest, const char *src)
{
	assert(dest); assert(src);
	char *destbak = dest;

	while (*dest++ = *src++);
	return destbak;
}

char *mystrncpy(char *dest, const char *src, int size)
{
	assert(dest); assert(src);
	char *destbak = dest,i = 0;

	for (i = 0; i < size; i++){
		*dest = *src;
		dest++;
		src++;
	}
	dest[i] = 0;
	
	return destbak;
}

int mystrlen(const char *str)
{
	return (assert(str), *str ? mystrlen(str + 1) + 1 : 0);
}

char *mystrstr(const char *src, const char *string)
{
	assert(src); assert(string);
	int len1 = mystrlen(src),
		len2 = mystrlen(string),
		i = 0;

	if (len2 > len1){
		return NULL;
	}
	char *srcbak = src;

	while (*srcbak != 0){
		char *nowsrc = srcbak;
		char *stringbak = string;
		int found = 1;
		while (*nowsrc != 0 && *stringbak != 0){
			if (*nowsrc != *stringbak){
				found = 0;
			}
			nowsrc++;
			stringbak++;
		}
		if (found == 1){
			return srcbak;
		}

		srcbak++;
	}
	return NULL;
}

int commanstring(const char *str1, const char *str2, char * const substr)
{
	assert(str1); assert(str2); assert(substr);
	char *longstr = NULL,
		*shortstr = NULL,
		i = 0,j = 0;
	int len1 = mystrlen(str1),
		len2 = mystrlen(str2);


	//找出两个字符串之间的长短关系，为了减少操作
	if (len1 > len2){
		longstr = str1;
		shortstr = str2;
	}
	else{	//小于等于的情况使用这个
		longstr = str2;
		shortstr = str1;
	}


	//如果包含最短子串，那么返回shortstr
	if (mystrstr(longstr, shortstr) != NULL){
		mystrcpy(substr, shortstr);
		return 1;
	}

	//否则，开始循环计算出短串中可能被长串包含的子串
	for (i = mystrlen(shortstr) - 1; i > 0; i--){
		for (j = 0; j < mystrlen(shortstr) - i; j++){
			mystrncpy(substr, shortstr + j, i);
			substr[i] = 0;

			if (mystrstr(longstr, substr) != NULL){
				return 1;
			}
		}
	}
	return 0;
}

int main(void)
{
	char substr[128];

	if (commanstring("546123456", "fgh123dfg", substr) == 0){
		printf("没有公共子串\n");
	}
	else{
		printf("公共子串:%s\n", substr);

	}

	system("pause");
	return 0;
}