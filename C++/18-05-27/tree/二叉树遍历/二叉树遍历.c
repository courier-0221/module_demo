#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include "SeqQueue.h"
#include "SeqStack.h"

//这篇博客详细介绍了代码思路：https://blog.csdn.net/zhangxiangDavaid/article/details/37115355

typedef struct _tar_node
{
	int data;
	struct _tar_node* lchild;
	struct _tar_node* rchild;
}BtNode;

static BtNode *BtreeMallocNode();
static void BtreeFreeNode(BtNode *tree);
BtNode *BtreePreorderingMiddleCreate(int *Preorder, int *Middle, int Len);
void BtreeDestroy(BtNode *tree);

/* 先序遍历--递归方式 */
void BtreePreordering(BtNode *tree);
/* 中序遍历--递归方式 */
void BtreeInorder(BtNode *tree);
/* 后序遍历--递归方式 */
void BtreePostorder(BtNode *tree);

/* 先序遍历--非递归方式 */
void BtreePreorderingNonRecursive(BtNode *tree);
/* 中序遍历--非递归方式 */
void BtreeInorderNonRecursive(BtNode *tree);
/* 后序遍历--非递归方式 */
/*
*后序遍历递归定义：先左子树，后右子树，再根节点。
*后序遍历的难点在于：需要判断上次访问的节点是位于左子树，还是右子树。
*若是位于左子树，则需跳过根节点，先进入右子树，再回头访问根节点；
*若是位于右子树，则直接访问根节点。
*/
void BtreePostorderNonRecursive(BtNode *tree);

/* 层次遍历 */
/* 借助队列实现 */
void BtreeLevelorderNonRecursive(BtNode* tree);


int main(void)
{
	BtNode *root = NULL;

	int Pre[7] = { 1, 2, 3, 4, 5, 6, 7 }, In[7] = { 3, 2, 4, 1, 6, 5, 7 }, Po[7] = { 3, 4, 2, 6, 7, 5, 1 };
	int len = sizeof(Pre) / sizeof(*Pre);

	root = BtreePreorderingMiddleCreate(Pre, In, len);

	/*
	printf("Preordering\n");
	BtreePreordering(root);
	printf("\n");

	printf("InOrder\n");
	BtreeInorder(root);
	printf("\n");

	printf("PostOrder\n");
	BtreePostorder(root);
	printf("\n");
	*/

	printf("Preordering\n");
	BtreePreorderingNonRecursive(root);
	printf("\n");
	
	
	printf("InOrder\n");
	BtreeInorderNonRecursive(root);
	printf("\n");


	printf("PostOrder\n");
	BtreePostorderNonRecursive(root);
	printf("\n");

	printf("LevelOrder\n");
	BtreeLevelorderNonRecursive(root);
	printf("\n");

	BtreeDestroy(root);

	system("pause");
	return 0;
}

static BtNode *BtreeMallocNode()
{
	BtNode *node = (BtNode *)malloc(sizeof(BtNode));
	if (NULL == node)
	{
		exit(1);
	}
	memset(node, 0, sizeof(BtNode));
	return node;
}

static void BtreeFreeNode(BtNode *tree)
{
	free(tree);
	tree = NULL;
}

