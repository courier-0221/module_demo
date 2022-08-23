#include "MinBinaryHeap.h"

/* 建立堆 */
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

/* 销毁堆 */
void MinHeapDestroy(BHeap* heap)
{
	free(heap);
	heap = NULL;
}

/* 取堆顶元素 */
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
* 最小堆的向上调整算法(从start开始向上直到0，调整堆)
*
* 注：数组实现的堆中，第N个节点的左孩子的索引值是(2N+1)，右孩子的索引是(2N+2)，父节点的索引是(N-1)/2。
*
* 参数说明：
*     start -- 被上调节点的起始位置(一般为数组中最后一个元素的索引)
*/
static void MinHeap_FilterUp(BHeap* heap, int start)
{
	int current		= start;					// 当前节点(current)的位置
	int parent		= (current - 1) / 2;        // 父(parent)结点的位置 
	int tmp			= heap->node[current];      // 当前节点(current)的大小

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

/* 向堆中插入一个新元素 */
int MinHeapInsert(BHeap* heap, int value)
{
	/* 如果"堆"已满，则返回 */
	if (heap->length == heap->capacity || NULL == heap)
	{
		return -1;
	}

	heap->node[heap->length] = value;			/* 将"数组"插在表尾 */
	MinHeap_FilterUp(heap, heap->length);		/* 向上调整堆 */
	heap->length++;								/* 堆的实际容量+1 */
	return 0;
}

/*
* 最小堆的向下调整算法
*
* 注：数组实现的堆中，第N个节点的左孩子的索引值是(2N+1)，右孩子的索引是(2N+2)。
*
* 参数说明：
*     start -- 被下调节点的起始位置(一般为0，表示从第1个开始)
*     end   -- 截至范围(一般为数组中最后一个元素的索引)
*/
static void MinHeap_FilterDown(BHeap* heap, int start, int end)
{
	int current = start;						// 当前节点(current)的位置
	int child = current * 2 + 1;				// 左孩子结点的位置 
	int tmp = heap->node[current];			// 当前节点(current)的大小

	while (child < end)
	{
		/*  "child"是左孩子，"child+1"是右孩子 */
		if (heap->node[child] > heap->node[child + 1])
		{
			child++;			/* 左右两孩子中选择较小者，即node[l+1] */
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
/* 从堆中删除元素 */
int MinHeapDelete(BHeap* heap, int value)
{
	/* 如果"堆"已空，则返回-1 */
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
	MinHeap_FilterDown(heap, index, length - 1);			/* 向下调整堆 */
	heap->length--;								/* 堆的实际容量-1 */
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