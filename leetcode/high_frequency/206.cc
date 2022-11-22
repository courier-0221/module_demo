#include <iostream>
using namespace std;

// 反转链表

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while(cur)
        {
            ListNode *tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }

        return prev;
    }
};

void print_list(ListNode *head)
{
    while (head)
    {
        printf("%d\t", head->val);
        head = head->next;
    }
}

int main(void)
{
    ListNode node1(1);
    ListNode node2(2, &node1);
    ListNode node3(3, &node2);
    ListNode node4(4, &node3);
    ListNode node5(5, &node4);
    ListNode node6(6, &node5);

    Solution s;
    ListNode *ret = s.reverseList(&node6);

    print_list(ret);

    return 0;
}