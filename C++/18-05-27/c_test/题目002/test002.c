#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
��Ŀ��
	��ҵ���ŵĽ������������ɡ�
	����(I) ���ڻ���� 10��Ԫʱ���������10%��
	������� 10 ��Ԫ������20 ��Ԫʱ������ 10 ��Ԫ�Ĳ��ְ� 10% ��ɣ����� 10 ��Ԫ�Ĳ��֣������ 7.5%��
	20 �� 40 ��֮��ʱ������20 ��Ԫ�Ĳ��֣������5%��
	40 �� 60 ��֮��ʱ���� 40 ��Ԫ�Ĳ��֣������ 3%��
	60 �� 100 ��֮��ʱ������ 60 ��Ԫ�Ĳ��֣������ 1.5%��
	����100 ��Ԫʱ������ 100 ��Ԫ�Ĳ��ְ� 1% ��ɣ�
	�Ӽ������뵱������I����Ӧ���Ž�������? 
*/

void main(void)
{
	int profits;
	int sum = 0.0;
	printf("pless input profits\n");
	scanf("%d", &profits);
	int bonus10, bonus20, bonus40, bonus60, bonus100;
	bonus10 = 100000 * 0.1;
	bonus20 = bonus10 + 100000 * 0.075;
	bonus40 = bonus20 + 200000 * 0.05;
	bonus60 = bonus40 + 200000 * 0.03;
	bonus100 = bonus60 + 400000 * 0.015;

	if (profits <= 10){
		sum = profits*0.1;
	}
	else if (100000 < profits < 200000){
		sum = bonus10 + (profits - 100000)*0.075;
	}
	else if (200000 < profits < 400000){
		sum = bonus20 + (profits - 200000)*0.005;
	}
	else if (400000 < profits < 600000){
		sum = bonus40 + (profits - 400000)*0.003;
	}
	else if (600000 < profits < 1000000){
		sum = bonus60 + (profits - 600000)*0.015;
	}
	else if (1000000 < profits ){
		sum = bonus100 + (profits - 1000000)*0.001;
	}

	printf("%d\n", sum);


	system("pause");
}