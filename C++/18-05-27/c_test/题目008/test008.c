#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
��Ŀ��
	Ҫ����������������̡�
������
	���8 * 8	1-8��A-H
	��һ�У�2,4,6,8�Ǻ�ɫ��
	�ڶ��У�1,3,5,7�Ǻ�ɫ��
	ż���е�����λ�Ǻ�ɫ�ģ�ż�����ǰ�ɫ��
	�����е�ż��λ�ǰ�ɫ�ģ��������Ǻ�ɫ��

	��㷽������ + �������������ɫ�������ż����ɫ
*/

void main(void)
{
	char a = 176, b = 219;	//219 -->white
	system("chcp 437");//�������� chcp ���������̨�Ļ����ҳ��Ϊ 437��United States��
						//����ҳ���ַ�������ı�����Ҳ��"�����"��
	
	int i, j;
	//for (i = 1; i <= 8; i++){	//��
	//	for (j = 1; j <= 8; j++){	//��
	//		if (i % 2 == 0){	//ż
	//			if (j % 2 == 0){//ż
	//				printf("%c", b);
	//			}
	//			else{
	//				printf("%c", a);
	//			}
	//		}else{
	//			if (j % 2 == 0){
	//				printf("%c", a);
	//			}
	//			else{
	//				printf("%c", b);
	//			}
	//		}
	//	
	//	}
	//	printf("\n");
	//}
	for (i = 0; i<8; i++)
	{
		for (j = 0; j<8; j++)
		if ((i + j) % 2 == 0)
			printf("%c", 219);
		else
			printf(" ");
		printf("\n");
	}


	system("pause");
}