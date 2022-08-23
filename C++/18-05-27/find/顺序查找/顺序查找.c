#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void find(int* array, int len, int key)
{
	if (!array)
	{
		exit(-1);
	}
	for (int i = 0; i < len; i++)
	{
		if (key == array[i])
		{
			printf("find\n");
			return;
		}
	}
	printf("no find\n");
	return;
}


int main(void)
{
	int key = 23;
	int array[10] = { 0 };
	srand((unsigned int)time(NULL));
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
	{
		array[i] = rand() % 100;
		printf("%d\t", array[i]);
	}
	find(array, 10, key);




	system("pause");
	return 0;
}