#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

//³óÊýp = 2 ^ x * 3 ^ y * 5 ^ z
//https://www.nowcoder.com/profile/5810633/codeBookDetail?submissionId=16629921
class Solution 
{
public:
	int GetUglyNumber_Solution(int index) 
	{
		if (index < 7)
		{
			return index;
		}

		vector<int> res(index);
		res[0] = 1;
		int t2 = 0, t3 = 0, t5 = 0, i;
		for (i = 1; i < index; ++i)
		{
			res[i] = min(res[t2] * 2, min(res[t3] * 3, res[t5] * 5));
			if (res[i] == res[t2] * 2)
				t2++;
			if (res[i] == res[t3] * 3)
				t3++;
			if (res[i] == res[t5] * 5)
				t5++;
		}
		return res[index - 1];
	}
};

int main(void)
{
	Solution s;


	cout << s.GetUglyNumber_Solution(7) << endl;


	system("pause");
	return 0;
}