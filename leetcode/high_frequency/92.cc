#include <iostream>
#include <vector>
using namespace std;

// 反转链表II
// 思路：一次遍历， 反转链表(头插法)
// 官方解释很容易理解
// 整体思想是：在需要反转的区间里，每遍历到一个节点，让这个新节点来到反转部分的起始位置。
// 同反转链表差不多，布局3个指针

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        // 设置 dummyNode 是这一类问题的一般做法
        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode *pre = dummyNode;
        // 找到pre
        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }
        ListNode *cur = pre->next;
        ListNode *next;
        for (int i = 0; i < right - left; i++) {
            next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        return dummyNode->next;
    }
};

void print_list(ListNode *head)
{
    while (head)
    {
        printf("%d\t", head->val);
        head = head->next;
    }
    printf("\n");
}

void test1(void)
{
    Solution s;

    ListNode node1(7);
    ListNode node2(6, &node1);
    ListNode node3(5, &node2);
    ListNode node4(4, &node3);
    ListNode node5(3, &node4);
    ListNode node6(2, &node5);
    ListNode node7(1, &node6);

    ListNode *ret = s.reverseBetween(&node7, 1, 6);

    print_list(ret);
}

void test2(void)
{
    Solution s;
    ListNode node1(1);
    
    ListNode *ret = s.reverseBetween(&node1, 1, 1);

    print_list(ret);
}


int main(void)
{
    test1();
    test2();

    return 0;
}