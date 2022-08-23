#include "SeqQueue.h"


void* SeqQueue_Create(int capacity) // O(1)
{
	if (capacity < 0)
	{
		printf("capacity < 0");
		return NULL;
	}
	SeqQueue *queue = (SeqQueue*)malloc(sizeof(SeqQueue)+sizeof(SeqQueueNode)* capacity);
	if (queue == NULL)
	{
		printf("malloc error\n");
		return NULL;
	}

	queue->capacity = capacity;
	queue->length = 0;
	queue->front = 0;
	queue->rear = 0;
	queue->queue = (SeqQueueNode*)(queue + 1);

	return queue;
}

void SeqQueue_Destroy(void *_queue)
{
	free(_queue);
	_queue = NULL;
}

int SeqQueue_IfEmpty(void *_queue)
{
	if (_queue == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		return -1;
	}
	SeqQueue *queue = (SeqQueue*)_queue;
	return (queue->front == queue->rear) && (queue->length == 0);
}
int SeqQueue_IfFull(void *_queue)
{
	if (_queue == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		return -1;
	}
	SeqQueue *queue = (SeqQueue*)_queue;
	return (queue->front == queue->rear) && (queue->length == queue->capacity);
}

int SeqQueue_Length(void *_queue)
{
	if (_queue == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		return -1;
	}
	SeqQueue *queue = (SeqQueue*)_queue;
	return queue->length;
}

int SeqQueue_Capacity(void *_queue)
{
	if (_queue == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		return -1;
	}
	SeqQueue *queue = (SeqQueue*)_queue;
	return queue->capacity;
}

void* SeqQueue_Header(void* _queue)
{
	if (_queue == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		return -1;
	}
	SeqQueue *queue = (SeqQueue*)_queue;
	void *ret = (void*)(queue->queue[queue->front]);

	return ret;
}

int SeqQueue_Append(void *_queue, void *item)
{
	int ret = (_queue != NULL) && (SeqQueue_IfFull(_queue) != 1) && (item != NULL);
	if (!ret)
	{
		printf("An error in %s\n", __FUNCTION__);
		return ret;
	}

	SeqQueue *queue = (SeqQueue*)_queue;

	queue->queue[queue->rear] = item;
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->length++;

	return ret;
}

void* SeqQueue_Retrieve(void *_queue)
{
	if ((_queue == NULL) || (SeqQueue_IfEmpty(_queue) == 1))
	{
		printf("An error in %s\n", __FUNCTION__);
		return NULL;
	}
	void* ret = SeqQueue_Header(_queue);

	SeqQueue *queue = (SeqQueue*)_queue;
	queue->front = (queue->front + 1) % queue->capacity;
	queue->length--;

	return ret;
}

