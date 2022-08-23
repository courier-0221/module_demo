#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int jumpFloorII(int number) 
	{
		if (number == 0)
		{
			return number;
		}
			
		int total = 1;
		for (int i = 1; i < number; i++)
		{
			total *= 2;
		}
			
		return total;
	}
};

int main(void)
{
	Solution s;
	cout << s.jumpFloorII(4) << endl;


	system("pause");
	return 0;
}