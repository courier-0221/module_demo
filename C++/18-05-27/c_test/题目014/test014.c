#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
��Ŀ��
	���������������Ƕ������ɴ��⣺ѧϰ�ɼ�>=90�ֵ�ͬѧ��A��ʾ��60-89��֮�����B��ʾ��60�����µ���C��ʾ��
������
	���������(a>b)?a:b��������������Ļ������ӡ�
*/

void main(void)
{
	int sum;
	
	scanf("%d", &sum);
	char t = (sum < 60) ? 'C' : ((sum>90) ? 'A' : 'B');

	printf("%c\n", t);

	system("pause");
}