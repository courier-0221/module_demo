#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <string.h>

//�ַ��������м���ϰ013��ʹ�õݹ�ʵ�ֵ�

/*
��Ŀ��
	����һ���ַ�����������ַ������ַ���������ϡ�
˼·��
	
*/

//����һ
/*
������⣺�ο���ϰ009	��	��ϰ015
	����1��
	��aocdfe����ַ���������
		��һ�֣� aocdfe aocdf aocd aoc ao a        
		�ڶ��֣� ocdfe ocdf ocd oc o
		�����֣� cdfe cdf cd c
		�����֣� dfe df d
		�����֣� fe f
		�����֣� e
	����2��
*/
void zuhe1(const char *str)
{
	assert(str);
	int len = strlen(str);
	

	//��ʽ1
	for (int i = len ; i > 0; i--){			//���ƿ������ӷ�����
		for (int j = 0; j < len - i + 1; j++){	//���ƿ����Ŀ�ʼλ�úʹ���
			char substr[64] = { 0 };
			strncpy(substr, str + j, i);
			substr[i] = 0;
			printf("%s\n", substr);
		}
	}
	/*
		��������
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


	//��ʽ2
	//for (int i = 0; i < len; i++){
	//	for (int j = len - i; j > 0; j--){
	//		char substr[64] = { 0 };
	//		strncpy(substr, str + i, j);
	//		substr[len - i] = 0;
	//		printf("%s\n", substr);
	//	}
	//}
	/*
		�����
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