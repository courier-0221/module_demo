#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
题目：
	输入n，用最快的方法求Fibonacci数列的第n项
	Fibonacci数列
	1,1,2,3,5,8,13,21,34
分析：
	第三项的值等于前两项值的和
*/

int Fibonacci(int n)
{
	if ((n == 1) || (n == 2)){
		return 1;
	}
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}
int main(void)
{
	printf("第n项的Fibonacci数值为：%d\n", Fibonacci(9));

	system("pause");
	return 0;
}