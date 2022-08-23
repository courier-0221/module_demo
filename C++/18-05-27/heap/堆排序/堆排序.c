#include <stdio.h>

//https://blog.csdn.net/u010339879/article/details/78323451

void Swap(int *array, int begin, int end)
{
	int tmp = array[begin];
	array[begin] = array[end];
	array[end] = tmp;
}

/* ���ֵ����ѵķ�ʽ����������һ����Ҷ�ӽ�㿪ʼ��һֱ���Ѷ�Ԫ�ؽ����� */
void HeapAdjust(int *array, int end, int LastNonLeafNode)
{
	//�������ڵ��±���ӽڵ��±�  
	int dad = LastNonLeafNode;
	int son = dad * 2 + 1;
	while (son <= end) 
	{ 
		if (son + 1 <= end && array[son] < array[son + 1]) //�ȱȽ������ӽڵ��С��ѡ������ 
		{
			son++;
		}
	
		if (array[dad] > array[son])		//������ڵ�����ӽڵ���������ϣ�ֱ����������
		{
			return;
		}
		else								//���򽻻����Ӄ����ٴӺ��ӽ�㿪ʼ�������µ���---> һ��Ҫ����������Ҫ
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
	/* ��ʼ���ѣ�i�����һ����Ҷ�ӽ�㿪ʼ����  */
	/* �������� */
	for (i = len / 2 - 1; i >= 0; i--)
	{
		HeapAdjust(array, len - 1, i);
	}
	/* �Ƚ���һ��Ԫ�غ����ź�Ԫ��ǰһλ���������ٴ��µ�����ֱ��������� */
	for (i = len - 1; i > 0; i--)
	{
		Swap(array, 0, i);
		/* ��һ�ο�ʼ��λ�ò������һ����Ҷ�ӽ���ˣ�����0��ԭ��Ϊ���±�Ϊ0�����Ԫ�غ�����β����Ԫ�ػ����� */
		/* �ٴ�����ʱֱ�ӴӸ��ڵ�����ͺ��ˡ� */
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


