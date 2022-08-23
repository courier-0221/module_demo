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

	/* ����height�� */
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

	/* ����height�� */
	k1->height = MAX(HEIGHT(k1->lchild), HEIGHT(k1->rchild)) + 1;
	k2->height = MAX(HEIGHT(k2->rchild), k1->height) + 1;

	return k1;
}

/*
	�Ƚ���RR��ת���ڽ���LL��ת
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
	�Ƚ���LL��ת���ڽ���RR��ת
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
	else if (tree->data > node->data)		/* ���뵽������ */
	{
		tree->lchild = AVLTreeInsert(tree->lchild, node);
		/* ����ڵ����AVL��ʧȥƽ�⣬�������Ӧ�ĵ��ڡ� */
		if ((HEIGHT(tree->lchild) - HEIGHT(tree->rchild)) == 2)
		{
			/* ��һ���ж��������ͻ��������� */
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
	else if (tree->data < node->data)		/* ���뵽������ */
	{
		tree->rchild = AVLTreeInsert(tree->rchild, node);
		/* ����ڵ����AVL��ʧȥƽ�⣬�������Ӧ�ĵ��ڡ� */
		if ((HEIGHT(tree->rchild) - HEIGHT(tree->lchild)) == 2)
		{
			/* ��һ���ж��������ͻ��������� */
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
		printf("���ʧ�ܣ������������ͬ�Ľڵ㣡\n");
	}


	/* �������ĸ߶ȡ� */
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
		/* ������Һ��Ӷ���Ϊ�� */
		if ((NULL != tree->lchild) && (NULL != tree->rchild))
		{
			if (HEIGHT(tree->lchild) > HEIGHT(tree->rchild))
			{
				// ���tree�����������������ߣ�
				// ��(01)�ҳ�tree���������е����ڵ�
				//   (02)�������ڵ��ֵ��ֵ��tree��
				//   (03)ɾ�������ڵ㡣
				// ����������"tree�������������ڵ�"��"tree"������
				// �������ַ�ʽ�ĺô��ǣ�ɾ��"tree�������������ڵ�"֮��AVL����Ȼ��ƽ��ġ�
				AVLTNode *max = AVLTreeMaxTreeNode(tree->lchild);
				tree->data = max->data;
				tree->lchild = AVLTreeSearchDeleteRecursion(tree->lchild, max);
			}
			else
			{
				// ���tree��������������������(��������ȣ�������������������1)
				// ��(01)�ҳ�tree���������е���С�ڵ�
				//   (02)������С�ڵ��ֵ��ֵ��tree��
				//   (03)ɾ������С�ڵ㡣
				// ����������"tree������������С�ڵ�"��"tree"������
				// �������ַ�ʽ�ĺô��ǣ�ɾ��"tree������������С�ڵ�"֮��AVL����Ȼ��ƽ��ġ�
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
		/* ɾ���ڵ����AVL��ʧȥƽ�⣬�������Ӧ�ĵ��ڡ� */
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
		/* ɾ�������������ж����Ƿ񻹱���ƽ�⡣ */
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
