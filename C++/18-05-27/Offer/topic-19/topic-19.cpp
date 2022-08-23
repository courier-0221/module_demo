#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*解题思路：顺时针打印就是按圈数循环打印，一圈包含两行或者两列，在打印的时候会出现某一圈中只包含一行，要判断从左向右打印和从右向左打印的时候是否会出现重复打印，
同样只包含一列时，要判断从上向下打印和从下向上打印的时候是否会出现重复打印的情况*/



class Solution 
{
public:
	vector<int> printMatrix(vector<vector<int> > matrix) 
	{
		vector<int> ret;
		ret.clear();
		int row = matrix.size();
		int column = matrix[0].size();
		int circle = ((row < column ? row : column) - 1) / 2 + 1;//圈数

		for (int i = 0; i < circle; i++)
		{
			//从左向右打印
			for (int j = i; j < column - i; j++)
			{
				ret.push_back(matrix[i][j]);
			}
			//从上往下的每一列数据
			for (int k = i + 1; k < row - i; k++)
			{
				ret.push_back(matrix[k][column - 1 - i]);
			}
				
			//判断是否会重复打印(从右向左的每行数据)
			for (int m = column - i - 2; (m >= i) && (row - i - 1 != i); m--)
			{
				ret.push_back(matrix[row - i - 1][m]);
			}
				
			//判断是否会重复打印(从下往上的每一列数据)
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
	vector<vector<int> > array(2);  //初始化为两行的二维数组

	for (i = 0; i < 2; i++)
	{
		array[i].resize(5);//设置数组的大小2 * 5
	}

	//使用数组方式使用vector
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 5; j++)
		{
			array[i][j] = i + j;
		}
	}

	//输出
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