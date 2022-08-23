#ifndef _SeqStack_H_
#define _SeqStack_H_

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef unsigned int SeqStackNode;		

typedef struct
{
	int capacity;
	int length;
	int pTop;
	int pBottom;
	SeqStackNode *node;
}SeqStack;

void *SeqStack_Create(int capacity);
void SeqStack_Destroy(void *_stack);

int SeqStack_Size(void *_stack);
int SeqStack_Push(void *_stack, void *_node);
void *SeqStack_Pop(void *_stack);
void *SeqStack_Top(void *_stack);

#endif