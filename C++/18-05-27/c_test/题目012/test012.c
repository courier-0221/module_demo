#include <stdio.h>

/*
��Ŀ��
	��ӡ�����еġ�ˮ�ɻ���������ν��ˮ�ɻ�������ָһ����λ�������λ���������͵��ڸ���
	�������磺153��һ����ˮ�ɻ���������Ϊ153=1�����η���5�����η���3�����η���

*/


void main(void)
{
	int i, ge, shi, bai;
	for (i = 100; i <= 999; i++){
		ge = i % 10;
		shi = (i % 100) / 10;
		bai = i / 100;
		int tmp = ge*ge*ge + shi*shi*shi + bai*bai*bai;
		if (tmp == i){
			printf("%d\t", i);
		}
	}

	system("pause");
}