#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
��Ŀ��
	һ���100�׸߶��������£�ÿ����غ�����ԭ�߶ȵ�һ�룻�����£������ڵ�10�����ʱ��������������?��10�η������?
*/

float Distance_traveled(float *tenth)
{
	int times = 10;
	float path = 100.0, height = 100.0 / 2;
	
	for (int n = 2; n <= 10; n++){
		path += height * 2;
		height /= 2;		/*��n�η����߶�*/
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
		sn = sn + 2 * hn;/*��n�����ʱ������������*/
		hn = hn / 2; /*��n�η����߶�*/
	}
	printf("the total of road is %f\n", sn);
	printf("the tenth is %f meter\n", hn);
	system("pause");
		return 0;
}


