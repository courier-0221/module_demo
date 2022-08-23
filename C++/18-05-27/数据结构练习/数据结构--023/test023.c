#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
/*
��Ŀ��
	����һ���������飬ʵ��һ���������������Ԫ��˳��ʹ������λ��ż����ǰ�벿�֣�ż��λ������ĺ�벿�֡�
	ʱ�临�Ӷ�O��n��
˼·��
	ͷ����β����������ż������ֵ

*/


void sort_array(int *array, int size)
{
	if (array == NULL){
		return;
	}
	int *begin = array, *end = &array[size - 1];
	while (begin < end){
		if (*begin % 2 != 0){		//�ҵ�ż��
			begin++;
			continue;
		}

		if (*end % 2 == 0){			//�ҵ�����
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