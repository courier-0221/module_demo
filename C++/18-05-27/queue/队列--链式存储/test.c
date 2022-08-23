#include "LinkQueue.h"

//业务结点
typedef struct
{
	LinkQueueNode header;
	int age;
	char name[10];
	int sex;
}student;

void printf_queue(void *_queue)
{
	student *st = NULL;
	if (_queue == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		return;
	}

	LinkQueue *queue = (LinkQueue *)_queue;

	LinkQueueNode *tmp = queue->front;
	while (tmp != queue->rear->next)
	{
		st = (student *)tmp;
		printf("student info: name: %s\tage: %d\tsex: %d\n", st->name, st->age, st->sex);
		tmp = tmp->next;
	}
}


void main(void)
{
	student *tmp,
		node1 = { NULL, 21, "aaa", 1 },
		node2 = { NULL, 22, "bbb", 0 },
		node3 = { NULL, 23, "ccc", 1 },
		node4 = { NULL, 24, "ddd", 0 },
		node5 = { NULL, 25, "eee", 1 };

	void *queue = LinkQueue_Create();

	LinkQueue_Append(queue, &node1);
	LinkQueue_Append(queue, &node2);
	LinkQueue_Append(queue, &node3);
	LinkQueue_Append(queue, &node4);
	LinkQueue_Append(queue, &node5);

	tmp = (student *)LinkQueue_Header(queue);
	printf("header: name: %s\tage: %d\tsex: %d\n", tmp->name, tmp->age, tmp->sex);
	printf("length: %d\n", LinkQueue_Length(queue));

	printf_queue(queue);

	while (LinkQueue_Length(queue) > 0)
	{
		tmp = (student *)LinkQueue_Retrieve(queue);
		printf("retrieve: name: %s\tage: %d\tsex: %d\n", tmp->name, tmp->age, tmp->sex);
	}

	if (LinkQueue_IfEmpty(queue))
	{
		printf("空栈!\n");
	}

	LinkQueue_Destroy(queue);
	system("pause");
}