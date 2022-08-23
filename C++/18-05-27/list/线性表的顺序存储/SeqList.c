#include "SeqList.h"

void *SeqList_Create(int _capacity)
{
	SeqList *list = (SeqList*)malloc(sizeof(SeqList)+sizeof(SeqListNode)* _capacity);
	if (!list)
	{
		printf("malloc error \n");
		return NULL;
	}
	list->capacity = _capacity;
	list->length = 0;
	list->node = (SeqListNode *)(list + 1);
	return list;
}

void SeqList_Destroy(void *_list)
{
	free(_list);
	_list = NULL;
}


int SeqList_Length(void *_list)
{
	SeqList *list = (SeqList *)_list;
	if (_list == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		return -1;
	}

	return list->length;
}

int SeqList_Capacity(void *_list)
{
	SeqList *list = (SeqList *)_list;
	if (_list == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		return -1;
	}

	return list->capacity;
}

int SeqList_Insert(void *_list, SeqListNode *_node, int pos)
{
	SeqList *list = (SeqList *)_list;
	if (list->capacity == list->length)
	{
		printf("SeqList is full\n");
		return -1;
	}
	if ((_list == NULL) || (_node == NULL))
	{
		printf("An error in %s\n", __FUNCTION__);
		return -1;
	}

	//移动数据
	int i = 0;
	for (i = list->length; i > pos; i--)
	{
		list->node[i] = list->node[i - 1];
	}

	list->node[pos] = (SeqListNode)_node;

	
	list->length++;
	return 1;
}


void *SeqList_Delete(void *_list, int pos)
{
	SeqList *list = (SeqList *)_list;
	if (_list == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		return	NULL;
	}
	SeqListNode *tmp = (SeqListNode*)(list->node[pos]);


	//移动数据
	int i = 0;
	for (i = pos; i < list->length; i++)
	{
		list->node[i] = list->node[i + 1];
	}

	list->length--;
	return tmp;
}

void *SeqList_Get(void *_list, int pos)
{
	SeqList *list = (SeqList *)_list;
	if (_list == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		return NULL;
	}

	//保护
	if (pos >= list->capacity)
	{
		pos = list->capacity - 1;
	}

	return (SeqListNode*)(list->node[pos]);
}

