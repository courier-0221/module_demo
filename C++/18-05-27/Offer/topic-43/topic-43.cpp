#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	string ReverseSentence(string str)
	{
		string ret;
		int point = 0;
		int key = 0;
		int i = 0, lastKey = 0;
		if (str.length() == 0)
		{
			return ret;
		}

		key = 0;
		lastKey = key;
		while ((key = str.find(' ', key)) != string::npos)
		{
			if (0 == lastKey)
			{
				ret.insert(0, str, lastKey, key - lastKey);
			}
			else
			{
				ret.insert(0, str, lastKey + 1, key - lastKey - 1);
			}
			ret.insert(0, " ");

			lastKey = key;
			key += 1;
		}

		if (0 == lastKey)
		{
			ret.insert(0,str);
		}
		else
		{
			ret.insert(0, str, lastKey + 1, str.length() - lastKey - 1);
		}

		return ret;
	}
};

int main(void)
{
	Solution s;

	cout << s.ReverseSentence("student. a am I") << endl;

	system("pause");
	return 0;
}