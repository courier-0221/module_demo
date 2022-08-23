#include <stdio.h>
#include <stdlib.h>

/*
题目：
	有一个字符串“1a2b3d4z”；
	要求写一个函数实现如下功能：
	功能1：把偶数位字符挑选出来，组成一个字符串1。
	功能2：把奇数位字符挑选出来，组成一个字符串2。
	功能3：把字符串1和字符串2，通过函数参数，传送给main，并打印。
	功能4：主函数能测试通过。
	int getStr1Str2(char *source, char *buf1, char *buf2);
*/

int mystrlen(char const *str)
{
	int ret = 0;
	if (!str){
		return -1;
	}

	if (*str == 0){
		return ret;
	}
	else{
		return mystrlen(str + 1) + 1;
	}

}

int getStr1Str2(char *source, char *buf1, char *buf2)
{
	if ((!source) || (!buf1) || (!buf2)){
		return;
	}
	int len = mystrlen(source);
	int i = 0, j = 0, k = 0;
	for (i = 0; i < len; i++){
		if (i % 2 == 0){	//偶
			buf1[j] = source[i];
			j++;
		}
		else if (i % 2 == 1){	//奇
			*(buf2 + k) = *(source + i);
			k++;
		}
	}

	buf1[j] = 0;
	buf2[k] = 0;
}

int main(void)
{
	char buf1[10] = { 0 };
	char buf2[10] = { 0 };

	getStr1Str2("1a2b3d4z", buf1, buf2);
	printf("ou = %s\nji = %s\n", buf1, buf2);

	system("pause");
	return 0;
}