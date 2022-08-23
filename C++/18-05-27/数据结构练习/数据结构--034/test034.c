#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>

/*
题目：
	找出两个数之间的素数的个数,并打印
*/


int count_prime_number(int begin, int end)
{
	int flag = 1, i = 0, j = 0, ret = 0;
	for (i = begin; i <= end; i++){
		flag = 1;
		int back = sqrt(i);
		for (j = 2; j <= back; j++){
			if (i%j == 0){
				flag = 0;
				break;
			}
		}
		if (flag == 1){
			printf("%d\t", i);
			ret++;
		}
	}
	return ret;
}


int main(void)
{
	count_prime_number(15,25);

	system("pause");
	return 0;
}