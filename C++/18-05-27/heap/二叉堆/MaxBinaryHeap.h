#ifndef __MAXBINARYHEAP_H_
#define __MAXBINARYHEAP_H_

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
void *MaxHeapCreate(int capacity);

/* ���ٶ� */
void MaxHeapDestroy(BHeap* heap);

/* ȡ�Ѷ�Ԫ�� */
int MaxHeapRoot(BHeap* heap);

/* ����в���һ����Ԫ�� */
int MaxHeapInsert(BHeap* heap, int value);

/* �Ӷ���ɾ��Ԫ�� */
int MaxHeapDelete(BHeap* heap, int value);

/* ������ */
int HeapSort();

void MaxHeapPrint(BHeap* heap);

#endif