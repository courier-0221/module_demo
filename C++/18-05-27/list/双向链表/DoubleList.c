#include "DoubleList.h"


void *DLinkList_Create(void)
{
	DLinkList *list = (DLinkList*)malloc(sizeof(DLinkList));
	if (list == NULL)
	{
		printf("malloc error\n");
		return NULL;
	}
	list->header.next = NULL;
	list->header.pre = NULL;
	list->slider = NULL;
	list->length = 0;

	return list;
}
void DLinkList_Destroy(void *_list)
{
	free(_list);
	_list = NULL;
}


int DLinkList_Length(void *_list)
{
	DLinkList* list = (DLinkList*)_list;
	if (_list == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		return -1;
	}
	return list->length;
}


void DLinkList_Insert(void *_list, DLinkListNode *_node, int pos)
{
	int i = 0;
	DLinkList* list = (DLinkList*)_list;
	if ((list == NULL) || (_node == NULL) || (pos < 0))
	{
		printf("An error in %s\n", __FUNCTION__);
		exit(-1);
	}

	DLinkListNode *current = (DLinkListNode*)list;
	DLinkListNode *next = NULL;
	for (i = 0; (i < pos) && (current->next != NULL); i++)
	{
		current = current->next;
	}
	next = current->next;

	current->next = _node;
	_node->next = next;
	if (next != NULL)
	{
		next->pre = _node;
	}
	_node->pre = current;

	if (list->length == 0)
	{
		list->slider = _node;
		
	}
	if (current == (DLinkListNode*)list)
	{
		_node->pre = NULL;
	}

	list->length++;

}

void *DLinkList_Get(void *_list, int  pos)
{
	int i = 0;
	DLinkList* list = (DLinkList*)_list;
	if ((list == NULL) || (pos < 0))
	{
		printf("An error in %s\n", __FUNCTION__);
		return NULL;
	}

	DLinkListNode *ret = NULL;
	DLinkListNode *current = (DLinkListNode*)list;
	for (i = 0; (i < pos) && (pos < list->length); i++)
	{
		current = current->next;
	}
	ret = current->next;
	return ret;
}

void *DLinkList_Delete(void *_list, int  pos)
{
	int i = 0;
	DLinkList* list = (DLinkList*)_list;
	if ((list == NULL) || (pos < 0))
	{
		printf("An error in %s\n", __FUNCTION__);
		return NULL;
	}

	DLinkListNode *current = (DLinkListNode*)list;
	DLinkListNode *next = NULL;
	DLinkListNode* ret = NULL;
	for (i = 0; (i < pos) && (current->next != NULL); i++)
	{
		current = current->next;
	}
	ret = current->next;
	next = ret->next;

	current->next = next;
	if (next != NULL)
	{
		next->pre = current;
		if (current == (DLinkListNode*)list)
		{
			next->pre = NULL;
		}
	}
	
	if (list->slider == ret)
	{
		list->slider = ret->next;
	}

	list->length--;

	return ret;
}

void *slider_reset(void *_list)
{
	DLinkList* list = (DLinkList*)_list;
	if (_list == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		return NULL;
	}

	list->slider = list->header.next;
	return list->slider;
}
void *slider_current(void *_list)
{
	DLinkList* list = (DLinkList*)_list;
	if (_list == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		return NULL;
	}
	return list->slider;
}
void *slider_next(void *_list)
{
	DLinkList* list = (DLinkList*)_list;
	if (_list == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		return NULL;
	}
	DLinkListNode *ret = NULL;
	if (list->slider != NULL)
	{
		ret = list->slider;
		list->slider = ret->next;
	}
	return ret;
}
void *slider_pre(void *_list)
{
	DLinkList* list = (DLinkList*)_list;
	if (_list == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		return NULL;
	}
	DLinkListNode *ret = NULL;
	if (list->slider != NULL)
	{
		ret = list->slider;
		list->slider = ret->pre;
	}
	return ret;
}
void *slider_delete(void *_list, DLinkListNode *_node)
{
	int i = 0;
	DLinkList* list = (DLinkList*)_list;
	if ((_list == NULL) || (_node == NULL))
	{
		printf("An error in %s\n", __FUNCTION__);
		return NULL;
	}
	DLinkListNode *ret = NULL;
	DLinkListNode *current = (DLinkListNode *)list;
	for (i = 0; i < list->length; i++)
	{
		if (current == _node)
		{
			ret = current->next;
			break;
		}
		current = current->next;
	}
	if (ret != NULL)
	{
		DLinkList_Delete(list, i);
	}

	return ret;
}





