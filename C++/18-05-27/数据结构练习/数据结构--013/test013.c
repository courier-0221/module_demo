#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
��Ŀ��
	��������n�������1��n���n��������ʮ���Ʊ�ʾ��1���ֵĴ�����
*/

//��������@m�а�������@digit�ĸ���
int count_digit_num(int m, int digit)
{
	int count = 0;
	while (m){
		if (m % 10 == digit){
			count++;
		}
		m = m / 10;
	}
	return count;
}


int count_digit_one(int n)
{
	int count = 0;
	for (int i = 0; i <= n; i++){
		count += count_digit_num(i, 1);
	}
	return count;
}


int main(void)
{
	printf("��1��nһ���� %d ��1\n", count_digit_one(20));

	system("pause");
	return 0;
}