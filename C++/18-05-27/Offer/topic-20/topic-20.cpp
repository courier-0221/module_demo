#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution 
{
public:
	void push(int value) 
	{
		int i = 0;
		if (v.size() == 0)
		{
			v.push_back(value);
		}
		else
		{
			for (i = 0; i < v.size(); i++)
			{
				if (value > v[i])
				{
					v.push_back(value);
				}
				else
				{
					v.insert(v.begin() + i, value);
					break;
				}
			}
		}
		s.push(value);
	}
	void pop() 
	{
		int i = 0;
		int target = 0;
		if (v.size() == 0)
		{
			return;
		}
		else
		{
			target = s.top();
			for (i = 0; i < v.size(); i++)
			{
				if (target == v[i])
				{
					v.erase(v.begin() + i);
					break;
				}
			}
		}
		s.pop();
	}
	int top() 
	{
		return s.top();
	}
	int min() 
	{
		return v[0];
	}

	stack<int> s;
	vector<int> v;
};

int main(void)
{
	Solution s;

	s.push(5);
	s.push(3);
	s.push(4);
	s.push(1);
	s.push(2);

	cout << s.top() << "  " << s.min() << endl;
	s.pop();

	cout << s.top() << "  " << s.min() << endl;
	s.pop();

	cout << s.top() << "  " << s.min() << endl;
	s.pop();

	cout << s.top() << "  " << s.min() << endl;
	s.pop();

	cout << s.top() << "  " << s.min() << endl;
	s.pop();

	system("pause");
	return 0;
}