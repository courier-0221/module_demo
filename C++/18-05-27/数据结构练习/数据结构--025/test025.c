#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*
��Ŀ��
	�ַ���ԭ��ѹ��,��Ŀ����:"eeeeeaaaff" ѹ��Ϊ"e5a3f2",����ʵ��
˼·��
	�ο����ַ����ϼ��е���ϰ017����ϰ018
*/

int mystrlen(const char *str)
{
	return (assert(str), (*str ? (mystrlen(str + 1) + 1) : 0));
}


//error		���ַ���������ʱ"eeeeeaaaffaa"	����Ľ��Ϊ e5a5f2	
//char *str_compression(char *str)
//{
//	if (str == NULL){
//		return NULL;
//	}
//	int array[128] = { 0 };		//��¼���ִ���
//	int order[64] = { 0 };		//��¼����˳��
//	char *strbak = str, *ret = str; int i = 0;
//	//��¼���ֵĴ�����˳��
//	while (*strbak != 0){
//		if (array[*strbak] == 0){
//			order[i++] = *strbak;
//		}
//		array[*strbak]++;
//		strbak++;
//	}
//
//	char *strbak2 = str;
//	for (i = 0; i < 64; i++){
//		if ((order[i] == 0) && (array[order[i]] == 0)){
//			break;
//		}
//		*str++ = order[i];
//		*str++ = array[order[i]] + 48;
//	}
//	*str = 0;
//	return ret;
//}

void zip_str(char *str)
{
	if (str == NULL)	return;
	char buf[128] = { 0 };
	int i = 0, j = 0, z = 0, len = strlen(str);

	while (i < len){
		while (str[i] == str[j])
			i++;
		buf[z++] = str[j];
		buf[z++] = i - j + '0';
		j = i;
	}
	buf[z] = 0;
	if (len < strlen(buf))
		printf("%s\n", str);
	else
		printf("%s\n", buf);
}

int main(void)
{
	//char buf[] = "eeeeeaaaff";
	char buf[] = "eeeeeaaaffaa";
	//printf("%s\n", str_compression(buf));

	zip_str(buf);

	system("pause");
	return 0;
}