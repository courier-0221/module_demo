#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
题目：
	输入两个正整数m和n，求其最大公约数和最小公倍数。
分析：
	最小公倍数等于m*n/最大公约数
*/

void main(void)
{
	int m, n,tmp;
	scanf("%d\t%d", &m, &n);
	if (n > m){
		tmp = n;
		n = m;
		m = tmp;
	}

	int a, b;
	a = m, b = n;
	while (b != 0)/*利用辗除法，直到b为0为止*/
	{
		tmp = a%b;
		a = b;
		b = tmp;
	}
	printf("gongyueshu:%d\n", a);
	printf("gongbeishu:%d\n", m*n / a);
	system("pause");
}