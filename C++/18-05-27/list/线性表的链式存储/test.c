#include "LinkList.h"

/* ҵ���� */
typedef struct
{
	LinkListNode header;	//��ȫ������������
	int age;
	char name[10];
	int sex;
}student;

void LinkList_Transf(void *_list);
void LinkList_Sort(void *_list);

int main(void)
{
	void *list = LinkList_Create();

	student
		st1 = { NULL, 21, "aaa", 1 },
		st2 = { NULL, 22, "bbb", 0 },
		st3 = { NULL, 23, "ccc", 0 },
		st4 = { NULL, 24, "ddd", 1 },
		st5 = { NULL, 25, "eee", 1 },
		st6 = { NULL, 26, "fff", 0 },
		st7 = { NULL, 27, "ggg", 1 };


	
	LinkList_Insert(list, LinkList_Length(list), (LinkListNode *)&st1);
	LinkList_Insert(list, LinkList_Length(list), (LinkListNode *)&st2);
	LinkList_Insert(list, LinkList_Length(list), (LinkListNode *)&st3);
	LinkList_Insert(list, LinkList_Length(list), (LinkListNode *)&st4);
	LinkList_Insert(list, LinkList_Length(list), (LinkListNode *)&st5);
	linklilst_BackInsert(list, (LinkListNode *)&st6);
	LinkList_FrintInsert(list, (LinkListNode *)&st7);
	printf("list length %d\n", LinkList_Length(list));
	LinkList_Transf(list);

	//printf("delete pos = 2\n");
	//student *st = (student *)LinkList_Delete(list, 2);
	//printf("delete student info\n\tname: %s\tage: %d\tsex:%d\n", st->name, st->age, st->sex);
	//LinkList_Transf(list);

	//{
	//	printf("front delete\n");
	//	student *st = (student *)LinkList_Frontdelete(list);
	//	printf("delete student info\n\tname: %s\tage: %d\tsex:%d\n", st->name, st->age, st->sex);
	//	LinkList_Transf(list);
	//}

	//printf("back delete\n");
	//student *st = (student *)LinkList_BackDelete(list);
	//printf("delete student info\n\tname: %s\tage: %d\tsex:%d\n", st->name, st->age, st->sex);
	//LinkList_transf(list);

	//printf("get pos = 1\n");
	//student *tmp = (student *)LinkList_Get(list, 1);
	//printf("get student info\n\tname: %s\tage: %d\tsex:%d\n", tmp->name, tmp->age, tmp->sex);


	printf("���������С����\n");
	LinkList_Sort(list);
	//LinkList_Reverse(list);
	LinkList_Transf(list);


	LinkList_Destroy(list);
	system("pause");
	return 0;
}


void LinkList_Sort(void *_list)
{
	LinkList *list = (LinkList *)_list;
	if (_list == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		exit(-1);
	}
	LinkListNode *cur = NULL, *pre = NULL, tmp;

	student std;
	for (pre = ((LinkListNode*)list)->next; pre->next != NULL; pre = pre->next)
	{
		for (cur = pre->next; cur != NULL; cur = cur->next)
		{
			if (((student *)pre)->age > ((student *)cur)->age)
			{
				//����������
				//tmp = *cur;
				//*cur = *pre;
				//*pre = tmp;
				////����ָ����
				//tmp.next = cur->next;
				//cur->next = pre->next;
				//pre->next = tmp.next;
				/*������Ҫע������������������д����᲻��ʹ��ԭ���������д洢���ǽ��ĵ�ַ
				*(����������ջ�ռ������ڴ�)����������ʱ��*��ȡ�����������������ж���Ľ��
				*/
				//printf("%x\n", cur);	//����һ�¿������������ʲô--->�洢������һ��ҵ����ĵ�ַ

				//����������
				std = *((student *)cur);
				*((student *)cur) = *((student *)pre);
				*((student *)pre) = std;


				//����ָ����
				tmp.next = cur->next;
				cur->next = pre->next;
				pre->next = tmp.next;
			}
		}
	}

}

void LinkList_Transf(void *_list)
{
	LinkList *list = (LinkList *)_list;
	if (_list == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		exit(-1);
	}

	int i = 0;
	LinkListNode *current = ((LinkListNode *)list)->next;
	for (i = 0; i < list->length; i++)
	{
		printf("student%d --  name: %s\tage: %d\tsex: %d\n", i,
			((student *)current)->name,
			((student *)current)->age,
			((student *)current)->sex);
		current = current->next;
	}

}