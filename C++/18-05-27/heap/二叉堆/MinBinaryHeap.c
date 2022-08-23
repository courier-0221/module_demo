#include "MinBinaryHeap.h"

/* ������ */
void *MinHeapCreate(int capacity)
{
	BHeap *heap = (BHeap*)malloc(sizeof(BHeap)+sizeof(BHNode)* capacity);
	if (NULL == heap)
	{
		printf("malloc error \n");
		return NULL;
	}
	heap->capacity = capacity;
	heap->length = 0;
	heap->node = (BHNode *)(heap + 1);
	return heap;
}

/* ���ٶ� */
void MinHeapDestroy(BHeap* heap)
{
	free(heap);
	heap = NULL;
}

/* ȡ�Ѷ�Ԫ�� */
int MinHeapRoot(BHeap* heap)
{
	if (NULL == heap)
	{
		printf("An error in %s\n", __FUNCTION__);
		return -1;
	}
	return heap->node[0];
}

/*
* ��С�ѵ����ϵ����㷨(��start��ʼ����ֱ��0��������)
*
* ע������ʵ�ֵĶ��У���N���ڵ�����ӵ�����ֵ��(2N+1)���Һ��ӵ�������(2N+2)�����ڵ��������(N-1)/2��
*
* ����˵����
*     start -- ���ϵ��ڵ����ʼλ��(һ��Ϊ���������һ��Ԫ�ص�����)
*/
static void MinHeap_FilterUp(BHeap* heap, int start)
{
	int current		= start;					// ��ǰ�ڵ�(current)��λ��
	int parent		= (current - 1) / 2;        // ��(parent)����λ�� 
	int tmp			= heap->node[current];      // ��ǰ�ڵ�(current)�Ĵ�С

	while (current > 0)
	{
		if (heap->node[parent] <= tmp)
		{
			break;
		}
		else
		{
			heap->node[current] = heap->node[parent];
			current = parent;
			parent = (parent - 1) / 2;
		}
	}
	heap->node[current] = tmp;
}

/* ����в���һ����Ԫ�� */
int MinHeapInsert(BHeap* heap, int value)
{
	/* ���"��"�������򷵻� */
	if (heap->length == heap->capacity || NULL == heap)
	{
		return -1;
	}

	heap->node[heap->length] = value;			/* ��"����"���ڱ�β */
	MinHeap_FilterUp(heap, heap->length);		/* ���ϵ����� */
	heap->length++;								/* �ѵ�ʵ������+1 */
	return 0;
}

/*
* ��С�ѵ����µ����㷨
*
* ע������ʵ�ֵĶ��У���N���ڵ�����ӵ�����ֵ��(2N+1)���Һ��ӵ�������(2N+2)��
*
* ����˵����
*     start -- ���µ��ڵ����ʼλ��(һ��Ϊ0����ʾ�ӵ�1����ʼ)
*     end   -- ������Χ(һ��Ϊ���������һ��Ԫ�ص�����)
*/
static void MinHeap_FilterDown(BHeap* heap, int start, int end)
{
	int current = start;						// ��ǰ�ڵ�(current)��λ��
	int child = current * 2 + 1;				// ���ӽ���λ�� 
	int tmp = heap->node[current];			// ��ǰ�ڵ�(current)�Ĵ�С

	while (child < end)
	{
		/*  "child"�����ӣ�"child+1"���Һ��� */
		if (heap->node[child] > heap->node[child + 1])
		{
			child++;			/* ������������ѡ���С�ߣ���node[l+1] */
		}
		if (tmp < heap->node[child])
		{
			break;
		}
		else
		{
			heap->node[current] = heap->node[child];
			current = child;
			child = child * 2 + 1;
		}

	}
	heap->node[current] = tmp;
}
/* �Ӷ���ɾ��Ԫ�� */
int MinHeapDelete(BHeap* heap, int value)
{
	/* ���"��"�ѿգ��򷵻�-1 */
	if (NULL == heap || heap->length == 0)
	{
		return -1;
	}

	int tmp = heap->node[heap->length];
	int index = 0;
	int length = heap->length;
	for (index = 0; index < heap->length; index++)
	{
		if (value == heap->node[index])
		{
			break;
		}
	}
	heap->node[index] = heap->node[--length];
	MinHeap_FilterDown(heap, index, length - 1);			/* ���µ����� */
	heap->length--;								/* �ѵ�ʵ������-1 */
	return 0;
}

void MinHeapPrint(BHeap* heap)
{
	int i;
	for (i = 0; i < heap->length; i++)
	{
		printf("%d\t", heap->node[i]);
	}
	printf("\n");
}