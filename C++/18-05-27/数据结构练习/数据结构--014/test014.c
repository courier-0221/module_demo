#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
题目：
	如何对n个数进行排序，要求时间复杂度O(n)，空间复杂度O(1)
*/

void flag_sort(int *array, int len)
{
	if (array == NULL){
		exit(-1);
	}
	int flag[1000] = { 0 }, j = 0;

	//标记
	for (int i = 0; i < len; i++){
		flag[array[i] - 1]++;
	}

	//将标记好的数组重新写入到传入的数组中
	for (int i = 0; i < 1000; i++){
		while (flag[i] > 0){
			array[j++] = i + 1;
			flag[i]--;
		}
	}
}

int main(void)
{
	int array[] = { 5, 4, 3, 2, 1, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int len = sizeof(array) / sizeof(*array);
	flag_sort(array, len);

	for (int i = 0; i < len; i++){
		printf("%d\t", array[i]);
	}

	system("pause");
	return 0;
}