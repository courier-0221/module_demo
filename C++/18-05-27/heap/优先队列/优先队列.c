#include "PriorityQueue.h"


int main(void)
{
	
	int a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int i, len = sizeof(a) / sizeof(*a);

	void *queue = PriorityQueueCreate(20);

	printf("== �������: \n");
	for (i = 0; i<len; i++)
	{
		printf("%d ", a[i]);
		PriorityQueueAppend(queue, a[i]);
	}
	printf("\nPrint Queue\n");
	PriorityQueuePrint(queue);

	i = 15;
	PriorityQueueAppend(queue, i);
	printf("\n== ���Ԫ��: %d\n", i);
	PriorityQueuePrint(queue);

	printf("\n== ɾ��Ԫ��\n");
	PriorityQueueRetrieve(queue);
	
	PriorityQueuePrint(queue);


	PriorityQueueDestroy(queue);

	printf("%d\n", (int)(9 / 2));

	system("pause");
	return 0;
}