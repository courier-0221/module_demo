#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
��Ŀ��
	���ӳ������⣺���ӵ�һ��ժ�����ɸ����ӣ���������һ�룬����񫣬�ֶ����һ���ڶ��������ֽ�ʣ�µ����ӳԵ�һ�룬�ֶ����һ����
	�Ժ�ÿ�����϶�����ǰһ��ʣ�µ�һ����һ��������10���������ٳ�ʱ����ֻʣ��һ�������ˡ����һ�칲ժ�˶��١�
*/

int monkeys_eat_peach(int num)
{
	if (num == 1){
		return 1;
	}
	return ((monkeys_eat_peach(num - 1) + 1) * 2);
}


int main(void)
{
	printf("��һ��ժ�� %d ������\n", monkeys_eat_peach(10));
	system("pause");
	return 0;
}





