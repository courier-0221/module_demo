#include "MaxBinaryHeap.h"

//��ƪ�ĵ���ϸ�����ˣ�https://www.cnblogs.com/skywang12345/p/3610187.html
//��ƪ�ĵ���ϸ��������С�ѵ����ִ�����ʽ��https://blog.csdn.net/jymn_chen/article/details/23891287
/*
[����һ] ��������ڵ��ֵ���ǲ�����(��С��)���ӽڵ��ֵ��
[���ʶ�] ������һ����ȫ����
*/

int MaxHeapTest(void)
{
	int a[] = { 10, 40, 30, 60, 90, 70, 20, 50, 80 };
	int i, len = sizeof(a) / sizeof(*a);

	BHeap *heap = MaxHeapCreate(20);

	printf("== �������: \n");
	for (i = 0; i < len; i++)
	{
		printf("%d\t", a[i]);
		MaxHeapInsert(heap, a[i]);
	}

	printf("\n== �� �� ��: \n");
	MaxHeapPrint(heap);

	i = 85;
	MaxHeapInsert(heap, i);
	printf("\n== ���Ԫ��: %d\n", i);
	MaxHeapPrint(heap);

	i = 90;
	MaxHeapDelete(heap, i);
	printf("\n== ɾ��Ԫ��: %d\n", i);
	MaxHeapPrint(heap);


	MaxHeapDestroy(heap);

	return 0;
}


int MinHeapTest(void)
{
	int a[] = { 80, 40, 30, 60, 90, 70, 10, 50, 20 };
	int i, len = sizeof(a) / sizeof(*a);

	BHeap *heap = MaxHeapCreate(20);

	printf("== �������: \n");
	for (i = 0; i<len; i++)
	{
		printf("%d ", a[i]);
		MinHeapInsert(heap, a[i]);
	}

	printf("\n== �� С ��: ");
	MinHeapPrint(heap);

	i = 15;
	MinHeapInsert(heap, i);
	printf("\n== ���Ԫ��: %d", i);
	printf("\n== �� С ��: ");
	MinHeapPrint(heap);

	i = 10;
	MinHeapDelete(heap, i);
	printf("\n== ɾ��Ԫ��: %d", i);
	printf("\n== �� С ��: ");
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