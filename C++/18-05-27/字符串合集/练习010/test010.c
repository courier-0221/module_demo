#include <stdio.h>
#include <assert.h>

/*
题目：
	编写一个 C 函数，该函数在一个字符串中找到可能的最长的子字符串，
	且该字符串是由同一字符组成的。
例如：
	"ddddddd0000000001112236543";
	最长的子串是000000000
*/

//第一次写，程序运行结束后指出了pos位置有问题。
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

//将pos作为函数返回值返回
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
			maxpos = pos;		//保存上一次的值
			*ch = strbak[maxpos];
			L = 1;
			pos = i + 1;
		}
		i++;
	}

	return maxpos;
}

//或者这样
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