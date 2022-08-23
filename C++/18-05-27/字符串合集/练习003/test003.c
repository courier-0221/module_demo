#include <stdio.h>
#include <stdlib.h>

/*
题目：
	有一个字符串开头或结尾含有n个空格 （”   abcdefgdddd    ”），欲去掉前后空格，返回一个新字符串。
	要求1：请自己定义一个接口（函数），并实现功能；
	要求2：编写测试用例。
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