#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
��Ŀ��
	����һ����������������Ķ����Ʊ��ʽ���ж��ٸ�1.
	��������10������������Ʊ�ʾΪ1010��������1��������2.
*/

//void tentotwo(int num)
//{
//	if (num == 0){
//		return;
//	}
//	int zhengshu = num / 2, yushu = num % 2;
//	tentotwo(zhengshu);
//	printf("%d", yushu);
//}
int count_bit_1(int num)
{
	int count = 0;
	while (num){
		if (num & 1){
			count++;
		}
		num = num >> 1;
	}
	return count;
}

int main(void)
{
	printf("10�Ķ�������ֵ���� %d ��1\n", count_bit_1(10));

	system("pause");
	return 0;
}