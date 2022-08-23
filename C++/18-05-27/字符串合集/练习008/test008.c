#include <stdio.h>
#include <assert.h>

int mystrlen(const char *str)
{
	return (assert(str), *str ? mystrlen(str + 1) + 1 : 0);
}

char *mystrstr(const char *src, const char *string)
{
	assert(src); assert(string);
	int len1 = mystrlen(src),
		len2 = mystrlen(string),
		i = 0;

	if (len2 > len1){
		return NULL;
	}
	char *srcbak = src;

	while (*srcbak != 0){
		char *nowsrc = srcbak;
		char *stringbak = string;
		int found = 1;
		while (*nowsrc != 0 && *stringbak != 0){
			if (*nowsrc != *stringbak){
				found = 0;
			}
			nowsrc++;
			stringbak++;
		}
		if (found == 1){
			return srcbak;
		}
		

		srcbak++;
	}
	return NULL;
}

int main(void)
{

	printf("%s\n", mystrstr("1234567", "54"));


	system("pause");
	return 0;
}