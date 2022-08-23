#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>



typedef struct linetree_node
{
	int i, j;//��ʾ����[i, j]
	int cover;//��ʾ���䱻���ǵĴ���
	struct linetree_node* left; //���Ҷ��ӽڵ�
	struct linetree_node* right;
}LTree;

//�����߶���

LTree* ltree_create(int i, int j)
{
	if (i > j)
	{
		return (NULL);
	}
		
	LTree* pNode = NULL;
	pNode = (LTree*)malloc(sizeof(LTree));
	pNode->i = i;
	pNode->j = j;
	pNode->cover = 0;
	if (j - i > 1)
	{
		int mid = i + (j - i) / 2;
		pNode->left = ltree_create(i, mid);
		pNode->right = ltree_create(mid, j);
	}
	else
	{
		pNode->left = pNode->right = NULL;
	}
	return pNode;
}

//����һ������

void ltree_insert(LTree* ltree, int i, int j)
{
	if (i > j) return;
	if (i <= ltree->i && ltree->j <= j)
	{
		ltree->cover++;
	}
	else
	{
		int mid = ltree->i + (ltree->j - ltree->i) / 2;
		if (j <= mid)
		{
			ltree_insert(ltree->left, i, j);
		}
		else if (mid <= i)
		{
			ltree_insert(ltree->right, i, j);
		}
		else
		{
			ltree_insert(ltree->left, i, mid);
			ltree_insert(ltree->right, mid, j);
		}
	}
}

//ɾ��һ�����䣬ע��ֻ��ɾ���Ѿ����������
void ltree_delete(LTree* ltree, int i, int j)
{
	if (i > j) return;
	if (i <= ltree->i && ltree->j <= j)
		ltree->cover--;
	else
	{
		int mid = ltree->i + (ltree->j - ltree->i) / 2;
		if (j <= mid)
		{
			ltree_delete(ltree->left, i, j);
		}
		else if (i >= mid)
		{
			ltree_delete(ltree->right, i, j);
		}
		else
		{
			ltree_delete(ltree->left, i, mid);
			ltree_delete(ltree->right, mid, j);
		}

	}
}

//����߶���

void ltree_print(LTree* ltree, int depth)
{
	if (ltree)
	{
		int i;
		for (i = 0; i < depth; ++i) printf("        ");
		printf("[%d,%d]:%d\n", ltree->i, ltree->j, ltree->cover);

		ltree_print(ltree->left, depth + 1);
		ltree_print(ltree->right, depth + 1);
	}
}

//�ͷ��߶����ڴ�

void ltree_destroy(LTree* ltree)
{
	if (ltree)
	{
		LTree* pNode = ltree;
		ltree_destroy(ltree->left);
		ltree_destroy(ltree->right);
		free(pNode);
	}
}

int main(int argc, char** argv)
{

	//�����߶���
	LTree* root = ltree_create(0, 10);
	ltree_print(root, 0);
	ltree_insert(root, 3, 6);
	ltree_print(root, 0);
	ltree_insert(root, 7, 9);
	ltree_print(root, 0);
	ltree_delete(root, 3, 5);
	ltree_print(root, 0);
	ltree_destroy(root);

	system("pause");
	return 0;
}