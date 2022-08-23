#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
题目：
	要求输出国际象棋棋盘。
分析：
	规格8 * 8	1-8，A-H
	第一行，2,4,6,8是黑色的
	第二行，1,3,5,7是黑色的
	偶数行的奇数位是黑色的，偶数行是白色的
	奇数行的偶数位是白色的，奇数行是黑色的

	简便方法是行 + 列如果是奇数黑色，如果是偶数白色
*/

void main(void)
{
	char a = 176, b = 219;	//219 -->white
	system("chcp 437");//该语句调用 chcp 命令，将控制台的活动代码页改为 437（United States）
						//代码页是字符集编码的别名，也称"内码表"。
	
	int i, j;
	//for (i = 1; i <= 8; i++){	//行
	//	for (j = 1; j <= 8; j++){	//列
	//		if (i % 2 == 0){	//偶
	//			if (j % 2 == 0){//偶
	//				printf("%c", b);
	//			}
	//			else{
	//				printf("%c", a);
	//			}
	//		}else{
	//			if (j % 2 == 0){
	//				printf("%c", a);
	//			}
	//			else{
	//				printf("%c", b);
	//			}
	//		}
	//	
	//	}
	//	printf("\n");
	//}
	for (i = 0; i<8; i++)
	{
		for (j = 0; j<8; j++)
		if ((i + j) % 2 == 0)
			printf("%c", 219);
		else
			printf(" ");
		printf("\n");
	}


	system("pause");
}