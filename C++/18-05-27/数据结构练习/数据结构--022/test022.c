#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
/*
��Ŀ��
	��һ���������ݼ������� ����{9��4��3��2��5��4��3��2}����ݼ�������Ϊ{9��5��4��3��2}

˼·��
	ͬ��һ����Ľⷨ����
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