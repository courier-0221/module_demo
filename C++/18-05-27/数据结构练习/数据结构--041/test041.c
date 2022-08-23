#include <stdio.h>
#include <assert.h>

/*
题目：
	学长博客中记录的CVTE嵌入式软件笔试编程题
	输入一个字符串，输出字符串中最后出现次数最少的字符，如果都有重复，则输出最后出现字符最多的字符，
	例如输入：“abbccdffgg”输出：d 输入：“aaabbbccddee”输出：b
*/
int mystrlen(const char *str)
{
	return (assert(str), (*str ? (mystrlen(str + 1) + 1) : 0));
}


char print_char(char *str)
{
	if (str == NULL){
		return -1;
	}
	int len = mystrlen(str), dayu2 = 1, max = 0;
	char order[64] = { 0 };			//记录出现顺序
	int charoftimes[128] = { 0 };	//记录出现次数
	char ret;


	for (int i = 0; i < len; i++){
		order[i] = str[i];
		charoftimes[order[i]]++;
	}

	for (int i = 0; i < 128; i++){
		if (charoftimes[i] == 1){
			dayu2 = 0;
			break;
		}
	}

	if (dayu2 == 1){		//都有重复的情况
		for (int i = len - 1; i >= 0; i--){
			if (charoftimes[order[i]] > max){
				max = charoftimes[order[i]];
				ret = order[i];
			}
		}
	}
	else if (dayu2 == 0){	//有的字符没有重复的情况
		for (int i = len - 1; i >= 0; i--){
			if (charoftimes[order[i]] == 1){
				ret = order[i];
				break;
			}
		}
	}
	return ret;
}



int main(int argc, char *argv[])
{

	printf("%c\n", print_char("abbccdffgg"));
	printf("%c\n", print_char("aaabbbccddee"));
	system("pause");
	return 0;
}
