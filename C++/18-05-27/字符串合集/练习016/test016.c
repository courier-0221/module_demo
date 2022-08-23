#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <string.h>

//字符串的排列见练习013，使用递归实现的

/*
题目：
	输入一个字符串，输出该字符串中字符的所有组合。
思路：
	
*/

//方法一
/*
暴力求解：参考练习009	和	练习015
	方法1：
	拿aocdfe这个字符串举例子
		第一轮： aocdfe aocdf aocd aoc ao a        
		第二轮： ocdfe ocdf ocd oc o
		第三轮： cdfe cdf cd c
		第四轮： dfe df d
		第五轮： fe f
		第六轮： e
	方法2：
*/
void zuhe1(const char *str)
{
	assert(str);
	int len = strlen(str);
	

	//方式1
	for (int i = len ; i > 0; i--){			//控制拷贝的子符个数
		for (int j = 0; j < len - i + 1; j++){	//控制拷贝的开始位置和次数
			char substr[64] = { 0 };
			strncpy(substr, str + j, i);
			substr[i] = 0;
			printf("%s\n", substr);
		}
	}
	/*
		输出结果：
			1234
			123
			234
			12
			23
			34
			1
			2
			3
			4

	*/


	//方式2
	//for (int i = 0; i < len; i++){
	//	for (int j = len - i; j > 0; j--){
	//		char substr[64] = { 0 };
	//		strncpy(substr, str + i, j);
	//		substr[len - i] = 0;
	//		printf("%s\n", substr);
	//	}
	//}
	/*
		结果：
			1234
			123
			12
			1
			234
			23
			2
			34
			3
			4
	*/



}

int main(void)
{
	zuhe1("1234");
	system("pause");
	return 0;
}