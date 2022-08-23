#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
题目：
	利用条件运算符的嵌套来完成此题：学习成绩>=90分的同学用A表示，60-89分之间的用B表示，60分以下的用C表示。
分析：
	程序分析：(a>b)?a:b这是条件运算符的基本例子。
*/

void main(void)
{
	int sum;
	
	scanf("%d", &sum);
	char t = (sum < 60) ? 'C' : ((sum>90) ? 'A' : 'B');

	printf("%c\n", t);

	system("pause");
}