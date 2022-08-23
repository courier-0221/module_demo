#include <stdio.h>
#include <assert.h>

void BubbleSort(int *array, int len)
{
	assert(array);
	int i = 0, j = 0;

	for (i = 0; i < len; i++)
	{
		for (j = len - 1; j > i; j--)
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


int main(void)
{
	printf("Ã°ÅÝÅÅÐò\n");
	int array[] = { 9, 6, 3, 2, 7, 1, 8, 4, 5, 0 };
	int len = sizeof(array) / sizeof(*array);
	BubbleSort(array, len);

	for (int i = 0; i < len; i++)
	{
		printf("%d\t", array[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}