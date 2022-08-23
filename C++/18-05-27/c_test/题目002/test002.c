#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
题目：
	企业发放的奖金根据利润提成。
	利润(I) 低于或等于 10万元时，奖金可提10%；
	利润高于 10 万元，低于20 万元时，低于 10 万元的部分按 10% 提成，高于 10 万元的部分，可提成 7.5%；
	20 万到 40 万之间时，高于20 万元的部分，可提成5%；
	40 万到 60 万之间时高于 40 万元的部分，可提成 3%；
	60 万到 100 万之间时，高于 60 万元的部分，可提成 1.5%，
	高于100 万元时，超过 100 万元的部分按 1% 提成，
	从键盘输入当月利润I，求应发放奖金总数? 
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