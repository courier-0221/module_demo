#include <stdio.h>
#include <math.h>

/*
题目：
	一个整数，它加上 100 后是一个完全平方数，再加上 168 又是一个完全平方数，请问该数是多少? 
*/

void main(void)
{ 
	int i,x,y;
	for (i = 0; i < 100000; i++){
		x = sqrt(i+100);
		y = sqrt(i+268);
		if ((x*x == i + 100) && (y*y == i + 268)){
			printf("%d\n", i);
			break;
		}
	}
	system("pause");
}