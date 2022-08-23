#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
��Ŀ��
	����һ�������ͷ��㣬��β��ͷ���������ÿ������ֵ��
������
	�������ֽ��ⷽ������ע�⣬��������ֻ��˳�������
	��1��ջ��˳�����������ÿ���ڵ���ջ������ڳ�ջ��
	��2������������������Ȼ���������ÿ���ڵ㣨��Ŀû��ע�������޸ı�ӿڣ�
	��3���ݹ飺��򵥣���������뵽�ķ���
*/


typedef struct _tar_list
{
	int data;
	struct _tar_list *next;
}*list,node;

list list_frontinsert(list _list, node *_node)
{
	if (_node == NULL){
		return NULL;
	}
	_node->next = _list;
	_list = _node;
	return _list;
}


void reverse_display(list head)
{
	if (head == NULL){
		return ;
	}
	reverse_display(head->next);
	printf("%d\t", head->data);
}


void list_printf(list _list)
{
	list current = _list;
	while (current != NULL){
		printf("%d\t", current->data);
		current = current->next;
	}
}

int main(void)
{
	node
		node1 = { 1, NULL },
		node2 = { 2, NULL },
		node3 = { 3, NULL },
		node4 = { 4, NULL },
		node5 = { 5, NULL };

	list _list = NULL;
	_list = list_frontinsert(_list, &node5);
	_list = list_frontinsert(_list, &node4);
	_list = list_frontinsert(_list, &node3);
	_list = list_frontinsert(_list, &node2);
	_list = list_frontinsert(_list, &node1);

	//list_printf(_list);
	reverse_display(_list);

	system("pause");
	return 0;
}