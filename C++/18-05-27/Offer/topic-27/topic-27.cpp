#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution 
{
private:
	void Perm(string str, int begin, int end)
	{
		if ((0 <= begin) && (begin <= end))
		{
			if (begin == end)
			{
				//cout << str << endl;
				ret.push_back(str);
			}
			else
			{
				int i = 0;
				for (i = begin; i < end; i++)
				{
					if (i != begin && str[begin] == str[i])
					{
						continue;
					}

					char c = str[begin];
					str[begin] = str[i];
					str[i] = c;

					Perm(str, begin + 1, end);

					c = str[begin];
					str[begin] = str[i];
					str[i] = c;
				}
			}
		}
	}
	vector<string> ret;
public:
	vector<string> Permutation(string str)
	{
		if (str.length() == 0)
		{
			return ret;
		}
		Perm(str, 0, str.length());
		sort(ret.begin(), ret.end());
		return ret;
	}
};



void permutation(char s[], int b, int e)
{
	if ((0 <= b) && (b <= e))
	{
		if (b == e)
		{
			printf("%s\n", s);
		}
		else
		{
			int i = 0;

			for (i = b; i <= e; i++)
			{
				char c = s[b];
				s[b] = s[i];
				s[i] = c;

				permutation(s, b + 1, e);

				c = s[b];
				s[b] = s[i];
				s[i] = c;
			}
		}
	}
}

int main(void)
{
	Solution s;
	string str("abc");
	vector<string> recv = s.Permutation(str);

	for (int i = 0; i < recv.size(); i++)
	{
		cout << recv[i] << endl;
	}


	//char s[] = "abc";
	//permutation(s, 0, 2);

	system("pause");
	return 0;
}