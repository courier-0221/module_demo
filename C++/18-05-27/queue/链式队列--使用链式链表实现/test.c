#include "LinkQueue.h"

//栈的业务结点
typedef struct 
{
	int age;
	char name[10];
	int sex;
}student;

void main(void)
{
	student *tmp,
		node1 = { 21, "aaa", 1 },
		node2 = { 22, "bbb", 0 },
		node3 = { 23, "ccc", 1 },
		node4 = { 24, "ddd", 0 },
		node5 = { 25, "eee", 1 };

	void *queue = LinkQueue_Create();

	LinkQueue_Append(queue, &node1);
	LinkQueue_Append(queue, &node2);
	LinkQueue_Append(queue, &node3);
	LinkQueue_Append(queue, &node4);
	LinkQueue_Append(queue, &node5);

	tmp = (student *)LinkQueue_Header(queue);
	printf("header: name: %s\tage: %d\tsex: %d\n", tmp->name, tmp->age, tmp->sex);
	printf("length: %d\n", LinkQueue_Length(queue));

	while (LinkQueue_Length(queue) > 0)
	{
		tmp = (student *)LinkQueue_Retrieve(queue);
		printf("retrieve: name: %s\tage: %d\tsex: %d\n", tmp->name, tmp->age, tmp->sex);
	}

	LinkQueue_Destroy(queue);
	system("pause");
}