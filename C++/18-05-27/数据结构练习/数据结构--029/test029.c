#include <stdio.h>
#include <string.h>

/*
题目：
	两个有序单链表合并为一个有序的单链表（默认升序）
*/


typedef struct _tar_listnode
{
	int key;
	struct _tar_listnode  *next;
}*list, listnode;


list list_insert(list _list,listnode *node)
{
	if (node == NULL){
		printf("无效的结点\n");
		return NULL;
	}
	node->next = _list;
	_list = node;
	return _list;
}

void list_print(list _list)
{
	if (_list == NULL){
		exit(-1);
	}
	listnode* current = _list;
	while (current != NULL){
		printf("%d--", current->key);
		current = current->next;
	}
}

void list_print_digui(list _list)
{
	if (_list == NULL){
		return;
	}
	printf("%d--", _list->key);
	list_print_digui(_list->next);
}


list list_merger(list head1, list head2,list *newhead)
{
	if ((head1 == NULL) || (head2 == NULL)){
		return NULL;
	}
	if (head1->key > head2->key){
		*newhead = head2;
		head2 = head2->next;
	}
	else{
		*newhead = head1;
		head1 = head1->next;
	}
		
	listnode *current = *newhead;
	while (head1 != NULL || head2 != NULL){
		//如果链表@h1先遍历完,直接把链表@h2后面节点连接到@current后面
		if (head1 == NULL || (head2 != NULL && head1->key > head2->key)){		//把@h2节点连接到@current节点后面
			current->next = head2;		/*把@h2节点连接到@current节点后面*/
			current = current->next;	/*调整@current指针,指向最新连接的节点*/
			head2 = head2->next;		/*过滤掉已经被连接过的节点*/
		}
		else{
			current->next = head1;
			current = current->next;
			head1 = head1->next;
		}
	}

	return *newhead;
}



int main(int argc, char *argv[])
{
	listnode
		node1 = { 1, NULL },
		node2 = { 2, NULL },
		node3 = { 3, NULL },
		node4 = { 4, NULL },
		node5 = { 5, NULL },
		node6 = { 6, NULL },
		node7 = { 7, NULL },
		node8 = { 8, NULL },
		node9 = { 9, NULL },
		node10 = { 10, NULL };
	list LIST1 = NULL, LIST2 = NULL;
	//1--3--5--7--9
	LIST1 = list_insert(LIST1, &node9);
	LIST1 = list_insert(LIST1, &node7);
	LIST1 = list_insert(LIST1, &node5);
	LIST1 = list_insert(LIST1, &node3);
	LIST1 = list_insert(LIST1, &node1);
	list_print_digui(LIST1);
	printf("\n");

	//2--4--6--8--10
	LIST2 = list_insert(LIST2, &node10);
	LIST2 = list_insert(LIST2, &node8);
	LIST2 = list_insert(LIST2, &node6);
	LIST2 = list_insert(LIST2, &node4);
	LIST2 = list_insert(LIST2, &node2);
	list_print(LIST2);


	printf("\n");
	list newhead = NULL;
	list_merger(LIST1, LIST2, &newhead);
	list_print(newhead);

	system("pause");
	return 0;
}
