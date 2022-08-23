#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
	int rectCover(int number)
	{
		if (0 == number)
		{
			return 0;
		}
		else if (1 == number)
		{
			return 1;
		}
		else if (2 == number)
		{
			return 2;
		}

		number -= 2;
		int n1 = 1, n2 = 2, n3;
		while (number > 0)
		{
			n3 = n2 + n1;
			n1 = n2;
			n2 = n3;
			number--;
		}
		return n3;
	}
};

int main(void)
{
	Solution s;
	cout << s.rectCover(4) << endl;


	system("pause");
	return 0;
}