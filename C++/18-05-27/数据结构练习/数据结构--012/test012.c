#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
题目：
	输入一个整数，求改整数的二进制表达式中有多少个1.
	例如输入10，由于其二进制表示为1010，有两个1，因此输出2.
*/

//void tentotwo(int num)
//{
//	if (num == 0){
//		return;
//	}
//	int zhengshu = num / 2, yushu = num % 2;
//	tentotwo(zhengshu);
//	printf("%d", yushu);
//}
int count_bit_1(int num)
{
	int count = 0;
	while (num){
		if (num & 1){
			count++;
		}
		num = num >> 1;
	}
	return count;
}

int main(void)
{
	printf("10的二进制数值中有 %d 个1\n", count_bit_1(10));

	system("pause");
	return 0;
}