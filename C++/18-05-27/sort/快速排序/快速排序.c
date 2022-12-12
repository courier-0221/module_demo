#include <stdio.h>
#include <assert.h>

// gcc -g -O2 -fsanitize=address -fno-omit-frame-pointer xxx.c
// 开启asan检测是否有堆栈越界

int FristLocal(int *array, int low, int high)
{
	assert(array);
	int pv = array[low];
	int tmp = 0;
	while (low < high)
	{
		
		while ((low < high) && (array[high] >= pv))
		{
			high--;
		}
		tmp = array[low];
		array[low] = array[high];
		array[high] = tmp;

		while ((low < high) && (array[low] <= pv))
		{
			low++;
		}
		tmp = array[low];
		array[low] = array[high];
		array[high] = tmp;
	}
	return low;
}

void QuickSort(int *array, int low, int high)
{
	assert(array);
	if (low < high)
	{
        int local = FristLocal(array, low, high);
		QuickSort(array, low, local - 1);
		QuickSort(array, local + 1, high);
	}
}



int main(void)
{
	printf("��������\n");
	int array[] = { 5, 6, 3, 2, 1, 9, 8, 4, 7, 0 };
	int len = sizeof(array) / sizeof(*array);
	
	QuickSort(array, 0, len - 1);

	for (int i = 0; i < len; i++)
	{
		printf("%d\t", array[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}