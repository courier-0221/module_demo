#include <stdio.h>

//视频讲解https://www.iqiyi.com/v_19rrhzzs1k.html

void adjustHeap(int param1, int j, int inNums[]);
void  HeapSort(int nums, int inNums[]);
//大根堆进行调整
void adjustHeap(int param1, int j, int inNums[])
{
	int temp = inNums[param1];
	for (int k = param1 * 2 + 1; k<j; k = k * 2 + 1)
	{
		//如果右边值大于左边值，指向右边
		if (k + 1<j && inNums[k]< inNums[k + 1])
		{
			k++;
		}
		//如果子节点大于父节点，将子节点值赋给父节点,并以新的子节点作为父节点（不用进行交换）
		if (inNums[k]>temp)
		{
			inNums[param1] = inNums[k];
			param1 = k;
		}
		else
			break;
	}
	//put the value in the final position
	inNums[param1] = temp;
}
//堆排序主要算法
void HeapSort(int nums, int inNums[])
{
	//1.构建大顶堆		
	/*从最后一个非叶子节点开始，最后一个非叶子结点是最后一个叶子节点的父亲结点，使用公式k/2 - 1求得，k为最后一个叶子节点*/
	for (int i = nums / 2 - 1; i >= 0; i--)
	{
		//put the value in the final position
		adjustHeap(i, nums, inNums);
	}
	//2.调整堆结构+交换堆顶元素与末尾元素
	for (int j = nums - 1; j>0; j--)
	{
		//堆顶元素和末尾元素进行交换
		int temp = inNums[0];
		inNums[0] = inNums[j];
		inNums[j] = temp;

		adjustHeap(0, j, inNums);//重新对堆进行调整
	}
}
int main() 
{
	int data[] = { 6, 5, 8, 4, 7, 9, 1, 3, 2 };
	int len = sizeof(data) / sizeof(int);
	HeapSort(len, data);

	for (int i = 0; i < len; i++)
	{
		printf("%d\n", data[i]);
	}

	///*int a = (6 - 1) / 2;*/
	//int a = 5 / 2 - 1;
	//printf("%d\n", a);

	system("pause");
	return 0;
}

