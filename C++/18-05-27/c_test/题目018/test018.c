#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
��Ŀ��
	һ�������ǡ�õ�����������֮�ͣ�������ͳ�Ϊ��������������6=1��2��3.����ҳ�1000���ڵ�����������
������
	�������� -- ���Ӿ������п����������������,���������������. 
	����15��������1��3��5 ����������Ϊ1,3,5,15��
*/

void find_wanshu(int num)
{
	if (num < 0){
		return;
	}
	int i = 0, j = 0, result = 0;

	for (i = 2; i <= num; i++){
		int end = i / 2 + 1;
		result = 0;
		for (j = 1; j < end; j++){
			if (i % j == 0){
				result += j;
			}
			if (result > i)
				break;
		}
		if (result == i){
			printf("%d\n", i);
		}
	}
}

int main(void)
{

	find_wanshu(1000);


	system("pause");
	return 0;
}



