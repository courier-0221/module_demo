#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int StrToInt(string str) 
	{
		if (str.length() == 0)
		{
			return 0;
		}

		int i = 0, j = 0, len = str.length() - 1, sum = 0, chengshi = 1, begin = 0, flag = 0;
		if (str[0] == '+')
		{
			begin = 1;
			flag = 1;
		}
		else if (str[0] == '-')
		{
			begin = 1;
			flag = -1;
		}
		else
		{
			begin = 0;
			flag = 1;
		}

		for (i = len; i >= begin; i--)
		{
			chengshi = 1;
			if (str[i] >= 'a')
			{
				return 0;
			}
			else
			{
				for (j = len; j > i; j--)
				{
					chengshi *= 10;
				}
				sum += (str[i] - '0') * chengshi * flag;
			}
		}

		return sum;
	}
};



int main(void)
{
	Solution s;

	cout << s.StrToInt("123") << endl;

	system("pause");
	return 0;
}