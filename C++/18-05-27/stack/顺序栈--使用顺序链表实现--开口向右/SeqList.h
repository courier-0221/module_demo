#pragma once
#include <malloc.h>
#include <stdio.h>


/* 结点指针, 和处理器相关，使用和指针所占字节大小相等 */
typedef unsigned int SeqListNode;	

/* 头结点 */
typedef struct
{
	int capacity;
	int length;
	SeqListNode *node;	/* 模拟数组，空间可自由拓展 */
}SeqList;

void *SeqList_Create(int _capacity);
void SeqList_Destroy(void *_list);

int SeqList_Length(void *_list);
int SeqList_Capacity(void *_list);
int SeqList_Insert(void *_list, void *_node, int pos);
void *SeqList_Delete(void *_list, int pos);
void *SeqList_Get(void *_list, int pos);


