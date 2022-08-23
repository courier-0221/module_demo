#include <stdio.h>
#include <assert.h>

/*
题目：
	给出一个函数来输出一个字符串的所有排列
思路：
	把字符串中的每一个字符都放到起始位置一次，然后对后面的字符串在做此操作
*/

int mystrlen(const char *str)
{
	return (assert(str), (*str) ? (mystrlen(str + 1) + 1) : 0);
}

void func(char *str,int begin,int end)
{
	assert(str);
	if (begin < 0 || end < begin){
		exit(-1);
	}

	if (begin == end){
		printf("%s\n", str);
	}
	else{
		int i = 0;
		for (i = begin; i <= end; i++){
			//将每一个字符都放到起始位置一次
			char frist = str[begin];
			str[begin] = str[i];
			str[i] = frist;

			//对剩下元素做全排列
			func(str, begin + 1, end);

			//交换回来
			frist = str[begin];
			str[begin] = str[i];
			str[i] = frist;
		}
		
	}

}





int main(void)
{
	char s[] = "abcd";

	func(s, 0, 3);

	system("pause");
	return 0;
}





