#include "DoubleList.h"

void main(void)
{
	int i = 0;
	student *st = NULL;
	void *list = DLinkList_Create();

	student
		st1 = { { NULL, NULL }, "111", 21, 1 },
		st2 = { { NULL, NULL }, "222", 22, 1 },
		st3 = { { NULL, NULL }, "333", 23, 0 },
		st4 = { { NULL, NULL }, "444", 24, 1 },
		st5 = { { NULL, NULL }, "555", 25, 1 };
	//这里要注意{ NULL, NULL }pre和next指针都要初始化，否则会出问题

	
	DLinkList_Insert(list, (DLinkListNode*)&st1, DLinkList_Length(list));
	DLinkList_Insert(list, (DLinkListNode*)&st2, DLinkList_Length(list));
	DLinkList_Insert(list, (DLinkListNode*)&st3, DLinkList_Length(list));
	DLinkList_Insert(list, (DLinkListNode*)&st4, DLinkList_Length(list));
	DLinkList_Insert(list, (DLinkListNode*)&st5, DLinkList_Length(list));

	{//遍历
		printf("list length is %d\n", DLinkList_Length(list));
		for (i = 0; i < DLinkList_Length(list); i++){
			student *st = (student *)DLinkList_Get(list, i);
			printf("%s\t%d\t%d\n", st->name, st->age, st->sex);
		}
	}
	/*
	DLinkList_Delete(list, DLinkList_Length(list) - 1);
	DLinkList_Delete(list, 0);

	{
		printf("delete pos = 2\n");
		student *st = (student *)DLinkList_Delete(list, 2);
		printf("%s\t%d\t%d\n", st->name, st->age, st->sex);
	}

	{//遍历
		printf("list length is %d\n", DLinkList_Length(list));
		for (i = 0; i < DLinkList_Length(list); i++){
			student *st = (student *)DLinkList_Get(list, i);
			printf("%s\t%d\t%d\n", st->name, st->age, st->sex);
		}
	}
	*/
	printf("测试游标\n");
	slider_reset(list);
	slider_next(list);
	st = (student*)slider_current(list);
	printf("%s\t%d\t%d\n", st->name, st->age, st->sex);
	
	slider_delete(list, (DLinkListNode*)st);
	st = (student*)slider_current(list);
	printf("%s\t%d\t%d\n", st->name, st->age, st->sex);

	slider_pre(list);
	st = (student*)slider_current(list);
	printf("%s\t%d\t%d\n", st->name, st->age, st->sex);
	printf("Length: %d\n", DLinkList_Length(list));

	DLinkList_Destroy(list);
	system("pause");
}
