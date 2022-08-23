#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
题目：
	求和1+2+3+...N
要求不能使用乘除法、for、while、if、else、switch、case等关键字以及条件判断语句.
分析：
	一、首先，题目不允许使用while，那我们得想到循环的唯一方法递归
	二、不能使用if语句，那么可以巧用&&运算符。这个操作符会先执行左边的语句，如果为真，则执行右边的语句，
		否则则会跳到下一条语句
或者三目运算符
*/

int sum(int num)
{
	int total = 0;
	num && (total = sum(num - 1) + num);
	return total;
}
int sum2(int num)
{
	return (num ? (sum(num - 1) + num) : 0);
}


int main(void)
{
	printf("5的阶乘为：%d\n", sum(5));
	

	system("pause");
	return 0;
}