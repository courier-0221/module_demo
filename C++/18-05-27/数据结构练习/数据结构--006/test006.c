#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
��Ŀ��
	��һ���ַ������ҵ���һ��ֻ����һ�ε��ַ���������abaccdeff�������b��
˼·��
	��˳������ַ������ٰ�ÿ�α����ĵõ����ַ����������ַ����в���
*/
int mystrlen(const char *str)
{
	return (assert(str), (*str ? (mystrlen(str + 1) + 1) : 0));
}

//��@str�в���@c,����˵�@num���ڵ��ַ�
char *mystrchr(const char *str, char ch,int num)
{
	if (str == NULL){
		return NULL;
	}
	char *strbak = str;
	int i = 0, len = mystrlen(str);
	for (i = 0; i < len;i++){
		if (i == num){
			strbak++;
			continue;
		}
		if (*strbak == ch){
			return strbak;
		}
		strbak++;
	}
	
	return NULL;
}

char find_once_char_in_str(const char *str)
{
	if (str == NULL){
		exit(-1);
	}
	int i = 0, len = mystrlen(str);
	char *strbak = str;
	for (i = 0; i < len;){
		if (mystrchr(strbak, strbak[i], i) != NULL){
			i++;
		}
		else{
			return str[i];
		}
	}
	return 0;
}


int main(void)
{
	
	char *str = "aabadccdebff7e";
	printf("---> %c\n", find_once_char_in_str(str));

	system("pause");
	return 0;
}