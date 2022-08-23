#include <stdio.h>

/*
题目：
	打印出所有的“水仙花数”，所谓“水仙花数”是指一个三位数，其各位数字立方和等于该数
	本身。例如：153是一个“水仙花数”，因为153=1的三次方＋5的三次方＋3的三次方。

*/


void main(void)
{
	int i, ge, shi, bai;
	for (i = 100; i <= 999; i++){
		ge = i % 10;
		shi = (i % 100) / 10;
		bai = i / 100;
		int tmp = ge*ge*ge + shi*shi*shi + bai*bai*bai;
		if (tmp == i){
			printf("%d\t", i);
		}
	}

	system("pause");
}