#pragma once
#include <malloc.h>
#include <stdio.h>


/* ���ָ��, �ʹ�������أ�ʹ�ú�ָ����ռ�ֽڴ�С��� */
typedef unsigned int SeqListNode;	

/* ͷ��� */
typedef struct
{
	int capacity;
	int length;
	SeqListNode *node;	/* ģ�����飬�ռ��������չ */
}SeqList;

void *SeqList_Create(int _capacity);
void SeqList_Destroy(void *_list);

int SeqList_Length(void *_list);
int SeqList_Capacity(void *_list);
int SeqList_Insert(void *_list, void *_node, int pos);
void *SeqList_Delete(void *_list, int pos);
void *SeqList_Get(void *_list, int pos);


