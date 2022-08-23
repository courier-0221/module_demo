#include "LinkQueue.h"


void *LinkQueue_Create(void)
{
	LinkQueue *queue = (LinkQueue*)malloc(sizeof(LinkQueue));
	if (queue == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		return NULL;
	}

	queue->front = NULL;
	queue->rear = NULL;
	queue->length = 0;
	return queue;
}

void LinkQueue_Destroy(void *_queue)
{
	free(_queue);
	_queue = NULL;
}

int LinkQueue_IfEmpty(void *_queue)
{
	if (_queue == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		return 0;
	}
	LinkQueue *queue = (LinkQueue *)_queue;
	return (queue->front == NULL) && (queue->rear == NULL);
//	return (queue->front == NULL) && (queue->length == 0);
}

int LinkQueue_Length(void *_queue)
{
	if (_queue == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		return -1;
	}
	LinkQueue *queue = (LinkQueue *)_queue;
	return queue->length;
}

void* LinkQueue_Header(void* _queue)
{
	if (_queue == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		return NULL;
	}
	LinkQueue *queue = (LinkQueue *)_queue;
	return queue->front;
}

int LinkQueue_Append(void *_queue, LinkQueueNode* item)
{
	int ret = (item != NULL) && (_queue != NULL);
	if (!ret)
	{
		printf("An error in %s\n", __FUNCTION__);
	}
	
	LinkQueue *queue = (LinkQueue *)_queue;
	if (queue->length == 0)
	{
		queue->front = item;
		queue->rear = item;
	}
	else
	{
		queue->rear->next = item;
		queue->rear = item;
	}

	queue->length++;
	return ret;
}

void* LinkQueue_Retrieve(void *_queue)
{
	if (_queue == NULL){
		printf("An error in %s\n", __FUNCTION__);
		return NULL;
	}
	if (LinkQueue_IfEmpty(_queue))
	{
		return NULL;
	}

	LinkQueue *queue = (LinkQueue *)_queue;

	LinkQueueNode *ret = queue->front;
	queue->front = ret->next;

	queue->length--;

	if (queue->length == 0)
	{
		queue->front = NULL;
		queue->rear = NULL;
	}
	return ret;
}


