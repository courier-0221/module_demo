#include <stdio.h>
#include <stdlib.h>

/*
��Ŀ��
	��һ���ַ�����ͷ���β����n���ո� ����   abcdefgdddd    ��������ȥ��ǰ��ո񣬷���һ�����ַ�����
	Ҫ��1�����Լ�����һ���ӿڣ�����������ʵ�ֹ��ܣ�
	Ҫ��2����д����������
	int trimSpace(char *inbuf, char *outbuf);  
*/

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

int trimSpace(char *inbuf, char *outbuf)
{
	if ((!inbuf) || (!outbuf)){
		return;
	}

	int begin = 0, end = mystrlen(inbuf) - 1;
	while (*(inbuf + begin) == ' '){
		begin++;
	}
	while (inbuf[end] == ' '){
		end--;
	}
	int i = 0,j = 0;
	for (i = begin,j = 0; i <= end; i++,j++){
		outbuf[j] = inbuf[i];
	}
	outbuf[j] = 0;
}

int main(void)
{
	char buf[20] = { 0 };
	trimSpace("   abcdefgdddd    ", buf);
	printf("%s\n", buf);


	system("pause");
	return 0;
}