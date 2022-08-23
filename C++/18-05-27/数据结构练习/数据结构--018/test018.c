#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
题目：
	输入一个链表的头结点，从尾到头反过来输出每个结点的值。
分析：
	给出三种解题方法：（注意，单向链表只能顺序遍历）
	（1）栈：顺序遍历链表，把每个节点入栈，最后在出栈。
	（2）链表逆序：链表逆序，然后正序输出每个节点（题目没有注明不能修改表接口）
	（3）递归：最简单，但最不容易想到的方法
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