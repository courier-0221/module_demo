#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
��Ŀ��
	����n�������ķ�����Fibonacci���еĵ�n��
	Fibonacci����
	1,1,2,3,5,8,13,21,34
������
	�������ֵ����ǰ����ֵ�ĺ�
*/

int Fibonacci(int n)
{
	if ((n == 1) || (n == 2)){
		return 1;
	}
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}
int main(void)
{
	printf("��n���Fibonacci��ֵΪ��%d\n", Fibonacci(9));

	system("pause");
	return 0;
}