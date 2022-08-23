#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


//˵������Щ����û�ж���õ�ͷ��㣬��᳣���Կ���ʹ�ö���ָ�������뺯������������ͷ���Ļ�����ʱʹ��һ��ָ��������������
//Ϊ�˸����һ��ָ��Ͷ���ָ�����β���ʲô���������ô������+֤��


/* ����һ��ָ���������������ϵ���ָ�� */
/* ���Զ���ָ���������������ϵ���ָ�� */
int a = 10;
int b = 20;
int c = 30;
int *ptr1 = &a;
int *ptr3 = NULL;

void FirstLevelPointerTest1(int *p)
{
	p = &b;
}

void FirstLevelPointerTest2(int *p)
{
	p = &c;
}

void TwoLevelPointerTest1(int **p)
{
	*p = &b;
}

void TwoLevelPointerTest2(int **p)
{
	*p = &c;
}

int main()
{
	


	/* ����һ��ָ���������������ϵ���ָ�� */
	/* ���һ��ջ�ռ��ָ�� */
	int *ptr2 = &a;
	FirstLevelPointerTest1(ptr2);
	FirstLevelPointerTest2(ptr2);
	printf("ptr2: %d\n", *ptr2);
	//result ====> 10

	/* �������ȫ������ָ�� */
	FirstLevelPointerTest1(ptr1);
	FirstLevelPointerTest2(ptr1);
	printf("ptr1: %d\n", *ptr1);
	//result ====> 10

	/* ����: ָ������������ʵ���ϻ���ֵ���ݣ�����ָ����ȫ�ֵĻ���ջ�ռ���ڵģ�ͳͳֵ���ݡ� */
	/* ������Ҫ����һ��ָ������������������ͨ��ָ������޸ı�����ֵ�� */
	/* ��Щ����û�з�װͷ���ʹ�õ��Ƕ���ָ�����������������Ҫע������һ��ָ������������������ԭ��ʵ�֡� */


	/* ���Զ���ָ���������������ϵ���ָ�� */
	/* ���һ��ջ�ռ��ָ�� */
	int *ptr4 = NULL;
	TwoLevelPointerTest1(&ptr4);
	TwoLevelPointerTest2(&ptr4);
	printf("ptr4: %d\n", *ptr4);
	//result ====> 30

	/* �������ȫ������ָ�� */
	TwoLevelPointerTest1(&ptr3);
	TwoLevelPointerTest2(&ptr3);
	printf("ptr3: %d\n", *ptr3);
	//result ====> 30


	/*
		������
			int a = 10;
			int *ptr = &a;
		�����ýӿڣ�
			void test1(int z)
			void test2(int *ptr)
			void test3(int **ptr)
		�������
			������һ��ʵ�������洢�ռ�ı�����ͨ�����������ֿ���ʹ�ô洢�ռ䡣
			��������ʵ������ֵ���ݣ������������ַ���ݡ�ֵ�����и������ơ�
		�⣺
			�裺 a �ĵ�ַΪ0x1000��ptr�ĵ�ַΪ0x1002��
			����֪�� ����a ��Ӧ��ַ�д洢������Ϊ10�� ����ptr ��Ӧ��ַ�д洢������Ϊ ����a �ĵ�ַ��
			���� test1(a)
				ʵ������ֵ���ݣ�������a��Ӧ��ַ�д洢��ֵ���     Ҳ���ǰ� 10 ���ֵ����һ����Ρ�
			���� test2(ptr)
				ʵ������ֵ���ݣ�������ptr��Ӧ��ַ�д洢��ֵ���   Ҳ���ǰ� a�ĵ�ַ ���ֵ����һ����Ρ�
			���� test2(&a)
				ʵ������ֵ���ݣ�������a�ĵ�ַ���			      Ҳ���ǰ� a�ĵ�ַ ���ֵ����һ����Ρ�
			���� test3(&ptr)
				ʵ������ֵ���ݣ�������ptr�ĵ�ַ���				  Ҳ���ǰ� ptr�ĵ�ַ ���ֵ����һ�����

	*/

	/* ͨ��ָ���޸ı�����ֵ���ԡ� */
	/*int aaa = 1;
	int *ptrrr = &aaa;
	test(&aaa);
	printf("%d\n", *ptrrr);*/


	system("pause");
	return 0;
}