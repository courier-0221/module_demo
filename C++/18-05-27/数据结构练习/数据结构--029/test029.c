#include <stdio.h>
#include <string.h>

/*
��Ŀ��
	������������ϲ�Ϊһ������ĵ�����Ĭ������
*/


typedef struct _tar_listnode
{
	int key;
	struct _tar_listnode  *next;
}*list, listnode;


list list_insert(list _list,listnode *node)
{
	if (node == NULL){
		printf("��Ч�Ľ��\n");
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
		//�������@h1�ȱ�����,ֱ�Ӱ�����@h2����ڵ����ӵ�@current����
		if (head1 == NULL || (head2 != NULL && head1->key > head2->key)){		//��@h2�ڵ����ӵ�@current�ڵ����
			current->next = head2;		/*��@h2�ڵ����ӵ�@current�ڵ����*/
			current = current->next;	/*����@currentָ��,ָ���������ӵĽڵ�*/
			head2 = head2->next;		/*���˵��Ѿ������ӹ��Ľڵ�*/
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
