#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*
题目：
	输出字符串的所有排列，如 abc 的全排列: abc, acb, bca, dac, cab, cba
*/

void permutation(char s[], int b, int e)
{
	if ((0 <= b) && (b <= e))
	{
		if (b == e)
		{
			printf("%s\n", s);
		}
		else
		{
			int i = 0;

			for (i = b; i <= e; i++)
			{
				char c = s[b];
				s[b] = s[i];
				s[i] = c;

				permutation(s, b + 1, e);

				c = s[b];
				s[b] = s[i];
				s[i] = c;
			}
		}
	}
}


void str_permutation(char* str, char* start)
{
	if (*start == 0){
		printf("%s\n", str);
	}
	char *tmp = start, m;
	while (*tmp != 0){
		m = *start;
		*start = *tmp;
		*tmp = m;

		str_permutation(str, start + 1);

		m = *start;
		*start = *tmp;
		*tmp = m;
		tmp++;
	}
}


int main(void)
{
	char buf[] = "abcd";
	str_permutation(buf, buf);
	system("pause");
	return 0;
}