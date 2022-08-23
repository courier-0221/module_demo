#pragma once
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>



typedef struct _tag_DLinkListNode
{
	struct _tag_DLinkListNode *next;
	struct _tag_DLinkListNode *pre;
}DLinkListNode;


typedef struct
{
	DLinkListNode header;
	DLinkListNode *slider;
	int length;
}DLinkList;

typedef struct
{
	DLinkListNode node;
	char name[10];
	int age;
	int sex;
}student;

void *DLinkList_Create(void);
void DLinkList_Destroy(void *_list);
int DLinkList_Length(void *_list);

void DLinkList_Insert(void *_list, DLinkListNode *_node, int pos);
void *DLinkList_Get(void *_list, int  pos);
void *DLinkList_Delete(void *_list, int  pos);

/*  游标相关操作  */
void *slider_reset(void *_list);
void *slider_current(void *_list);
void *slider_next(void *_list);
void *slider_pre(void *_list);
void *slider_delete(void *_list, DLinkListNode *_node);


