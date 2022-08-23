#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
题目：
	一个数如果恰好等于它的因子之和，这个数就称为“完数”。例如6=1＋2＋3.编程找出1000以内的所有完数。
分析：
	数的因子 -- 因子就是所有可以整除这个数的数,不包括这个数自身. 
	比如15的因子是1，3，5 　　而因数为1,3,5,15。
*/

void find_wanshu(int num)
{
	if (num < 0){
		return;
	}
	int i = 0, j = 0, result = 0;

	for (i = 2; i <= num; i++){
		int end = i / 2 + 1;
		result = 0;
		for (j = 1; j < end; j++){
			if (i % j == 0){
				result += j;
			}
			if (result > i)
				break;
		}
		if (result == i){
			printf("%d\n", i);
		}
	}
}

int main(void)
{

	find_wanshu(1000);


	system("pause");
	return 0;
}



