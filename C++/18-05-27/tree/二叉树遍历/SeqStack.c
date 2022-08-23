#include "SeqStack.h"

void *SeqStack_Create(int capacity)
{
	SeqStack *stack = NULL;
	if (capacity <= 0)
	{
		printf("An error in %s\n", __FUNCTION__);
		return NULL;
	}
	stack = (SeqStack*)malloc(sizeof(SeqStack)+sizeof(SeqStackNode)* capacity);
	if (stack == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		return NULL;
	}

	stack->capacity = capacity;
	stack->length = 0;
	stack->pBottom = 0;
	stack->pTop = 0;
	stack->node = (SeqStackNode*)(stack + 1);
	return stack;
}
void SeqStack_Destroy(void *_stack)
{
	free(_stack);
	_stack = NULL;
}


int SeqStack_Size(void *_stack)
{
	int ret = _stack != NULL;
	SeqStack *stack = (SeqStack*)_stack;
	if (!ret)
	{
		printf("An error in %s\n", __FUNCTION__);
		return -1;
	}

	ret = stack->length;
	return ret;
}
int SeqStack_Push(void *_stack, void *_node)
{
	SeqStack *stack = (SeqStack*)_stack;
	int ret = (_stack != NULL) && (_node != NULL);
	
	if (!ret)
	{
		printf("An error in %s\n", __FUNCTION__);
		return ret;
	}

	if (SeqStack_Size(_stack) == stack->capacity)
	{
		printf("stack is full");
		return ret;
	}
	//	sstack->node[++sstack->pTop] = val;	//3
	stack->pTop++;						//1
	stack->node[stack->pTop] = _node;	//2		1和2等价于注释掉的3
	stack->length++;

	return ret;
}
void *SeqStack_Pop(void *_stack)
{
	void *ret = NULL;
	SeqStack *stack = (SeqStack*)_stack;
	if (!stack)
	{
		printf("An error in %s\n", __FUNCTION__);
		return NULL;
	}
	ret = stack->node[stack->pTop--];
	//ret = sstack->node[sstack->pTop];
	//sstack->pTop--;

	stack->length--;
	return ret;
}

void *SeqStack_Top(void *_stack)
{
	void *ret = NULL;
	SeqStack *stack = (SeqStack*)_stack;
	if (!stack)
	{
		printf("An error in %s\n", __FUNCTION__);
		return NULL;
	}
	ret = stack->node[stack->pTop];

	return ret;
}



