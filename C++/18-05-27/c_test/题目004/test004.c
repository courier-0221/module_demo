#define _CRT_SECURE_NO_WARNINGS
#include  <stdio.h>
/*
��Ŀ��
	����ĳ��ĳ��ĳ�գ��ж���һ������һ��ĵڼ���?
*/

void main(void)
{
	int year, month, day;
	scanf("%d\t%d\t%d", &year, &month, &day);

	if ((day > 31) || (month > 12)){
		printf("input error\n");
		exit(-1);
	}
	
	int january = 31;
	int february;
	if ((year % 4 == 0) && (year % 100 != 0)){
		february = january + 29;
	}
	else{
		february = january + 28;
	}
	int march = february + 31;
	int April = march + 30;
	int May = April + 31;
	int June = May + 30;
	int July = June + 31;
	int August = July + 30;	//8
	int September = August + 31;
	int October = September + 30;
	int November = October + 31;

	switch (month)
	{
		case 1:{
				 printf("��һ����%d��ĵ�%d��\n", year, day);
		}
		break;

		case 2:{
					 printf("��һ����%d��ĵ�%d��\n", year, day + january);
		}
		break;

		case 3:{
					 printf("��һ����%d��ĵ�%d��\n", year, day + february);
		}
		break;

		case 4:{
					 printf("��һ����%d��ĵ�%d��\n", year, day + march);
		}
		break;

		case 5:{
					 printf("��һ����%d��ĵ�%d��\n", year, day + April);
		}
		break;

		case 6:{
					 printf("��һ����%d��ĵ�%d��\n", year, day + May);
		}
		break;

		case 7:{
					 printf("��һ����%d��ĵ�%d��\n", year, day + June);
		}
		break;

		case 8:{
					 printf("��һ����%d��ĵ�%d��\n", year, day + July);
		}
		break;

		case 9:{
					 printf("��һ����%d��ĵ�%d��\n", year, day + August);
		}
		break;

		case 10:{
					  printf("��һ����%d��ĵ�%d��\n", year, day + September);
		}
		break;

		case 11:{
					  printf("��һ����%d��ĵ�%d��\n", year, day + October);
		}
		break;

		case 12:{
					  printf("��һ����%d��ĵ�%d��\n", year, day + November);
		}
		break;

		default :
			printf("error month \n");
	}


	system("pause");
}
