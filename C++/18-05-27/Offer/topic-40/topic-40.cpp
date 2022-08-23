#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum) 
	{
		vector<vector<int> > ret;
		
		if (sum == 0)
		{
			return ret;
		}
		int begin = 1, end = 1, sumtmp = 0;
		while (begin <= end)
		{
			end = begin;
			sumtmp = 0;
			if (begin >= sum)
			{
				break;
			}
			while (sumtmp < sum)
			{
				sumtmp += end;
				end++;
			}

			if (sumtmp == sum)
			{
				vector<int> tmp;
				for (int i = begin; i < end; i++)
				{
					tmp.push_back(i);
				}
				ret.push_back(tmp);

			}
			begin++;
		}
		return ret;
	}
};

int main(void)
{
	Solution s;
	vector<vector<int> > recv;



	recv = s.FindContinuousSequence(15);

	for (int i = 0; i < recv.size(); i++)
	{
		for (int j = 0; j < recv[i].size(); j++)
		{
			cout << recv[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;

	system("pause");
	return 0;
}