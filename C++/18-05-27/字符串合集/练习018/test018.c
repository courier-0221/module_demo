#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <string.h>

/*
题目：
	在一个字符串(1<=字符串长度<=10000，全部由大写字母组成)中找到第一个只出现一次的字符,并返回它的位置
例如：
	输入“abaccdeff”，则输出 1
*/

typedef struct _tar_charnode
{
	char ch;
	int pos;
	int cishu;
	struct _tar_charnode *next;
}cnode;


//这个程序没能实现题目的要求，如果有的元素出现奇数次，那么这个元素还会被插入到出现一次的链表中
//int find_first_char(const char *str,char *buf)
//{
//	if (str == NULL || buf == NULL){
//		return -1;
//	}
//	cnode *head = NULL;
//	//向链表中插入第一个字符
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
//		//遍历链表看链表中存不存在这个字符
//		cnode *current = head, *pre = head;
//		int findflag = 1;
//		while (current != NULL){
//			if (current->ch == str[i]){	//存在从链表中删除
//				cnode *tmp = current;
//				if (tmp == head){		//如果删除的是链表的头部元素
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
//		if (findflag == 1){				//不存在,将这个字符插入进链表的尾部
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
//	//将链表中第一个元素返回出去
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
思路：
	使用一个链表，尾插法插入出现的顺序元素，如果要插入的元素在链表中出现，就将元素的出现次数属性
	+1操作。最后从头部到尾部的顺序遍历链表找到次数为1的元素。
*/

int find_first_char(const char *str, char *buf)
{
	if (str == NULL || buf == NULL){
		return -1;
	}
	cnode *head = NULL;
	//向链表中插入第一个字符
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
		//遍历链表看链表中存不存在这个字符
		cnode *current = head, *pre = head;
		int findflag = 1;
		while (current != NULL){
			if (current->ch == str[i]){	//存在降钙元素的次数加1
				(current->cishu)++;
				findflag = 0;
				break;
			}
			pre = current;
			current = current->next;
		}
		if (findflag == 1){				//不存在,将这个字符插入进链表的尾部
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

	//将链表中元素出现次数为1的元素返回出去
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
	printf("位置是：%d\t元素是：%c\n", pos, buf);
	

	

	system("pause");
	return 0;
}