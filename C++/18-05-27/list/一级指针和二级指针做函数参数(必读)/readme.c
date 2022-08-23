#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


//说明：有些链表并没有定义好的头结点，这会常可以看到使用二级指针做插入函数参数，而有头结点的话插入时使用一级指针做函数参数，
//为了搞清楚一级指针和二级指针做形参有什么区别，下面用代码解释+证明


/* 测试一级指针做函数参数不断调整指向 */
/* 测试二级指针做函数参数不断调整指向 */
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
	


	/* 测试一级指针做函数参数不断调整指向 */
	/* 情况一：栈空间的指针 */
	int *ptr2 = &a;
	FirstLevelPointerTest1(ptr2);
	FirstLevelPointerTest2(ptr2);
	printf("ptr2: %d\n", *ptr2);
	//result ====> 10

	/* 情况二：全局区的指针 */
	FirstLevelPointerTest1(ptr1);
	FirstLevelPointerTest2(ptr1);
	printf("ptr1: %d\n", *ptr1);
	//result ====> 10

	/* 结论: 指针做函数参数实际上还是值传递，无论指针是全局的还是栈空间存在的，统统值传递。 */
	/* 链表主要考察一级指针做函数参数，还有通过指针可以修改变量的值。 */
	/* 有些链表没有封装头结点使用的是二级指针做函数参数，这会要注意理解和一级指针做函数参数的区别及原理实现。 */


	/* 测试二级指针做函数参数不断调整指向 */
	/* 情况一：栈空间的指针 */
	int *ptr4 = NULL;
	TwoLevelPointerTest1(&ptr4);
	TwoLevelPointerTest2(&ptr4);
	printf("ptr4: %d\n", *ptr4);
	//result ====> 30

	/* 情况二：全局区的指针 */
	TwoLevelPointerTest1(&ptr3);
	TwoLevelPointerTest2(&ptr3);
	printf("ptr3: %d\n", *ptr3);
	//result ====> 30


	/*
		场景：
			int a = 10;
			int *ptr = &a;
		待调用接口：
			void test1(int z)
			void test2(int *ptr)
			void test3(int **ptr)
		基础概念：
			变量是一段实际连续存储空间的别名，通过变量的名字可以使用存储空间。
			函数参数实际上是值传递，数组除外它是址传递。值传递有副本机制。
		解：
			设： a 的地址为0x1000，ptr的地址为0x1002。
			可以知道 变量a 对应地址中存储的数据为10， 变量ptr 对应地址中存储的数据为 变量a 的地址。
			调用 test1(a)
				实际上是值传递，将变量a对应地址中存储的值入参     也就是把 10 这个值复制一份入参。
			调用 test2(ptr)
				实际上是值传递，将变量ptr对应地址中存储的值入参   也就是把 a的地址 这个值复制一份入参。
			调用 test2(&a)
				实际上是值传递，将变量a的地址入参			      也就是把 a的地址 这个值复制一份入参。
			调用 test3(&ptr)
				实际上是值传递，将变量ptr的地址入参				  也就是把 ptr的地址 这个值复制一份入参

	*/

	/* 通过指针修改变量的值测试。 */
	/*int aaa = 1;
	int *ptrrr = &aaa;
	test(&aaa);
	printf("%d\n", *ptrrr);*/


	system("pause");
	return 0;
}