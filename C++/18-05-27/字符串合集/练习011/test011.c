#include <stdio.h>
#include <assert.h>

/*
��Ŀ��
	���ÿ⺯��,��C����ʵ�ֽ�һ��������ת��Ϊ�ַ���
	0��ascii��ֵΪ48��Ȼ���Դ˵���
*/



void tostr(int num,char *arr)
{
	int i = 0,shu = 0,wei = 0,numbak = num;

	while (numbak != 0){
		numbak = numbak / 10;
		wei++;
	}
	for (i = 0; i < wei; i++){
		shu = num % 10;
		num /= 10;
		arr[wei - i - 1] = shu + 48;
	}
	arr[wei] = 0;
}

int tonum(const char *str)
{
	assert(str);
	int wei = 0,i = 0,result = 0;
	char *strbak = str;
	while (*strbak != 0){
		if ((*strbak < '0') || (*strbak > '9')){
			return -1;
		}
		wei++;
		strbak++;
	}
	strbak = str;
	for (i = 0; i < wei; i++){
		result *= 10;
		result += (strbak[i] - 48);
	}
	return result;
}

int main(void)
{
	//char buf[128];
	//tostr(1234, buf);
	//printf("%s\n", buf);

	printf("%d\n", tonum("123"));

	system("pause");
	return 0;
}