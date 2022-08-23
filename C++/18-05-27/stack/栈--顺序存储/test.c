#include "SeqStack.h"

//用户自定义业务结点
typedef struct
{	
	int age;
	char name[12];
	int sex;
}student;

int SeqStack_Traverse(void *_stack)
{
	int ret = _stack != NULL;
	SeqStack *stack = (SeqStack*)_stack;
	if (!ret)
	{
		printf("An error in %s\n", __FUNCTION__);
		return ret;
	}
	int tmp = stack->pTop;
	while (tmp != 0)
	{
		student *st = (student *)stack->node[tmp];
		printf("student info -- name: %s\tage: %d\tsex: %d\n", st->name, st->age, st->sex);
		tmp--;
	}
	printf("\n");

	return ret;
}

void main(void)
{
	student *tmp,
		node1 = { 21, "aaa", 1 },
		node2 = { 22, "bbb", 0 },
		node3 = { 23, "ccc", 1 },
		node4 = { 24, "ddd", 0 },
		node5 = { 25, "eee", 1 };

	void *stack = SeqStack_Create(10);
	
	SeqStack_Push(stack, &node1);
	SeqStack_Push(stack, &node2);
	SeqStack_Push(stack, &node3);
	SeqStack_Push(stack, &node4);
	SeqStack_Push(stack, &node5);

	tmp = (student *)SeqStack_Top(stack);
	printf("top: name: %s\tage: %d\tsex: %d\n", tmp->name, tmp->age, tmp->sex);
	printf("size: %d\n", SeqStack_Size(stack));

	{
		printf("Test transf func\n");
		SeqStack_Traverse(stack);
	}

	while (SeqStack_Size(stack) > 0)
	{
		tmp = (student *)SeqStack_Pop(stack);
		printf("pop: name: %s\tage: %d\tsex: %d\n", tmp->name, tmp->age, tmp->sex);
	}

	SeqStack_Destroy(stack);
	system("pause");
}