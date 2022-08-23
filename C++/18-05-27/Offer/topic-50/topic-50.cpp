#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
	vector<int> multiply(const vector<int>& A) {


		int n = A.size();
		vector<int> B0(n, 1);
		vector<int> B1(n, 1);

		for (int i = 1; i < n; ++i)
		{
			B0[i] = B0[i - 1] * A[i - 1];
		}
		for (int i = n - 2; i >= 0; --i)
		{
			B1[i] = B1[i + 1] * A[i + 1];
		}

		vector<int> B(n, 1);
		for (int i = 0; i < n; ++i)
		{
			B[i] = B0[i] * B1[i];
		}

		return B;


	}
};


int main(void)
{
	Solution s;
	vector<int> input, output;

	input.push_back(1);
	input.push_back(2);
	input.push_back(3);
	input.push_back(4);

	output = s.multiply(input);

	for (int i = 0; i < output.size(); i++)
	{
		cout << output[i] << "   ";
	}

	cout << endl;

	system("pause");
	return 0;
}