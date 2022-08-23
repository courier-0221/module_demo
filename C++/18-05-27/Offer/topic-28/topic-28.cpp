#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;



class Solution 
{
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) 
	{
		if (numbers.size() < 0)
		{
			return 0;
		}
		int i = 0;
		bool flag = false;
		ListNode *tmp = NULL;
		ListNode *lastnode = NULL;
		int ret = 0;

		for (i = 0; i < numbers.size(); i++)
		{
			tmp = list;
			flag = false;
			if (i == 0)
			{
				ListNode *node = new ListNode(numbers[i]);
				node->count = 1;
				list = node;
				continue;
			}

			while (tmp != NULL)
			{
				if (tmp->val == numbers[i])
				{
					tmp->count++;
					flag = true;
					break;
				}
				lastnode = tmp;
				tmp = tmp->next;
			}

			if (flag == false)
			{
				ListNode *node = new ListNode(numbers[i]);
				node->count = 1;
				lastnode->next = node;
			}
		}
		tmp = list;
		while (tmp != NULL)
		{
			if (tmp->count >= (numbers.size() / 2 + 1))
			{
				ret = tmp->val;
				break;
			}
			//cout << tmp->val << "  " << tmp->count << endl;
			tmp = tmp->next;
		}

		//ÊÍ·ÅÄÚ´æ
		ListNode *p1 = list, *p2 = list->next;
		while (p2 != NULL)
		{
			delete p1;
			p1 = p2;
			p2 = p2->next;
		}

		return ret;
	}
private:
	struct ListNode
	{
		int val;
		int count;
		struct ListNode *next;
		ListNode(int x) :val(x), next(NULL) {}
	};
	ListNode *list;
};



int main(void)
{
	Solution s;

	//1,2,3,2,2,2,5,4,2
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(2);
	v.push_back(2);
	v.push_back(2);
	v.push_back(5);
	v.push_back(4);
	v.push_back(2);

	cout << s.MoreThanHalfNum_Solution(v) << endl;


	system("pause");
	return 0;
}