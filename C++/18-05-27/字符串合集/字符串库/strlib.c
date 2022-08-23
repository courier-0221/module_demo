#define _CRT_SECURE_NO_WARNINGS	
#include "strlib.h"


//官方库仿写

void* mymemset(void *s, int c, unsigned int count)
{
	char *xs = s;
	while (count--)
		*xs++ = c;
	return s;
}


void *mymemcpy(void *dest, const void *src, unsigned int count)
{
	char *tmp = dest;
	const char *s = src;

	while (count--){
		*tmp++ = *s++;
	}
	return dest;
}



int  mystrlen(const char* str)
{
	int ret = 0;
	if (*str == 0){
		return ret;
	}
	else{
		//ret = mystrlen(str + 1);
		//ret += 1;
		return mystrlen(str + 1) + 1;
	}

	//return ret;
}
char *mystrcpy(char* dst, const char* src)
{
	if ((!dst) || (!src)){
		return NULL;
	}
	char *form = src, *to = dst;
	//while (*form != 0){
	//	*to = *form;
	//	form++;
	//	to++;
	//}
	//*to = 0;
	while ((*to++ = *form++) != 0);


	return dst;
}

char *mystrcat(char* dst, const char* src)
{
	if ((!dst) || (!src)){
		return NULL;
	}
	char *from = src, *to = dst;
	while (*to != 0){
		to++;
	}
	while ((*to++ = *from++) != 0);


	//while (*from != 0){
	//	*to = *from;
	//	to++;
	//	form++;
	//}
	//*to = 0;

	return dst;
}

char *mystrchr(char *dst, char ch)
{
	if (!dst){
		return NULL;
	}

	while (*dst != 0){
		if (*dst == ch){
			return dst;
		}
		dst++;
	}
	return NULL;
}

char *mystrstr(const char* const dst, const char *string)
{
	if ((!dst) || (!string)){
		return NULL;
	}
	char *dstbak = dst;

	while (*dstbak != 0){
		char *nowdstbak = dstbak;
		char *stringbak = string;
		int flag = 1;	//定义一个标志位，先假定找到了(flag = 1代表找到)

		while (*stringbak != 0 && *nowdstbak != 0){
			
			if (*stringbak != *nowdstbak){
				flag = 0;	//只要有一个元素不相等，直接判定不相同
			}
			nowdstbak++;
			stringbak++;
		}
	
		if (flag == 1){
			return dstbak;
		}
	
		dstbak++;
	}
	return NULL;
}





void *mystring_create(void)
{
	mystring *str = (mystring *)malloc(sizeof(mystring));
	if (!str){
		printf("malloc error\n");
		return NULL;
	}

	str->length = 0;
	str->p = NULL;

	return str;
}
void mystring_destroy(void *str)
{
	free(str);
	str = NULL;
}

void mystring_init(void *str, char *copystring)
{
	if ((!str) || (!copystring)){
		printf("An error in %s\n", error(mystring_init));
		exit(-1);
	}
	mystring *mystr = (mystring *)str;
	int len = mystrlen(copystring);
	mystr->p = (char *)calloc(len + 1, sizeof(char));
	if (!mystr->p){
		printf("malloc error\n");
		exit(-1);
	}
	mystrcpy(mystr->p, copystring);
	mystr->length = len + 1;

}
void mystring_print(void *str)
{
	if (!str){
		exit(-1);
	}
	mystring *mystr = (mystring *)str;
	printf("%s\n", mystr->p);
}

void backaddchar(void *str, char ch)
{
	if (!str){
		exit(-1);
	}
	mystring *mystr = (mystring *)str;
	if ((mystrlen(mystr->p) + 1) >= mystr->length){
		mystr->p = realloc(mystr->p, mystr->length + 1);
		if (!mystr->p){
			exit(-1);
		}
		mystr->length++;
		mystr->p[mystr->length - 2] = ch;
		mystr->p[mystr->length - 1] = 0;
	}
	else
	{
		mystr->p[mystrlen(mystr->p)] = ch;
		mystr->p[mystrlen(mystr->p)+1] = 0;
		mystr->length++;
	}
}
void backaddstring(void *str, char *string)
{
	if ((!str) || (!string)){
		exit(-1);
	}
	mystring *mystr = (mystring *)str;
	int nowlength = mystrlen(mystr->p);
	int addlength = mystrlen(string);

	if ((mystr->length + addlength) >= mystr->length){
		mystr->p = realloc(mystr->p, mystr->length + addlength);
		if (!mystr->p){
			exit(-1);
		}
		
		mystrcat(mystr->p, string);
		mystr->length = addlength + nowlength + 1;
	
	}
	else{
		mystrcat(mystr->p, string);
		mystr->length = addlength + nowlength + 1;
	}

}

