#include <stdio.h>


/*
��Ŀ��
	����a[N]�������1��N-1����������ĳ�����ظ�һ�Ρ�дһ���������ҳ����ظ�������.
	ʱ�临�Ӷȱ���Ϊo��N����
*/

int findtwicenum(int *array, int len)
{
	if (array == NULL)
	{
		exit(-1);
	}
	int timesofnum[64] = { 0 }, i = 0;
	for (i = 0; i < len; i++)
	{
		timesofnum[array[i] - 1]++;
	}

	for (i = 0; i < len; i++)
	{
		if (timesofnum[i] == 2)
		{
			return i + 1;
		}
	}
	
}

int method2(int *array, int len)
{
	int i = 0, sum1 = 0, sum2 = 0;
	for (i = 0; i < len; i++)
	{
		sum1 += i;
		sum2 += array[i];
	}

	return sum2 - sum1;
}

int main(void)
{

	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9 };
	int len = sizeof(array) / sizeof(*array);

	printf("�������ε������ǣ�%d\n", findtwicenum(array, len));

	printf("�������ε������ǣ�%d\n", method2(array, len));
	
	system("pause");
	return 0;
}
