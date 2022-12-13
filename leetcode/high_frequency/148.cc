#include <iostream>
#include <vector>
using namespace std;

// 单链表排序
// 思路：快速排序
// 空间复杂度

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// leetcode提交超时
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* curNode = head, *preNode = head;
        while (nullptr != curNode)
        {
            preNode = curNode;
            curNode = curNode->next;
        }
        subSort(head, preNode);
        return head;
    }

    void subSort(ListNode* low, ListNode* high)
    {
        if (nullptr == low || nullptr == low->next || low == high)
            return;
        
        int pivot = low->val;
        ListNode* i = low->next;
        ListNode* i_pre = low;
        ListNode* j = low->next;

        while (j != high->next)
        {
            if (j->val < pivot)
            {
                swap(i->val, j->val);
                i_pre = i;
                i = i->next;
            }
            j = j->next;
        }
        swap(low->val, i_pre->val);
        subSort(low, i_pre);
        subSort(i, high);
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
    ListNode node1_1(11);
    ListNode node1_2(8, &node1_1);
    ListNode node1_3(6, &node1_2);
    ListNode node1_4(2, &node1_3);
    ListNode node1_5(1, &node1_4);
    ListNode node1_6(5, &node1_5);

    Solution s;
    ListNode *ret = s.sortList(&node1_6);

    print_list(ret);
}

void test2(void)
{
    Solution s;
    ListNode node1_2(0);
    ListNode node1_3(4, &node1_2);
    ListNode node1_4(3, &node1_3);
    ListNode node1_5(5, &node1_4);
    ListNode node1_6(-1, &node1_5);
    ListNode *ret = s.sortList(&node1_6);

    print_list(ret);
}


int main(void)
{
    test1();
    test2();

    return 0;
}