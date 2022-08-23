#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
题目：
	输入三个整数x,y,z，请把这三个数由小到大输出
思路：
	我们想办法把最小的数放到x上，先将x与y进行比较，如果x>y则将x与y的值进行交换，
	然后再用x与z进行比较，如果x>z则将x与z的值进行交换，这样能使x最小。

*/

void main(void)
{
	int x, y, z,tmp;
	scanf("%d\t%d\t%d", &x, &y, &z);

	if (x>y)
	{
		tmp = x; x = y; y = tmp;
	} /*交换x,y的值*/
	if (x>z)
	{
		tmp = z; z = x; x = tmp;
	}/*交换x,z的值*/
	if (y>z)
	{
		tmp = y; y = z; z = tmp;
	}/*交换z,y的值*/
	printf("small to big : %d\t%d\t%d\n", x, y, z);



	system("pause");
}