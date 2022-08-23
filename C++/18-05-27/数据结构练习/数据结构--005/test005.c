#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
��Ŀ��
	����һ���������飬������������Ҳ�и�����
	������������һ�������������һ�������飬ÿ�������鶼��һ���͡�
	������������ĺ͵����ֵ��Ҫ��ʱ�临�Ӷ�ΪO(n)��
������
	һ�����������ȫ��Ϊ�������򷵻������ֵ����
	��������������Ҳ�и�����ʱ��
		��1���������ҵ��ӣ������ǰ����ֵС�ڻ��ߵ���0��������������ܺ���0
			����һ����������0�Ǻ�������ģ����Ӵ�λ�ü������µ���
		��2������������ܺʹ�����һ�μ�¼�ĵ����ܺͣ�����µ����ܺͼ���
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