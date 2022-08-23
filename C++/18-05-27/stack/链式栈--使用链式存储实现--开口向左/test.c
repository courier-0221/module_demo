#include "LinkStack.h"

//业务结点	
typedef struct
{
	int age;
	char name[10];
	int sex;
}student;

void main(void)
{

	void *stack = LinkStack_Create();
	student *tmp,
		node1 = { 21, "aaa", 1 },
		node2 = { 22, "bbb", 0 },
		node3 = { 23, "ccc", 1 },
		node4 = { 24, "ddd", 0 },
		node5 = { 25, "eee", 1 };

	LinkStack_Push(stack, &node1);
	LinkStack_Push(stack, &node2);
	LinkStack_Push(stack, &node3);
	LinkStack_Push(stack, &node4);
	LinkStack_Push(stack, &node5);

	printf("Length: %d\n", LinkStack_Size(stack));
	tmp = (student*)LinkStack_Top(stack);
	printf("top: %s\t%d\t%d\n\n", tmp->name, tmp->age, tmp->sex);
	

	while (LinkStack_Size(stack) > 0)
	{
		tmp = (student*)LinkStack_Pop(stack);
		printf("Pop: %s\t%d\t%d\n\n",tmp->name,tmp->age,tmp->sex );
	}

	LinkStack_Destroy(stack);
	
	system("pause");
}