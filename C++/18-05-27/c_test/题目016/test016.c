#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
��Ŀ��
	����һ���ַ����ֱ�ͳ�Ƴ�����Ӣ����ĸ���ո����ֺ������ַ��ĸ�����
������
	"sdfg 123    f4t567h @#!`  "
*/

void main(void)
{
	
	int zimu = 0,shuzi = 0,kongge = 0,qita = 0;

	char tmp;

	while ((tmp = getchar()) != '\n'){
		if ((('a' <= tmp) && (tmp <= 'z')) && ('A' <= tmp <= 'Z')){
			zimu++;
		}
		else if (('0' <= tmp) && (tmp <= '9')){
			shuzi++;
		}
		else if (tmp == ' '){
			kongge++;
		}
		else{
			qita++;
		}

	}

	printf("��ĸ��%d\t���֣�%d\t�ո�%d\t������%d\n", zimu, shuzi, kongge, qita);



	system("pause");
}



