#include <stdio.h>
#include <assert.h>

/*
��Ŀ��
	�ж�һ���ַ����ǲ��ǻ���
˼·��
	���ģ���121 ��3443,124421,3456543��Щ
*/


int mystrlen(const char *str)
{
	//��һ�ַ���
	//if (str == NULL){
	//	exit(-1);
	//}

	//if(*str == 0){
	//	return 0;
	//}
	//else{
	//	return mystrlen(str + 1) + 1;
	//}

	//�ڶ��ַ�����һ�����ʵ��,ʹ���˶��ű��ʽ����Ŀ�����
	return (assert(str), (*str ? (mystrlen(str + 1) + 1) : 0));
}


/*
�ɹ���
	����1
ʧ�ܣ�
	����0
*/
int IsReverseStr(const char *str)
{
	char *tmp = str;
	int i = 0;
	if (tmp == NULL){
		return 0;
	}
	int len = mystrlen(tmp);
	
	for (i = 0; i < len; i++){
		if (*(tmp + i) != *(tmp + len - 1 - i)){
			return 0;
		}
	}

	return 1;
}

int main(void)
{
	if (IsReverseStr("12") == 0){
		printf("���ǻ��Ĵ�\n");
	}
	else{
		printf("�ǻ��Ĵ�\n");
	}
	

	system("pause");
	return 0;
}