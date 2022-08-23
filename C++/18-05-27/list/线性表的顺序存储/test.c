#include "SeqList.h"

/* 业务结点 */
typedef struct 
{
	int age;
	char name[10];
	int sex;
}student;

static void SeqList_Transf(void *_list)
{
	SeqList *list = (SeqList *)_list;
	if (_list == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		exit(-1);
	}

	int i = 0;
	for (i = 0; i < list->length; i++)
	{
		printf("student%d -- name:%s\tage:%d\tsex:%d\n", i,
			((student *)(list->node[i]))->name,
			((student *)(list->node[i]))->age,
			((student *)(list->node[i]))->sex);
	}
}

void main(void)
{
	void *list = SeqList_Create(5);
	student
		node1 = {21, "aaa", 1 },
		node2 = {22, "bbb", 0 },
		node3 = {23, "ccc", 1 },
		node4 = {24, "ddd", 0 };
	
	SeqList_Insert(list, &node1, SeqList_Length(list));
	SeqList_Insert(list, &node2, SeqList_Length(list));
	SeqList_Insert(list, &node3, SeqList_Length(list));
	SeqList_Insert(list, &node4, SeqList_Length(list));

	printf("list length is %d\n", SeqList_Length(list));
	SeqList_Transf(list);

	student *tmp = (student *)SeqList_Delete(list, 2);
	printf("delete student -- name:%s\tage:%d\tsex:%d\n", tmp->name, tmp->age, tmp->sex);

	SeqList_Transf(list);

	SeqList_Destroy(list);
	system("pause");
}
