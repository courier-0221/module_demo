#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
��Ŀ��
	����һ����ʾ�������ַ������Ѹ��ַ���ת���������������
	���������ַ���"345"�����������345��
*/


int str_to_num(const char *str)
{
	if (str == NULL){
		return - 1;
	}

	int result = 0;
	char *strbak = str;
	while (*strbak != 0){
		if (*strbak >= '0' && *strbak <= '9'){
			result *= 10;
			result += (*strbak - 48);
		}
		strbak++;
	}

	return result;
}

int main(void)
{

	printf("%d\n", str_to_num("123"));

	system("pause");
	return 0;
}