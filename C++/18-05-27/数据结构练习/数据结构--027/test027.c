#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*
��Ŀ��
	�������ַ����е��ַ�'*'�Ƶ�����ǰ���֣�ǰ��ķ�'*'�ַ����ƣ������ܸı��'*'�ַ����Ⱥ�˳��,
	�������ش����ַ�'*'��������
������
	����2��˼·��
		�ÿ���ָ�룬ָ���ַ���β�ͣ���ָ��ָ��ǡ�*���ַ�������ָ��ָ��'*'��Ȼ�󽻻�ָ�����ݼ���

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
	//��¼��*���Ÿ���
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

		if (*first == move_char){		//�ҵ���ĸ
			first--;
			zimu++;
			continue;
		}

		if (*second != move_char){		//�ҵ���*��
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
	printf("* ������%d\nbuf: %s\n", len, buf);



	system("pause");
	return 0;
}