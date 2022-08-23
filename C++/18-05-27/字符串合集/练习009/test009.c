#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>


/*
��Ŀ��
	�����ַ���A��B,���A��B�е���󹫹��Ӵ���
	����A="aocdfe" B="pmcdfa" �����"cdf"
����ֵ��
	�ɹ�������1
	ʧ�ܣ�����0
˼·��
	�����ִ�һ��aocdfe  �ִ�����pmcdfa
	����ΪѰ�ҵķ���

		��һ�֣� aocdfe aocdf aocd aoc ao a        
		�ڶ��֣� ocdfe ocdf ocd oc o
		�����֣� cdfe cdf cd c
		�����֣� dfe df d
		�����֣� fe f
		�����֣� e
*/

char *mystrcpy(char *dest, const char *src)
{
	assert(dest); assert(src);
	char *destbak = dest;

	while (*dest++ = *src++);
	return destbak;
}

char *mystrncpy(char *dest, const char *src, int size)
{
	assert(dest); assert(src);
	char *destbak = dest,i = 0;

	for (i = 0; i < size; i++){
		*dest = *src;
		dest++;
		src++;
	}
	dest[i] = 0;
	
	return destbak;
}

int mystrlen(const char *str)
{
	return (assert(str), *str ? mystrlen(str + 1) + 1 : 0);
}

char *mystrstr(const char *src, const char *string)
{
	assert(src); assert(string);
	int len1 = mystrlen(src),
		len2 = mystrlen(string),
		i = 0;

	if (len2 > len1){
		return NULL;
	}
	char *srcbak = src;

	while (*srcbak != 0){
		char *nowsrc = srcbak;
		char *stringbak = string;
		int found = 1;
		while (*nowsrc != 0 && *stringbak != 0){
			if (*nowsrc != *stringbak){
				found = 0;
			}
			nowsrc++;
			stringbak++;
		}
		if (found == 1){
			return srcbak;
		}

		srcbak++;
	}
	return NULL;
}

int commanstring(const char *str1, const char *str2, char * const substr)
{
	assert(str1); assert(str2); assert(substr);
	char *longstr = NULL,
		*shortstr = NULL,
		i = 0,j = 0;
	int len1 = mystrlen(str1),
		len2 = mystrlen(str2);


	//�ҳ������ַ���֮��ĳ��̹�ϵ��Ϊ�˼��ٲ���
	if (len1 > len2){
		longstr = str1;
		shortstr = str2;
	}
	else{	//С�ڵ��ڵ����ʹ�����
		longstr = str2;
		shortstr = str1;
	}


	//�����������Ӵ�����ô����shortstr
	if (mystrstr(longstr, shortstr) != NULL){
		mystrcpy(substr, shortstr);
		return 1;
	}

	//���򣬿�ʼѭ��������̴��п��ܱ������������Ӵ�
	for (i = mystrlen(shortstr) - 1; i > 0; i--){
		for (j = 0; j < mystrlen(shortstr) - i; j++){
			mystrncpy(substr, shortstr + j, i);
			substr[i] = 0;

			if (mystrstr(longstr, substr) != NULL){
				return 1;
			}
		}
	}
	return 0;
}

int main(void)
{
	char substr[128];

	if (commanstring("546123456", "fgh123dfg", substr) == 0){
		printf("û�й����Ӵ�\n");
	}
	else{
		printf("�����Ӵ�:%s\n", substr);

	}

	system("pause");
	return 0;
}