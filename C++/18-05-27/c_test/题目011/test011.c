#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

/*
题目：
	判断101-200之间有多少个素数，并输出所有素数。
思路：
	素数只能被自己整除的数
	判断素数的方法：用一个数分别去除2到sqrt(这个数)，如果能被整除，
	则表明此数不是素数，反之是素数。
*/



void main(void)
{
	int i,j,k=0;
	for (i = 101; i <= 200; i++){
		int flag = 1;
		for (j = 2; j <= sqrt(i); j++){
			if (i%j == 0){	//如果有一个数能整出就不是素数，没必要向下判断了
				flag = 0;
				break;
			}
		}
		if (flag == 1){
			k++;
			printf("%d\t", i);
			if (k % 5 == 0){
				printf("\n");
			}
		}
		
	}


	system("pause");
}