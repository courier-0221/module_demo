#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

//¶¯Ì¬¹æ»®
class Solution 
{
public:
	int FindGreatestSumOfSubArray(vector<int> array) 
	{
		int maxResult = array[0], resultTmp = array[0];
		for (int i = 1; i < array.size(); i++)
		{
			resultTmp = max(maxResult + array[i], array[i]);
			maxResult = max(maxResult, resultTmp);
		}
		
		return maxResult;
	}
};

int main(void)
{
	Solution s;
	vector<int> v;
	//v.push_back(1);
	//v.push_back(2);
	//v.push_back(3);
	//v.push_back(4);
	//v.push_back(5);
	//v.push_back(-6);
	//v.push_back(7);
	//v.push_back(8);
	//v.push_back(9);

	v.push_back(-6);
	v.push_back(5);

	cout << s.FindGreatestSumOfSubArray(v) << endl;


	system("pause");
	return 0;
}