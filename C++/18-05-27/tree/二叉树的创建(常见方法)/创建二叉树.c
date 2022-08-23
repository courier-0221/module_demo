#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <malloc.h>

/*
三种方法
	1.前序创建
		2种方式，利用的是 # 号表示法，ABDH#K###E##CFI###G#J##，将树通过函数参数或者返回值返回。
	2.用前序和中序创建二叉树
	3.用中序和后序创建二叉树
*/

/*
scanf用法及scanf中使用%c的问题
对scanf来讲跳过前导空白符有个例外，当参数是%c的时候，就把缓冲区的第一个字符返回回去，不管是什么。
空白符（空白符：指空格符、制表符、回车符）
所以解决的办法是刷新缓冲区。
//fflush(stdin);//第一种方法刷新输入缓冲区
while ((ch = getchar()) != '\n')//第二种方法
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

/* 方法一：方式一 通过入参将构造好的树返回*/
void BtreePreorderingCreate_1(BtNode **tree);
/* 方法一：方式二 通过函数返回值将构造好的树返回*/
BtNode *BtreePreorderingCreate_2(void);
/* 方法一：方式三 通过入参将构造好的树返回,要构造的树通过第二个参数传入*/
void BtreePreorderingCreate_3(BtNode **tree, char *str);

/* 方法二： 通过入参将构造好的树返回,要构造的树通过第二个参数传入*/
BtNode *BtreePreorderingMiddleCreate(int *Preorder, int *Middle, int Len);

/* 方法三： 通过入参将构造好的树返回,要构造的树通过第二个参数传入*/
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

/* 方法一：方式一 通过入参将构造好的树返回*/
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

/* 方法一：方式二 通过函数返回值将构造好的树返回*/
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

/* 方法一：方式三 通过入参将构造好的树返回,要构造的树通过第二个参数传入*/
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

/* 方法二： 通过入参将构造好的树返回,要构造的树通过第二个参数传入*/
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

/* 方法三： 通过入参将构造好的树返回,要构造的树通过第二个参数传入*/
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
