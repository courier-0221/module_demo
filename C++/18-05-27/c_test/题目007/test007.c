#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
题目：
	输出特殊图案
*/

void main(void)
{
	char a = 176, b = 219;
	system("chcp 437");//该语句调用 chcp 命令，将控制台的活动代码页改为 437（United States）
						//代码页是字符集编码的别名，也称"内码表"。
	printf("%c%c%c%c%c\n", b, a, a, a, b);
	printf("%c%c%c%c%c\n", a, b, a, b, a);
	printf("%c%c%c%c%c\n", a, a, b, a, a);
	printf("%c%c%c%c%c\n", a, b, a, b, a);
	printf("%c%c%c%c%c\n", b, a, a, a, b);

	



	system("pause");
}