#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <string.h>

/*
��Ŀ��
	��һ���ַ���(1<=�ַ�������<=10000��ȫ���ɴ�д��ĸ���)���ҵ���һ��ֻ����һ�ε��ַ�,����������λ��
���磺
	���롰abaccdeff��������� 1
*/

typedef struct _tar_charnode
{
	char ch;
	int pos;
	int cishu;
	struct _tar_charnode *next;
}cnode;


//�������û��ʵ����Ŀ��Ҫ������е�Ԫ�س��������Σ���ô���Ԫ�ػ��ᱻ���뵽����һ�ε�������
//int find_first_char(const char *str,char *buf)
//{
//	if (str == NULL || buf == NULL){
//		return -1;
//	}
//	cnode *head = NULL;
//	//�������в����һ���ַ�
//	cnode *pnew = (cnode *)malloc(sizeof(cnode));
//	if (pnew == NULL){
//		printf("malloc error\n");
//		exit(-1);
//	}
//	pnew->ch = str[0];
//	pnew->pos = 0;
//	pnew->next = NULL;
//	head = pnew;
//
//	int i = 0, len = strlen(str);
//	for (i = 1; i < len; i++){
//		//�������������д治��������ַ�
//		cnode *current = head, *pre = head;
//		int findflag = 1;
//		while (current != NULL){
//			if (current->ch == str[i]){	//���ڴ�������ɾ��
//				cnode *tmp = current;
//				if (tmp == head){		//���ɾ�����������ͷ��Ԫ��
//					head = head->next;
//				}
//				else{
//					pre->next = current->next;
//				}
//				free(tmp);
//				tmp = NULL;
//				findflag = 0;
//				break;
//			}
//			pre = current;
//			current = current->next;
//		}
//		if (findflag == 1){				//������,������ַ�����������β��
//			cnode *zuihou = head,*qian = head;
//			while (zuihou != NULL){
//				qian = zuihou;
//				zuihou = zuihou->next;
//			}
//			
//			cnode *pnew = (cnode *)malloc(sizeof(cnode));
//			if (pnew == NULL){
//				printf("malloc error\n");
//				exit(-1);
//			}
//			pnew->ch = str[i];
//			pnew->pos = i;
//			pnew->next = NULL;
//			qian->next = pnew;
//		}
//
//	}
//
//	//test printf
//	//cnode* current = head;
//	//while (current != NULL){
//	//	printf("%c\t", current->ch);
//	//	current = current->next;
//	//}
//
//	//�������е�һ��Ԫ�ط��س�ȥ
//	*buf = head->ch;
//	int pos = head->pos;
//
//	//destroy
//	while (head != NULL){
//		cnode *tmp = head;
//		head = head->next;
//		free(tmp);
//		tmp = NULL;
//	}
//
//	return pos;
//}

/*
˼·��
	ʹ��һ������β�巨������ֵ�˳��Ԫ�أ����Ҫ�����Ԫ���������г��֣��ͽ�Ԫ�صĳ��ִ�������
	+1����������ͷ����β����˳����������ҵ�����Ϊ1��Ԫ�ء�
*/

int find_first_char(const char *str, char *buf)
{
	if (str == NULL || buf == NULL){
		return -1;
	}
	cnode *head = NULL;
	//�������в����һ���ַ�
	cnode *pnew = (cnode *)malloc(sizeof(cnode));
	if (pnew == NULL){
		printf("malloc error\n");
		exit(-1);
	}
	pnew->ch = str[0];
	pnew->pos = 0;
	pnew->cishu = 0;
	pnew->next = NULL;
	head = pnew;

	int i = 0, len = strlen(str), pos = 0;
	for (i = 1; i < len; i++){
		//�������������д治��������ַ�
		cnode *current = head, *pre = head;
		int findflag = 1;
		while (current != NULL){
			if (current->ch == str[i]){	//���ڽ���Ԫ�صĴ�����1
				(current->cishu)++;
				findflag = 0;
				break;
			}
			pre = current;
			current = current->next;
		}
		if (findflag == 1){				//������,������ַ�����������β��
			cnode *zuihou = head, *qian = head;
			while (zuihou != NULL){
				qian = zuihou;
				zuihou = zuihou->next;
			}
			cnode *pnew = (cnode *)malloc(sizeof(cnode));
			if (pnew == NULL){
				printf("malloc error\n");
				exit(-1);
			}
			pnew->ch = str[i];
			pnew->pos = i;
			pnew->next = NULL;
			pnew->cishu = 0;
			qian->next = pnew;
		}
	}

	////test printf
	//cnode* current = head;
	//while (current != NULL){
	//	printf("%c\t", current->ch);
	//	current = current->next;
	//}

	//��������Ԫ�س��ִ���Ϊ1��Ԫ�ط��س�ȥ
	cnode *current = head;
	while (current != NULL){
		if (current->cishu == 0){
			*buf = current->ch;
			pos = current->pos;
			break;
		}
		current = current->next;
	}

	//destroy
	while (head != NULL){
		cnode *tmp = head;
		head = head->next;
		free(tmp);
		tmp = NULL;
	}

	return pos;
}


int main(int argc, char* argv[])
{

	char buf, pos = 0;
	pos = find_first_char("ABDCA", &buf);
	printf("λ���ǣ�%d\tԪ���ǣ�%c\n", pos, buf);
	

	

	system("pause");
	return 0;
}