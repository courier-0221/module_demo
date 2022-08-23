#include <stdio.h>
#include <assert.h>

/*
题目：
	商汤科技嵌入式软件工程师第一套题中编程题二
	从字符串中"aecbcda"找出不重复的字符组成的顺序子串"aecbd"，用最优的时间复杂度
*/

int mystrlen(const char *str)
{
	return (assert(str), (*str ? (mystrlen(str + 1) + 1) : 0));
}


char *no_repeat_str(char *str)
{
	if (str == NULL)
		return NULL;
	char order[64] = { 0 };			//记录出现顺序
	int charoftimes[128] = { 0 };	//记录出现次数

	
	int len = mystrlen(str), i = 0, j = 0;

	for (i = 0; i < len; i++){
		charoftimes[str[i]]++;
		order[i] = str[i];
	}
	char *ret = str;
	for (i = 0; i < len; i++){
		if (charoftimes[order[i]] > 0){
			str[j++] = order[i];
			charoftimes[order[i]] = 0;
		}
	}
	str[j] = 0;
	return str;
}




int main(int argc, char *argv[])
{
	char buf[] = "aecbcda";
	no_repeat_str(buf);
	printf("%s\n", buf);


	system("pause");
	return 0;
}
