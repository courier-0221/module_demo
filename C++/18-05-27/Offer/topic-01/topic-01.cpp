#include <iostream>
#include <vector>
using namespace std;


class Solution
{
public:
	bool Find(int target, vector<vector<int> > array)
	{
		if (array.empty())
		{
			return false;
		}
		//int row = array.size();
		//int column = array[0].size();
		int i = 0, j = 0;

		for (i = 0; i < array.size(); i++)
		{
			if (array[i].empty())
			{
				continue;
			}

			j = array[i].size() / 2 + 1;
			if (target == array[i][j])
			{
				return true;
			}
			else if (target > array[i][j])
			{
				int tmp = j;
				for (tmp = j; tmp < array[0].size(); tmp++)
				{
					if (target == array[i][tmp])
					{
						return true;
					}
				}
			}
			else if (target < array[i][j])
			{
				int tmp = 0;
				for (tmp = 0; tmp < j; tmp++)
				{
					if (target == array[i][tmp])
					{
						return true;
					}
				}
			}
		}
		return false;
	}
};

int main(void)
{


	Solution s1;
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

	if (s1.Find(30, array))
	{
		cout << "find" << endl;
	}
	else
	{
		cout << "no find" << endl;
	}


	array.resize(4);
	array[2].resize(5);
	array[3].resize(5);
	//现在是4 * 5的数组了
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 5; j++)
		{
			array[i][j] = i + j;
		}
	}

	for (i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << array[i][j] << "   ";
		}
		cout << endl;
	}

	if (s1.Find(8, array))
	{
		cout << "find" << endl;
	}
	else
	{
		cout << "no find" << endl;
	}



	system("pause");
	return 0;
}