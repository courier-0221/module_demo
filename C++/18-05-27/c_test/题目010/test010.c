#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
��Ŀ��
	�ŵ����⣺��һ�����ӣ��ӳ������3������ÿ���¶���һ�����ӣ�С���ӳ�����������
	��ÿ��������һ�����ӣ��������Ӷ���������ÿ���µ���������Ϊ����?
˼·��
	���ӵĹ���Ϊ����1,1,2,3,5,8,13,21��.
	�����³��������ӵ��������ֿ��������ӣ�֮ǰ�����ӵ������»�������
*/

int feibonaqi(int month)
{
	
	if ((month == 1) || (month == 2)){
		return 1;
	}
	else{
		return feibonaqi(month - 1) + feibonaqi(month - 2);
	}
	
}

void main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d���º���������Ϊ%d\n", n, feibonaqi(n));

	//�ǵݹ��
	int i, f1 = 1, f2 = 1;
	for (i = 1; i <= 20; i++)
	{
		printf("% 12ld % 12ld", f1, f2);
		if (i % 2 == 0) 
			printf("\n");/*���������ÿ���ĸ�*/
		f1 = f1 + f2; /*ǰ�����¼�������ֵ����������*/
		f2 = f1 + f2; /*ǰ�����¼�������ֵ����������*/
	}


	system("pause");
}