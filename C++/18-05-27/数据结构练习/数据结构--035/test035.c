#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


/*
题目：
	ip合法性检查
题目分析：
	(1) 字符串只含有数字和'.'
	(2) 长度在7-15之间(0.0.0.0--255.255.255.255)
	(3) 每个数字在0-255之间
	(4) '.'号不能超过3个,且不能连续
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
		printf("ip地址中字段长度最大为255\n");
		return 0;
	}
	printf("%d\n", atoi(buf));
	return 1;
}

/*
返回值：
	0，不合法
	1，合法的
*/
int check_ip(const char *str)
{
	int len = mystrlen(str);
	if ((len > 15) || (len < 7)){
		printf("ip地址长度不合法\n");
		return 0;
	}
	char *strbak = str;
	while (*strbak != 0){
		if ((*strbak != '.') && (*strbak < '0' || *strbak > '9')){
			printf("ip地址中含有非数字\n");
			return 0;
		}
		strbak++;
	}

	int count = 0, size = 0;
	char *now = mystrchr(str, '.'),*now_last = str;
	
	while (now != NULL){
		if (*now == *(now + 1)){
			printf("ip地址中格式书写不正确，有两个.挨着\n");
			return 0;
		}
		
		size = now - now_last;
		if ((size > 3) || (if_legal(now_last, size) == 0)){
			printf("ip地址中每个字段最大由3个数字组成，且不超过255\n");
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
		printf("ip 合法\n");
	}
	else{
		printf("ip 不合法\n");
	}

	

	system("pause");
	return 0;
}