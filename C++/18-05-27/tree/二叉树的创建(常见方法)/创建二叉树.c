#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <malloc.h>

/*
���ַ���
	1.ǰ�򴴽�
		2�ַ�ʽ�����õ��� # �ű�ʾ����ABDH#K###E##CFI###G#J##������ͨ�������������߷���ֵ���ء�
	2.��ǰ������򴴽�������
	3.������ͺ��򴴽�������
*/

/*
scanf�÷���scanf��ʹ��%c������
��scanf��������ǰ���հ׷��и����⣬��������%c��ʱ�򣬾Ͱѻ������ĵ�һ���ַ����ػ�ȥ��������ʲô��
�հ׷����հ׷���ָ�ո�����Ʊ�����س�����
���Խ���İ취��ˢ�»�������
//fflush(stdin);//��һ�ַ���ˢ�����뻺����
while ((ch = getchar()) != '\n')//�ڶ��ַ���
{
;
}
https://blog.csdn.net/weiweicsdn1/article/details/52185453
*/


typedef struct _tar_node
{
	char data;
	struct _tar_node* lchild;
	struct _tar_node* rchild;
}BtNode;

static BtNode *BtreeMallocNode();
static void BtreeFreeNode(BtNode *tree);

void BtreePreordering(BtNode *tree);
void BtreeDestroy(BtNode *tree);

/* ����һ����ʽһ ͨ����ν�����õ�������*/
void BtreePreorderingCreate_1(BtNode **tree);
/* ����һ����ʽ�� ͨ����������ֵ������õ�������*/
BtNode *BtreePreorderingCreate_2(void);
/* ����һ����ʽ�� ͨ����ν�����õ�������,Ҫ�������ͨ���ڶ�����������*/
void BtreePreorderingCreate_3(BtNode **tree, char *str);

/* �������� ͨ����ν�����õ�������,Ҫ�������ͨ���ڶ�����������*/
BtNode *BtreePreorderingMiddleCreate(int *Preorder, int *Middle, int Len);

/* �������� ͨ����ν�����õ�������,Ҫ�������ͨ���ڶ�����������*/
BtNode *BtreeMiddlePostCreate(int *Middle, int *Post, int Len);


/*
DEMO
int a = 10;
test(++a);
test(a++);
void test(int a)
{
	printf("%d\n", a);
}
*/

int main(void)
{
	BtNode *root = NULL;
	//char *ShapeOfTree = "AB##C##";
	//BtreePreorderingCreate_1(&root);
	//root = BtreePreorderingCreate_2();
	//BtreePreorderingCreate_3(&root, &ShapeOfTree);
	//BtreePreorderingCreate_3(&root, ShapeOfTree);
	int Pre[7] = { 1, 2, 3, 4, 5, 6, 7 }, In[7] = { 3, 2, 4, 1, 6, 5, 7 }, Po[7] = { 3, 4, 2, 6, 7, 5, 1 };
	int len = sizeof(Pre) / sizeof(*Pre);

	root = BtreePreorderingMiddleCreate(Pre, In, len);
	//root = BtreeMiddlePostCreate(In, Po, len);

	BtreePreordering(root);
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

/* ����һ����ʽһ ͨ����ν�����õ�������*/
void BtreePreorderingCreate_1(BtNode **tree)
{
	char ch;
	fflush(stdin);
	scanf_s("%c", &ch);
	if (NULL == tree || '#' == ch)
	{
		return;
	}
	else
	{
		*tree = BtreeMallocNode();
		(*tree)->data = ch;
		BtreePreorderingCreate_1(&(*tree)->lchild);
		BtreePreorderingCreate_1(&(*tree)->rchild);
	}
}

/* ����һ����ʽ�� ͨ����������ֵ������õ�������*/
BtNode *BtreePreorderingCreate_2(void)
{
	char data;
	fflush(stdin);
	scanf_s("%c", &data);

	BtNode *node = NULL;
	if ('#' == data)
	{
		return node;
	}
	else
	{
		node = BtreeMallocNode();
		node->data = data;
		node->lchild = BtreePreorderingCreate_2();
		node->rchild = BtreePreorderingCreate_2();
	}
	return node;
}

/* ����һ����ʽ�� ͨ����ν�����õ�������,Ҫ�������ͨ���ڶ�����������*/
/*
void BtreePreorderingCreate_3(BtNode **tree, char **str)
{

	if (NULL == tree || '#' == **str || NULL == str || NULL == *str)
	{
		return;
	}
	else
	{
		*tree = BtreeMallocNode();
		(*tree)->data = **str;
		BtreePreorderingCreate_3(&(*tree)->lchild, &(++*str));
		//tmp = (++(*str));
		BtreePreorderingCreate_3(&(*tree)->rchild, ++*str);
	}
}
*/

/* �������� ͨ����ν�����õ�������,Ҫ�������ͨ���ڶ�����������*/
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

/* �������� ͨ����ν�����õ�������,Ҫ�������ͨ���ڶ�����������*/
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
