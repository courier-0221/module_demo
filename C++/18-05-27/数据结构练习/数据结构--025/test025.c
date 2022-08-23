#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*
题目：
	字符串原地压缩,题目描述:"eeeeeaaaff" 压缩为"e5a3f2",请编程实现
思路：
	参考了字符串合集中的练习017和练习018
*/

int mystrlen(const char *str)
{
	return (assert(str), (*str ? (mystrlen(str + 1) + 1) : 0));
}


//error		当字符串是这种时"eeeeeaaaffaa"	输出的结果为 e5a5f2	
//char *str_compression(char *str)
//{
//	if (str == NULL){
//		return NULL;
//	}
//	int array[128] = { 0 };		//记录出现次数
//	int order[64] = { 0 };		//记录出现顺序
//	char *strbak = str, *ret = str; int i = 0;
//	//记录出现的次数及顺序
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