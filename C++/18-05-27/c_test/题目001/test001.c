#include <stdio.h>

/*
题目：
	有1、2、3、4个数字，能组成多少个互不相同且无重复数字的三位数?都是多少?
*/
/*
思路：
	全排列思想，数学思想第一个位置有4种可能，第二个位置有3种可能，第二个位置有2种可能
	转换成程序实现的方式是使用3个for循环当循环因子都不相等时输出
*/

void main(void)
{
	int i, j, k;
	int count = 0;
	for (i = 1; i < 5; i++){
		for (j = 1; j < 5; j++){
			for (k = 1; k < 5; k++){
				if ((i != k) && (j != k) && (i != j)){
					printf("%d,%d,%d\n", i, j, k);
					count++;
				}
			}
		}
	}

	printf("count%： %d\n", count);
	system("pause");
}