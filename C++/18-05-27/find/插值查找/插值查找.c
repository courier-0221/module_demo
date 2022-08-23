#include <stdio.h>

/*
前提：
	数据有序

二分查找改进版
	折半查找这种查找方式，不是自适应的。
		mid=(low+high)/2, 即mid=low+1/2*(high-low);
	通过类比，我们可以将查找的点改进为如下：
		mid=low+(key-a[low])/(a[high]-a[low])*(high-low)

	通过这种方式找到的mid可能大于high或者小于low，要判断下。
*/

int InterpolationSearch(int *array, int low, int high, int key)
{
	int mid = low + (high - low) * (key - array[low]) / (array[high] - array[low]);
	int ret = -1;

	if ((array == NULL) || (low > high) || (mid > high) || (mid < low))
	{
		return -1;
	}

	if (array[mid] == key)
	{
		return mid;
	}
	else if (array[mid] > key)
	{
		ret = InterpolationSearch(array, low, mid - 1, key);
	}
	else if (array[mid] < key)
	{
		ret = InterpolationSearch(array, mid + 1, high, key);
	}
		
	return ret;
}

/* 非递归版 */
int Search(int *array, int low, int high, int key)
{
	int mid = 0, ret = -1;

	while (low < high)
	{
		mid = low + (high - low) * (key - array[low]) / (array[high] - array[low]);//插值算法核心
		if ((mid > high) || (mid < low))
		{
			break;
		}
		if (array[mid] == key)
		{
			ret = mid;
			break;
		}
		else if (array[mid] > key)
		{
			high = mid - 1;
		}
		else if (array[mid] < key)
		{
			low = mid + 1;
		}
	}
	return ret;
}

int main(void)
{
	//int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8 ,10};
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//int array[] = { 1, 12, 18, 22, 47, 56, 77, 78, 91 };
	int len = sizeof(array) / sizeof(*array);

#if 1
	/* 非递归版测试 */
	//if (Search(array, 0, len - 1, 7) >= 0)
	if (Search(array, 0, len - 1, 77) >= 0)
	{
		printf("find\n");
	}
	else
	{
		printf("no find\n");
	}
#endif


#if 0
	if (InterpolationSearch(array, 0, len - 1, 7) >= 0)
	{
		printf("find\n");
	}
	else
	{
		printf("no find\n");
	}
#endif
	
	system("pause");
	return 0;
}