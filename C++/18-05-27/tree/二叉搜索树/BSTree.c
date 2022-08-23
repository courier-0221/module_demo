#include "BSTree.h"


void BSTreePreordering(BSTNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	else
	{
		printf("%d\t", tree->data);
		BSTreePreordering(tree->lchild);
		BSTreePreordering(tree->rchild);
	}
}


BSTree* BSTreeCreate()
{
	BSTree* ret = (BSTree*)malloc(sizeof(BSTree));

	if (ret != NULL)
	{
		ret->count = 0;
		ret->root = NULL;
	}

	return ret;
}

void BSTreeDestroy(BSTree* tree) 
{
	free(tree);
	tree = NULL;
}

void BSTreeClear(BSTree* tree)
{
	if (NULL != tree)
	{
		tree->count = 0;
		tree->root = NULL;
	}
}

static int InsertRecursion(BSTNode* root, BSTNode* node, BSTreeCompare* compare)
{
	int ret = 1;
	int CompareValue = compare(node->data, root->data);
	if (0 == CompareValue)
	{
		ret = 0;
	}
	else if (0 > CompareValue)
	{
		if (NULL != root->lchild)
		{
			ret = InsertRecursion(root->lchild, node, compare);
		}
		else
		{
			/* 指定关系 */
			root->lchild = node;
		}
	}
	else if (0 < CompareValue)
	{
		if (NULL != root->rchild)
		{
			ret = InsertRecursion(root->rchild, node, compare);
		}
		else
		{
			/* 指定关系 */
			root->rchild = node;
		}
	}
	return ret;
}

int BSTreeInsert(BSTree* tree, BSTNode* node, BSTreeCompare* compare)
{
	int ret = (tree != NULL) && (node != NULL) && (compare != NULL);

	if (0 == ret)
	{
		return ret;
	}

	node->lchild = NULL;
	node->rchild = NULL;

	if (tree->root == NULL)
	{
		tree->root = node;
	}
	else
	{
		ret = InsertRecursion(tree->root, node, compare);
	}

	tree->count++;

	return ret;
}

static BSTNode* DeleteNode(BSTNode** pRoot)
{
	BSTNode* ret = *pRoot;

	if ((*pRoot)->rchild == NULL)
	{
		*pRoot = (*pRoot)->lchild;
	}
	else if ((*pRoot)->lchild == NULL)
	{
		*pRoot = (*pRoot)->rchild;
	}
	else
	{
		BSTNode* g = *pRoot;
		BSTNode* c = (*pRoot)->lchild;

		while (c->rchild != NULL)
		{
			g = c;
			c = c->rchild;
		}

		if (g != *pRoot)
		{
			g->rchild = c->lchild;
		}
		else
		{
			g->lchild = c->lchild;
		}

		c->lchild = (*pRoot)->lchild;
		c->rchild = (*pRoot)->rchild;

		*pRoot = c;
	}

	return ret;
}
static BSTNode* DeleteRecursion(BSTNode** pRoot, void* key, BSTreeCompare* compare)
{
	BSTNode* ret = NULL;

	if ((pRoot == NULL) && (*pRoot == NULL))
	{
		return ret;
	}
	else
	{
		int CompareValue = compare(key, (*pRoot)->data);

		if (CompareValue == 0)
		{
			ret = DeleteNode(pRoot);
		}
		else if (CompareValue < 0)
		{
			ret = DeleteRecursion(&((*pRoot)->lchild), key, compare);
		}
		else if (CompareValue > 0)
		{
			ret = DeleteRecursion(&((*pRoot)->rchild), key, compare);
		}
	}

	return ret;
}

BSTNode* BSTreeDelete(BSTree* tree, void* key, BSTreeCompare* compare)
{
	BSTree* btree = (BSTree*)tree;
	BSTNode* ret = NULL;

	if ((btree == NULL) && (key == NULL) && (compare == NULL))
	{
		return ret;
	}
	ret = DeleteRecursion(&btree->root, key, compare);

	if (ret != NULL)
	{
		btree->count--;
	}
	return ret;
}

static BSTNode* GetRecursive(BSTNode* root, void* key, BSTreeCompare* compare)
{
	BSTNode* ret = NULL;

	if (root == NULL)
	{
		return ret;
	}
	else
	{
		int CompareValue = compare(key, root->data);

		if (CompareValue == 0)
		{
			ret = root;
		}
		else if (CompareValue < 0)
		{
			ret = GetRecursive(root->lchild, key, compare);
		}
		else if (CompareValue > 0)
		{
			ret = GetRecursive(root->rchild, key, compare);
		}
	}

	return ret;
}

BSTNode* BSTreeGet(BSTree* tree, void* key, BSTreeCompare* compare)
{
	BSTNode* ret = NULL;

	if ((tree != NULL) && (key != NULL) && (compare != NULL))
	{
		ret = GetRecursive(tree->root, key, compare);
	}

	return ret;
}

BSTNode* BSTreeRoot(BSTree* tree)
{
	BSTNode* ret = NULL;
	if (tree != NULL)
	{
		ret = tree->root;
	}
	return ret;
}

static int HeightRecursion(BSTNode *tree)
{
	int LeftCount = 0;
	int RightCount = 0;
	if (NULL == tree)
	{
		return 0;
	}
	else
	{
		LeftCount = HeightRecursion(tree->lchild);
		RightCount = HeightRecursion(tree->rchild);
		return (((LeftCount > RightCount) ? LeftCount : RightCount) + 1);
	}
}
int BSTreeHeight(BSTree* tree)
{
	if (NULL == tree)
	{
		return 0;
	}
	else
	{
		return HeightRecursion(tree->root);
	}
}

int BSTreeCount(BSTree* tree)
{
	int ret = 0;
	if (tree != NULL)
	{
		ret = tree->count;
	}
	return ret;
}


static void DisplayRecursive(BSTNode* node, BSTreePrintf* pFunc, int format, int gap, char div) // O(n)
{
	int i = 0;

	if ((node != NULL) && (pFunc != NULL))
	{
		for (i = 0; i<format; i++)
		{
			printf("%c", div);
		}

		pFunc(node);

		printf("\n");

		if ((node->lchild != NULL) || (node->rchild != NULL))
		{
			DisplayRecursive(node->lchild, pFunc, format + gap, gap, div);
			DisplayRecursive(node->rchild, pFunc, format + gap, gap, div);
		}
	}
	else
	{
		for (i = 0; i<format; i++)
		{
			printf("%c", div);
		}
		printf("\n");
	}
}

void BSTreeDisplay(BSTree* tree, BSTreePrintf* pFunc, int gap, char div)
{
	if (tree != NULL)
	{
		DisplayRecursive(tree->root, pFunc, 0, gap, div);
	}
}


BSTNode* BSTreeMaxNum(BSTree *tree)
{
	BSTNode* btree = (BSTNode*)tree->root;
	if (btree == NULL)
	{
		return NULL;
	}
		
	while (btree->rchild != NULL)
	{
		btree = btree->rchild;
	}

	return btree;
}

BSTNode* BSTreeMinNum(BSTree *tree)
{
	BSTNode* btree = (BSTNode*)tree->root;
	if (btree == NULL)
	{
		return NULL;
	}

	while (btree->lchild != NULL)
	{
		btree = btree->lchild;
	}

	return btree;
}