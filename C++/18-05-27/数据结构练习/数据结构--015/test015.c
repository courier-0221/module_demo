#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
题目：
	输入一个正数n，输出所有和为n连续正数序列
	例如输入15，由于1+2+3+4+5=4+5+6=7+8=15，所以输出3个连续序列1-5、4-6和7-8。
*/

void print(int sum)
{
	int total = 0, begin = 0, end = 0 ;
	for (int i = 1; i <= (sum + 1) / 2; i++){
		total = 0;
		begin = end = i;
		while (total <= sum){
			total += end++;
			if (total == sum){
				printf(" [%d--%d]", begin, end - 1);
			}
		}
	}
	printf("\n");
}


int main(void)
{
	print(15);

	system("pause");
	return 0;
}