#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <string.h>

/*
题目：
	找出字符串中第一个只出现一次的字符，并返回是什么元素
例如：
	输入“abaccdeff”，则输出‘b’。
*/

int find_first_char(const char *str)
{
	if (str == NULL){
		return -1;
	}
	int array[26] = { 0 };		//记录出现次数
	int order[26] = { 0 },		//记录出现顺序
		i = 0;
	const char *strbak = str;

	//记录元素出现的次数和顺序
	while (*strbak){
		char tmp = *strbak;
		if (array[tmp - 65] == 0){	//只记录第一次出现的
			order[i++] = tmp;
		}
		array[tmp - 65]++;
		strbak++;
	}

	//根据元素出现的顺序然后在记录出现次数的数组中查找是否出现1次
	for (i = 0; i < 26; i++){
		if (order[i] != 0){
			if (array[order[i] - 65] == 1){
				return order[i];
			}
		}
	}

}
int main(int argc, char* argv[])
{

	char ch = (char)find_first_char("ABCDFCDAF");
	printf("%c\n", ch);

	//printf("%d\n", 'A');

	system("pause");
	return 0;
}