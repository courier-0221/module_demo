#include <stdio.h>
#include <assert.h>

/*
��Ŀ��
	�ж��ַ����Ƿ��л����ַ��Ӵ�
˼·��
	ö���ַ�����ÿ��λ�ã���Ϊ���Ĵ����м�λ��(��ż�������������)��
	����ҵ������Ҳ�����������ֹͣ�������ܵĸ��ӶȲ�����O(n)
*/

int if_huiwen(const char *str)
{
	assert(str);
	char *strbak = str + 1;
	while (*strbak != 0){
		
		if (*strbak == *(strbak - 1)){				//ż�����
			return 1;
		}
		else if(*(strbak - 1) == *(strbak + 1)){	//�������
			return 1;
		}
		strbak++;
	}
	return 0;
}

int main(void)
{

	if (if_huiwen("sdg121fh") == 1){
		printf("�ô��к��л���\n");
	}
	else{
		printf("�ô��в����л���\n");
	}


	system("pause");
	return 0;
}
