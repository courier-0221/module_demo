#include <stdio.h>
#include <assert.h>

/*
��Ŀ��
	�����Ƽ�Ƕ��ʽ�������ʦ��һ�����б�����
	���ַ�����"aecbcda"�ҳ����ظ����ַ���ɵ�˳���Ӵ�"aecbd"�������ŵ�ʱ�临�Ӷ�
*/

int mystrlen(const char *str)
{
	return (assert(str), (*str ? (mystrlen(str + 1) + 1) : 0));
}


char *no_repeat_str(char *str)
{
	if (str == NULL)
		return NULL;
	char order[64] = { 0 };			//��¼����˳��
	int charoftimes[128] = { 0 };	//��¼���ִ���

	
	int len = mystrlen(str), i = 0, j = 0;

	for (i = 0; i < len; i++){
		charoftimes[str[i]]++;
		order[i] = str[i];
	}
	char *ret = str;
	for (i = 0; i < len; i++){
		if (charoftimes[order[i]] > 0){
			str[j++] = order[i];
			charoftimes[order[i]] = 0;
		}
	}
	str[j] = 0;
	return str;
}




int main(int argc, char *argv[])
{
	char buf[] = "aecbcda";
	no_repeat_str(buf);
	printf("%s\n", buf);


	system("pause");
	return 0;
}
