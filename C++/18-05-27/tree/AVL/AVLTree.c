#include "AVLTree.h"





AVLTNode* AVLTreeLeftLeftRotate(AVLTNode *k2)
{
	if (NULL == k2)
	{
		return NULL;
	}

	AVLTNode *k1 = k2->lchild;
	k2->lchild = k1->rchild;
	k1->rchild = k2;

	/* 更新height。 */
	k2->height = MAX(HEIGHT(k2->lchild), HEIGHT(k2->rchild)) + 1;
	k1->height = MAX(HEIGHT(k1->lchild), k2->height) + 1;

	return k1;
}


AVLTNode* AVLTreeRightRightRotate(AVLTNode *k1)
{
	if (NULL == k1)
	{
		return NULL;
	}

	AVLTNode *k2 = k1->rchild;
	k1->rchild = k2->lchild;
	k2->lchild = k1;

	/* 更新height。 */
	k1->height = MAX(HEIGHT(k1->lchild), HEIGHT(k1->rchild)) + 1;
	k2->height = MAX(HEIGHT(k2->rchild), k1->height) + 1;

	return k1;
}

/*
	先进行RR旋转，在进行LL旋转
*/
AVLTNode* AVLTreeLeftRightRotate(AVLTNode *node)
{
	if (NULL == node)
	{
		return NULL;
	}

	node->lchild = AVLTreeRightRightRotate(node->lchild);

	return AVLTreeLeftLeftRotate(node);
}

/*
	先进行LL旋转，在进行RR旋转
*/
AVLTNode* AVLTreeRightLeftRotate(AVLTNode *node)
{
	if (NULL == node)
	{
		return NULL;
	}
	
	node->rchild = AVLTreeLeftLeftRotate(node->rchild);

	return AVLTreeRightRightRotate(node);
}


int AVLTreeHeight(AVLTNode* tree)
{
	return HEIGHT(tree);
}

int AVLTreeInsert(AVLTNode* tree, AVLTNode* node)
{
	if (NULL == tree)
	{
		tree = node;
	}
	else if (tree->data > node->data)		/* 插入到左子树 */
	{
		tree->lchild = AVLTreeInsert(tree->lchild, node);
		/* 插入节点后，若AVL树失去平衡，则进行相应的调节。 */
		if ((HEIGHT(tree->lchild) - HEIGHT(tree->rchild)) == 2)
		{
			/* 进一步判断是左左型还是左右型 */
			if (node->data < tree->lchild->data)
			{
				tree = AVLTreeLeftLeftRotate(tree);
			}
			else
			{
				tree = AVLTreeLeftRightRotate(tree);
			}
		}
	}
	else if (tree->data < node->data)		/* 插入到右子树 */
	{
		tree->rchild = AVLTreeInsert(tree->rchild, node);
		/* 插入节点后，若AVL树失去平衡，则进行相应的调节。 */
		if ((HEIGHT(tree->rchild) - HEIGHT(tree->lchild)) == 2)
		{
			/* 进一步判断是左左型还是左右型 */
			if (node->data > tree->rchild->data)
			{
				tree = AVLTreeRightRightRotate(tree);
			}
			else 
			{
				tree = AVLTreeRightLeftRotate(tree);
			}
		}
	}
	else if (tree->data == node->data)
	{
		printf("添加失败：不允许添加相同的节点！\n");
	}


	/* 给定树的高度。 */
	tree->height = MAX(HEIGHT(tree->lchild), HEIGHT(tree->rchild)) + 1;
	return tree;
}


AVLTNode* AVLTreeSearch(AVLTNode* tree, int key)
{
	if ((NULL == tree) || (tree->data == key))
	{
		return tree;
	}
	
	if (tree->data < key)
	{
		AVLTreeSearch(tree->rchild, key);
	}
	else if (tree->data > key)
	{
		AVLTreeSearch(tree->lchild, key);
	}
}

