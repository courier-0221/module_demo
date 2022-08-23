#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
题目：
	猴子吃桃问题：猴子第一天摘下若干个桃子，当即吃了一半，还不瘾，又多吃了一个第二天早上又将剩下的桃子吃掉一半，又多吃了一个。
	以后每天早上都吃了前一天剩下的一半零一个。到第10天早上想再吃时，见只剩下一个桃子了。求第一天共摘了多少。
*/

int monkeys_eat_peach(int num)
{
	if (num == 1){
		return 1;
	}
	return ((monkeys_eat_peach(num - 1) + 1) * 2);
}


int main(void)
{
	printf("第一天摘了 %d 个桃子\n", monkeys_eat_peach(10));
	system("pause");
	return 0;
}





