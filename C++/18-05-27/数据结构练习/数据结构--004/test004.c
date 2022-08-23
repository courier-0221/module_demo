#include <stdio.h>
#include <assert.h>
#include <stdlib.h>



/*
��Ŀ��
	����һ��������������������е�����k����㡣����ĵ�����0�����Ϊ�����βָ�롣
*/

typedef struct _tar_listnode
{
	int data;
	struct _tar_listnode* next;
}*list,listnode;

list list_frontinsert(list _list,listnode *node)
{
	if (node == NULL){
		exit(-1);
	}
	node->next = _list;
	_list = node;
	return _list;
}

void list_printf(list _list)
{
	listnode *current = _list;
	while (current != NULL){
		printf("%d\n", current->data);
		current = current->next;
	}
}

int print_rev_k_data(list _list,int k)
{
	if (_list == NULL){
		exit(-1);
	}
	int len = 0, i = 0;
	listnode *current = _list;
	while (current != NULL){
		len++;
		current = current->next;
	}
	current = _list;
	for (i = 0; i < len - k;i++){
		current = current->next;
	}
	return current->data;
}


int main(void)
{
	listnode 
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


	printf("������2��Ԫ��Ϊ:%d\n", print_rev_k_data(_list, 2));
//	list_printf(_list);


	system("pause");
	return 0;
}
