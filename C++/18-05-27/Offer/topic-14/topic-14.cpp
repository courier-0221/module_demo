#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

class Solution 
{
public:
	ListNode* ReverseList(ListNode* pHead) 
	{
		if (NULL == pHead)
		{
			return NULL;
		}

		ListNode *p1, *p2, *tmp;
		p1 = pHead;
		tmp = pHead;
		p2 = pHead->next;

		while (NULL != p2)
		{
			tmp = p2->next;
			p2->next = p1;
			p1 = p2;
			p2 = tmp;
		}
		pHead->next = NULL;
		return p1;
	}
};


int main(void)
{
	Solution s;

	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(4);
	ListNode n5(5);
	n1.next = (ListNode*)&n2;
	n2.next = (ListNode*)&n3;
	n3.next = (ListNode*)&n4;
	n4.next = (ListNode*)&n5;

	ListNode *recv = s.ReverseList(&n1);

	while (NULL != recv)
	{
		cout << recv->val << "  ";
		recv = recv->next;
	}
	cout << endl;


	system("pause");
	return 0;
}