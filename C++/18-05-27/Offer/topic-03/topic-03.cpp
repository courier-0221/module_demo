#include <iostream>
#include <vector>
using namespace std;


struct ListNode 
{
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) 
	{
		vector <int> v;
		if (NULL == head)
		{
			return v;
		}
		while (NULL != head)
		{
			v.insert(v.begin(), head->val);
			head = head->next;
		}
		return v;
	}
};

int main(void)
{
	int j = 0;
	Solution s;
	vector<int> v;

	ListNode node1(1);
	ListNode node2(2);
	ListNode node3(3);
	ListNode node4(4);
	ListNode node5(5);
	node1.next = (ListNode*)(&node2);
	node2.next = (ListNode*)(&node3);
	node3.next = (ListNode*)(&node4);
	node4.next = (ListNode*)(&node5);

	
	v = s.printListFromTailToHead(&node1);

	for (j = 0; j < v.size(); j++)
	{
		cout << v[j] << "  ";
	}
	cout << endl;

	system("pause");
	return 0;
}