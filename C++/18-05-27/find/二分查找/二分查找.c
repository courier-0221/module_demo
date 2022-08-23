#include <stdio.h>

/*
ǰ�᣺
	��������
˼�룺
	keyֵ���mid=��low+high��/2λ�õ�Ԫ�رȽϣ��ȽϽ�������������
����1����ȣ�midλ�õ�Ԫ�ؼ�Ϊ����
����2��>��low=mid+1;
    3��<��high=mid-1��
*/

int digui_erfen(int *array, int low, int high, int key)
{
	if ((array == NULL) || (low > high))return -1;
	
	int mid = (low + high) / 2, ret = -1;
	if (array[mid] == key)
	{
		return mid;
	}
	else if (array[mid] > key)
	{
		ret = digui_erfen(array, low, mid - 1, key);
	}
	else if (array[mid] < key)
	{
		ret = digui_erfen(array, mid + 1, high, key);
	}
		
	return ret;
}

int nodigui_erfen(int *array, int low, int high, int key)
{
	if ((array == NULL) || (low > high))return -1;

	int mid = 0, ret = -1;

	while (low < high)
	{
		mid = (low + high) / 2;
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
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int len = sizeof(array) / sizeof(*array);
	//if (digui_erfen(array, 0, len, 9) >= 0)
	//	printf("find\n");
	//else
	//	printf("no find\n");

	if (nodigui_erfen(array, 0, len, 9) >= 0)
	{
		printf("find\n");
	}
	else
	{
		printf("no find\n");
	}
	
	system("pause");
	return 0;
}