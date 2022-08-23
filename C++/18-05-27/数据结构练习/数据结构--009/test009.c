#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
题目：
	假设这有一个各种字母组成的字符串A，和另外一个字符串B，字符串里B的字母数相对少一些。
	什么方法能最快的查出所有小字符串B里的字母在大字符串A里都有？
方法2：
	哈希
		（1）定义一个数组hash[26]，并清0。定义一个不同字符出现次数总和m
		（2）遍历短字符串，把找到的字符相应位置置1，m++
		（3）遍历长字符串，把找到的字符相应位置置0，m--
		（4）最后m等于0，则是包含关系，否则是非包含关系
*/

int mystrlen(const char *str)
{
	return (assert(str), (*str ? (mystrlen(str + 1) + 1) : 0));
}

int if_include(char *longstr, char *shortstr)
{
	if (longstr == NULL || shortstr == NULL){
		exit(-1);
	}
	int hash[26] = { 0 };
	int shortlen = mystrlen(shortstr), longlen = mystrlen(longstr), i = 0, key = 0, total = 0;
	for (i = 0; i < shortlen; i++){
		key = shortstr[i] - 'A';
		if (hash[key] == 1)
			continue;

		total++;
		hash[key] = 1;
		
	}

	for (i = 0; i < longlen; i++){
		key = longstr[i] - 'A';
		if (hash[key] == 0){
			continue;
		}
		hash[key] = 0;
		total--;
	}

	if (total == 0){
		return 1;
	}
	else{
		return -1;
	}
}


int main(void)
{
	
	if (if_include("ABCDEFGHLMNOPQRS", "ABZC") == 1){
		printf("包含\n");
	}
	else{
		printf("不包含\n");
	}

	system("pause");
	return 0;
}