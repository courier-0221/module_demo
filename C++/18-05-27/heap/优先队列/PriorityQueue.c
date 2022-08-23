#include "PriorityQueue.h"

void *PriorityQueueCreate(int capacity)
{
	return MinHeapCreate(capacity);
}
void PriorityQueueDestroy(void* queue)
{
	MinHeapDestroy(queue);
}
int PriorityQueueAppend(void* queue, int value)
{
	return MinHeapInsert(queue, value);
}
int PriorityQueueRetrieve(void* queue)
{
	int value = ((BHeap*)queue)->node[0];
	return MinHeapDelete(queue, value);
}
void PriorityQueuePrint(void* queue)
{
	MinHeapPrint(queue);
}