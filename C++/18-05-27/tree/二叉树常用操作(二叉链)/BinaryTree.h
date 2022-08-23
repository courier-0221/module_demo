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

/* 统计二叉树中结点的个数 */
int BtreeNodeCount(BtNode *tree);

/* 计算二叉树的深度 */
int BtreeHeight(BtNode *tree);

/* 统计二叉树的叶结点个数 */
void BtreeLeafCount(BtNode *tree, int *num);

/* 拷贝二叉树 */
/* 从上至下建立树 */
BtNode *BtreeCopyTree(BtNode *tree);

/* 拷贝二叉树 */
/* 从下至上建立树 */
BtNode *BtreeCopyTree2(BtNode *tree);

/* 输出二叉树中从每个叶子结点到根结点的路径 */
void BtreePrintAllPath(BtNode *tree, int *path, int pathlen);

/* 交换二叉树每个结点的左孩子和右孩子 */
/* 从上至下操作 */
void BtreeExchangeNode(BtNode *tree);


#endif