#include <stdio.h>

//��Ƶ����https://www.iqiyi.com/v_19rrhzzs1k.html

void adjustHeap(int param1, int j, int inNums[]);
void  HeapSort(int nums, int inNums[]);
//����ѽ��е���
void adjustHeap(int param1, int j, int inNums[])
{
	int temp = inNums[param1];
	for (int k = param1 * 2 + 1; k<j; k = k * 2 + 1)
	{
		//����ұ�ֵ�������ֵ��ָ���ұ�
		if (k + 1<j && inNums[k]< inNums[k + 1])
		{
			k++;
		}
		//����ӽڵ���ڸ��ڵ㣬���ӽڵ�ֵ�������ڵ�,�����µ��ӽڵ���Ϊ���ڵ㣨���ý��н�����
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
//��������Ҫ�㷨
void HeapSort(int nums, int inNums[])
{
	//1.�����󶥶�		
	/*�����һ����Ҷ�ӽڵ㿪ʼ�����һ����Ҷ�ӽ�������һ��Ҷ�ӽڵ�ĸ��׽�㣬ʹ�ù�ʽk/2 - 1��ã�kΪ���һ��Ҷ�ӽڵ�*/
	for (int i = nums / 2 - 1; i >= 0; i--)
	{
		//put the value in the final position
		adjustHeap(i, nums, inNums);
	}
	//2.�����ѽṹ+�����Ѷ�Ԫ����ĩβԪ��
	for (int j = nums - 1; j>0; j--)
	{
		//�Ѷ�Ԫ�غ�ĩβԪ�ؽ��н���
		int temp = inNums[0];
		inNums[0] = inNums[j];
		inNums[j] = temp;

		adjustHeap(0, j, inNums);//���¶Զѽ��е���
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