BtNode *BtreePreorderingMiddleCreate(int *Preorder, int *Middle, int Len)
{
	BtNode* tmp = NULL;
	int index = 0;
	if (Len <= 0 || NULL == Preorder || NULL == Middle)
	{
		return NULL;
	}

	tmp = BtreeMallocNode();
	tmp->data = Preorder[0];

	for (int i = 0; i < Len; i++)
	{
		if (Middle[i] == Preorder[0])
		{
			index = i;
			break;
		}
	}

	tmp->lchild = BtreePreorderingMiddleCreate(Preorder + 1, Middle, index);
	tmp->rchild = BtreePreorderingMiddleCreate(Preorder + index + 1, Middle + index + 1, Len - index - 1);
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

void BtreeInorder(BtNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	else
	{
		BtreeInorder(tree->lchild);
		printf("%d\t", tree->data);
		BtreeInorder(tree->rchild);
	}
}

void BtreePostorder(BtNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	else
	{
		BtreePostorder(tree->lchild);
		BtreePostorder(tree->rchild);
		printf("%d\t", tree->data);
	}
}

void BtreePreorderingNonRecursive(BtNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	BtNode		*tmp	= tree;
	SeqStack	*stack	= SeqStack_Create(20);

	while ((NULL != tmp) || (0 != SeqStack_Size(stack)))
	{
		while (NULL != tmp)
		{
			printf("%d\t", tmp->data);
			SeqStack_Push(stack, tmp);
			tmp = tmp->lchild;
		}
		if (0 != SeqStack_Size(stack))
		{
			tmp = SeqStack_Pop(stack);
			tmp = tmp->rchild;
		}
	}

	SeqStack_Destroy(stack);
}

void BtreeInorderNonRecursive(BtNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	BtNode		*tmp = tree;
	SeqStack	*stack = SeqStack_Create(20);

	while ((NULL != tmp) || (0 != SeqStack_Size(stack)))
	{
		while (NULL != tmp)				/* 先把左孩子入栈，所有左孩子入栈结束 */
		{
			SeqStack_Push(stack, tmp);
			tmp = tmp->lchild;
		}
		if (0 != SeqStack_Size(stack))	/* 左孩子入栈结束，取栈顶，输出栈顶元素，遍历右孩子 */
		{
			tmp = SeqStack_Pop(stack);
			printf("%d\t", tmp->data);
			tmp = tmp->rchild;
		}
	}
	SeqStack_Destroy(stack);
}
/*
*后序遍历递归定义：先左子树，后右子树，再根节点。
*后序遍历的难点在于：需要判断上次访问的节点是位于左子树，还是右子树。
*若是位于左子树，则需跳过根节点，先进入右子树，再回头访问根节点；
*若是位于右子树，则直接访问根节点。
*/
void BtreePostorderNonRecursive(BtNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	/* pCur:当前访问节点，pLastVisit:上次访问节点 */
	BtNode		*pCur		= tree;
	BtNode		*pLastVisit	= NULL;
	SeqStack	*stack = SeqStack_Create(20);
	while ((NULL != pCur) || (0 != SeqStack_Size(stack)))
	{
		/* 把pCur移动到左子树最下边 */
		while (NULL != pCur)
		{
			SeqStack_Push(stack, pCur);
			pCur = pCur->lchild;
		}
		/* 走到这里，pCur都是空，并已经遍历到左子树底端 */
		pCur = SeqStack_Pop(stack);
		/* 一个根节点被访问的前提是：无右子树或右子树已被访问过 */
		if (NULL == pCur->rchild || pLastVisit == pCur->rchild)
		{
			printf("%d\t", pCur->data);
			/* 修改最近被访问的节点 */
			pLastVisit = pCur;
			pCur = NULL;
		}
		/*
		这里的else语句可换成带条件的else if:
		else if (pCur->lchild == pLastVisit)//若左子树刚被访问过，则需先进入右子树(根节点需再次入栈)
		因为：上面的条件没通过就一定是下面的条件满足。仔细想想！
		*/
		else
		{
			/* 根节点再次入栈 */
			SeqStack_Push(stack, pCur);
			/* 进入右子树，且可肯定右子树一定不为空 */
			pCur = pCur->rchild;
		}
	}

	SeqStack_Destroy(stack);
}


void BtreeLevelorderNonRecursive(BtNode* tree)
{
	if (tree == NULL)
	{
		return;
	}
	BtNode		*tmp	= tree;
	SeqQueue	*queue	= SeqQueue_Create(20);

	SeqQueue_Append(queue, tmp);

	while (SeqQueue_Length(queue) > 0)
	{
		tmp = SeqQueue_Retrieve(queue);
		printf("%d\t", tmp->data);
		if (NULL != tmp->lchild)
		{
			SeqQueue_Append(queue, tmp->lchild);
		}
		if (NULL != tmp->rchild)
		{
			SeqQueue_Append(queue, tmp->rchild);
		}
	}
}