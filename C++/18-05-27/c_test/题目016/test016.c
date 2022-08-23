#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
题目：
	输入一行字符，分别统计出其中英文字母、空格、数字和其它字符的个数。
分析：
	"sdfg 123    f4t567h @#!`  "
*/

void main(void)
{
	
	int zimu = 0,shuzi = 0,kongge = 0,qita = 0;

	char tmp;

	while ((tmp = getchar()) != '\n'){
		if ((('a' <= tmp) && (tmp <= 'z')) && ('A' <= tmp <= 'Z')){
			zimu++;
		}
		else if (('0' <= tmp) && (tmp <= '9')){
			shuzi++;
		}
		else if (tmp == ' '){
			kongge++;
		}
		else{
			qita++;
		}

	}

	printf("字母：%d\t数字：%d\t空格：%d\t其他：%d\n", zimu, shuzi, kongge, qita);



	system("pause");
}



