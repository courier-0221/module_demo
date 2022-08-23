#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
题目：
	输出9*9口诀


*/

void main(void)
{
	int i, j;
	for (i = 1; i <= 9; i++){
		for (j = 1; j <= 9; j++){
			printf("%d x %d = %d\n", i, j, i*j);
		}
		printf("\n");
	}
	
	system("pause");
}