#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
��Ŀ��
	��������������m��n���������Լ������С��������
������
	��С����������m*n/���Լ��
*/

void main(void)
{
	int m, n,tmp;
	scanf("%d\t%d", &m, &n);
	if (n > m){
		tmp = n;
		n = m;
		m = tmp;
	}

	int a, b;
	a = m, b = n;
	while (b != 0)/*����շ������ֱ��bΪ0Ϊֹ*/
	{
		tmp = a%b;
		a = b;
		b = tmp;
	}
	printf("gongyueshu:%d\n", a);
	printf("gongbeishu:%d\n", m*n / a);
	system("pause");
}