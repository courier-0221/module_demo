#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/****************************************************
题目：		--百度2014笔试题
	使用C/C++语言写一个函数，实现字符串的反转，要求不能用任何系统函数，
	且时间复杂度最小。函数原型是：char *reverse_str(char *str)(15分)
*****************************************************/

/*
	思路：
		获取首尾指针，然后将首尾指针指向的元素交换，将首指针指向下一个，将尾指针指向前一个，
		交换指针指向的元素，然后重复执行，直到首尾指针相遇。
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
