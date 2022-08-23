#include <stdio.h>
#include <assert.h>

/*
	打麻将场景，码好手里的牌，然后抓牌和自己的牌比较放在那里
*/

void InsertionSort_1(int *array, int len)
{
	assert(array);
	int i = 0, j = 0;
	for (i = 1; i < len; i++)
	{
		for (j = i; j > 0; j--)
		{
			if (array[j] < array[j - 1])
			{
				int tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
			}
		}
	}
}

void InsertionSort_2(int *array, int len)
{
	assert(array);
	int i = 0, j = 0;
	for (i = 1; i < len; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (array[i] < array[j])
			{
				int tmp = array[j];
				array[j] = array[i];
				array[i] = tmp;
			}
		}
	}
}


int main(void)
{
	printf("插入排序\n");
	int array[] = { 9, 6, 3, 2, 7, 1, 8, 4, 5, 0 };
	int len = sizeof(array) / sizeof(*array);

	InsertionSort_2(array, len);

	for (int i = 0; i < len; i++)
	{
		printf("%d\t", array[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}