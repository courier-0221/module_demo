#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


/* 链表结点 */
typedef struct _tag_CircleListNode CircleListNode;
struct _tag_CircleListNode
{
	CircleListNode* next;
};

/* 头结点 */
typedef struct			
{
	CircleListNode header;
	CircleListNode *slider;
	int length;
}CircleList;

/* 业务结点 */
typedef struct			
{
	CircleListNode node;
	char name[10];
	int age;
	int sex;
}student;


void *CircleList_Create(void);
void CircleList_Destroy(void *_list);

void CircleList_Insert(void *_list, CircleListNode *_node,int pos);
void *CircleList_Get(void *_list, int pos);
int CircleList_Length(void *_list);
void *CircleList_Delete(void *_list, int pos);
void CircleList_Transf(void *_list);

//游标操作定义
void *slider_reset(void *_list);
void *slider_next(void *_list);
void *slider_current(void *_list);
void *slider_delete(void *_list, CircleListNode *_node);