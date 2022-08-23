#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct _tar_LinkQueueNode LinkQueueNode;
struct _tar_LinkQueueNode
{
	LinkQueueNode *next;
};

typedef struct
{
	int length;
	LinkQueueNode *front;
	LinkQueueNode *rear;
}LinkQueue;


void *LinkQueue_Create(void);
void LinkQueue_Destroy(void *_queue);

void* LinkQueue_Header(void* _queue);
int LinkQueue_Length(void *_queue);
int LinkQueue_Append(void *_queue, LinkQueueNode* item);
void* LinkQueue_Retrieve(void *_queue);

int LinkQueue_IfEmpty(void *_queue);