char *findfirstchar(void *str, const char ch)
{
	if (!str){
		return NULL;
	}
	mystring *mystr = (mystring *)str;
	
	return mystrchr(mystr->p, ch);
}

char *findfirststring(void *str, const char *string)
{
	if ((!str) || (!string)){
		return NULL;
	}
	mystring *mystr = (mystring *)str;	
	return mystrstr(mystr->p, string);
}

void deletefirstchar(void *str, const char ch)
{
	if (!str){
		exit(-1);
	}
	mystring *mystr = (mystring *)str;
	
	char *now = mystrchr(mystr->p,ch);
	char *nownext = now + 1;
	if (!now){
		printf("no find\n");
		return;
	}
	while (*nownext != 0){
		*now = *nownext;
		now++;
		nownext++;
	}
	*now = 0;
	mystr->length--;
}
void deletefirststring(void *str, const char *string)
{
	if ((!str) || (!string)){
		exit(-1);
	}
	mystring *mystr = (mystring *)str;

	char *now = mystrstr(mystr->p, string);
	int len = mystrlen(string);
	char *nownext = now + len;
	if (!now){
		printf("no find\n");
		return;
	}
	while (*nownext != 0){
		*now = *nownext;
		nownext++;
		now++;
	}
	*now = 0;
	mystr->length -= len;
}

char *delete_all_char(char *str, char ch)
{
	if (str == NULL){
		return NULL;
	}
	char *ret = str, *tmp = str;
	while (*tmp){
		if (*tmp != ch){
			*str++ = *tmp;
		}
		tmp++;
	}
	*str = 0;
	return ret;
}

void addchar(void *str, char ch, int pos)
{
	if (!str){
		exit(-1);
	}
	mystring *mystr = (mystring *)str;
	int now_length = mystrlen(mystr->p);
	int move_length = mystrlen(mystr->p + pos);
	if ((mystrlen(mystr->p) + 1) >= mystr->length){
		mystr->p = realloc(mystr->p, mystr->length + 1);
		mystr->length++;

		for (int i = now_length; i > (now_length - move_length); i--){
			mystr->p[i] = mystr->p[i - 1];
		}
		mystr->p[now_length - move_length] = ch;
		mystr->p[now_length + 1] = 0;
	}
	else{
		mystr->length++;

		for (int i = now_length; i > (now_length - move_length); i--){
			mystr->p[i] = mystr->p[i - 1];
		}
		mystr->p[now_length - move_length] = ch;
		mystr->p[now_length + 1] = 0;
	}

}
void addstring(void *str, char *string, int pos)
{
	if (!str){
		exit(-1);
	}
	mystring *mystr = (mystring *)str;
	int now_length = mystrlen(mystr->p);
	int move_length = mystrlen(mystr->p + pos);
	int add_len = mystrlen(string);
	if ((mystrlen(mystr->p) + add_len) >= mystr->length){
		mystr->p = realloc(mystr->p, mystr->length + add_len + 1);
		mystr->length += add_len;

		for (int i = now_length; i >= (now_length - move_length); i--){
			mystr->p[i + add_len] = mystr->p[i];
		}
		for (int i = 0; i < add_len; i++){
			mystr->p[now_length - move_length + i] = *(string + i);
		}
		
		mystr->p[now_length + add_len] = 0;
	}
	else{
		mystr->length += add_len;

		for (int i = now_length; i >= (now_length - move_length); i--){
			mystr->p[i + add_len] = mystr->p[i];
		}
		for (int i = 0; i < add_len; i++){
			mystr->p[now_length - move_length + i] = *(string + i);
		}

		mystr->p[now_length + add_len] = 0;
	}

}

void changefirstchar(void *str, const char oldchar, const char newchar)
{
	if (!str){
		exit(-1);
	}
	mystring *mystr = (mystring *)str;
	char *first = strchr(mystr->p, oldchar);
	if (!first){
		printf("no find\n");
	}
	*first = newchar;
	
}
void changefirststring(void *str, char *const oldstring, char *const newstring)
{
	if ((!str) || (!oldstring) || (!newstring)){
		exit(-1);
	}
	mystring *mystr = (mystring *)str;
	char *first = mystrstr(mystr->p, oldstring);
	if (!first){
		printf("no find\n");
	}
	int len = first - mystr->p;
	deletefirststring(str, oldstring);
	addstring(str, newstring, len);

}
