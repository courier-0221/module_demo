#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
/*
题目：
	输入一个整数数组，实现一个函数调整数组的元素顺序，使得奇数位于偶数的前半部分，偶数位于数组的后半部分。
	时间复杂度O（n）
思路：
	头部和尾部的奇数和偶数互换值

*/


void sort_array(int *array, int size)
{
	if (array == NULL){
		return;
	}
	int *begin = array, *end = &array[size - 1];
	while (begin < end){
		if (*begin % 2 != 0){		//找到偶数
			begin++;
			continue;
		}

		if (*end % 2 == 0){			//找到奇数
			end--;
			continue;
		}
		int tmp = *begin;
		*begin = *end;
		*end = tmp;
	}

}



int main(void)
{
	int array[] = { 38, 1, 2, 4, 6, 7, 9, 11, 12, 38 };
	//int array[]={9, 4, 3, 2,100, 99, 88, 77, 66, 6, 5, 4, 8, 3, 2};
	int size = sizeof(array) / sizeof(int);

	sort_array(array, size);

	for (int i = 0; i <size; i++)
		printf(" %d\t", array[i]);
	printf("\n");

	system("pause");
	return 0;
}