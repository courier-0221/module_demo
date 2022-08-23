#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


/*
题目：
	寻找数组中的最大值和最小值
	时间复杂度0(1)
*/


void get_array_max_and_min(int *array, int len, int *max, int *min)
{
	if (array == NULL){
		return;
	}
	if (len == 1)
		*max = *min = array[0];

	for (int i = 0; i < len; i++){
		if (array[i] > *max){
			*max = array[i];
		}
		if (array[i] < *min){
			*min = array[i];
		}
	}

}


int main(void)
{
	int array[] = {2, 5, 6, 9, 12, 38, 11, 9, 0, 7, 1, -2, 12};
	int max = 0, min = 0;
	get_array_max_and_min(array, sizeof(array) / sizeof(*array), &max, &min);
	printf("max = %d, min = %d\n", max, min);


	system("pause");
	return 0;
}