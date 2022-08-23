#include "strlib.h"



int main(void)
{
	void *str = mystring_create();

	mystring_init(str, "qitiandasheng");
	mystring_print(str);


	printf("length: %d\n", ((mystring *)str)->length);

	backaddchar(str, '!');
	mystring_print(str);
	printf("length: %d\n", ((mystring *)str)->length);

	backaddstring(str, "l like zixia");
	mystring_print(str);
	printf("length: %d\n", ((mystring *)str)->length);

	//printf("find 'd'\n");
	//printf("%s\n", findfirstchar(str, 'd'));

	//printf("find 'tian'\n");
	//printf("%s\n", findfirststring(str, "tian"));
	
	//printf("delete 'qitian'\n");
	//deletefirststring(str, "qitian");
	//mystring_print(str);
	//printf("length: %d\n", ((mystring *)str)->length);

	//printf("add char\t pos = 6,data = '-'\n");
	//addchar(str, '-',6);
	//mystring_print(str);
	//printf("length: %d\n", ((mystring *)str)->length);
	
	/*printf("add char\t pos = 6,data = '<----->'\n");
	addstring(str, "<----->", 14);
	mystring_print(str);
	printf("length: %d\n", ((mystring *)str)->length);*/

	//printf("change '!' to '?'\n");
	//changefirstchar(str, '!', '?');
	//mystring_print(str);
	//printf("length: %d\n", ((mystring *)str)->length);

	printf("change 'qitian' to '----> '\n");
	changefirststring(str, "qitian", "---->");
	mystring_print(str);
	printf("length: %d\n", ((mystring *)str)->length);
	
	//test
	char buf[10] = "01234";
	//printf("%s\n", mystrcat(buf, "5678"));
	//printf("size %d\n", strlen(buf));
	//printf("find 2\n");
	//printf("%s\n", mystrchr(buf, '2'));

	mystring_destroy(str);
	system("pause");
	return 0;
}
