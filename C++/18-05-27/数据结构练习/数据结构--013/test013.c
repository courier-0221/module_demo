#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
题目：
	输入整数n，计算从1到n这个n个整数的十进制表示中1出现的次数和
*/

//计算整数@m中包含数字@digit的个数
int count_digit_num(int m, int digit)
{
	int count = 0;
	while (m){
		if (m % 10 == digit){
			count++;
		}
		m = m / 10;
	}
	return count;
}


int count_digit_one(int n)
{
	int count = 0;
	for (int i = 0; i <= n; i++){
		count += count_digit_num(i, 1);
	}
	return count;
}


int main(void)
{
	printf("从1到n一共有 %d 个1\n", count_digit_one(20));

	system("pause");
	return 0;
}