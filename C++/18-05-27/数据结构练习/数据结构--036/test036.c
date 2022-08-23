#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


/*
题目：
	最大公约数问题		最小公倍数等于m*n/最大公约数
三种方法
	这篇文章有详细说明：https://blog.csdn.net/a1414345/article/details/51770430
	方法一：相减法 
		1.如果a>b  a = a - b;
		2.如果b>a    b = b - a;
		3.假如a = b ，则 a或b  是最大公约数
		4.如果a != b,则继续从1开始执行
		5.也就是说循环的判断条件为a != b  ，直到a = b时，循环结束。
	方法二：穷举法
		1.选出a，b中最小的一个数字放到c中
		2.分别用a，b对c求余数，即看是否能被c整除
		3.直到a，b同时都能被c整除
		4.如不能整除，c-- (c的值减一) 继续从2开始执行
		5.也就是说该循环的判断条件为 a，b能否同时被c整除，只要有一个数不能被c整除，循环继续执行
	方法三：辗转相除法
		1.将两整数求余 a%b = c
		2.如果c = 0;则b为最大公约数 
		3.如果c != 0,则 a = b；b = c；继续从1开始执行
		4.也就是说该循环的是否继续的判断条件就是c是否为0
*/

int method1(int x, int y)
{
	while (x != y){
		if (x > y)
			x = x - y;
		else
			y = y - x;
	}
	return x;
}

int method2(int x, int y)
{
	int c = (x > y) ? y : x;
	while (x%c != 0 || y%c != 0){
		c--;
	}
	return c;
}

int method3_nodigui(int x, int y)
{
	int one = 0, two = 0, tmp = 0;
	if (x > y){
		one = x;
		two = y;
	}
	else{
		one = y;
		two = x;
	}

	while (two != 0){
		tmp = one % two;
		one = two;
		two = tmp;
	}
	return one;
}

int method3_digui(int x, int y)
{
	return ((y) ? method3_digui(y, x%y) : x);
}


int main(void)
{
	printf("%d\n", method3_digui(24, 36));
	printf("%d\n", method1(24, 36));
	printf("%d\n", method2(24, 36));
	
	system("pause");
	return 0;
}