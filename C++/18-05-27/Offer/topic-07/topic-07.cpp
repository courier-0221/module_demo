#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//class Solution 
//{
//public:
//	int Fibonacci(int n) 
//	{
//		if (0 == n || -1 == n)
//		{
//			return 0;
//		}
//
//		if (n == 1)
//		{
//			return 1;
//		}
//
//		return Fibonacci(n - 1) + Fibonacci(n - 2);
//	}
//};

class Solution
{
public:
	int Fibonacci(int n)
	{
		int n1 = 0, n2 = 1, n3 = 0;
		if (0 == n)
		{
			return 0;
		}
		else if (1 == n)
		{
			return 1;
		}

		n = n - 2;

		while (n >= 0)
		{
			n3 = n1 + n2;
			n1 = n2;
			n2 = n3;
			n--;
		}

		return n3;
	}
};

int main(void)
{
	Solution s;

	cout << s.Fibonacci(2) << endl;

	system("pause");
	return 0;
}