#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) 
	{
		int count = 0;
		if (data.size() == 0)
		{
			return 0;
		}

		int index = BinarySearch(data, 0, data.size() - 1, k);
		if (index == -1)
		{
			return 0;
		}

		for (int i = index; i >= 0; i--)
		{
			if (data[i] == k)
			{
				count++;
			}
			else
			{
				break;
			}
		}

		for (int i = index + 1; i <data.size(); i++)
		{
			if (data[i] == k)
			{
				count++;
			}
			else
			{
				break;
			}
		}
		return count;
	}
private:
	int BinarySearch(vector<int> data, int low, int high, int k)
	{
		while (low <= high)
		{
			int m = (high + low) / 2;
			if (data[m] == k)
			{
				return m;
			}
			else if (data[m] < k)
			{
				low = m + 1;
			}
			else
			{
				high = m - 1;

			}
		}
		return -1;
	}
};

int main(void)
{
	Solution s;
	vector<int> v;
	v.push_back(1);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	cout << s.GetNumberOfK(v, 3) << endl;


	system("pause");
	return 0;
}