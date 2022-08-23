#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
��Ŀ��
	��ζ�n������������Ҫ��ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
*/

void flag_sort(int *array, int len)
{
	if (array == NULL){
		exit(-1);
	}
	int flag[1000] = { 0 }, j = 0;

	//���
	for (int i = 0; i < len; i++){
		flag[array[i] - 1]++;
	}

	//����Ǻõ���������д�뵽�����������
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