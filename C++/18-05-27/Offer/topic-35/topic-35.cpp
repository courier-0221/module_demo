#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

struct ListNode 
{
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {}
}; 

class Solution 
{
public:
	ListNode* FindFirstCommonNode(ListNode *pHead1, ListNode *pHead2) 
	{
		ListNode *p1 = pHead1;
		ListNode *p2 = pHead2;
		while (p1 != p2)
		{
			p1 = (p1 == NULL ? pHead2 : p1->next);
			p2 = (p2 == NULL ? pHead1 : p2->next);
		}
		return p1;
	}
};

int main(void)
{
	Solution s;
	ListNode node1(1);
	ListNode node2(2);
	ListNode node3(3);
	ListNode node4(4);
	ListNode node5(5);

	node1.next = (ListNode *)&node2;
	node2.next = (ListNode *)&node3;
	node3.next = (ListNode *)&node4;
	node4.next = (ListNode *)&node5;

	ListNode *recv = s.FindFirstCommonNode(&node1, &node2);

	cout <<  recv->val << endl;


	system("pause");
	return 0;
}