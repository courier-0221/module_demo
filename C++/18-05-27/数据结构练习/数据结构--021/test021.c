#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
/*
��Ŀ��
	дһ������,����ԭ����int continumax(char *outputstr,char *intputstr)

���ܣ�
	���ַ������ҳ�����������ִ�������������ĳ��ȷ��أ�
	�����������ִ���������һ����������outputstr��ָ�ڴ档
���磺"abcd12345ed125ss123456789"���׵�ַ����intputstr�󣬺���������9��
outputstr��ָ��ֵΪ123456789
*/

/*
˼·��
	��������ָ�룬һ��ָ�����ֿ�ʼ��λ�ã���һ��ָ�����ֽ�����λ�ã�Ȼ���жϳ����Ƿ�������ǵĻ�����copy
*/


int continumax(char *outputstr, char *intputstr)
{
	if ((outputstr == NULL) || (intputstr == NULL)){
		return -1;
	}

	char *first = intputstr, *second = first;
	int max = 0, tmp = 0;
	while (*first != 0){
		tmp = 0;
		second = first;
		while ((*second <= '9') && (*second >= '0')){
			tmp++;
			second++;
		}
		if (max < tmp){
			max = tmp;
			strncpy(outputstr, first, tmp);
		}	
		first = second;
		first++;
	}
	return max;
}




int main(void)
{
	//char *intputstr = "abcd12345ed125ss123456789";
	char *intputstr = "abcd12345879889ed125ss123456789";
	char outputstr[64] = { 0 };
	int len = continumax(outputstr, intputstr);

	printf("max len is:%d\nstr is :%s\n", len, outputstr);

	system("pause");
	return 0;
}