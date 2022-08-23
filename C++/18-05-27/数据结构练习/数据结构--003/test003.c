#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


/*
��Ŀ��
	����һ��Ӣ�ľ��ӣ���ת�����е��ʵ�˳�򣬵��������ַ���˳�򲻱䡣
	�����е����Կո��������Ϊ������������ź���ͨ��ĸһ������
	�������롰I am a student.�����������student. a am I����
˼·��
	��ת2���ַ�������1���ȷ�ת�����ַ��� ��2���ڷ�ת�����еĵ���
*/

int mystrlen(const char *str)
{
	return (assert(str), (*str) ? (mystrlen(str + 1) + 1) : 0);
}

char *over(char *str, int begin, int end)
{
	if (str == NULL){
		return NULL;
	}
	if (begin > end){
		return str;
	}

	while (end >= begin){
		char tmp = *(str + begin);
		*(str + begin) = *(str + end);
		*(str + end) = tmp;
		end--;
		begin++;
	}
	return str;
}

char *revstr(char *str)
{
	if (str == NULL){
		return NULL;
	}
	int len = mystrlen(str);
	int begin = 0, end = len - 1,i = 0;

	//1���ȷ�ת�����ַ���
	over(str, begin, end);


	//2����ת���еĵ���
	int count = 0;
	begin = 0, end = 0;
	for (i = 0; i < len; i++){
		count++;
		if ((str[i] == ' ') || (str[i + 1] == 0)){
			begin = i - count + 1;
			end = i - 1;
			count = 0;
			over(str, begin, end);
		}	
	}


	return str;
}



int main(void)
{
	char str[] = "I am a student.";
	revstr(str);

	printf("%s\n", str);
	//printf("%d\n", mystrlen(str));

	system("pause");
	return 0;
}
