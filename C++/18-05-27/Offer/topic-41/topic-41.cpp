#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution 
{
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) 
	{
		vector<int> ret;
		int end = array.size() - 1;
		int endTmp = end;
		int begin = 0;
		int minSum = 0;

		if (array.size() == 0)
		{
			return ret;
		}

		while (begin < end)
		{
			endTmp = end;
			while (endTmp > begin)
			{
				if ((array[begin] + array[endTmp]) == sum)
				{
					if (minSum == 0)
					{
						minSum = array[begin] * array[endTmp];
					}

					if (minSum >= (array[begin] * array[endTmp]))
					{
						minSum = array[begin] * array[endTmp];
						ret.push_back(array[begin]);
						ret.push_back(array[endTmp]);
					}
					
					end--;
					break;
				}
				endTmp--;
			}
			begin++;
		}

		if (ret.size() != 0)
		{
			sort(ret.begin(), ret.end());
		}
		return ret;
	}
};

int main(void)
{
	Solution s;
	vector<int> v;
	vector<int> recv;

	//v.push_back(1);
	//v.push_back(2);
	//v.push_back(3);
	//v.push_back(4);
	//v.push_back(5);
	//v.push_back(6);
	//v.push_back(7);
	//v.push_back(8);
	//v.push_back(9);
	//v.push_back(10);
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(7);
	v.push_back(11);
	v.push_back(15);



	recv = s.FindNumbersWithSum(v, 15);

	for (int i = 0; i < recv.size(); i++)
	{
		cout << recv[i] << endl;
	}

	system("pause");
	return 0;
}