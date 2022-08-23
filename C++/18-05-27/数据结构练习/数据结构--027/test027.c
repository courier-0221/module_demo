#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*
题目：
	函数将字符串中的字符'*'移到串的前部分，前面的非'*'字符后移，但不能改变非'*'字符的先后顺序,
	函数返回串中字符'*'的数量。
分析：
	方法2的思路是
		用快慢指针，指向字符串尾巴，快指针指向非‘*’字符串，慢指针指向'*'，然后交换指针内容即可

*/



int mystrlen(const char *str)
{
	return (assert(str), (*str ? (mystrlen(str + 1) + 1) : 0));
}


void *mymemcpy(void *dest, const void *src, int count)
{
	char *d = dest;
	const char *s = src;
	while (count > 0){
		*d++ = *s++;
		count--;
	}
	return dest;
}

int str_move_char_to_head1(char *str, char move_char)
{
	if (str == NULL){
		return NULL;
	}
	int ret = 0, strlen = mystrlen(str), xinghao = 0;
	char str_bak[64] = { 0 }, *tmp = str;
	mymemcpy(str_bak, str, strlen);
	//记录‘*’号个数
	while (*tmp != 0){
		if (*tmp == move_char){
			xinghao++;
		}
		tmp++;
	}
	ret = xinghao;
	tmp = str;
	for (int i = 0; i < xinghao; i++){
		tmp[i] = move_char;
	}

	for (int i = 0; i < strlen; i++){
		if (str_bak[i] != move_char){
			tmp[xinghao++] = str_bak[i];
		}
	}
	tmp[xinghao] = 0;

	return ret;
}

int str_move_char_to_head2(char *str, char move_char)
{
	if (str == NULL){
		return NULL;
	}
	int len = mystrlen(str), zimu = 0;
	char *first = str + len - 1, *second = first;
	while (len--){

		if (*first == move_char){		//找到字母
			first--;
			zimu++;
			continue;
		}

		if (*second != move_char){		//找到‘*’
			second--;
			continue;
		}
		
		char tmp = *first;
		*first-- = *second;
		*second-- = tmp;
	}
	return len - zimu;
}


int main(void)
{
	char buf[] = "a*c*e*g*i*k*m*";
	int len = str_move_char_to_head2(buf, '*');
	printf("* 个数：%d\nbuf: %s\n", len, buf);



	system("pause");
	return 0;
}