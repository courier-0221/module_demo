#include "SeqStack.h"

void *SeqStack_Create(int capacity)
{
	return SeqList_Create(capacity);
}

void SeqStack_Destroy(void *_stack)
{
	SeqList_Destroy(_stack);
}

int SeqStack_Push(void *_stack, void *item)
{
	return SeqList_Insert(_stack, item, SeqList_Length(_stack));
}

void *SeqStack_Pop(void *_stack)
{
	return SeqList_Delete(_stack, SeqList_Length(_stack) - 1);
}

void *SeqStack_Top(void *_stack)
{
	return SeqList_Get(_stack, SeqList_Length(_stack) - 1);
}

int SeqStack_Size(void *_stack)
{
	return SeqList_Length(_stack);
}

int SeqStack_Capacity(void *_stack)
{
	return SeqList_Capacity(_stack);
}
