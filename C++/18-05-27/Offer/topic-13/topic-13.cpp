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

//class Solution 
//{
//public:
//	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) 
//	{
//		int count = 0, i = 0;
//		ListNode *pListTmp = pListHead;
//		if (NULL == pListHead || k <= 0)
//		{
//			return NULL;
//		}
//		//计算链表长度
//		while (pListTmp != NULL)
//		{
//			count++;
//			pListTmp = pListTmp->next;
//		}
//
//		if ((count - k) < 0)  //k和count类型要匹配
//		{
//			return NULL;
//		}
//		pListTmp = pListHead;
//		for (i = 0; i < count - k; i++)
//		{
//			pListTmp = pListTmp->next;
//		}
//
//		return pListTmp;
//	}
//};

/*设置两个指针，p1，p2，先让p2走k-1步，然后再一起走，直到p2为最后一个 时，p1即为倒数第k个节点 */
class Solution
{
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
	{
		ListNode *p1 = pListHead;
		ListNode *p2 = pListHead;
		int num = 0;
		if (NULL == pListHead || k <= 0)
		{
			return NULL;
		}

		while (p1 != NULL)
		{
			if (num >= k)
			{
				p2 = p2->next;
			}
			p1 = p1->next;
			num++;
		}
		return num < k ? NULL : p2;
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

	ListNode *recv = s.FindKthToTail(&n1, 1);

	cout << recv->val << endl;

	system("pause");
	return 0;
}