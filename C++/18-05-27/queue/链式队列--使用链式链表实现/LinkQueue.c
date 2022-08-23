#include "LinkQueue.h"

void* LinkQueue_Create(void)
{
	return LinkList_Create();
}
void LinkQueue_Destroy(void *_queue)
{
	LinkQueue_Clear(_queue);
	LinkList_Destroy(_queue);
}

int LinkQueue_Length(void *_queue)
{
	return LinkList_Length(_queue);
}

int LinkQueue_Append(void *_queue, void* item)
{
	LinkQueueNode *node = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	int ret = (node != NULL) && (_queue != NULL) && (item != NULL);
	if (!ret)
	{
		printf("An error in %s\n", __FUNCTION__);
		return ret;
	}

	node->item = item;
	ret = LinkList_Insert(_queue, LinkList_Length(_queue), (LinkQueueNode*)node);
	if (!ret)
	{
		free(node);
		node = NULL;
	}

	return ret;
}

void *LinkQueue_Retrieve(void *_queue)
{
	LinkQueueNode *node = (LinkQueueNode*)LinkList_Delete(_queue, 0);
	if (!node)
	{
		printf("An error in %s\n", __FUNCTION__);
		return NULL;
	}
	void *ret = node->item;
	free(node);
	node = NULL;

	return ret;
}
void *LinkQueue_Header(void *_queue)
{
	LinkQueueNode *node = (LinkQueueNode*)LinkList_Get(_queue, 0);
	if (!node)
	{
		printf("An error in %s\n", __FUNCTION__);
		return NULL;
	}

	return node->item;
}

int LinkQueue_Clear(void *_queue)
{
	while (LinkQueue_Length(_queue) > 0)
	{
		LinkQueue_Retrieve(_queue);
	}
}