#pragma once  

#include <stdio.h>
#include <stdlib.h>

//循环使用队列中的空间

typedef unsigned int SeqQueueNode;	//结点指针

typedef struct
{
	int capacity;
	int length;
	int front;
	int rear;
	SeqQueueNode *queue;
}SeqQueue;


void* SeqQueue_Create(int capacity);
void SeqQueue_Destroy(void *_queue);

int SeqQueue_IfEmpty(void *_queue);
int SeqQueue_IfFull(void *_queue);

int SeqQueue_Length(void *_queue);
int SeqQueue_Capacity(void *_queue);
int SeqQueue_Append(void *_queue, void *item);
void* SeqQueue_Retrieve(void *_queue);
void* SeqQueue_Header(void* _queue);
