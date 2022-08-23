#pragma once
#include "SeqList.h"


void *SeqStack_Create(int capacity);
void SeqStack_Destroy(void *_stack);
int SeqStack_Push(void *_stack, void *item);
void *SeqStack_Pop(void *_stack);
void *SeqStack_Top(void *_stack);
int SeqStack_Size(void *_stack);
int SeqStack_Capacity(void *_stack);