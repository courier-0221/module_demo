#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
	void FindNumsAppearOnce(vector<int> array, int* num1, int* num2)
	{
		int length = array.size();
		if (length == 2){
			*num1 = array[0];
			*num2 = array[1];
			return;
		}
		int bitResult = 0;
		for (int i = 0; i < length; ++i)
		{
			bitResult ^= array[i];
		}
		int index = findFirst1(bitResult);
		for (int i = 0; i < length; ++i)
		{
			if (isBit1(array[i], index))
			{
				*num1 ^= array[i];
			}
			else
			{
				*num2 ^= array[i];
			}
		}
	}

private:
	int findFirst1(int bitResult)
	{
		int index = 0;
		while (((bitResult & 1) == 0) && index < 32)
		{
			bitResult >>= 1;
			index++;
		}
		return index;
	}

private:
	bool isBit1(int target, int index)
	{
		return ((target >> index) & 1) == 1;
	}
};

int main(void)
{
	int num1, num2;
	Solution s;
	vector<int> v;
	
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);

	s.FindNumsAppearOnce(v, &num1, &num2);
	//cout << num1 << num2 << endl;
	printf("%u %u\n", num1, num2);


	system("pause");
	return 0;
}