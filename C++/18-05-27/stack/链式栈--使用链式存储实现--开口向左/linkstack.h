#pragma once
#include "linklist.h"



typedef struct _tag_LinkStackNode
{
	struct LinkStackNode *pNext;
	void *item;		//��������û��Զ����ҵ����ĵ�ַ��Ȼ��Ѳ��뵽malloc��LinkStacknode����ַ�������������
}LinkStackNode;

void *LinkStack_Create();
void LinkStack_Destroy(void *_stack);
int LinkStack_Push(void *_stack, void *item);
void *LinkStack_Pop(void *_stack);
void *LinkStack_Top(void *_stack);
int LinkStack_Size(void *_stack);
void LinkStack_Clear(void *_stack);
