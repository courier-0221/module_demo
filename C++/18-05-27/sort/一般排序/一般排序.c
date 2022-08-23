#include <stdio.h>
#include <assert.h>
#include <string.h>


/*
��Ŀ��
	��N����С���ȵ���Ȼ����1--N�����뽫������С��������
Ҫ������㷨��
	ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)��
*/
void sortOnorder1(int *array, int len)
{
	assert(array);
	for (int i = 0; i < len;)
	{
		//�ж��±��ֵ���������Ӧ��ϵ
		if (i + 1 == array[i])			//���㣬i++��������һ��Ԫ��
		{
			i++;
		}
		else		//�����㣬���±�Ϊi�е�Ԫ�غ����Ԫ��ֵ��ȵ��±�ֵ�д洢��Ԫ�ػ���
		{
			int tmp = array[array[i] - 1];
			array[array[i] - 1] = array[i];
			array[i] = tmp;
		}
	}
}

int main01(void)
{
	int arr[] = { 10, 1, 3, 4, 2, 9, 6, 8, 5, 7 };
	sortOnorder1(arr, sizeof(arr) / sizeof(*arr));
	for (int i = 0; i < sizeof(arr) / sizeof(*arr); i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}


/*
ע��������һ����Ŀ��Ҫע������
��Ŀ��
	ĳ��˾�м�����Ա���������һ��ʱ�临�Ӷ�Ϊ O(n)���㷨�Ըù�˾Ա��������������
	��ʹ��O(1)�ĸ����ռ䡣
ע�⣺
	�����Ŀ��Ԫ�����ظ��ģ�
	��һ����Ŀ��Ԫ�ز����ظ�
˼·��
	������Ĳ��
*/

void SortAges(int *ages, int num)
{
	assert(ages);
	int timesofages[100] = {0};
	
	for (int i = 0; i < num; i++)
	{
		timesofages[ages[i]]++;
	}

	int index = 0;
	for (int i = 0; i < 100; i++)
	{
		while (timesofages[i]>0)
		{
			ages[index] = i;
			timesofages[i]--;
			index++;
		}
	}
}

int main(void)
{
	int ages[] = { 13, 43, 35, 7, 58, 6, 32, 9, 65, 22, 47, 45, 7, 47, 78, 5, 32, 68, 67, 54, 34, 43, 56, 45 };
	SortAges(ages, sizeof(ages) / 4);
	for (int i = 0; i<sizeof(ages) / 4; i++)
	{
		printf("%d\t", ages[i]);
	}
	printf("\n");


	system("pause");
	return 0;
}