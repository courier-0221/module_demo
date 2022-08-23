#ifndef __BINARYTREE_H_
#define __BINARYTREE_H_

#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>

typedef struct _tar_node
{
	char data;
	struct _tar_node* lchild;
	struct _tar_node* rchild;
}BtNode;

BtNode *BtreeMallocNode();
void BtreeFreeNode(BtNode *tree);

void BtreePreordering(BtNode *tree);
BtNode *BtreeMiddlePostCreate(int *Middle, int *Post, int Len);
void BtreeDestroy(BtNode *tree);

/* ͳ�ƶ������н��ĸ��� */
int BtreeNodeCount(BtNode *tree);

/* �������������� */
int BtreeHeight(BtNode *tree);

/* ͳ�ƶ�������Ҷ������ */
void BtreeLeafCount(BtNode *tree, int *num);

/* ���������� */
/* �������½����� */
BtNode *BtreeCopyTree(BtNode *tree);

/* ���������� */
/* �������Ͻ����� */
BtNode *BtreeCopyTree2(BtNode *tree);

/* ����������д�ÿ��Ҷ�ӽ�㵽������·�� */
void BtreePrintAllPath(BtNode *tree, int *path, int pathlen);

/* ����������ÿ���������Ӻ��Һ��� */
/* �������²��� */
void BtreeExchangeNode(BtNode *tree);


#endif