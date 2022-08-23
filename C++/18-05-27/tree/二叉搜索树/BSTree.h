#ifndef __BSTREE_H_
#define __BSTREE_H_

#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>

typedef struct _tar_node
{
	char data;
	struct _tar_node* lchild;
	struct _tar_node* rchild;
}BSTNode;

 typedef struct _tag_BSTree
{
	int count;
	BSTNode* root;
 }BSTree;


void BSTreePreordering(BSTNode *tree);



typedef void (BSTreePrintf)(BSTNode*);
typedef int (BSTreeCompare)(void*, void*);

BSTree* BSTreeCreate();
void BSTreeDestroy(BSTree* tree);
void BSTreeClear(BSTree* tree);

int BSTreeInsert(BSTree* tree, BSTNode* node, BSTreeCompare* compare);
BSTNode* BSTreeDelete(BSTree* tree, void* key, BSTreeCompare* compare);
BSTNode* BSTreeGet(BSTree* tree, void* key, BSTreeCompare* compare);
BSTNode* BSTreeRoot(BSTree* tree);
int BSTreeHeight(BSTree* tree);
int BSTreeCount(BSTree* tree);
void BSTreeDisplay(BSTree* tree, BSTreePrintf* pFunc, int gap, char div);

BSTNode* BSTreeMaxNum(BSTree *tree);
BSTNode* BSTreeMinNum(BSTree *tree);

#endif