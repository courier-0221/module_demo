#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

/*
����һ��������ջ������ѹջ˳���Ƚ���һ������ջ�У�������1��Ȼ���ж�ջ��Ԫ���ǲ��ǳ�ջ˳��ĵ�һ��Ԫ�أ�������4������Ȼ1��4���������Ǽ���ѹջ��ֱ������Ժ�ʼ��ջ����ջһ��Ԫ�أ��򽫳�ջ˳������ƶ�һλ��ֱ������ȣ�����ѭ����ѹջ˳�������ɣ��������ջ����Ϊ�գ�˵���������в��Ǹ�ջ�ĵ���˳��

������

��ջ1,2,3,4,5

��ջ4,5,3,2,1

����1�븨��ջ����ʱջ��1��4��������ջ2

��ʱջ��2��4��������ջ3

��ʱջ��3��4��������ջ4

��ʱջ��4��4����ջ4�������������һλ����ʱΪ5��,����ջ������1,2,3

��ʱջ��3��5��������ջ5

��ʱջ��5=5����ջ5,�����������һλ����ʱΪ3��,����ջ������1,2,3

��.
����ִ�У������ջΪ�ա������Ϊ��˵���������в��Ǹ�ջ�ĵ���˳�� */

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