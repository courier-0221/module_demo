#include <stdio.h>
#include <assert.h>

/*
��Ŀ��
	��дһ�� C �������ú�����һ���ַ������ҵ����ܵ�������ַ�����
	�Ҹ��ַ�������ͬһ�ַ���ɵġ�
���磺
	"ddddddd0000000001112236543";
	����Ӵ���000000000
*/

//��һ��д���������н�����ָ����posλ�������⡣
//void serach(const char *str, int *pos, char *ch,int *len)
//{
//	assert(str); assert(pos); assert(ch); assert(len);
//	*len = 0;
//	char *strbak = str,i = 0,L = 1,tmppos = 0;
//
//	while (strbak[i] != 0){
//		if (str[i] == str[i + 1]){
//			L++;
//			printf("%d\n", L);
//		}
//		else if (L > *len){
//			*len = L;
//			*pos = tmppos;
//			*ch = strbak[tmppos];
//			L = 1;
//			tmppos = i+1;
//			
//		}
//		i++;
//	}
//}

//��pos��Ϊ��������ֵ����
int serach(const char *str,  char *ch, int *len)
{
	assert(str); assert(ch); assert(len);
	*len = 0;
	char *strbak = str, i = 0, L = 1, pos = 0,maxpos = 0;

	while (strbak[i] != 0){
		if (str[i] == str[i + 1]){
			L++;
			//printf("%d\n", L);
		}
		else if (L > *len){
			*len = L;
			maxpos = pos;		//������һ�ε�ֵ
			*ch = strbak[maxpos];
			L = 1;
			pos = i + 1;
		}
		i++;
	}

	return maxpos;
}

//��������
int serach2(char *str, char *ch, char *len)
{
	if ((str == NULL) || (ch == NULL) || (len == NULL))return -1;

	int size = strlen(str), pos = 0,count = 1, ret = 0;
	for (int i = 0; i < size; i++){
		if (str[i] == str[i + 1]){
			count++;
			continue;
		}
		if (count > *len){
			*len = count;
			*ch = str[i];
			ret = pos + 1;
		}
		count = 1;
		pos = i;
	}
	return ret;
}

int main(void)
{
	char pos, ch, len;

	pos = serach("ddddd0000000", &ch, &len);

	printf("pos:%d\tlen:%d\tch:%c\n", pos, len, ch);

	system("pause");
	return 0;
}