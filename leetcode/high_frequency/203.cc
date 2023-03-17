#include <iostream>
using namespace std;

// 移除链表元素
// 思路：构造一个虚拟头节点dummyhead指向头节点然后向后操作，
//      目的是为了代码流程统一，如果头节点是target需要将头节点删除掉，要特殊处理下，非头节点的删除是另一个逻辑

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (nullptr == head)
            return nullptr;
        
        ListNode dummyHead;
        dummyHead.next = head;
        ListNode *cur = &dummyHead;

        while (nullptr != cur->next)
        {
            if (cur->next->val == val)
                cur->next = cur->next->next;
            else
                cur = cur->next;
        }

        return dummyHead.next;
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
    ListNode node1_1(6);
    ListNode node1_2(5, &node1_1);
    ListNode node1_3(4, &node1_2);
    ListNode node1_4(3, &node1_3);
    ListNode node1_5(6, &node1_4);
    ListNode node1_6(2, &node1_5);
    ListNode node1_7(1, &node1_6);

    Solution s;
    ListNode *ret = s.removeElements(&node1_7, 6);

    print_list(ret);
}

void test2(void)
{
    ListNode node1_1(7);
    ListNode node1_2(7, &node1_1);
    ListNode node1_3(7, &node1_2);
    ListNode node1_4(7, &node1_3);

    Solution s;
    ListNode *ret = s.removeElements(&node1_4, 7);

    print_list(ret);
}

void test3(void)
{
    Solution s;
    ListNode *ret = s.removeElements(nullptr, 1);

    print_list(ret);
}


int main(void)
{
    test1();
    test2();
    test3();
    return 0;
}