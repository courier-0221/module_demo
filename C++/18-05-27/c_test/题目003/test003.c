#include <stdio.h>
#include <math.h>

/*
��Ŀ��
	һ�������������� 100 ����һ����ȫƽ�������ټ��� 168 ����һ����ȫƽ���������ʸ����Ƕ���? 
*/

void main(void)
{ 
	int i,x,y;
	for (i = 0; i < 100000; i++){
		x = sqrt(i+100);
		y = sqrt(i+268);
		if ((x*x == i + 100) && (y*y == i + 268)){
			printf("%d\n", i);
			break;
		}
	}
	system("pause");
}