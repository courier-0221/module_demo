#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
题目：
	数组中有一个数字出现的次数超过了数组长度的一半，找出这个数字。
分析：
	（1）删除法：顺序遍历一次数组，每次删除2个数字
	（2）标记法：如果数组长度是有限的，申请一个hasn[65536]的数组，然后把数组值映射到其中，
		最后在顺序遍历hash表从中查找个数超过一半的数
	（3）排序法：先排序，返回数组中间的那个值
*/

/*
第一种方法分析
	用了两个辅助变量。k用于临时存储数组中的数据，j用于存储某个数出现的次数。
	开始时k存储数组中的第一个数,j为0，如果数组出现的数于k相等，则j加1，否则就减1，如果j为0，
		就把当前数组中的数赋给k
	因为指定的数出现的次数大于数组长度的一半，所有j++与j--相抵消之后，最后j的值是大于等于1的，
		k中存的那个数就是出现最多的那个数。
*/

int find(int *array, int len)
{
	if (array == NULL){
		exit(-1);
	}

	int j = 0, k = 0;
	for (int i = 0; i < len; i++){
		if (j == 0){
			k = array[i];
		}

		if (k == array[i]){
			j++;
		}
		else{
			j--;
		}
	}
	return k;
}

int main(void)
{
//	int array[] = { 1, 2, 1 };
//	int array[] = { 1, 1, 1, 2, 4 };
	int array[] = { 1, 2, 2, 4, 2, 6, 2, 4};
	//int array[] = { 1, 3, 3, 3, 2, 2, 2, 1, 1, 2, 1, 1, 4, 1, 1, 4, 1, 1, 1 };
	int len = sizeof(array) / sizeof(*array);
	
	printf("多于数组一半的元素是：%d\n", find(array, len));

	system("pause");
	return 0;
}