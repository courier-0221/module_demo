#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
/*
题目：
	写一个函数,它的原形是int continumax(char *outputstr,char *intputstr)

功能：
	在字符串中找出连续最长的数字串，并把这个串的长度返回，
	并把这个最长数字串付给其中一个函数参数outputstr所指内存。
例如："abcd12345ed125ss123456789"的首地址传给intputstr后，函数将返回9，
outputstr所指的值为123456789
*/

/*
思路是
	定义两个指针，一个指向数字开始的位置，另一个指向数字结束的位置，然后判断长度是否是最长，是的话进行copy
*/


int continumax(char *outputstr, char *intputstr)
{
	if ((outputstr == NULL) || (intputstr == NULL)){
		return -1;
	}

	char *first = intputstr, *second = first;
	int max = 0, tmp = 0;
	while (*first != 0){
		tmp = 0;
		second = first;
		while ((*second <= '9') && (*second >= '0')){
			tmp++;
			second++;
		}
		if (max < tmp){
			max = tmp;
			strncpy(outputstr, first, tmp);
		}	
		first = second;
		first++;
	}
	return max;
}




int main(void)
{
	//char *intputstr = "abcd12345ed125ss123456789";
	char *intputstr = "abcd12345879889ed125ss123456789";
	char outputstr[64] = { 0 };
	int len = continumax(outputstr, intputstr);

	printf("max len is:%d\nstr is :%s\n", len, outputstr);

	system("pause");
	return 0;
}