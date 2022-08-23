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

	/* ������������������е�һ����㣬�α�ֱ��ָ����,����ָ����Ҫָ�����Լ�����Ϊ��ѭ������*/
	if (list->length == 0)
	{
		list->slider = _node;
	}

	list->length++;

	/* �����õ���ͷ�巨����ʱcurrent��ָ��ͷ�������������һ������ָ�����Ҫ����ָ��ָ���²���Ľ�� */
	if (current == (CircleListNode *)list)
	{
		CircleListNode *last = (CircleListNode *)CircleList_Get(list, list->length - 1);
		last->next = current->next;
	}
}

/*
	�ɹ��� ���� ����ַ
	ʧ�ܣ� ���� NULL
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

	//ֻ��ɾ�����ǵ�һ�����ʱ�����õ����һ����㣬�����һ������ָ������ָ�����������ж�ɾ�����ǲ��ǵ�һ���ڵ�
	//����ǵĻ��Ŷ�������һ������λ�ã���ʡЧ��
	if (current == (CircleListNode*)list)
	{
		back = (CircleListNode*)CircleList_Get(list, CircleList_Length(list) - 1);
	}

	CircleListNode *ret = current->next;
	current->next = ret->next;
	list->length--;
	/*���ϴ����ǵ�����Ĳ���*/

	//�������1�����ɾ���Ľ���ǵ�һ����㣬���һ�����������ָ��ָ��
	if (back != NULL)
	{
		list->header.next = ret->next;
		back->next = ret->next;
	}

	//�������2�����ɾ���Ľ�����ñ��α�ָ���ˣ��α������ƶ�һ����λ
	if (list->slider == ret)
	{
		list->slider = ret->next;
	}

	//��ɾ��Ԫ�غ�������Ϊ0
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