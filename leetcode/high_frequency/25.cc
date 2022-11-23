#include <iostream>
#include <vector>
using namespace std;

// K个一组反转链表

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode *head, int k)
    {
        // 创建一个新节点装载链表的头，用于返回
        ListNode *dummy = new ListNode(-1, head);
        ListNode *prev = dummy; // prev节点记录K个节点中的最后一个节点的位置
        while (true)
        {
            // 检查剩余节点是否有k个，不足则返回
            ListNode *last = prev;
            for (int i = 0; i < k; i++)
            {
                last = last->next;
                if (last == nullptr) {
                    return dummy->next;
                }
            }

            // 翻转k个节点
            ListNode *curr = prev->next, *next = nullptr;
            for (int i = 0; i < k - 1; i++)
            {
                next = curr->next;
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
            }
            prev = curr;
        }
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

// 偶数用例
void test1(void)
{
    ListNode node1(1);
    ListNode node2(2, &node1);
    ListNode node3(3, &node2);
    ListNode node4(4, &node3);
    ListNode node5(5, &node4);
    ListNode node6(6, &node5);

    Solution s;
    ListNode *ret = s.reverseKGroup(&node6, 3);

    print_list(ret);
}

// 奇数用例
void test2(void)
{
    ListNode node1(1);
    ListNode node2(2, &node1);
    ListNode node3(3, &node2);
    ListNode node4(4, &node3);
    ListNode node5(5, &node4);
    ListNode node6(6, &node5);
    ListNode node7(7, &node6);

    Solution s;
    ListNode *ret = s.reverseKGroup(&node7, 3);

    print_list(ret);
}


int main(void)
{
    test1();
    test2();

    return 0;
}
