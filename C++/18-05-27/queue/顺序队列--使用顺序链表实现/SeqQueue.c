#include "SeqQueue.h"

void* SeqQueue_Create(int capacity)
{
	return SeqList_Create(capacity);
}
void SeqQueue_Destroy(void *_queue)
{
	SeqList_Destroy(_queue);
}

int SeqQueue_Length(void *_queue)
{
	return SeqList_Length(_queue);
}

int SeqQueue_Capacity(void *_queue)
{
	return SeqList_Capacity(_queue);
}

int SeqQueue_Append(void *_queue, void* item)
{
	return SeqList_Insert(_queue, item, SeqList_Length(_queue));
}
void *SeqQueue_Retrieve(void *_queue)
{
	return SeqList_Delete(_queue, 0);
}

void *SeqQueue_Header(void *_queue)
{
	return SeqList_Get(_queue, 0);
}
