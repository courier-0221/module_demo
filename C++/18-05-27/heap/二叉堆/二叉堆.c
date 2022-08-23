#include "MaxBinaryHeap.h"

//这篇文档详细介绍了：https://www.cnblogs.com/skywang12345/p/3610187.html
//这篇文档详细介绍了最小堆的两种创建方式：https://blog.csdn.net/jymn_chen/article/details/23891287
/*
[性质一] 堆中任意节点的值总是不大于(不小于)其子节点的值；
[性质二] 堆总是一棵完全树。
*/

int MaxHeapTest(void)
{
	int a[] = { 10, 40, 30, 60, 90, 70, 20, 50, 80 };
	int i, len = sizeof(a) / sizeof(*a);

	BHeap *heap = MaxHeapCreate(20);

	printf("== 依次添加: \n");
	for (i = 0; i < len; i++)
	{
		printf("%d\t", a[i]);
		MaxHeapInsert(heap, a[i]);
	}

	printf("\n== 最 大 堆: \n");
	MaxHeapPrint(heap);

	i = 85;
	MaxHeapInsert(heap, i);
	printf("\n== 添加元素: %d\n", i);
	MaxHeapPrint(heap);

	i = 90;
	MaxHeapDelete(heap, i);
	printf("\n== 删除元素: %d\n", i);
	MaxHeapPrint(heap);


	MaxHeapDestroy(heap);

	return 0;
}


int MinHeapTest(void)
{
	int a[] = { 80, 40, 30, 60, 90, 70, 10, 50, 20 };
	int i, len = sizeof(a) / sizeof(*a);

	BHeap *heap = MaxHeapCreate(20);

	printf("== 依次添加: \n");
	for (i = 0; i<len; i++)
	{
		printf("%d ", a[i]);
		MinHeapInsert(heap, a[i]);
	}

	printf("\n== 最 小 堆: ");
	MinHeapPrint(heap);

	i = 15;
	MinHeapInsert(heap, i);
	printf("\n== 添加元素: %d", i);
	printf("\n== 最 小 堆: ");
	MinHeapPrint(heap);

	i = 10;
	MinHeapDelete(heap, i);
	printf("\n== 删除元素: %d", i);
	printf("\n== 最 小 堆: ");
	MinHeapPrint(heap);


	MaxHeapDestroy(heap);

	return 0;
}

int main(void)
{
	//MaxHeapTest();
	MinHeapTest();
	system("pause");
	return 0;
}