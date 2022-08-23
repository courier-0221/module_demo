#include <stdio.h>
#include <assert.h>

/*
��Ŀ��
	strcmp�����ķ�д
���ܣ�
	�Ƚ��ַ���s1��s2��
˵����
	��s1<s2ʱ������ֵ<0
	��s1=s2ʱ������ֵ=0
	��s1>s2ʱ������ֵ>0

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