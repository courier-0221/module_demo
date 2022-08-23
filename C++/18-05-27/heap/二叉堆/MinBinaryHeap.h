#ifndef __MINBINARYHEAP_H_
#define __MINBINARYHEAP_H_

#include <stdio.h>
#include <malloc.h>

/* ���ָ��, �ʹ�������أ�ʹ�ú�ָ����ռ�ֽڴ�С��� */
typedef unsigned int BHNode;

/* ͷ��� */
typedef struct
{
	int capacity;
	int length;
	BHNode *node;	/* ģ�����飬�ռ��������չ */
}BHeap;

/* ������ */
void *MinHeapCreate(int capacity);

/* ���ٶ� */
void MinHeapDestroy(BHeap* heap);

/* ȡ�Ѷ�Ԫ�� */
int MinHeapRoot(BHeap* heap);

/* ����в���һ����Ԫ�� */
int MinHeapInsert(BHeap* heap, int value);

/* �Ӷ���ɾ��Ԫ�� */
int MinHeapDelete(BHeap* heap, int value);

void MinHeapPrint(BHeap* heap);

#endif