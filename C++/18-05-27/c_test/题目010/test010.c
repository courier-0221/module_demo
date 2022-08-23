#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
题目：
	古典问题：有一对兔子，从出生后第3个月起每个月都生一对兔子，小兔子长到第三个月
	后每个月又生一对兔子，假如兔子都不死，问每个月的兔子总数为多少?
思路：
	兔子的规律为数列1,1,2,3,5,8,13,21….
	所有新出生的兔子第三个月又可以生兔子，之前的兔子第三个月还可以生
*/

int feibonaqi(int month)
{
	
	if ((month == 1) || (month == 2)){
		return 1;
	}
	else{
		return feibonaqi(month - 1) + feibonaqi(month - 2);
	}
	
}

void main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d个月后兔子数量为%d\n", n, feibonaqi(n));

	//非递归版
	int i, f1 = 1, f2 = 1;
	for (i = 1; i <= 20; i++)
	{
		printf("% 12ld % 12ld", f1, f2);
		if (i % 2 == 0) 
			printf("\n");/*控制输出，每行四个*/
		f1 = f1 + f2; /*前两个月加起来赋值给第三个月*/
		f2 = f1 + f2; /*前两个月加起来赋值给第三个月*/
	}


	system("pause");
}