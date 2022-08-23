#pragma once
#include "linklist.h"



typedef struct _tag_LinkStackNode
{
	struct LinkStackNode *pNext;
	void *item;		//这里接收用户自定义的业务结点的地址，然后把插入到malloc的LinkStacknode结点地址插入进链表里面
}LinkStackNode;

void *LinkStack_Create();
void LinkStack_Destroy(void *_stack);
int LinkStack_Push(void *_stack, void *item);
void *LinkStack_Pop(void *_stack);
void *LinkStack_Top(void *_stack);
int LinkStack_Size(void *_stack);
void LinkStack_Clear(void *_stack);
