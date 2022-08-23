#include "BinaryTree.h"




int main(void)
{
	/*
	//手动建立关系
	BtNode
		t1 = { 'A', NULL, NULL },
		t2 = { 'B', NULL, NULL },
		t3 = { 'C', NULL, NULL },
		t4 = { 'D', NULL, NULL },
		t5 = { 'E', NULL, NULL },
		t6 = { 'F', NULL, NULL },
		t7 = { 'G', NULL, NULL };
	//建立关系
	t1.lchild = &t2;	t1.rchild = &t3;
	t2.lchild = &t4;	t4.rchild = &t7;
	t3.lchild = &t5;	t3.rchild = &t6;
	*/

	BtNode *root = NULL;
	int Pre[7] = { 1, 2, 3, 4, 5, 6, 7 }, In[7] = { 3, 2, 4, 1, 6, 5, 7 }, Po[7] = { 3, 4, 2, 6, 7, 5, 1 };
	int len = sizeof(Pre) / sizeof(*Pre);

	
	root = BtreeMiddlePostCreate(In, Po, len);
	
	printf("Preordering\n");
	BtreePreordering(root);
	printf("\n");

	printf("二叉树中结点的个数 = %d\n", BtreeNodeCount(root)); 
	printf("二叉树的深度 = %d\n", BtreeHeight(root));

	int CountOfLeaf = 0;
	BtreeLeafCount(root, &CountOfLeaf);
	printf("二叉树的叶结点个数 = %d\n", CountOfLeaf);
	

	printf("拷贝二叉树测试\n");
	BtNode *CopyTree = BtreeCopyTree2(root);
	printf("Preordering\n");
	BtreePreordering(CopyTree);
	printf("\n");
	BtreeDestroy(CopyTree);

	printf("交换二叉树每个结点的左孩子和右孩子测试\n");
	BtreeExchangeNode(root);
	BtreePreordering(root);
	printf("\n");

	printf("输出二叉树中从每个叶子结点到根结点的路径\n");
	int path[256]	= { 0 };
	int pathlen		= 0;
	BtreePrintAllPath(root, path, pathlen);






	BtreeDestroy(root);


	system("pause");
	return 0;
}