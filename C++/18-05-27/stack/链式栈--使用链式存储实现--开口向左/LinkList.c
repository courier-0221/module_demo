#include "LinkList.h"



void *LinkList_Create(void)
{
	LinkList *list = (LinkList *)malloc(sizeof(LinkList));
	if (NULL == list)
	{
		printf("malloc error\n");
		return NULL;
	}
	list->length = 0;
	list->header.next = NULL;

	return list;
}
void LinkList_Destroy(void *_list)
{
	free(_list);
	_list = NULL;
}

int LinkList_Insert(void *_list, int pos, LinkListNode *st)
{
	LinkList *list = (LinkList *)_list;

	int ret = (_list != NULL) && (pos >= 0) && (st != NULL);
	if (0 == ret)
	{
		printf("An error in %s\n", __FUNCTION__);
		return ret;
	}

	/* 保护 */
	if (pos >= list->length)
	{
		pos = list->length - 1;
	}
	else if (pos < 0)
	{
		pos = 0;
	}

	int i = 0;
	LinkListNode *current = list;
	for (i = 0; (i<pos) && (current->next != NULL); i++)
	{
		current = current->next;
	}
	st->next = current->next;
	current->next = st;
	
	list->length++;

	return ret;
}


int linklilst_BackInsert(void *_list, LinkListNode *st)
{
	LinkList *list = (LinkList *)_list;
	int ret = (_list != NULL) && (st != NULL);
	if (0 == ret)
	{
		printf("An error in %s\n", __FUNCTION__);
		return ret;
	}

	int i = 0;
	LinkListNode *current = list;
	for (i = 0; i < LinkList_Length(list); i++)
	{
		current = current->next;
	}
	st->next = current->next;
	current->next = st;

	list->length++;
	return ret;
}
int LinkList_FrintInsert(void *_list, LinkListNode *st)
{
	LinkList *list = (LinkList *)_list;

	int ret = (_list != NULL) && (st != NULL);
	if (0 == ret)
	{
		printf("An error in %s\n", __FUNCTION__);
		return ret;
	}

	LinkListNode *current = list;
	st->next = current->next;
	current->next = st;

	list->length++;
	return ret;
}

LinkListNode *LinkList_BackDelete(void *_list)
{
	LinkList *list = (LinkList *)_list;

	if (_list == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		exit(-1);
	}

	LinkListNode *current = list;
	int i = 0;
	for (i = 0; i < list->length; i++)
	{
		current = current->next;
	}
	LinkListNode *tmp = current;
	current->next = NULL;
	list->length--;

	return tmp;
}
LinkListNode *LinkList_FrontDelete(void *_list)
{
	LinkList *list = (LinkList *)_list;

	if (_list == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		exit(-1);
	}

	LinkListNode *current = list;
	LinkListNode *tmp = current->next;
	current->next = current->next->next;
	
	list->length--;
	return tmp;
}


LinkListNode *LinkList_Delete(void *_list, int pos)
{
	LinkList *list = (LinkList *)_list;

	if (_list == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		return NULL;
	}

	/* 保护 */
	if (pos >= list->length)
	{
		pos = list->length - 1;
	}
	else if (pos < 0)
	{
		pos = 0;
	}
	int i = 0;
	LinkListNode *current = list;
	for (i = 0; i < pos; i++)
	{
		current = current->next;
	}
	LinkListNode *ret = current->next;
	current->next = current->next->next;

	list->length--;
	return ret;
}

LinkListNode *LinkList_Get(void *_list, int pos)
{
	LinkList *list = (LinkList *)_list;

	if (_list == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		exit(-1);
	}

	//保护
	if (pos >= list->length)
	{
		pos = list->length - 1;
	}
	else if (pos < 0)
	{
		pos = 0;
	}

	int i = 0;
	LinkListNode *current = list;
	for (i = 0; i < pos; i++)
	{
		current = current->next;
	}

	return current->next;
}


int LinkList_Length(void *_list)
{
	LinkList *list = (LinkList *)_list;
	if (_list == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		return -1;
	}
	return list->length;
}

void LinkList_Reverse(void *_list)
{
	LinkList *list = (LinkList *)_list;
	if (_list == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		exit(-1);
	}
	LinkListNode *pre = list, *cur = pre->next;
	pre->next = NULL;
	while (cur != NULL)
	{
		
		//布局第三个点
		LinkListNode *tmp = cur->next;
		//调整指向
		cur->next = pre;

		//移动指针
		pre = cur;
		cur = tmp;
	}
	((LinkListNode *)list)->next = pre;
}