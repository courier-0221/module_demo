#include <stdio.h>

/*
��Ŀ��
	��ӡ¥�ݣ�ͬʱ��¥���Ϸ���ӡ����Ц����
*/
void main(void)
{
	char b = 219;	//219 -->white
	system("chcp 437");

	int i, j;
	printf("\1\1\n");
	for (i = 0; i < 11; i++){
		for (j = 0; j < i; j++){
			printf("%c%c", b,b);			
		}
		printf("\n");
	}


	system("pause");
}