#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


/*
题目：
	求两个串中的第一个最长子串(神州数码以前试题).如"abractyeyt","dgdsaeactyey"的最大子串为"actyey".
分析：
	

*/



int mystrlen(const char *str)
{
	return (assert(str), (*str ? (mystrlen(str + 1) + 1) : 0));
}
char *mystrncpy(char *dest, char *src, int  n)
{
	if ((dest == NULL) || (src == NULL)){
		return NULL;
	}
	char *ret = dest;
	while (n-- > 0){
		*dest++ = *src++;
	}
	*dest = 0;
	return ret;
}
char *mystrstr(const char *str, const char *string)
{
	if ((str == NULL) || (string == NULL)){
		return NULL;
	}
	char *str_bak = str, *string_bak = string;
	while (*str != 0){
		int found = 1;
		str_bak = str;
		string_bak = string;
		while (*str_bak != 0 && *string_bak != 0){
			if (*str_bak != *string_bak){
				found = 0;
			}
			string_bak++;
			str_bak++;
		}
		if (found == 1){
			return str_bak;
		}
		++str;
	}
	return NULL;
}



char *max_public_str(const char *str1, const char *str2)
{
	if ((str1 == NULL) || (str2 == NULL)){
		return NULL;
	}
	int len1 = mystrlen(str1), len2 = mystrlen(str2),minlen = 0;
	char *shortstr = NULL, *longstr = NULL;
	

	if (len1 < len2){
		shortstr = str1;
		longstr = str2;
		minlen = len1;
	}
	else{
		shortstr = str2;
		longstr = str1;
		minlen = len2;
	}
	char *substr = (char *)malloc(minlen);
	if (substr == NULL){
		printf("malloc error\n");
		return NULL;
	}
	for (int i = minlen; i > 0; i--){
		for (int j = 0; j <= minlen - i; j++){
			mystrncpy(substr, shortstr + j, i);
			substr[i] = 0;
			if (mystrstr(longstr, substr) != NULL){
				return substr;
			}
		}
	}
	return substr;
}



int main(void)
{
	char *buf = max_public_str("abractyeyt", "dgdsaeactyey");
	//char *buf = max_public_str("abra", "br"));
	printf("最大公子串为： %s\n",buf );
	if (buf != NULL){
		free(buf);
		buf = NULL;
	}

	

	

	system("pause");
	return 0;
}