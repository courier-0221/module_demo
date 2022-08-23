#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
��Ŀ��
	�����ַ���������ת���������ַ���ǰ������ɸ��ַ��ƶ����ַ�����β��������ַ���abcdef
	����ת2λ�õ��ַ���cdefab��
��ʵ���ַ�������ת�ĺ�����Ҫ��Գ���Ϊn���ַ���������ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1)��
*/

int mystrlen(const char *str)
{
	return (assert(str), (*str ? (mystrlen(str + 1) + 1) : 0));
}


char *left_one_step(char *str,int len)
{
	if (str == NULL){
		return NULL;
	}
	int i = 0;
	char first = str[0];
	for(i = 0; i < len; i++){
		str[i] = str[i + 1];
	}
	str[--i] = first;

	return str;
}

char *left_n_step(char *str, int len ,int num)
{
	while (num--){
		str = left_one_step(str, len);
		
	}
	return str;
}

int main(void)
{
	char buf[] = "1234567";
	int len = mystrlen(buf);
	printf("����λ֮���Ч����%s\n", left_n_step(buf, len, 3));

	system("pause");
	return 0;
}