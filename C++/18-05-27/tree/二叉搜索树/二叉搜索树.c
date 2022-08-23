#include "BSTree.h"

int comparekey(void* k1, void* k2)
{
	return (int)k1 - (int)k2;
}

void printfdata(BSTNode* node)
{
	if (node != NULL)
	{
		printf("%d", ((BSTNode*)node)->data);
	}
}

int main(void)
{
	BSTree* tree = BSTreeCreate();
	BSTNode
		n1 = { 1, NULL, NULL },
		n2 = { 2, NULL, NULL },
		n3 = { 3, NULL, NULL },
		n4 = { 4, NULL, NULL },
		n5 = { 5, NULL, NULL },
		n6 = { 6, NULL, NULL };


	BSTreeInsert(tree, &n4, comparekey);
	BSTreeInsert(tree, &n1, comparekey);
	BSTreeInsert(tree, &n3, comparekey);
	BSTreeInsert(tree, &n6, comparekey);
	BSTreeInsert(tree, &n2, comparekey);
	BSTreeInsert(tree, &n5, comparekey);

	printf("Height: %d\n", BSTreeHeight(tree));
	BSTNode *root = BSTreeRoot(tree);
	printf("Root: %d\n", root->data); 
	printf("Count: %d\n", BSTreeCount(tree));
	printf("Search Key 5: %d\n", ((BSTNode*)BSTreeGet(tree, (void*)5, comparekey))->data);
	printf("Max Num: %d\n", ((BSTNode*)BSTreeMaxNum(tree))->data);
	printf("Min Num: %d\n", ((BSTNode*)BSTreeMinNum(tree))->data);

	printf("Preordering\n");
	BSTreePreordering((BSTree*)(tree->root));
	printf("\n");

	BSTreeDisplay(tree, printfdata, 4, '-');

	

	BSTreeDelete(tree, (void*)4, comparekey);
	printf("After Delete Key 4: \n");
	printf("Height: %d\n", BSTreeHeight(tree));
	printf("Count: %d\n", BSTreeCount(tree));

	printf("Preordering\n");
	BSTreePreordering((BSTree*)(tree->root));
	printf("\n");
	BSTreeDisplay(tree, printfdata, 4, '-');

	BSTreeClear(tree);
	printf("After Clear: \n");
	printf("Height: %d\n", BSTreeHeight(tree));
	printf("Count: %d\n", BSTreeCount(tree));



	BSTreeDestroy(tree);

	system("pause");
	return 0;
}