#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
题目：
	输入一个整形数组，数组里有正数也有负数。
	数组中连续的一个或多个整数组成一个子数组，每个子数组都有一个和。
	求所有子数组的和的最大值。要求时间复杂度为O(n)。
分析：
	一、如果数组中全部为负数，则返回最大负数值即可
	二、当既有正数也有负数的时候：
		（1）从左往右叠加，如果当前叠加值小于或者等于0，则放弃，叠加总和清0
			（加一个负数或者0是毫无意义的），从此位置继续重新叠加
		（2）如果当叠加总和大于上一次记录的叠加总和，则更新叠加总和即可
*/

int return_sub_max(int *array, int size)
{
	int max_sum = array[0], temp = array[0];

	int i = 1;
	for (; i < size; i++){
		temp += array[i];
		if (temp > max_sum){
			max_sum = temp;
		}
		if (temp <= 0){
			temp = 0;
		}
	}
	return max_sum;
}


int main(void)
{
	int array[] = {-8, -2, -1, -3, -10, -4, -7, -2, -5};
	//int array[] = {1, 2, 3, -2, -3, 9};
	//int array[] = {1, -2, -3, 10, -4, 7, 2, -5};
	//int array[] = { 1, -9, 3, 10, 4, 7, 2, 5 };

	int i = 0;
	int size = sizeof(array) / sizeof(int);
	printf("max = %d\n", return_sub_max(array, size));



	system("pause");
	return 0;
}