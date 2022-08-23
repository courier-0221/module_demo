#include <stdio.h>
#include <assert.h>

/*
题目：
	判断一个字符串是不是回文
思路：
	回文，像121 ，3443,124421,3456543这些
*/


int mystrlen(const char *str)
{
	//第一种方法
	//if (str == NULL){
	//	exit(-1);
	//}

	//if(*str == 0){
	//	return 0;
	//}
	//else{
	//	return mystrlen(str + 1) + 1;
	//}

	//第二种方法，一条语句实现,使用了逗号表达式和三目运算符
	return (assert(str), (*str ? (mystrlen(str + 1) + 1) : 0));
}


/*
成功：
	返回1
失败：
	返回0
*/
int IsReverseStr(const char *str)
{
	char *tmp = str;
	int i = 0;
	if (tmp == NULL){
		return 0;
	}
	int len = mystrlen(tmp);
	
	for (i = 0; i < len; i++){
		if (*(tmp + i) != *(tmp + len - 1 - i)){
			return 0;
		}
	}

	return 1;
}

int main(void)
{
	if (IsReverseStr("12") == 0){
		printf("不是回文串\n");
	}
	else{
		printf("是回文串\n");
	}
	

	system("pause");
	return 0;
}