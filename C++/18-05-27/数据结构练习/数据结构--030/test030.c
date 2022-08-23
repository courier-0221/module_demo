#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*
题目：
	编写一个函数求一个数组中的第二大数
*/


int search_second_max(int *array, int size)
{
	if (array == NULL){
		return NULL;
	}
	int max = 0, second_max = 0, i = 0;
	if (array[0] > array[1]){
		max = array[0];
		second_max = array[1];
	}
	else{
		max = array[1];
		second_max = array[0];
	}
	i = 2;
	for (; i < size; i++){
		if (array[i] > max){
			second_max = max;
			max = array[i];
		}
		else if (array[i] > second_max && array[i] < max){
			second_max = array[i];
		}
	}
	return second_max;
}


int main(void)
{
	
	int a[] = { 1, 65, 8, 4, 5, 65, 67, 9, 12, 35, 14, 67 };
	printf("------>%d\n", search_second_max(a, sizeof(a) / sizeof(int)));




	system("pause");
	return 0;
}