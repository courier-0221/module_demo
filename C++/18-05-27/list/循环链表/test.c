#include "CircleList.h"


void main_test(void)
{

	int i = 0;
	void *list = CircleList_Create();
	student
		st1 = { NULL, "111", 21, 1 },
		st2 = { NULL, "222", 22, 1 },
		st3 = { NULL, "333", 23, 0 },
		st4 = { NULL, "444", 24, 1 },
		st5 = { NULL, "555", 25, 1 };

	CircleList_Insert(list, (CircleListNode*)&st1, 0);
	CircleList_Insert(list, (CircleListNode*)&st2, 0);
	CircleList_Insert(list, (CircleListNode*)&st3, 0);
	CircleList_Insert(list, (CircleListNode*)&st4, 0);
	CircleList_Insert(list, (CircleListNode*)&st5, 0);

	printf("list length is %d\n", CircleList_Length(list));

	{
		for (i = 0; i < 2 * CircleList_Length(list); i++){
			student *st = (student *)CircleList_Get(list, i);
			printf("%s\t%d\t%d\n", st->name, st->age, st->sex);
		}
	}
	

	student *st = CircleList_Delete(list, 8);
	printf("\n%s\t%d\t%d\n\n", st->name, st->age, st->sex);

	{
		for (i = 0; i < CircleList_Length(list); i++){
			student *st = (student *)CircleList_Get(list, i);
			printf("%s\t%d\t%d\n", st->name, st->age, st->sex);
		}
	}

	CircleList_Destroy(list);
	system("pause");
}

void main_slider(void)
{
	/* 业务结点 */
	typedef struct				
	{
		CircleListNode node;
		int num;
	}data;

	int i = 0;
	void *list = CircleList_Create();
	data
		d1 = { NULL, 1 },
		d2 = { NULL, 2 },
		d3 = { NULL, 3 },
		d4 = { NULL, 4 },
		d5 = { NULL, 5 },
		d6 = { NULL, 6 },
		d7 = { NULL, 7 },
		d8 = { NULL, 8 };

	CircleList_Insert(list, (CircleListNode*)&d1, CircleList_Length(list));
	CircleList_Insert(list, (CircleListNode*)&d2, CircleList_Length(list));
	CircleList_Insert(list, (CircleListNode*)&d3, CircleList_Length(list));
	CircleList_Insert(list, (CircleListNode*)&d4, CircleList_Length(list));
	CircleList_Insert(list, (CircleListNode*)&d5, CircleList_Length(list));
	CircleList_Insert(list, (CircleListNode*)&d6, CircleList_Length(list));
	CircleList_Insert(list, (CircleListNode*)&d7, CircleList_Length(list));
	CircleList_Insert(list, (CircleListNode*)&d8, CircleList_Length(list));

	//约瑟夫问题
	slider_reset(list);
	while (CircleList_Length(list) > 0)
	{
		data *da = NULL;
		for (i = 1; i < 3; i++)
		{
			slider_next(list);
		}

		da = (data *)slider_current(list);
		printf("%d\n", da->num);
		slider_delete(list, (CircleListNode*)da);
	}
	/*
	{
		printf("list length is %d\n", CircleList_length(list));
		for (i = 0; i < CircleList_Length(list); i++){
			data *st = (data *)CircleList_Get(list, i);
			printf("%d\n", st->num);
		}
	}
	*/
	CircleList_Destroy(list);
	system("pause");
}


void main(void)
{

	main_slider();
}