#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


/*
��Ŀ��
	ip�Ϸ��Լ��
��Ŀ������
	(1) �ַ���ֻ�������ֺ�'.'
	(2) ������7-15֮��(0.0.0.0--255.255.255.255)
	(3) ÿ��������0-255֮��
	(4) '.'�Ų��ܳ���3��,�Ҳ�������
*/
int mystrlen(const char *str)
{
	return (assert(str), (*str ? (mystrlen(str + 1) + 1) : 0));
}
char *mystrchr(const char *str,char ch)
{
	if (str == NULL){
		return NULL;
	}
	while (*str){
		if (*str == ch){
			return str;
		}
		str++;
	}
	return NULL;
}

int if_legal(char *start, int len)
{
	char buf[4] = {0};
	strncpy(buf, start, len);
	if (atoi(buf) > 255){
		printf("ip��ַ���ֶγ������Ϊ255\n");
		return 0;
	}
	printf("%d\n", atoi(buf));
	return 1;
}

/*
����ֵ��
	0�����Ϸ�
	1���Ϸ���
*/
int check_ip(const char *str)
{
	int len = mystrlen(str);
	if ((len > 15) || (len < 7)){
		printf("ip��ַ���Ȳ��Ϸ�\n");
		return 0;
	}
	char *strbak = str;
	while (*strbak != 0){
		if ((*strbak != '.') && (*strbak < '0' || *strbak > '9')){
			printf("ip��ַ�к��з�����\n");
			return 0;
		}
		strbak++;
	}

	int count = 0, size = 0;
	char *now = mystrchr(str, '.'),*now_last = str;
	
	while (now != NULL){
		if (*now == *(now + 1)){
			printf("ip��ַ�и�ʽ��д����ȷ��������.����\n");
			return 0;
		}
		
		size = now - now_last;
		if ((size > 3) || (if_legal(now_last, size) == 0)){
			printf("ip��ַ��ÿ���ֶ������3��������ɣ��Ҳ�����255\n");
			return 0;
		}
		now_last = now + 1;
		now = mystrchr(now + 1, '.'); 
		if (now == NULL){
			size = str + len - now_last;
			if ((size > 3) || if_legal(now_last, size) == 0){
				return 0;
			}
		}	
	}
	return 1;
}



int main(void)
{
	//int ret = check_ip("192.168.1.231");
	//int ret = check_ip("192.1a8.1.231");
	int ret = check_ip("192.1348.1.231");
	//int ret = check_ip("0.0.0.0");
	//int ret = check_ip("192.268.1.231");
	//int ret = check_ip("..1.");
	if (ret == 1){
		printf("ip �Ϸ�\n");
	}
	else{
		printf("ip ���Ϸ�\n");
	}

	

	system("pause");
	return 0;
}