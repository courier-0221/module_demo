#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
	int Sum_Solution(int n) 
	{
		return (n > 0 ? (Sum_Solution(n - 1) + n) : 0);
	}
};



int main(void)
{
	Solution s;

	cout << s.Sum_Solution(5) << endl;

	system("pause");
	return 0;
}