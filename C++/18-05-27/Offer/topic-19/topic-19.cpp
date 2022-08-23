#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*����˼·��˳ʱ���ӡ���ǰ�Ȧ��ѭ����ӡ��һȦ�������л������У��ڴ�ӡ��ʱ������ĳһȦ��ֻ����һ�У�Ҫ�жϴ������Ҵ�ӡ�ʹ��������ӡ��ʱ���Ƿ������ظ���ӡ��
ͬ��ֻ����һ��ʱ��Ҫ�жϴ������´�ӡ�ʹ������ϴ�ӡ��ʱ���Ƿ������ظ���ӡ�����*/



class Solution 
{
public:
	vector<int> printMatrix(vector<vector<int> > matrix) 
	{
		vector<int> ret;
		ret.clear();
		int row = matrix.size();
		int column = matrix[0].size();
		int circle = ((row < column ? row : column) - 1) / 2 + 1;//Ȧ��

		for (int i = 0; i < circle; i++)
		{
			//�������Ҵ�ӡ
			for (int j = i; j < column - i; j++)
			{
				ret.push_back(matrix[i][j]);
			}
			//�������µ�ÿһ������
			for (int k = i + 1; k < row - i; k++)
			{
				ret.push_back(matrix[k][column - 1 - i]);
			}
				
			//�ж��Ƿ���ظ���ӡ(���������ÿ������)
			for (int m = column - i - 2; (m >= i) && (row - i - 1 != i); m--)
			{
				ret.push_back(matrix[row - i - 1][m]);
			}
				
			//�ж��Ƿ���ظ���ӡ(�������ϵ�ÿһ������)
			for (int n = row - i - 2; (n > i) && (column - i - 1 != i); n--)
			{
				ret.push_back(matrix[n][i]);
			}
				
		}
		return ret;
	}
};

int main(void)
{
	Solution s;
	int i = 0, j = 0;
	vector<vector<int> > array(2);  //��ʼ��Ϊ���еĶ�ά����

	for (i = 0; i < 2; i++)
	{
		array[i].resize(5);//��������Ĵ�С2 * 5
	}

	//ʹ�����鷽ʽʹ��vector
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 5; j++)
		{
			array[i][j] = i + j;
		}
	}

	//���
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 5; j++)
		{
			cout << array[i][j] << "   ";
		}
		cout << endl;
	}


	system("pause");
	return 0;
}