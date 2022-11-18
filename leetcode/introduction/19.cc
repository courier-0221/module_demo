#include <iostream>
#include <vector>
using namespace std;

//leetcode 算法入门 第五天 双指针

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    int getLength(ListNode* head)
    {
        int length = 0;
        while (head)
        {
            ++length;
            head = head->next;
        }
        return length;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* dummy = new ListNode(0, head);    //创建一个头部节点，用于考虑删除原链表的头部节点
        int length = getLength(head);
        ListNode* cur = dummy;
        for (int i = 1; i < length - n + 1; ++i)
        {
            cur = cur->next;
        }
        cur->next = cur->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};

int main(void)
{
    return 0;
}