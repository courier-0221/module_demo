#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
题目：
	一球从100米高度自由落下，每次落地后反跳回原高度的一半；再落下，求它在第10次落地时，共经过多少米?第10次反弹多高?
*/

float Distance_traveled(float *tenth)
{
	int times = 10;
	float path = 100.0, height = 100.0 / 2;
	
	for (int n = 2; n <= 10; n++){
		path += height * 2;
		height /= 2;		/*第n次反跳高度*/
		printf("%f\t%f\n", height, path);
		if (n == 10){
			*tenth = height;
		}
	}
	return path;
}

//int main(void)
//{
//	float tenth = 0;
//	float path = Distance_traveled(&tenth);
//	printf("path:%f\ntenth:%f\n", path, tenth);
//
//	system("pause");
//	return 0;
//}

int main()
{
	float sn = 100.0, hn = sn / 2;
	int n;
	for (n = 2; n <= 10; n++)
	{
		sn = sn + 2 * hn;/*第n次落地时共经过的米数*/
		hn = hn / 2; /*第n次反跳高度*/
	}
	printf("the total of road is %f\n", sn);
	printf("the tenth is %f meter\n", hn);
	system("pause");
		return 0;
}


