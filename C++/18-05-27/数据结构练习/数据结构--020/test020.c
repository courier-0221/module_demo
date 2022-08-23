#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
题目：
	单向链表的就地逆置
*/


typedef struct _tar_list
{
	int data;
	struct _tar_list *next;
}*list, node;

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
		return;
	}
	reverse_display(head->next);
	printf("%d\t", head->data);
}


list list_reverse(list _list)
{
	node *pre = _list, *current = pre->next;
	pre->next = NULL;
	while (current != NULL){
		node *tmp = current->next;
		
		current->next = pre;
		pre = current;
		current = tmp;
	}
	_list = pre;
	return _list;
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
	_list = list_frontinsert(_list, &node1);
	_list = list_frontinsert(_list, &node2);
	_list = list_frontinsert(_list, &node3);
	_list = list_frontinsert(_list, &node4);
	_list = list_frontinsert(_list, &node5);
	reverse_display(_list);

	printf("\n逆置后\n");
	_list = list_reverse(_list);
	reverse_display(_list);

	system("pause");
	return 0;
}