#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/****************************************************
��Ŀ��
	��һ���ַ��������еĿո��ɾȥ,
	����:ԭ����sΪ"abc de fg"ɾ����Ĵ�s��Ϊ"abcdefg" 
*****************************************************/

char *deletespace(char *str)
{
	if (!str){
		return NULL;
	}
	int len = strlen(str);
	int i = 0,spacecount = 0;
	for (i = 0; i < len; i++){
		if (*(str + i) == ' '){
			spacecount++;
			char *start = str + i;
			int move_len = strlen(str + i + 1);
			int j = 0;
			for (j = 0; j < move_len; j++){
				start[j] = start[j + 1];
			}
			//printf("%s\n", start);
			//printf("%d\n", move_len);
		}
	}

	*(str + (len - spacecount)) = 0;
	return str;
}

//�Ż���	--2018��8��29��15:50:26
char *deletespace2(char *str)
{
	if (str == NULL){
		return NULL;
	}
	char *strbak = str, *ret = str;
	while (*strbak != 0){
		if (*strbak != ' '){
			*str++ = *strbak;
		}
		strbak++;
	}
	*str = 0;
	return ret;
}

int main(void){

	char str[30] = "abc de fg";
	printf("%s\n", deletespace2(str));

	system("pause");
	return 0;
}
