#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution 
{
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) 
	{
		vector<int> ret;
		if (input.size() == 0 || k <= 0 || k > input.size())
		{
			return ret;
		}

		sort(input.begin(), input.end());

		for (int i = 0; i < k; i++)
		{
			ret.push_back(input[i]);
		}

		return ret;
	}
};

int main(void)
{
	Solution s;

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	v.push_back(9);

	vector<int> recv = s.GetLeastNumbers_Solution(v, 3);

	for (int i = 0; i < recv.size(); i++)
	{
		cout << recv[i] << endl;
	}


	system("pause");
	return 0;
}