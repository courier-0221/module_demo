#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


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

int main03() {
	//int N, K, max, min;
	//scanf("%d %d", &N, &K);

	//int array[1024] = {0}, tmp;
	//for (int i = 0; i<N; i++){
	//	scanf("%d", &tmp);
	//	array[i] = tmp;
	//}

	//for (int i = 0; i<N; i++){
	//	if ((array[i] - array[i + 1])>K){
	//		array[i] -= K;
	//	}
	//	else{
	//		array[i] += K;
	//	}
	//}

	//max = array[0]; min = array[0];
	//for (int i = 0; i < N; i++){
	//	if (array[i] > max){
	//		max = array[i];
	//	}
	//	if (array[i] < min){
	//		min = array[i];
	//	}
	//}
	//for (int i = 0; i < N; i++){ printf("%d\t", array[i]); }
	//printf("%d\n", max - min);

	//int a[3][4] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	//printf("%d\n", *(&a[1][1]));
	//printf("%d\n", *(*(a + 1) + 1));
	//printf("%d\n", (*(a + 1))[1]);
	//printf("%d\n", *(a[1] + 1));


	//printf("%d\n", *(a + 1)[1]);
	//printf("%d\n", *(a + 5));	//等价于	printf("%d\n", a[5]);


	//int(*p)[4] = a;
	//printf("%d\n", p[1][1]);
	//printf("%d\n", *(*(p + 1) + 1));
	//printf("%d\n", (*(p + 1))[1]);
	//printf("%d\n", *(p[1] + 1));

	//unsigned long long ret = 0;
	//ret = get_squr(1 << 20);
	//printf("%llx\n", ret);

	//int array[][4] = { 0, 0 };
	//printf("%d\n", sizeof(array) / sizeof(*array));

	//int int_1_ = 0;

	//float a = 9.7;
	//printf("%d\n", (int)a);

	//char buf[256] = {0};
	//sprintf(buf + sprintf(buf, "%s", "abc%d"), "%s", "efg%%d");
	////sprintf(buf, "%s", "abc%d");
	////printf("%s\n", buf);

	//printf(buf, 300);
	////printf("%s\n", buf);

	//char c = 'a';
	//if ('a' < c <= 'z')
	//	printf("Low");
	//else 
	//	printf("UP");

	//int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//if (find(array, 0, 10, 8) >= 0)
	//	printf("find\n");
	//else
	//	printf("no find \n");

	//int array[] = { 21, 25, 49, 25, 16, 8 };
	//int len = sizeof(array) / sizeof(*array);
	//sort(array, 0, len - 1);

	//for (int i = 0; i < len; i++){
	//	printf("%d\t", array[i]);
	//}



	//printf("%d\n", duiqi1(0));

	//char buf[] = "1234567";
	//printf("%s\n", reverse_str(buf));

	/*char line[128] = { 0 };
	scanf("%s", line);
	printf("%s\n", line);*/


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
	//result ====> 10

	/* 情况二：全局区的指针 */
	TwoLevelPointerTest1(&ptr3);
	TwoLevelPointerTest2(&ptr3);
	printf("ptr3: %d\n", *ptr3);
	//result ====> 10


	/* 
		结论：
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


#define STRUCT(type) typedef struct _tar_##type type;\
struct _tar_##type

STRUCT(linklistnode)	//链表结点	不可能包含的了全世界
{
	int data;
	linklistnode *next;
};

STRUCT(student)	//业务结点		
{
	linklistnode header;	//让全世界来包含他
	int age;
	char name[10];
	int sex;
};

STRUCT(linklist)	//头结点
{
	linklistnode *head;
	int length;
};

void insert(linklist *ll, int data)
{
	linklistnode node;
	node.data = data;
	node.next = ll->head;

	ll->head = &node;
}

void display(linklist *ll)
{
	linklistnode *tmp = NULL;
	for (tmp = ll->head; tmp != NULL; tmp = tmp->next)
	{
		printf("%d\t", tmp->data);
	}
	printf("\n");
}

int main()
{
	linklist ll = { NULL, 0 };

	insert(&ll, 11);
	insert(&ll, 22);
	insert(&ll, 33);

	display(&ll);

	system("pause");
	return 0;
}