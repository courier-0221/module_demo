#include <stdio.h>
#define MAXN 20  

/*

<2>��key > a[mid]��low=mid+1,k-=2;
	˵����low=mid+1˵�������ҵ�Ԫ����[mid+1,high]��Χ�ڣ�
	k-=2 ˵����Χ[mid+1,high]�ڵ�Ԫ�ظ���Ϊn-(F(k-1))= Fk-1-F(k-1)=Fk-F(k-1)-1=F(k-2)-1�������Կ��Եݹ��Ӧ��쳲��������ҡ�
<3>��key < a[mid]��high=mid-1,k-=1��
	˵����low=mid+1˵�������ҵ�Ԫ����[low,mid-1]��Χ�ڣ�k-=1 ˵����Χ[low,mid-1]�ڵ�Ԫ�ظ���ΪF(k-1)-1����
	���Կ��Եݹ� ��Ӧ��쳲��������ҡ�

	���ȣ����ǹ���һ��������쳲��������У�Ȼ��ʼ�֣�С�ھ�ȡ��ߵķָF��ΪF-1�����ھ�ȡ�ұߵķָF��ΪF-2��
*/

/*
	����쳲���������
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
	while (len > FBI[k] - 1)          //�����n��쳲������е����� 
	{
		++k;
	}
	for (i = len; i < FBI[k] - 1; ++i) //�����鲹ȫ  
	{
		array[i] = array[high];
	}
	while (low <= high)
	{
		mid = low + FBI[k - 1] - 1;  //����쳲��������н��лƽ�ָ�  
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
			if (mid <= high) //���Ϊ�����ҵ���Ӧ��λ��  
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
		printf("������ĵ�%d��λ���ҵ�Ԫ��\n", res + 1);
	else
		printf("δ���������ҵ�Ԫ��\n");

	system("pause");
	return 0;
}




