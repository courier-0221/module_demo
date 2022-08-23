#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution 
{
public:
	int FirstNotRepeatingChar(string str) 
	{
		if (str.size() == 0)
		{
			return -1;
		}

		char tmp[256] = { 0 };
		for (int i = 0; i < str.size(); i++)
		{
			tmp[str[i]]++;
		}

		for (int i = 0; i < str.size(); i++)
		{
			if (tmp[str[i]] == 1)
			{
				return i;
			}
		}

		return -1;
	}
};

int main(void)
{
	Solution s;
	string str("1123434");

	cout << s.FirstNotRepeatingChar(str) << endl;


	system("pause");
	return 0;
}