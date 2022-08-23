#include <stdio.h>
#define MAXN 20  

/*

<2>、key > a[mid]，low=mid+1,k-=2;
	说明：low=mid+1说明待查找的元素在[mid+1,high]范围内，
	k-=2 说明范围[mid+1,high]内的元素个数为n-(F(k-1))= Fk-1-F(k-1)=Fk-F(k-1)-1=F(k-2)-1个，所以可以递归的应用斐波那契查找。
<3>、key < a[mid]，high=mid-1,k-=1。
	说明：low=mid+1说明待查找的元素在[low,mid-1]范围内，k-=1 说明范围[low,mid-1]内的元素个数为F(k-1)-1个，
	所以可以递归 的应用斐波那契查找。

	首先，我们构造一个完整的斐波那契数列，然后开始分，小于就取左边的分割，F变为F-1；大于就取右边的分割，F变为F-2。
*/

/*
	产生斐波那契数列
 */
void Fibonacci(int *FBI)
{
	int i;
	FBI[0] = 1;
	FBI[1] = 1;
	for (i = 2; i < MAXN; ++i)
	{
		FBI[i] = FBI[i - 2] + FBI[i - 1];
	}
		
}

int FibonacciSearch(int *array, int len, int key)
{
	int i, low = 0, high = len - 1;
	int mid = 0;
	int k = 0;
	int FBI[MAXN];
	Fibonacci(FBI);
	while (len > FBI[k] - 1)          //计算出n在斐波那契中的数列 
	{
		++k;
	}
	for (i = len; i < FBI[k] - 1; ++i) //把数组补全  
	{
		array[i] = array[high];
	}
	while (low <= high)
	{
		mid = low + FBI[k - 1] - 1;  //根据斐波那契数列进行黄金分割  
		if (array[mid] > key)
		{
			high = mid - 1;
			k = k - 1;
		}
		else if (array[mid] < key)
		{
			low = mid + 1;
			k = k - 2;
		}
		else
		{
			if (mid <= high) //如果为真则找到相应的位置  
			{
				return mid;
			}
			else
			{
				return -1;
			}	
		}
	}
	return -1;
}

int main()
{
	int array[MAXN] = { 5, 15, 19, 20, 25, 31, 38, 41, 45, 49, 52, 55, 57 };
	int res = 0;

	res = FibonacciSearch(array, 13, 14);
	if (res != -1)
		printf("在数组的第%d个位置找到元素\n", res + 1);
	else
		printf("未在数组中找到元素\n");

	system("pause");
	return 0;
}




