#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
	int minNumberInRotateArray(vector<int> rotateArray) 
	{
		sort(rotateArray.begin(), rotateArray.end());
		if (rotateArray.empty())
		{
			return 0;
		}
		

		return rotateArray[0];
	}
};

int main(void)
{
	Solution s;
	vector<int> v;
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(1);
	v.push_back(2);

	cout << s.minNumberInRotateArray(v) << endl;

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "  ";
	}
	cout << endl; 

	system("pause");
	return 0;
}