#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
��Ŀ��
	����һ������n��������к�Ϊn������������
	��������15������1+2+3+4+5=4+5+6=7+8=15���������3����������1-5��4-6��7-8��
*/

void print(int sum)
{
	int total = 0, begin = 0, end = 0 ;
	for (int i = 1; i <= (sum + 1) / 2; i++){
		total = 0;
		begin = end = i;
		while (total <= sum){
			total += end++;
			if (total == sum){
				printf(" [%d--%d]", begin, end - 1);
			}
		}
	}
	printf("\n");
}


int main(void)
{
	print(15);

	system("pause");
	return 0;
}