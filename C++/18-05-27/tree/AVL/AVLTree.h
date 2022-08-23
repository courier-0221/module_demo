#ifndef __AVLTREE_H_
#define __AVLTREE_H_

#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>



typedef struct _tar_node
{
	int data;
	int height;
	struct _tar_node* lchild;
	struct _tar_node* rchild;
}AVLTNode;

/*
typedef struct _tag_AVLTree
{
	int count;
	AVLTNode** root;
}AVLTree;
*/

#define MAX(a, b)    ( (a) > (b) ? (a) : (b) )
#define HEIGHT(p)    ( (p==NULL) ? 0 : (((AVLTNode *)(p))->height) )

void AVLTreePreordering(AVLTNode *tree);


AVLTNode* AVLTreeLeftLeftRotate(AVLTNode *k2);
AVLTNode* AVLTreeRightRightRotate(AVLTNode *k1);
AVLTNode* AVLTreeLeftRightRotate(AVLTNode *node);
AVLTNode* AVLTreeRightLeftRotate(AVLTNode *node);




int AVLTreeInsert(AVLTNode* tree, AVLTNode* node);






#endif