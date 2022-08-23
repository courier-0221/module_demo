#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n == 0)
		{
			return -1;
		}

		int index = 0, tmp = 0, i, j, z;
		child.resize(n);
		for (i = 0; i < n; i++)
		{
			//child.push_back(i);
			child[i] = i;
		}

		index = (m - 1) % child.size();
		while (child.size() != 1)
		{
			if (index == child.size() - 1)
			{
				tmp = child[0];
			}
			else
			{
				tmp = child[index + 1];
			}

			child.erase(child.begin() + index);
			for (j = 0; j < child.size(); j++)
			{
				if (child[j] == tmp)
				{
					z = j;
					break;
				}
			}
			index = (z + m - 1) % child.size();
		}

		return child[0];
	}
private:
	vector<int> child;
};



int main(void)
{
	Solution s;

	cout << s.LastRemaining_Solution(5, 3) << endl;

	system("pause");
	return 0;
}