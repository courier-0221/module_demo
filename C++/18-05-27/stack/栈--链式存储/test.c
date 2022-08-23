#include "LinkStack.h"

//用户自定义业务结点
typedef struct
{
	LinkStackNode header;
	int age;
	char name[12];
	int sex;
}student;

void LinkStack_Traverse(void *_stack)
{
	LinkStack *stack = (LinkStack*)_stack;
	if (stack == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		exit(-1);
	}
	LinkStackNode *p = stack->pTop;
	while (p != stack->pBottom)
	{
		student *st = (student *)p;
		printf("student info -- name: %s\tage: %d\tsex: %d\n", st->name, st->age, st->sex);

		p = p->pNext;
	}
	printf("\n");

	return;
}

void main(void)
{
	student *tmp,
		node1 = { NULL, 21, "aaa", 1 },
		node2 = { NULL, 22, "bbb", 0 },
		node3 = { NULL, 23, "ccc", 1 },
		node4 = { NULL, 24, "ddd", 0 },
		node5 = { NULL, 25, "eee", 1 };

	void *stack = LinkStack_Create();

	LinkStack_Push(stack, &node1);
	LinkStack_Push(stack, &node2);
	LinkStack_Push(stack, &node3);
	LinkStack_Push(stack, &node4);
	LinkStack_Push(stack, &node5);

	tmp = (student *)LinkStack_Top(stack);
	printf("top: name: %s\tage: %d\tsex: %d\n", tmp->name, tmp->age, tmp->sex);
	printf("size: %d\n", LinkStack_Size(stack));

	{
		printf("Test transf func\n");
		LinkStack_Traverse(stack);
	}

	while (LinkStack_Size(stack) > 0)
	{
		tmp = (student *)LinkStack_Pop(stack);
		printf("pop: name: %s\tage: %d\tsex: %d\n", tmp->name, tmp->age, tmp->sex);
	}

	LinkStack_Destroy(stack);

	system("pause");
}