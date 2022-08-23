#pragma once
#include "SeqList.h"

void* SeqQueue_Create(int capacity);
void SeqQueue_Destroy(void *_queue);

int SeqQueue_Length(void *_queue);
int SeqQueue_Capacity(void *_queue);
int SeqQueue_Append(void *_queue, void* item);
void *SeqQueue_Retrieve(void *_queue);
void *SeqQueue_Header(void *_queue);