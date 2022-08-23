#include <stdio.h>
#include <assert.h>
#include <string.h>
/*
��Ŀ��
����һ���ַ��������ַ������ظ����ֵ��ַ���ֻ�ڵ�һ�γ���ʱ����������ȥ���ظ����ַ���
�磺abdabbefgf -> abdefg��
*/



#define STRUCT(type) typedef struct _tar_##type type;\
struct _tar_##type

STRUCT(node)
{
	char ch;
	node *next;
};

void func(const char *str, char *const buf)
{
	assert(str);
	char *strbak = str;
	node *header = NULL;
	node *current = NULL;
	node *pre = NULL;

	//�������д洢��һ���ַ�
	node *newnode = (node*)malloc(sizeof(node));
	if (newnode == NULL){
		printf("malloc error\n");
		return NULL;
	}
	header = newnode;
	newnode->ch = *(strbak++);
	newnode->next = NULL;

	while (*strbak != 0){

		//���������ҵ��������Ƿ������ͬԪ��
		current = header;
		int flag = 1;
		while (current != NULL){
			if (current->ch == *strbak){
				flag = 0;
				break;
			}
			pre = current;
			current = current->next;
		}
		//��������ڣ���������β������δ���ֵ��ַ�
		if (flag == 1){
			node *newnode = (node*)malloc(sizeof(node));
			if (newnode == NULL){
				printf("malloc error\n");
				return NULL;
			}
			newnode->ch = *strbak;
			newnode->next = NULL;
			pre->next = newnode;
			//�����������

		}

		strbak++;
	}

	////���Ա�������
	//current = header;
	//while (current != NULL){
	//	printf("%c\t", current->ch);
	//	current = current->next;
	//}



	//�������е��ַ���ֵ���س�ȥ�����ͷ�������ڴ�
	current = header;
	char *tmp = NULL, i = 0;
	while (current != NULL){
		buf[i] = current->ch;
		i++;
		tmp = current;
		current = current->next;
		free(tmp);
		tmp = NULL;
	}
	buf[i] = 0;


}

//�Ż�	2018��8��29��20:49:20
char *str_del_rep_ch(char *str, char *buf)
{
	if ((str == NULL) || (buf == NULL)){
		return NULL;
	}
	int timesofchar[128] = { 0 }, i = 0;
	char order[64] = { 0 }, *ret = buf;

	while (*str != 0){
		if (timesofchar[*str] == 0){
			order[i++] = *str;
		}
		timesofchar[*str]++;
		str++;
	}

	for (int j = 0; j < i; j++){
		*buf++ = order[j];
	}
	*buf = 0;
	return ret;
}

int main(void)
{
	char buf[128] = { 0 };
	//func("1232415",buf);
	//printf("%s\n", buf);


	str_del_rep_ch("abdabbefgf", buf);
	printf("%s\n", buf);

	system("pause");
	return 0;
}