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
public :
	ListNode *Merge(ListNode *list1, ListNode *list2)
	{
		if (list1 == NULL)
		{
			return list2;
		}
		if (list2 == NULL)
		{
			return list1;
		}
		if (list1->val <= list2->val)
		{
			list1->next = Merge(list1->next, list2);
			return list1;
		}
		else
		{
			list2->next = Merge(list1, list2->next);
			return list2;
		}
	}
};

//class Solution 
//{
//public:
//	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
//	{
//		if (pHead1 == NULL){
//			return pHead2;
//		}
//		if (pHead2 == NULL){
//			return pHead1;
//		}
//		ListNode *mergeHead = NULL;
//		ListNode *current = NULL;
//		while (pHead1 != NULL && pHead2 != NULL)
//		{
//			if (pHead1->val <= pHead2->val)
//			{
//				if (mergeHead == NULL)
//				{
//					mergeHead = current = pHead1;
//				}
//				else
//				{
//					current->next = pHead1;
//					current = current->next;
//				}
//				pHead1 = pHead1->next;
//			}
//			else
//			{
//				if (mergeHead == NULL)
//				{
//					mergeHead = current = pHead2;
//				}
//				else
//				{
//					current->next = pHead2;
//					current = current->next;
//				}
//				pHead2 = pHead2->next;
//			}
//		}
//		if (pHead1 == NULL)
//		{
//			current->next = pHead2;
//		}
//		else
//		{
//			current->next = pHead1;
//		}
//		return mergeHead;
//	}
//};

int main(void)
{
	Solution s;

	ListNode n1(1);
	ListNode n2(3);
	ListNode n3(5);
	ListNode n4(7);
	ListNode n5(9);
	n1.next = (ListNode*)&n2;
	n2.next = (ListNode*)&n3;
	n3.next = (ListNode*)&n4;
	n4.next = (ListNode*)&n5;

	ListNode n6(2);
	ListNode n7(4);
	//ListNode n8(6);
	//ListNode n9(8);
	//ListNode n10(10);
	n6.next = (ListNode*)&n7;
	//n7.next = (ListNode*)&n8;
	//n8.next = (ListNode*)&n9;
	//n9.next = (ListNode*)&n10;

	ListNode *recv = s.Merge(&n6,&n1);

	while (NULL != recv)
	{
		cout << recv->val << "  ";
		recv = recv->next;
	}
	cout << endl;


	system("pause");
	return 0;
}