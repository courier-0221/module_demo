#include <stdio.h>

//https://blog.csdn.net/u010339879/article/details/78323451

void Swap(int *array, int begin, int end)
{
	int tmp = array[begin];
	array[begin] = array[end];
	array[end] = tmp;
}

/* 这种调整堆的方式很巧妙，从最后一个非叶子结点开始，一直到堆顶元素结束。 */
void HeapAdjust(int *array, int end, int LastNonLeafNode)
{
	//建立父节点下标和子节点下标  
	int dad = LastNonLeafNode;
	int son = dad * 2 + 1;
	while (son <= end) 
	{ 
		if (son + 1 <= end && array[son] < array[son + 1]) //先比较两個子节点大小，选择最大的 
		{
			son++;
		}
	
		if (array[dad] > array[son])		//如果父节点大于子节点代表调整完毕，直接跳出函数
		{
			return;
		}
		else								//否则交换父子內容再从孩子结点开始继续向下调整---> 一定要理解这里，很重要
		{
			Swap(array, dad, son);
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

void HeapSort(int *array, int len)
{
	if (NULL == array)
	{
		return;
	}
	int i = 0;
	/* 初始化堆，i从最后一個非叶子结点开始调整  */
	/* 建立最大堆 */
	for (i = len / 2 - 1; i >= 0; i--)
	{
		HeapAdjust(array, len - 1, i);
	}
	/* 先将第一個元素和已排好元素前一位做交换，再从新调整，直到排序完毕 */
	for (i = len - 1; i > 0; i--)
	{
		Swap(array, 0, i);
		/* 再一次开始的位置不是最后一个非叶子结点了，而是0的原因为把下标为0的最大元素和数组尾部的元素互换了 */
		/* 再次排序时直接从根节点继续就好了。 */
		HeapAdjust(array, i - 1, 0);
	}
}

int main(void)
{
	int array[] = { 1, 34, 6, 21, 98, 31, 7, 4, 36, 47, 39, 45, 5, 2 };
	int length = sizeof(array) / sizeof(*array);
	
	HeapSort(array, length);

	int i = 0;
	for ( i = 0; i < length; i++)
	{
		printf("%d\t", array[i]);
	}
	printf("\n");


	system("pause");
	return 0;
}


