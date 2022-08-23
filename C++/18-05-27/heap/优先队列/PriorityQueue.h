#ifndef __PRIORITYQUEUE_H_
#define __PRIORITYQUEUE_H_

#include "MinBinaryHeap.h"


void *PriorityQueueCreate(int capacity);
void PriorityQueueDestroy(void* queue);
int PriorityQueueAppend(void* queue, int value);
int PriorityQueueRetrieve(void* queue);
void PriorityQueuePrint(void* queue);

#endif