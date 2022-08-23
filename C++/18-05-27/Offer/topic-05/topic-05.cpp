#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
	void push(int node) 
	{
		stack1.push(node);
	}

	int pop() 
	{
		int ret = 0;
		while (stack1.size() > 0)
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
		ret = stack2.top();
		stack2.pop();
		while (stack2.size() > 0)
		{
			stack1.push(stack2.top());
			stack2.pop();
		}

		return ret;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

int main(void)
{
	Solution s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;

	system("pause");
	return 0;
}