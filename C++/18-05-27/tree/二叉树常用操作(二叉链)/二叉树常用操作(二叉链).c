#include "BinaryTree.h"




int main(void)
{
	/*
	//�ֶ�������ϵ
	BtNode
		t1 = { 'A', NULL, NULL },
		t2 = { 'B', NULL, NULL },
		t3 = { 'C', NULL, NULL },
		t4 = { 'D', NULL, NULL },
		t5 = { 'E', NULL, NULL },
		t6 = { 'F', NULL, NULL },
		t7 = { 'G', NULL, NULL };
	//������ϵ
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

	printf("�������н��ĸ��� = %d\n", BtreeNodeCount(root)); 
	printf("����������� = %d\n", BtreeHeight(root));

	int CountOfLeaf = 0;
	BtreeLeafCount(root, &CountOfLeaf);
	printf("��������Ҷ������ = %d\n", CountOfLeaf);
	

	printf("��������������\n");
	BtNode *CopyTree = BtreeCopyTree2(root);
	printf("Preordering\n");
	BtreePreordering(CopyTree);
	printf("\n");
	BtreeDestroy(CopyTree);

	printf("����������ÿ���������Ӻ��Һ��Ӳ���\n");
	BtreeExchangeNode(root);
	BtreePreordering(root);
	printf("\n");

	printf("����������д�ÿ��Ҷ�ӽ�㵽������·��\n");
	int path[256]	= { 0 };
	int pathlen		= 0;
	BtreePrintAllPath(root, path, pathlen);






	BtreeDestroy(root);


	system("pause");
	return 0;
}