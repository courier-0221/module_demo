#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <assert.h>
#include <string.h>

/*
��Ŀ��
	�ҳ��ַ����е�һ��ֻ����һ�ε��ַ�����������ʲôԪ��
���磺
	���롰abaccdeff�����������b����
*/

int find_first_char(const char *str)
{
	if (str == NULL){
		return -1;
	}
	int array[26] = { 0 };		//��¼���ִ���
	int order[26] = { 0 },		//��¼����˳��
		i = 0;
	const char *strbak = str;

	//��¼Ԫ�س��ֵĴ�����˳��
	while (*strbak){
		char tmp = *strbak;
		if (array[tmp - 65] == 0){	//ֻ��¼��һ�γ��ֵ�
			order[i++] = tmp;
		}
		array[tmp - 65]++;
		strbak++;
	}

	//����Ԫ�س��ֵ�˳��Ȼ���ڼ�¼���ִ����������в����Ƿ����1��
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