#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/****************************************************
��Ŀ��		--�ٶ�2014������
	ʹ��C/C++����дһ��������ʵ���ַ����ķ�ת��Ҫ�������κ�ϵͳ������
	��ʱ�临�Ӷ���С������ԭ���ǣ�char *reverse_str(char *str)(15��)
*****************************************************/

/*
	˼·��
		��ȡ��βָ�룬Ȼ����βָ��ָ���Ԫ�ؽ���������ָ��ָ����һ������βָ��ָ��ǰһ����
		����ָ��ָ���Ԫ�أ�Ȼ���ظ�ִ�У�ֱ����βָ��������
*/

char *reverse_str(char *str)
{
	if (!str){
		return NULL;
	}
	int begin = 0;
	int end = mystrlen(str) - 1;
	while (begin < end){
		char tmp = *(str + begin);
		*(str + begin) = *(str + end);
		*(str + end) = tmp;
		begin++;
		end--;
	}
	return str;
}

int mystrlen(char const *str)
{
	int ret = 0;
	if (!str){
		return -1;
	}

	if (*str == 0){
		return ret;
	}
	else{
		return mystrlen(str + 1) + 1;
	}

}


char *reverse_str01(char *str)
{
	if (!str){
		return NULL;
	}

	if (*str == 0){
		return;
	}
	else{
		reverse_str(str + 1);
		printf("%c", *str);
	}
}


int main(void){

	//reverse_str01("123456");
	char buf[10] = "123456";
	printf("%s\n", reverse_str(buf));


	system("pause");
	return 0;
}
