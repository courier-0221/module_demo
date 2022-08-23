#include "BinaryTree.h"


void BtreePreordering(BtNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	else
	{
		printf("%d\t", tree->data);
		BtreePreordering(tree->lchild);
		BtreePreordering(tree->rchild);
	}
}


BtNode *BtreeMiddlePostCreate(int *Middle, int *Post, int Len)
{
	BtNode* tmp = NULL;
	int index = 0;
	if (Len <= 0 || NULL == Middle || NULL == Post)
	{
		return NULL;
	}

	tmp = BtreeMallocNode();
	tmp->data = Post[Len - 1];

	for (int i = 0; i < Len; i++)
	{
		if (Middle[i] == Post[Len - 1])
		{
			index = i;
			break;
		}
	}

	tmp->lchild = BtreeMiddlePostCreate(Middle, Post, index);
	tmp->rchild = BtreeMiddlePostCreate(Middle + index + 1, Post + index, Len - index - 1);
	return tmp;
}

void BtreeDestroy(BtNode *tree)
{
	if (NULL == tree)
	{
		return;
	}
	else
	{
		BtreeDestroy(tree->lchild);
		BtreeDestroy(tree->rchild);
		BtreeFreeNode(tree);
	}
}

BtNode *BtreeMallocNode()
{
	BtNode *node = (BtNode *)malloc(sizeof(BtNode));
	if (NULL == node)
	{
		exit(1);
	}
	memset(node, 0, sizeof(BtNode));
	return node;
}

void BtreeFreeNode(BtNode *tree)
{
	free(tree);
	tree = NULL;
}

/* 统计二叉树中结点的个数 */
int BtreeNodeCount(BtNode *tree)
{
	int LeftCount = 0;
	int RightCount = 0;
	if (NULL == tree)
	{
		return 0;
	}
	else
	{
		LeftCount = BtreeNodeCount(tree->lchild);
		RightCount = BtreeNodeCount(tree->rchild);
		return LeftCount + RightCount + 1;
	}
}

int BtreeHeight(BtNode *tree)
{
	int LeftHeight = 0;
	int RightHeight = 0;
	if (NULL == tree)
	{
		return 0;
	}
	else
	{
		LeftHeight = BtreeHeight(tree->lchild);
		RightHeight = BtreeHeight(tree->rchild);
		return (((LeftHeight > RightHeight) ? LeftHeight : RightHeight) + 1);
	}
}

/* 统计二叉树的叶结点个数 */
void BtreeLeafCount(BtNode *tree, int *num)
{
	if (NULL == tree || num == NULL)
	{
		return;
	}
	else
	{
		if (NULL == tree->lchild && NULL == tree->rchild)
		{
			(*num)++;
		}
		BtreeLeafCount(tree->lchild, num);
		BtreeLeafCount(tree->rchild, num);
	}
}

/* 拷贝二叉树 */
/* 从上至下建立树 */
BtNode *BtreeCopyTree(BtNode *tree)
{
	if (NULL == tree)
	{
		return NULL;
	}
	else
	{
		BtNode *node = BtreeMallocNode();
		//memcpy(node, tree, sizeof(BtNode));	//这里不要左右孩子域
		node->data = tree->data;
		/* 建立关系 */
		node->lchild = BtreeCopyTree(tree->lchild);
		node->rchild = BtreeCopyTree(tree->rchild);
		return node;
	}
}

/* 拷贝二叉树 */
/* 从下至上建立树 */
BtNode *BtreeCopyTree2(BtNode *tree)
{
	BtNode *newnode		= NULL;
	BtNode *newlp		= NULL;
	BtNode *newrp		= NULL;
	if (NULL == tree)
	{
		return NULL;
	}
	else
	{
		newlp = BtreeCopyTree2(tree->lchild);
		newrp = BtreeCopyTree2(tree->rchild);

		newnode = BtreeMallocNode();
		//建立关系
		newnode->lchild = newlp;
		newnode->rchild = newrp;
		newnode->data = tree->data;
		return newnode;
	}
}

/* 输出二叉树中从每个叶子结点到根结点的路径 */
void BtreePrintAllPath(BtNode *tree, int *path, int pathlen)
{
	if (NULL == tree || NULL == path )
	{
		return NULL;
	}
	else
	{
		int i = 0;
		path[pathlen] = tree->data;
		if ((NULL == tree->lchild) && (NULL == tree->rchild))
		{
			for (i = pathlen; i >= 0; i--)
			{
				printf("%d\t", path[i]);
			}
			printf("\n");
		}
		BtreePrintAllPath(tree->lchild, path, pathlen + 1);
		BtreePrintAllPath(tree->rchild, path, pathlen + 1);
	}
}

/* 交换二叉树每个结点的左孩子和右孩子 */
/* 从上至下操作 */
void BtreeExchangeNode(BtNode *tree)
{
	if (NULL == tree)
	{
		return NULL;
	}
	else
	{
		BtNode *tmp = tree->lchild;
		tree->lchild = tree->rchild;
		tree->rchild = tmp;

		BtreeExchangeNode(tree->lchild);
		BtreeExchangeNode(tree->rchild);
	}
}
