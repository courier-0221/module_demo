#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
/*
题目：
	求一个数组的最长递减子序列 比如{9，4，3，2，5，4，3，2}的最长递减子序列为{9，5，4，3，2}

思路：
	同上一个题的解法类似
*/

void *mymemcpy(void *dest, const void *src, int count)
{
	char *tmp = (char *)dest;
	const char *s = (char *)src;
	while (count--){
		*tmp++ = *s++;
	}
	return dest;
}

int count_max_decrease_array(int *array, int size, int *output_array)
{
	if ((array == NULL) || (output_array == NULL)){
		return -1;
	}

	int *first = array, *second = first, max = 1, tmp = 1;
	for (int i = 0; i < size; i++){
		
		if (array[i] > array[i + 1]){
			tmp++;
			second++;
			continue;
		}

		if (max < tmp){
			max = tmp;
			mymemcpy(output_array, first, tmp * 4);
			tmp = 1;
		}
		
		second++;
		first = second;
	}

	return max;
}




int main(void)
{
	int array[] = { 9, 4, 3, 2, 100, 99, 88, 77, 66, 6, 5, 4, 8, 3, 2 };
//	int array[] = { 1, 2, 3, 4, 5, };
	int out[128] = { 0 };
	int size = sizeof(array) / sizeof(*array);

	int len = count_max_decrease_array(array, size, out);

	printf("max len is:%d\n", len);
	for (int i = 0; i < len; i++){
		printf("%d\t", out[i]);
	}

	system("pause");
	return 0;
}