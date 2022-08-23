#define D_SCL_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <iostream>
#include <string>
using namespace std;


class Solution 
{
public:
	void replaceSpace(char *str, int length) 
	{
		int local = 0;
		if ((NULL == str) || (0 == length))
		{
			exit(-1);
		}
		string s(str);

		while ((local = s.find(' ', local)) != string::npos)
		{
			s.replace(local, 1, "%20");
			local += 3;
			local = s.find(' ', local);
		}
		strcpy(str, s.c_str());
		//cout << s << endl;
	}
};

int main(void)
{
	Solution s;
	char buf[128] = "We Are Happy";
	s.replaceSpace(buf, 12);

	cout << buf << endl;

	system("pause");
	return 0;
}