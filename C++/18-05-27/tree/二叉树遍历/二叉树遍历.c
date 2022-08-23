#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include "SeqQueue.h"
#include "SeqStack.h"

//��ƪ������ϸ�����˴���˼·��https://blog.csdn.net/zhangxiangDavaid/article/details/37115355

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

/* �������--�ݹ鷽ʽ */
void BtreePreordering(BtNode *tree);
/* �������--�ݹ鷽ʽ */
void BtreeInorder(BtNode *tree);
/* �������--�ݹ鷽ʽ */
void BtreePostorder(BtNode *tree);

/* �������--�ǵݹ鷽ʽ */
void BtreePreorderingNonRecursive(BtNode *tree);
/* �������--�ǵݹ鷽ʽ */
void BtreeInorderNonRecursive(BtNode *tree);
/* �������--�ǵݹ鷽ʽ */
/*
*��������ݹ鶨�壺���������������������ٸ��ڵ㡣
*����������ѵ����ڣ���Ҫ�ж��ϴη��ʵĽڵ���λ����������������������
*����λ���������������������ڵ㣬�Ƚ������������ٻ�ͷ���ʸ��ڵ㣻
*����λ������������ֱ�ӷ��ʸ��ڵ㡣
*/
void BtreePostorderNonRecursive(BtNode *tree);

/* ��α��� */
/* ��������ʵ�� */
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
		while (NULL != tmp)				/* �Ȱ�������ջ������������ջ���� */
		{
			SeqStack_Push(stack, tmp);
			tmp = tmp->lchild;
		}
		if (0 != SeqStack_Size(stack))	/* ������ջ������ȡջ�������ջ��Ԫ�أ������Һ��� */
		{
			tmp = SeqStack_Pop(stack);
			printf("%d\t", tmp->data);
			tmp = tmp->rchild;
		}
	}
	SeqStack_Destroy(stack);
}
/*
*��������ݹ鶨�壺���������������������ٸ��ڵ㡣
*����������ѵ����ڣ���Ҫ�ж��ϴη��ʵĽڵ���λ����������������������
*����λ���������������������ڵ㣬�Ƚ������������ٻ�ͷ���ʸ��ڵ㣻
*����λ������������ֱ�ӷ��ʸ��ڵ㡣
*/
void BtreePostorderNonRecursive(BtNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	/* pCur:��ǰ���ʽڵ㣬pLastVisit:�ϴη��ʽڵ� */
	BtNode		*pCur		= tree;
	BtNode		*pLastVisit	= NULL;
	SeqStack	*stack = SeqStack_Create(20);
	while ((NULL != pCur) || (0 != SeqStack_Size(stack)))
	{
		/* ��pCur�ƶ������������±� */
		while (NULL != pCur)
		{
			SeqStack_Push(stack, pCur);
			pCur = pCur->lchild;
		}
		/* �ߵ����pCur���ǿգ����Ѿ��������������׶� */
		pCur = SeqStack_Pop(stack);
		/* һ�����ڵ㱻���ʵ�ǰ���ǣ������������������ѱ����ʹ� */
		if (NULL == pCur->rchild || pLastVisit == pCur->rchild)
		{
			printf("%d\t", pCur->data);
			/* �޸���������ʵĽڵ� */
			pLastVisit = pCur;
			pCur = NULL;
		}
		/*
		�����else���ɻ��ɴ�������else if:
		else if (pCur->lchild == pLastVisit)//���������ձ����ʹ��������Ƚ���������(���ڵ����ٴ���ջ)
		��Ϊ�����������ûͨ����һ����������������㡣��ϸ���룡
		*/
		else
		{
			/* ���ڵ��ٴ���ջ */
			SeqStack_Push(stack, pCur);
			/* �������������ҿɿ϶�������һ����Ϊ�� */
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