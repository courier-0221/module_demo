#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
题目：
	求s=a+aa+aaa+aaaa+aa…a的值，其中a是一个数字。例如2+22+222+2222+22222(此时共有5个数相加)，几个数相加有键盘控制。
*/

int main(void)
{
	int num = 0, count = 0;
	printf("pelase input num and count,Space in between\n");
	scanf("%d\t%d", &num, &count);
	long long result = 0, numdizeng = num, n = 0;

	while (count--){
		result += numdizeng;
		n = numdizeng;
		numdizeng = numdizeng * 10 + num;
	}
	
	printf("%lld\n", result);


	
	system("pause");
	return 0;
}



