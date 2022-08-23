#include <stdio.h>
#include <assert.h>

/*
��Ŀ��
	ѧ�������м�¼��CVTEǶ��ʽ������Ա����
	����һ���ַ���������ַ����������ִ������ٵ��ַ�����������ظ���������������ַ������ַ���
	�������룺��abbccdffgg�������d ���룺��aaabbbccddee�������b
*/
int mystrlen(const char *str)
{
	return (assert(str), (*str ? (mystrlen(str + 1) + 1) : 0));
}


char print_char(char *str)
{
	if (str == NULL){
		return -1;
	}
	int len = mystrlen(str), dayu2 = 1, max = 0;
	char order[64] = { 0 };			//��¼����˳��
	int charoftimes[128] = { 0 };	//��¼���ִ���
	char ret;


	for (int i = 0; i < len; i++){
		order[i] = str[i];
		charoftimes[order[i]]++;
	}

	for (int i = 0; i < 128; i++){
		if (charoftimes[i] == 1){
			dayu2 = 0;
			break;
		}
	}

	if (dayu2 == 1){		//�����ظ������
		for (int i = len - 1; i >= 0; i--){
			if (charoftimes[order[i]] > max){
				max = charoftimes[order[i]];
				ret = order[i];
			}
		}
	}
	else if (dayu2 == 0){	//�е��ַ�û���ظ������
		for (int i = len - 1; i >= 0; i--){
			if (charoftimes[order[i]] == 1){
				ret = order[i];
				break;
			}
		}
	}
	return ret;
}



int main(int argc, char *argv[])
{

	printf("%c\n", print_char("abbccdffgg"));
	printf("%c\n", print_char("aaabbbccddee"));
	system("pause");
	return 0;
}
