#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define size 10

void find(int* array, int len, int key)
{
	if (!array)
	{
		exit(-1);
	}
	int i = len - 1;
	array[0] = key;
	while (array[i] != key)
	{
		i--;
	}
	if (i == 0)
	{
		printf("no find\n");
	}
	else
	{
		printf("find %d\n", i);
	}

	return;
}


int main(void)
{
	int key = 23;
	int array[size + 1] = { 0 };
	srand((unsigned int)time(NULL));
	for (int i = 1; i < sizeof(array) / sizeof(array[0]); i++)
	{
		array[i] = rand() % 100;
		printf("%d\t", array[i]);
	}
	array[10] = 23;
	find(array, 11, key);




	system("pause");
	return 0;
}

