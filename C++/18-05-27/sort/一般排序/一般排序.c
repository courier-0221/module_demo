#include <stdio.h>
#include <assert.h>
#include <string.h>


/*
题目：
	有N个大小不等的自然数（1--N），请将它们由小到大排序。
要求程序算法：
	时间复杂度为O(n)，空间复杂度为O(1)。
*/
void sortOnorder1(int *array, int len)
{
	assert(array);
	for (int i = 0; i < len;)
	{
		//判断下标和值满不满足对应关系
		if (i + 1 == array[i])			//满足，i++，计算下一个元素
		{
			i++;
		}
		else		//不满足，将下标为i中的元素和这个元素值相等的下标值中存储的元素互换
		{
			int tmp = array[array[i] - 1];
			array[array[i] - 1] = array[i];
			array[i] = tmp;
		}
	}
}

int main01(void)
{
	int arr[] = { 10, 1, 3, 4, 2, 9, 6, 8, 5, 7 };
	sortOnorder1(arr, sizeof(arr) / sizeof(*arr));
	for (int i = 0; i < sizeof(arr) / sizeof(*arr); i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}


/*
注意有这样一个题目，要注意区分
题目：
	某公司有几万名员工，请完成一个时间复杂度为 O(n)的算法对该公司员工的年龄作排序，
	可使用O(1)的辅助空间。
注意：
	这个题目中元素是重复的，
	上一个题目中元素不能重复
思路：
	和上面的差不多
*/

void SortAges(int *ages, int num)
{
	assert(ages);
	int timesofages[100] = {0};
	
	for (int i = 0; i < num; i++)
	{
		timesofages[ages[i]]++;
	}

	int index = 0;
	for (int i = 0; i < 100; i++)
	{
		while (timesofages[i]>0)
		{
			ages[index] = i;
			timesofages[i]--;
			index++;
		}
	}
}

int main(void)
{
	int ages[] = { 13, 43, 35, 7, 58, 6, 32, 9, 65, 22, 47, 45, 7, 47, 78, 5, 32, 68, 67, 54, 34, 43, 56, 45 };
	SortAges(ages, sizeof(ages) / 4);
	for (int i = 0; i<sizeof(ages) / 4; i++)
	{
		printf("%d\t", ages[i]);
	}
	printf("\n");


	system("pause");
	return 0;
}