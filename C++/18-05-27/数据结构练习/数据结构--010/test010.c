#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
��Ŀ��
	���1+2+3+...N
Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ����Լ������ж����.
������
	һ�����ȣ���Ŀ������ʹ��while�������ǵ��뵽ѭ����Ψһ�����ݹ�
	��������ʹ��if��䣬��ô��������&&��������������������ִ����ߵ���䣬���Ϊ�棬��ִ���ұߵ���䣬
		�������������һ�����
������Ŀ�����
*/

int sum(int num)
{
	int total = 0;
	num && (total = sum(num - 1) + num);
	return total;
}
int sum2(int num)
{
	return (num ? (sum(num - 1) + num) : 0);
}


int main(void)
{
	printf("5�Ľ׳�Ϊ��%d\n", sum(5));
	

	system("pause");
	return 0;
}