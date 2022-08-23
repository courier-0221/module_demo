#include "LinkStack.h"

void *LinkStack_Create(void)
{
	LinkStack *stack = (LinkStack*)malloc(sizeof(LinkStack));
	if (stack == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		return NULL;
	}
	stack->length = 0;
	stack->pTop = NULL;
	stack->pBottom = NULL;
	return stack;
}

void LinkStack_Destroy(LinkStack *_stack)
{
	free(_stack);
	_stack = NULL;
}

int LinkStack_Size(void *_stack)
{
	LinkStack *stack = (LinkStack *)_stack;
	if (_stack == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		return -1;
	}

	if (stack->pTop == NULL)
	{
		printf("¿ÕÕ»\n");
		return 0;
	}

	return stack->length;
}

int LinkStack_Push(void *_stack, LinkStackNode* item)
{
	int ret = (_stack != NULL) && (item != NULL);
	LinkStack *stack = (LinkStack*)_stack;
	if (!ret)
	{
		printf("An error in %s\n", __FUNCTION__);
		return ret;
	}

	if (stack->length == 0)
	{
		stack->pTop = item;
		stack->pBottom = item;
		stack->pBottom->pNext = NULL;
	}
	else
	{
		item->pNext = stack->pTop;
		stack->pTop = item;
	}

	stack->length++;
	return ret;
}

void *LinkStack_Pop(void *_stack)
{
	LinkStackNode *ret = NULL;
	LinkStack *stack = (LinkStack*)_stack;
	if (stack == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		return NULL;
	}
	ret = stack->pTop;
	stack->pTop = ret->pNext;
	stack->length--;

	if (stack->length == 0)
	{
		stack->pTop = NULL;
		stack->pBottom = NULL;
	}

	return ret;
}

void *LinkStack_Top(void *_stack)
{
	LinkStack *stack = (LinkStack*)_stack;
	if (stack == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		return NULL;
	}
	LinkStackNode *ret = stack->pTop;

	return ret;
}