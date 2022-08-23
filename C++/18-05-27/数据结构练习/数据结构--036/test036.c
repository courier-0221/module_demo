#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


/*
��Ŀ��
	���Լ������		��С����������m*n/���Լ��
���ַ���
	��ƪ��������ϸ˵����https://blog.csdn.net/a1414345/article/details/51770430
	����һ������� 
		1.���a>b  a = a - b;
		2.���b>a    b = b - a;
		3.����a = b ���� a��b  �����Լ��
		4.���a != b,�������1��ʼִ��
		5.Ҳ����˵ѭ�����ж�����Ϊa != b  ��ֱ��a = bʱ��ѭ��������
	����������ٷ�
		1.ѡ��a��b����С��һ�����ַŵ�c��
		2.�ֱ���a��b��c�������������Ƿ��ܱ�c����
		3.ֱ��a��bͬʱ���ܱ�c����
		4.�粻��������c-- (c��ֵ��һ) ������2��ʼִ��
		5.Ҳ����˵��ѭ�����ж�����Ϊ a��b�ܷ�ͬʱ��c������ֻҪ��һ�������ܱ�c������ѭ������ִ��
	��������շת�����
		1.������������ a%b = c
		2.���c = 0;��bΪ���Լ�� 
		3.���c != 0,�� a = b��b = c��������1��ʼִ��
		4.Ҳ����˵��ѭ�����Ƿ�������ж���������c�Ƿ�Ϊ0
*/

int method1(int x, int y)
{
	while (x != y){
		if (x > y)
			x = x - y;
		else
			y = y - x;
	}
	return x;
}

int method2(int x, int y)
{
	int c = (x > y) ? y : x;
	while (x%c != 0 || y%c != 0){
		c--;
	}
	return c;
}

int method3_nodigui(int x, int y)
{
	int one = 0, two = 0, tmp = 0;
	if (x > y){
		one = x;
		two = y;
	}
	else{
		one = y;
		two = x;
	}

	while (two != 0){
		tmp = one % two;
		one = two;
		two = tmp;
	}
	return one;
}

int method3_digui(int x, int y)
{
	return ((y) ? method3_digui(y, x%y) : x);
}


int main(void)
{
	printf("%d\n", method3_digui(24, 36));
	printf("%d\n", method1(24, 36));
	printf("%d\n", method2(24, 36));
	
	system("pause");
	return 0;
}