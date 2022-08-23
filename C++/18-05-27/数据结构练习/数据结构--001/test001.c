#include <stdio.h>


/*
题目：
	数组a[N]，存放了1至N-1个数，其中某个数重复一次。写一个函数，找出被重复的数字.
	时间复杂度必须为o（N）。
*/

int findtwicenum(int *array, int len)
{
	if (array == NULL)
	{
		exit(-1);
	}
	int timesofnum[64] = { 0 }, i = 0;
	for (i = 0; i < len; i++)
	{
		timesofnum[array[i] - 1]++;
	}

	for (i = 0; i < len; i++)
	{
		if (timesofnum[i] == 2)
		{
			return i + 1;
		}
	}
	
}

int method2(int *array, int len)
{
	int i = 0, sum1 = 0, sum2 = 0;
	for (i = 0; i < len; i++)
	{
		sum1 += i;
		sum2 += array[i];
	}

	return sum2 - sum1;
}

int main(void)
{

	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9 };
	int len = sizeof(array) / sizeof(*array);

	printf("出现两次的数字是：%d\n", findtwicenum(array, len));

	printf("出现两次的数字是：%d\n", method2(array, len));
	
	system("pause");
	return 0;
}
