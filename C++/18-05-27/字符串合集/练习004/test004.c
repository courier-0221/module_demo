#include <stdio.h>
#include <stdlib.h>

/*
��Ŀ��
	��һ���ַ�����1a2b3d4z����
	Ҫ��дһ������ʵ�����¹��ܣ�
	����1����ż��λ�ַ���ѡ���������һ���ַ���1��
	����2��������λ�ַ���ѡ���������һ���ַ���2��
	����3�����ַ���1���ַ���2��ͨ���������������͸�main������ӡ��
	����4���������ܲ���ͨ����
	int getStr1Str2(char *source, char *buf1, char *buf2);
*/

int mystrlen(char const *str)
{
	int ret = 0;
	if (!str){
		return -1;
	}

	if (*str == 0){
		return ret;
	}
	else{
		return mystrlen(str + 1) + 1;
	}

}

int getStr1Str2(char *source, char *buf1, char *buf2)
{
	if ((!source) || (!buf1) || (!buf2)){
		return;
	}
	int len = mystrlen(source);
	int i = 0, j = 0, k = 0;
	for (i = 0; i < len; i++){
		if (i % 2 == 0){	//ż
			buf1[j] = source[i];
			j++;
		}
		else if (i % 2 == 1){	//��
			*(buf2 + k) = *(source + i);
			k++;
		}
	}

	buf1[j] = 0;
	buf2[k] = 0;
}

int main(void)
{
	char buf1[10] = { 0 };
	char buf2[10] = { 0 };

	getStr1Str2("1a2b3d4z", buf1, buf2);
	printf("ou = %s\nji = %s\n", buf1, buf2);

	system("pause");
	return 0;
}