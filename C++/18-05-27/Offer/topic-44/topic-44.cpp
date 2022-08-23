#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
	bool IsContinuous(vector<int> numbers)
	{
		if (numbers.size() == 0)
		{
			return false;
		}

		vector<int> tmp;
		int index = 0;
		tmp.resize(14);
		for (int i = 0; i<numbers.size(); i++)
		{
			tmp[numbers[i]]++;
		}

		for (int i = 1; i<14; i++)
		{
			if (tmp[i] != 0)
			{
				index = i;
				break;
			}
		}

		for (int i = index + 1; i<index + 5; i++)
		{
			if (tmp[i] == 0 && tmp[0] > 0)
			{
				tmp[i] = 1;
				tmp[0]--;
			}
			else if (tmp[i] == 0 && tmp[0] == 0)
			{
				return false;
			}
		}
		return true;
	}
};

int main(void)
{
	Solution s;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	//v.push_back(6);
	v.push_back(0);

	if (s.IsContinuous(v))
	{
		cout << "is true" << endl;
	}
	else
	{
		cout << "is false" << endl;
	}

	system("pause");
	return 0;
}