#include <iostream>
#include <vector>
using namespace std;

// 重排链表
// 简单粗暴的解法，把链表存储到数组中，然后用下标依次从头尾取元素即可

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) 
    {
        vector<int> stor;
        ListNode *curr = head;
        // 存储链表中的值到数组
        while (curr)
        {
            stor.push_back(curr->val);
            curr = curr->next;
        }

        // 偶数链表下标位置从数组头部取值，奇数链表下标位置从数组尾部取值
        int start = 0, end = stor.size() - 1, index = 0;
        curr = head;
        while (curr)
        {
            if (0 == index % 2)
            {
                curr->val = stor[start++];
            }
            else
            {
                curr->val = stor[end--];
            }
            index++;
            curr = curr->next;
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
    s.reorderList(&node6);

    print_list(&node6);
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
    s.reorderList(&node7);

    print_list(&node7);
}


int main(void)
{
    test1();
    test2();

    return 0;
}