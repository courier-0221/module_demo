#pragma once
#include <stdio.h>
#include <malloc.h>

/* 链表结点	不可能包含的了全世界 */
typedef struct _tar_LinkListnode LinkListNode;
struct _tar_LinkListnode
{
	LinkListNode *next;
};

/* 头结点 */
typedef struct 
{
	LinkListNode header;
	int length;
}LinkList;

void *LinkList_Create(void);
void LinkList_Destroy(void *_list);

int LinkList_Insert(void *_list, int pos, LinkListNode *st);
int linklilst_BackInsert(void *_list, LinkListNode *st);
int LinkList_FrintInsert(void *_list, LinkListNode *st);


LinkListNode *LinkList_Delete(void *_list, int pos);
LinkListNode *LinkList_BackDelete(void *_list);
LinkListNode *LinkList_FrontDelete(void *_list);

LinkListNode *LinkList_Get(void *_list, int pos);

int LinkList_Length(void *_list);

void LinkList_Reverse(void *_list);


