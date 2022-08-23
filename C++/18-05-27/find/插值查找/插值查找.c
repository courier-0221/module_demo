#include <stdio.h>

/*
ǰ�᣺
	��������

���ֲ��ҸĽ���
	�۰�������ֲ��ҷ�ʽ����������Ӧ�ġ�
		mid=(low+high)/2, ��mid=low+1/2*(high-low);
	ͨ����ȣ����ǿ��Խ����ҵĵ�Ľ�Ϊ���£�
		mid=low+(key-a[low])/(a[high]-a[low])*(high-low)

	ͨ�����ַ�ʽ�ҵ���mid���ܴ���high����С��low��Ҫ�ж��¡�
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

/* �ǵݹ�� */
int Search(int *array, int low, int high, int key)
{
	int mid = 0, ret = -1;

	while (low < high)
	{
		mid = low + (high - low) * (key - array[low]) / (array[high] - array[low]);//��ֵ�㷨����
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
	/* �ǵݹ����� */
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