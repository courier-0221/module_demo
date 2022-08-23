#include "LinkStack.h"


void *LinkStack_Create()
{
	return LinkList_Create();
}

void LinkStack_Destroy(void *_stack)
{
	LinkStack_Clear(_stack);
	LinkList_Destroy(_stack);
}

int LinkStack_Push(void *_stack, void *item)
{
	LinkStackNode *node = (LinkStackNode*)malloc(sizeof(LinkStackNode));
	int ret = (node != NULL) && (_stack != NULL) && (item != NULL);
	if (!ret)
	{
		printf("An error in %s\n", __FUNCTION__);
		return ret;
	}

	node->item = item;
	ret = LinkList_Insert(_stack, 0, (LinkListNode*)node);
	if (!ret)
	{
		free(node);
		node = NULL;
	}

	return ret;
}
void *LinkStack_Pop(void *_stack)
{
	LinkStackNode *node = (LinkStackNode*)LinkList_Delete(_stack, 0);
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
void *LinkStack_Top(void *_stack)
{
	LinkStackNode *node = (LinkStackNode*)LinkList_Get(_stack, 0);
	if (!node)
	{
		printf("An error in %s\n", __FUNCTION__);
		return NULL;
	}

	return node->item;
}
int LinkStack_Size(void *_stack)
{
	return LinkList_Length(_stack);
}

void LinkStack_Clear(void *_stack)
{
	while (LinkStack_Size(_stack) > 0)
	{
		LinkStack_Pop(_stack);
	}
}