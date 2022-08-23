#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

/*
借用一个辅助的栈，遍历压栈顺序，先讲第一个放入栈中，这里是1，然后判断栈顶元素是不是出栈顺序的第一个元素，这里是4，很显然1≠4，所以我们继续压栈，直到相等以后开始出栈，出栈一个元素，则将出栈顺序向后移动一位，直到不相等，这样循环等压栈顺序遍历完成，如果辅助栈还不为空，说明弹出序列不是该栈的弹出顺序。

举例：

入栈1,2,3,4,5

出栈4,5,3,2,1

首先1入辅助栈，此时栈顶1≠4，继续入栈2

此时栈顶2≠4，继续入栈3

此时栈顶3≠4，继续入栈4

此时栈顶4＝4，出栈4，弹出序列向后一位，此时为5，,辅助栈里面是1,2,3

此时栈顶3≠5，继续入栈5

此时栈顶5=5，出栈5,弹出序列向后一位，此时为3，,辅助栈里面是1,2,3

….
依次执行，最后辅助栈为空。如果不为空说明弹出序列不是该栈的弹出顺序。 */

class Solution 
{
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) 
	{
		if ((pushV.size() == 0) || (popV.size() == 0))
		{
			return false;
		}

		int i = 0, j = 0;
		stack<int> s;
		for (i = 0; i < pushV.size(); i++)
		{
			s.push(pushV[i]);
			while ((false == s.empty()) && (s.top() == popV[j]))
			{
				s.pop();
				j++;
			}
		}

		if (s.empty() == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

int main(void)
{
	Solution s;

	vector<int> push, pop;
	push.push_back(1);
	push.push_back(2);
	push.push_back(3);
	push.push_back(4);
	push.push_back(5);

	pop.push_back(4);
	pop.push_back(3);
	pop.push_back(5);
	pop.push_back(1);
	pop.push_back(2);

	bool ret = s.IsPopOrder(push, pop);

	if (ret == false)
	{
		cout << "false" << endl;
	}
	else
	{
		cout << "true" << endl;
	}

	system("pause");
	return 0;
}