#include <stdio.h>
#include <assert.h>

void SelectionSort(int *array, int len)
{
	assert(array);
	int i = 0, j = 0;
	for (i = 0; i < len; i++)
	{
		for (j = i; j < len; j++)
		{
			if (array[i] > array[j])
			{
				int tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}
}


int main(void)
{
	printf("—°‘Ò≈≈–Ú\n");
	int array[] = { 9, 6, 3, 2, 7, 1, 8, 4, 5, 0 };
	int len = sizeof(array) / sizeof(*array);
	SelectionSort(array, len);

	for (int i = 0; i < len; i++)
	{
		printf("%d\t", array[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}