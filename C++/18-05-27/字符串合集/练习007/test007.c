#include <stdio.h>
#include <assert.h>

/*
题目：
	strcmp函数的仿写
功能：
	比较字符串s1和s2。
说明：
	当s1<s2时，返回值<0
	当s1=s2时，返回值=0
	当s1>s2时，返回值>0

*/

int mystrlen(const char *str)
{
	return (assert(str), *str ? mystrlen(str + 1) + 1 : 0);
}

int mystrcmp(const char *str1, const char *str2)
{
	assert(str1); assert(str2);
	int ret = 0;
	while (((ret = *(unsigned char*)str1 - *(unsigned char*)str2) == 0) && *str1 && *str2){
		str1++;
		str2++;
	}

	if (ret < 0)
		ret = -1;
	else if (ret > 0)
		ret = 1;

	return ret;
}

int main(void)
{
	printf("%d\n", mystrcmp("def", "sdg"));

	system("pause");
	return 0;
}