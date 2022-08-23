#ifndef __MINBINARYHEAP_H_
#define __MINBINARYHEAP_H_

#include <stdio.h>
#include <malloc.h>

/* 结点指针, 和处理器相关，使用和指针所占字节大小相等 */
typedef unsigned int BHNode;

/* 头结点 */
typedef struct
{
	int capacity;
	int length;
	BHNode *node;	/* 模拟数组，空间可自由拓展 */
}BHeap;

/* 建立堆 */
void *MinHeapCreate(int capacity);

/* 销毁堆 */
void MinHeapDestroy(BHeap* heap);

/* 取堆顶元素 */
int MinHeapRoot(BHeap* heap);

/* 向堆中插入一个新元素 */
int MinHeapInsert(BHeap* heap, int value);

/* 从堆中删除元素 */
int MinHeapDelete(BHeap* heap, int value);

void MinHeapPrint(BHeap* heap);

#endif