#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
��Ŀ��
	�������ͼ��
*/

void main(void)
{
	char a = 176, b = 219;
	system("chcp 437");//�������� chcp ���������̨�Ļ����ҳ��Ϊ 437��United States��
						//����ҳ���ַ�������ı�����Ҳ��"�����"��
	printf("%c%c%c%c%c\n", b, a, a, a, b);
	printf("%c%c%c%c%c\n", a, b, a, b, a);
	printf("%c%c%c%c%c\n", a, a, b, a, a);
	printf("%c%c%c%c%c\n", a, b, a, b, a);
	printf("%c%c%c%c%c\n", b, a, a, a, b);

	



	system("pause");
}