#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

/*对vector容器内的数据进行排序，按照 将a和b转为string后
若 a＋b<b+a  a排在在前 的规则排序,
如 2 21 因为 212 < 221 所以 排序后为 21 2
to_string() 可以将int 转化为string
*/

class Solution 
{
public:
	string PrintMinNumber(vector<int> numbers) 
	{
		string ret;
		if (numbers.size() == 0)
		{
			return ret;
		}

		sort(numbers.begin(), numbers.end(), cmp);

		for (int i = 0; i < numbers.size(); i++)
		{
			ret += to_string(numbers[i]);
		}
		return ret;
	}

	static bool cmp(int a, int b)
	{
		string A, B;
		A = to_string(a) + to_string(b);
		B = to_string(b) + to_string(a);
		return A < B;
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

	cout << s.PrintMinNumber(v) << endl;


	system("pause");
	return 0;
}