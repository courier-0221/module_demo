#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

/*
��Ŀ��
	�ж�101-200֮���ж��ٸ����������������������
˼·��
	����ֻ�ܱ��Լ���������
	�ж������ķ�������һ�����ֱ�ȥ��2��sqrt(�����)������ܱ�������
	���������������������֮��������
*/



void main(void)
{
	int i,j,k=0;
	for (i = 101; i <= 200; i++){
		int flag = 1;
		for (j = 2; j <= sqrt(i); j++){
			if (i%j == 0){	//�����һ�����������Ͳ���������û��Ҫ�����ж���
				flag = 0;
				break;
			}
		}
		if (flag == 1){
			k++;
			printf("%d\t", i);
			if (k % 5 == 0){
				printf("\n");
			}
		}
		
	}


	system("pause");
}