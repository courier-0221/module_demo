#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
��Ŀ��
	��������һ��������ĸ��ɵ��ַ���A��������һ���ַ���B���ַ�����B����ĸ�������һЩ��
	ʲô���������Ĳ������С�ַ���B�����ĸ�ڴ��ַ���A�ﶼ�У�
����2��
	��ϣ
		��1������һ������hash[26]������0������һ����ͬ�ַ����ִ����ܺ�m
		��2���������ַ��������ҵ����ַ���Ӧλ����1��m++
		��3���������ַ��������ҵ����ַ���Ӧλ����0��m--
		��4�����m����0�����ǰ�����ϵ�������Ƿǰ�����ϵ
*/

int mystrlen(const char *str)
{
	return (assert(str), (*str ? (mystrlen(str + 1) + 1) : 0));
}

int if_include(char *longstr, char *shortstr)
{
	if (longstr == NULL || shortstr == NULL){
		exit(-1);
	}
	int hash[26] = { 0 };
	int shortlen = mystrlen(shortstr), longlen = mystrlen(longstr), i = 0, key = 0, total = 0;
	for (i = 0; i < shortlen; i++){
		key = shortstr[i] - 'A';
		if (hash[key] == 1)
			continue;

		total++;
		hash[key] = 1;
		
	}

	for (i = 0; i < longlen; i++){
		key = longstr[i] - 'A';
		if (hash[key] == 0){
			continue;
		}
		hash[key] = 0;
		total--;
	}

	if (total == 0){
		return 1;
	}
	else{
		return -1;
	}
}


int main(void)
{
	
	if (if_include("ABCDEFGHLMNOPQRS", "ABZC") == 1){
		printf("����\n");
	}
	else{
		printf("������\n");
	}

	system("pause");
	return 0;
}