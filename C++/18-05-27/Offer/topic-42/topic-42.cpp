#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
	string LeftRotateString(string str, int n)
	{
		string ret;
		int len = 0;
		if (str.length() == 0)
		{
			return ret;
		}
		if ((n >= str.length() && str.length() % n == 0) || (n == 0))
		{
			return str;
		}
		else if (n >= str.length() && str.length() % n != 0)
		{
			len = n % str.length();
		}
		len = n;

		//string &insert(int p0,const string &s, int pos, int n);——在p0位置插入字符串s从pos开始的连续n个字符
		ret.insert(0, str, len, str.length() - len);
		//cout << ret << endl;
		ret.insert(ret.length(), str, 0, len);
		//cout << ret << endl;

		return ret;
	}
};

int main(void)
{
	Solution s;

	cout << s.LeftRotateString("abcXYZdef", 3) << endl;

	system("pause");
	return 0;
}