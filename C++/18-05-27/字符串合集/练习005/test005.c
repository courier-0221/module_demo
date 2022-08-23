#include <stdio.h>
#include <stdlib.h>

/*
题目：
	键值对（“key = value”）字符串，在开发中经常使用
	要求1：请自己定义一个接口，实现根据key获取.
	要求2：编写测试用例。
	要求3：键值对中间可能有n多空格，请去除空格

	注意：键值对字符串格式可能如下：
	"key1 = value1"
	"key2 =       value2"
	"key3  = value3"
	"key4        = value4"
	"key5   =   "
	"key6   ="
	
	int getKeyByValue(char *keyvaluebuf,  char *keybuf,  char *valuebuf, int * valuebuflen);

*/
char *mystrstr(char *src, char *key)
{
	if ((!src) || (!key)){
		return NULL;
	}
	char *srcbak = src;
	char *keybak = key;
	while (*srcbak != 0){
		char *nowsrc = srcbak;
		int flag = 1;
		while (*keybak != 0){
			if (*nowsrc != *keybak){
				flag = 0;
			}
			keybak++;
			nowsrc++;
		}
		if (flag == 1){
			return srcbak;
		}
		srcbak++;
	}

	return NULL;
}

char *mystrchr(char *src, char key)
{
	if (!src){
		return NULL;
	}
	while (*src != 0){
		if (*src == key){
			return src;
		}
		src++;
	}
	return NULL;
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

int getKeyByValue(char *keyvaluebuf, char *keybuf, char *valuebuf, int * valuebuflen)
{
	if ((!keyvaluebuf) || (!keybuf) || (!valuebuf) || (!valuebuflen)){
		return;
	}
	char *key_buf = mystrstr(keyvaluebuf, keybuf);
	if (!key_buf){
		printf("no find\n");
		return;
	}
	char *finddenghao = mystrchr(key_buf, '=');
	if (!finddenghao){
		printf("no find\n");
		return;
	}
	char *start = finddenghao + 1;
	char *startbak = start;
//	printf("%s\n\n", start);
	int len = mystrlen(start);
	int begin = 0, end = len - 1;
	while (*startbak != 0){
		if (startbak[begin] == ' '){
			begin++;
		}

		if (startbak[end] == ' '){
			end--;
		}
		startbak++;
	}
	*valuebuflen = end - begin + 1;
	int i;
	for (i = 0; i < *valuebuflen; i++){
		valuebuf[i] = *(start + begin + i);
		//printf("%c\n", *(start + begin + i));
	}
	valuebuf[i] = 0;
}

int main(void)
{
	char buf[10] = { 0 };
	int len;
	
	getKeyByValue("key4        = value4", "key4", buf, &len);
	printf("%s\nlen = %d\n", buf, len);
	

	system("pause");
	return 0;
}