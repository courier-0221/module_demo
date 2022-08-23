#include <stdio.h>
#include <assert.h>
#include <string.h>
/*
题目：
解析一个字符串，对字符串中重复出现的字符，只在第一次出现时保留，就是去除重复的字符。
如：abdabbefgf -> abdefg。
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

	//向链表中存储第一个字符
	node *newnode = (node*)malloc(sizeof(node));
	if (newnode == NULL){
		printf("malloc error\n");
		return NULL;
	}
	header = newnode;
	newnode->ch = *(strbak++);
	newnode->next = NULL;

	while (*strbak != 0){

		//遍历链表找到链表中是否存在相同元素
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
		//如果不存在，则在链表尾部插入未出现的字符
		if (flag == 1){
			node *newnode = (node*)malloc(sizeof(node));
			if (newnode == NULL){
				printf("malloc error\n");
				return NULL;
			}
			newnode->ch = *strbak;
			newnode->next = NULL;
			pre->next = newnode;
			//计算出链表长度

		}

		strbak++;
	}

	////测试遍历链表
	//current = header;
	//while (current != NULL){
	//	printf("%c\t", current->ch);
	//	current = current->next;
	//}



	//将链表中的字符赋值返回出去，并释放申请的内存
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

//优化	2018年8月29日20:49:20
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