#pragma once
#include "LinkList.h"


typedef struct _tar_LinkQueuenode LinkQueueNode;
struct _tar_LinkQueuenode
{
	LinkListNode header;
	void *item;
};

void* LinkQueue_Create(void);
void LinkQueue_Destroy(void *_queue);
int LinkQueue_Clear(void *_queue);

int LinkQueue_Length(void *_queue);
int LinkQueue_Append(void *_queue, void* item);
void *LinkQueue_Retrieve(void *_queue);
void *LinkQueue_Header(void *_queue);