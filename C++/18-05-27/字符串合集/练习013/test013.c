#include <stdio.h>
#include <assert.h>

/*
��Ŀ��
	����һ�����������һ���ַ�������������
˼·��
	���ַ����е�ÿһ���ַ����ŵ���ʼλ��һ�Σ�Ȼ��Ժ�����ַ��������˲���
*/

int mystrlen(const char *str)
{
	return (assert(str), (*str) ? (mystrlen(str + 1) + 1) : 0);
}

void func(char *str,int begin,int end)
{
	assert(str);
	if (begin < 0 || end < begin){
		exit(-1);
	}

	if (begin == end){
		printf("%s\n", str);
	}
	else{
		int i = 0;
		for (i = begin; i <= end; i++){
			//��ÿһ���ַ����ŵ���ʼλ��һ��
			char frist = str[begin];
			str[begin] = str[i];
			str[i] = frist;

			//��ʣ��Ԫ����ȫ����
			func(str, begin + 1, end);

			//��������
			frist = str[begin];
			str[begin] = str[i];
			str[i] = frist;
		}
		
	}

}





int main(void)
{
	char s[] = "abcd";

	func(s, 0, 3);

	system("pause");
	return 0;
}





