#include "CircleList.h"


void *CircleList_Create(void)
{
	CircleList *list = (CircleList *)malloc(sizeof(CircleList));
	if (list == NULL)
	{
		printf("malloc error \n");
		return NULL;
	}
	list->length = 0;
	list->header.next = NULL;
	list->slider = NULL;
	return list;
}

void CircleList_Destroy(void *_list)
{
	free(_list);
	_list = NULL;

}

void CircleList_Insert(void *_list, CircleListNode *_node, int pos)
{
	int i = 0;
	CircleList *list = (CircleList*)_list;
	if ((_list == NULL) || (_node == NULL) || (pos < 0))
	{
		printf("An error in %s\n", __FUNCTION__);
		exit(-1);
	}

	CircleListNode *current = (CircleListNode *)list;

	for (i = 0; (i<pos) && (current->next != NULL); i++)
	{
		current = current->next;
	}
	_node->next = current->next;
	current->next = _node;

	/* 特殊情况：插入链表中第一个结点，游标直接指向它,它的指针域还要指向它自己，因为是循环链表。*/
	if (list->length == 0)
	{
		list->slider = _node;
	}

	list->length++;

	/* 若采用的是头插法，这时current仍指向头部，链表中最后一个结点的指针域就要调整指向，指向新插入的结点 */
	if (current == (CircleListNode *)list)
	{
		CircleListNode *last = (CircleListNode *)CircleList_Get(list, list->length - 1);
		last->next = current->next;
	}
}

/*
	成功： 返回 结点地址
	失败： 返回 NULL
*/
void *CircleList_Get(void *_list, int pos)
{
	int i = 0;
	if ((_list == NULL) || (pos < 0))
	{
		printf("An error in %s\n", __FUNCTION__);
		return NULL;
	}

	CircleListNode *current = (CircleListNode*)_list;
	for (i = 0; i < pos; i++)
	{
		current = current->next;
	}

	return current->next;
}

int CircleList_Length(void *_list)
{
	CircleList *list = (CircleList*)_list;
	if (_list == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		return -1;
	}
	return list->length;
}

void *CircleList_Delete(void *_list, int pos)
{
	int i = 0;
	CircleList *list = (CircleList*)_list;
	if ((_list == NULL) || (pos < 0))
	{
		printf("An error in %s\n", __FUNCTION__);
		return NULL;
	}

	CircleListNode *current = (CircleListNode*)list;
	CircleListNode *back = NULL;
	for (i = 0; i < pos; i++)
	{
		current = current->next;
	}

	//只有删除的是第一个结点时，才用到最后一个结点，让最后一个结点的指针重新指向，所以这里判断删除的是不是第一个节点
	//如果是的话才定义出最后一个结点的位置，节省效率
	if (current == (CircleListNode*)list)
	{
		back = (CircleListNode*)CircleList_Get(list, CircleList_Length(list) - 1);
	}

	CircleListNode *ret = current->next;
	current->next = ret->next;
	list->length--;
	/*以上代码是单链表的操作*/

	//特殊情况1：如果删除的结点是第一个结点，最后一个结点调整结点指针指向
	if (back != NULL)
	{
		list->header.next = ret->next;
		back->next = ret->next;
	}

	//特殊情况2：如果删除的结点正好被游标指向了，游标向下移动一个单位
	if (list->slider == ret)
	{
		list->slider = ret->next;
	}

	//若删除元素后，链表长度为0
	if (list->length == 0)
	{
		list->header.next = NULL;
		list->slider = NULL;
	}
	return ret;
}
void CircleList_Transf(void *_list)
{
	CircleList *list = (CircleList*)_list;
	if (_list == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		exit(-1);
	}
}

void *slider_reset(void *_list)
{
	CircleListNode *ret = NULL;
	CircleList *list = (CircleList*)_list;
	if (_list == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		return NULL;
	}

	list->slider = list->header.next;
	ret = list->slider;

	return ret;
}
void *slider_next(void *_list)
{
	CircleListNode *ret = NULL;
	CircleList *list = (CircleList*)_list;
	if (_list == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		return NULL;
	}
	ret = list->slider;
	list->slider = ret->next;

	return ret->next;
}
void *slider_current(void *_list)
{
	CircleListNode *ret = NULL;
	CircleList *list = (CircleList*)_list;
	if (_list == NULL)
	{
		printf("An error in %s\n", __FUNCTION__);
		return NULL;
	}
	ret = list->slider;

	return ret;
}
void *slider_delete(void *_list, CircleListNode *_node)
{
	CircleListNode *ret = NULL;
	
	int i = 0;
	CircleList *list = (CircleList*)_list;
	if ((_list == NULL) || (_node == NULL))
	{
		printf("An error in %s\n", __FUNCTION__);
		return NULL;
	}

	CircleListNode *current = (CircleListNode *)list;
	for (i = 0; i<list->length; i++)
	{
		if (current->next == _node)
		{
			ret = current->next;
			break;
		}
		current = current->next;
	}

	if (ret != NULL)
	{
		CircleList_Delete(list, i);
	}

	return ret;
}