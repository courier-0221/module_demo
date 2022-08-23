#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
题目：
	输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。
	例如，输入”They are students.”和”aeiou”， 则删除之后的第一个字符串变成”Thy r stdnts.”。
*/

int mystrlen(const char *str)
{
	return (assert(str), (*str ? (mystrlen(str + 1) + 1) : 0));
}

//char *mystrchr(char *dst, char ch)
//{
//	if (!dst){
//		return NULL;
//	}
//
//	while (*dst != 0){
//		if (*dst == ch){
//			return dst;
//		}
//		dst++;
//	}
//	return NULL;
//}

//char *delete_frist_char(char *str, char ch)
//{
//	if (str == NULL){
//		return NULL;
//	}
//	char *ret = str;
//	int len = mystrlen(str);
//	char *now = mystrchr(str, ch);
//	if (now == NULL){
//		return NULL;
//	}
//	char *nownext = now + 1;
//	while (*nownext != 0){
//		*now = *nownext;
//		now++, nownext++;
//	}
//	*now = 0;
//	return ret;
//}


//method 1
char *delete_all_char(char *str, char ch)
{
	if (str == NULL){
		return NULL;
	}
	char *ret = str, *tmp = str;
	while (*tmp){
		if (*tmp != ch){
			*str++ = *tmp;
		}
		tmp++;
	}
	*str = 0;
	return ret;
}
char *delete_chars(char *str, char *del_chars)
{
	if ((str == NULL) || (del_chars == NULL)){
		return NULL;
	}
	char *ret = str;
	
	while (*del_chars != 0){
		str = delete_all_char(str, *del_chars);
		del_chars++;
	}
	return ret;
}

//method 2
char *delete_chars2(char *str, char *del_chars)
{
	if ((str == NULL) || (del_chars == NULL)){
		return NULL;
	}
	char *ret = str, *pos = str;
	int hash[256] = { 0 };
	while (*del_chars != 0){
		if (hash[*del_chars] == 0)
			hash[*del_chars] = 1;
		del_chars++;
	}

	int strlen = mystrlen(str);
	while (strlen--){
		if (hash[*pos] == 0){
			*str++ = *pos;
		}
		pos++;
	}
	*str = 0;

	return ret;
}

int main(void)
{
	char buf[] = "They are students.";
	//printf("%s\n", delete_chars(buf, "aeiou"));
	printf("%s\n", delete_chars2(buf, "aeiou"));


	system("pause");
	return 0;
}