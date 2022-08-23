#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
	void reOrderArray(vector<int> &array) 
	{
		vector <int> jishu, oushu;
		for (int i = 0; i < array.size(); i++)
		{
			if (array[i] % 2 == 0)
			{
				oushu.push_back(array[i]);
			}
			else
			{
				jishu.push_back(array[i]);
			}
		}

		for (int i = 0; i < jishu.size(); i++)
		{
			array[i] = jishu[i];
		}
		for (int j = 0;j < oushu.size(); j++)
		{
			array[j+jishu.size()] = oushu[j];
		}
	}
};

int main(void)
{
	Solution s;
	vector <int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	s.reOrderArray(v);

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "  ";
	}
	cout << endl;


	system("pause");
	return 0;
}