AVLTNode* AVLTreeSearchNonRecursion(AVLTNode* tree, int key)
{
	while ((NULL != tree) && (tree->data != key))
	{
		if (tree->data < key)
		{
			tree = tree->rchild;
		}
		else if (tree->data > key)
		{
			tree = tree->lchild;
		}
	}
	return tree;
}

AVLTNode* AVLTreeMaxTreeNode(AVLTNode* tree)
{
	if (NULL == tree)
	{
		return NULL;
	}

	while (NULL != tree->rchild)
	{
		tree = tree->rchild;
	}

	return tree;
}

AVLTNode* AVLTreeMinTreeNode(AVLTNode* tree)
{
	if (NULL == tree)
	{
		return NULL;
	}

	while (NULL != tree->lchild)
	{
		tree = tree->lchild;
	}

	return tree;
}

AVLTNode* AVLTreeSearchDeleteRecursion(AVLTNode* tree, AVLTNode* node)
{
	if ((NULL == tree) || (NULL == node))
	{
		return NULL;
	}

	if (tree->data == node->data)
	{
		/* 如果左右孩子都不为空 */
		if ((NULL != tree->lchild) && (NULL != tree->rchild))
		{
			if (HEIGHT(tree->lchild) > HEIGHT(tree->rchild))
			{
				// 如果tree的左子树比右子树高；
				// 则(01)找出tree的左子树中的最大节点
				//   (02)将该最大节点的值赋值给tree。
				//   (03)删除该最大节点。
				// 这类似于用"tree的左子树中最大节点"做"tree"的替身；
				// 采用这种方式的好处是：删除"tree的左子树中最大节点"之后，AVL树仍然是平衡的。
				AVLTNode *max = AVLTreeMaxTreeNode(tree->lchild);
				tree->data = max->data;
				tree->lchild = AVLTreeSearchDeleteRecursion(tree->lchild, max);
			}
			else
			{
				// 如果tree的左子树不比右子树高(即它们相等，或右子树比左子树高1)
				// 则(01)找出tree的右子树中的最小节点
				//   (02)将该最小节点的值赋值给tree。
				//   (03)删除该最小节点。
				// 这类似于用"tree的右子树中最小节点"做"tree"的替身；
				// 采用这种方式的好处是：删除"tree的右子树中最小节点"之后，AVL树仍然是平衡的。
				AVLTNode *min = AVLTreeMinTreeNode(tree->rchild);
				tree->data = min->data;
				tree->rchild = AVLTreeSearchDeleteRecursion(tree->rchild, min);
			}
		}
		else
		{
			return tree->lchild ? tree->lchild : tree->rchild;
		}
		
	}
	else if (tree->data > node->data)
	{
		tree->lchild = AVLTreeSearchDeleteRecursion(tree->lchild, node);
		/* 删除节点后，若AVL树失去平衡，则进行相应的调节。 */
		if (HEIGHT(tree->rchild) - HEIGHT(tree->lchild) == 2)
		{
			AVLTNode *r = tree->rchild;
			if (HEIGHT(r->lchild) > HEIGHT(r->rchild))
			{
				tree = AVLTreeRightLeftRotate(tree);
			}
			else
			{
				tree = AVLTreeRightRightRotate(tree);
			}
		}
	}
	else if (tree->data < node->data)
	{
		tree->rchild = AVLTreeSearchDeleteRecursion(tree->rchild, node);
		/* 删除结束，继续判断树是否还保持平衡。 */
		if (HEIGHT(tree->lchild) - HEIGHT(tree->rchild) == 2)
		{
			AVLTNode *l = tree->lchild;
			if (HEIGHT(l->rchild) > HEIGHT(l->lchild))
			{
				tree = AVLTreeLeftRightRotate(tree);
			}
			else
			{
				tree = AVLTreeLeftLeftRotate(tree);
			}
		}
	}
}

AVLTNode* AVLTreeSearchDelete(AVLTNode* tree, int key)
{
	if (NULL == tree)
	{
		return NULL;
	}

	AVLTNode *node = AVLTreeSearch(tree, key);
	AVLTreeSearchDeleteRecursion(tree, node);
}
