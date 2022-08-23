#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

/*��vector�����ڵ����ݽ������򣬰��� ��a��bתΪstring��
�� a��b<b+a  a������ǰ �Ĺ�������,
�� 2 21 ��Ϊ 212 < 221 ���� �����Ϊ 21 2
to_string() ���Խ�int ת��Ϊstring
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