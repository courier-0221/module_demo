#include <stdio.h>
#include <assert.h>

/*
题目：
	求最长回文子串

方法一：
	蛮力求解，即求出该字符串的每一个子串，再判断子串是否是回文串，找到最长的那个
	这篇文章介绍了其他几种效率高的方法https://www.cnblogs.com/xiuyangleiasp/p/5070991.html
*/

int mystrlen(const char *str)
{
	return (assert(str), (*str) ? (mystrlen(str + 1) + 1) : 0);
}


int IsReverseStr(const char *str, int begin, int end)
{
	while (begin <= end){
		if (str[begin] == str[end]){
			begin++;
			end--;
		}
		else
			return 0;
	}
	return 1;
}

int longestPalindrome(const char *str)
{
	assert(str);
	int len = mystrlen(str);
	if (len == 1)
		return 1;
	int longest = 1;
	for (int i = 0; i < len; i++)
		for (int j = i + 1; j < len; j++)
			if (IsReverseStr(str, i, j) == 1)
				longest = longest < j - i + 1 ? j - i + 1 : longest;

	return longest;
}

//同样也可以这样写
int maxhuiwenstr(const char* str, char *buf)
{
	assert(str); assert(buf);
	int len = mystrlen(str);
	int maxlen = 0;
	for (int i = len; i > 0; i--){
		for (int j = 0; j < len - i + 1; j++){
			/*strncpy(buf, str + j, i);
			buf[i] = 0;
			printf("%s\n", buf);*/
			int begin = j, end = j + i - 1, flag = 1;
			while (begin <= end){
				if (str[begin] == str[end]){
					begin++;
					end--;
				}
				else{
					flag = 0;
					break;
				}
			}
			if (flag == 1){
				if (i>maxlen){
					maxlen = i;
					strncpy(buf, str + j, i);
					buf[j + i - 1] = 0;
				}

			}
		}
	}
	return maxlen;
}

int main(void)
{

	printf("%d\n", longestPalindrome("dfg1231hjgh"));

	char buf[64] = { 0 };
	int len = maxhuiwenstr("dfhg121gh", buf);
	printf("maxlen:%d\nbuf:%s\n", len, buf);

	system("pause");
	return 0;
}
