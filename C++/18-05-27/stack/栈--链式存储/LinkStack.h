#ifndef _LinkStack_H_
#define _LinkStack_H_

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct _tag_LinkStackNode
{
	struct LinkStackNode *pNext;
}LinkStackNode;

typedef struct
{
	int length;
	LinkStackNode* pTop;
	LinkStackNode* pBottom;
}LinkStack;

void *LinkStack_Create(void);
void LinkStack_Destroy(void *_stack);

int LinkStack_Size(void *_stack);
int LinkStack_Push(void *_stack, LinkStackNode *item);
void *LinkStack_Pop(void *_stack);
void *LinkStack_Top(void *_stack);






#endif