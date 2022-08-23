#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		if (n < 1)
		{
			return 0;
		}
		int i = 0, tmp = 0, count = 0;
		for (i = 0; i <= n; i++)
		{
			tmp = i;
			while (tmp != 0)
			{
				if (tmp % 10 == 1)
				{
					count++;
				}
				tmp = tmp / 10;
			}
		}
		return count;
	}
};

int main(void)
{
	Solution s;


	cout << s.NumberOf1Between1AndN_Solution(15) << endl;


	system("pause");
	return 0;
}