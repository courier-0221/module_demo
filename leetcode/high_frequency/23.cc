#include <iostream>
#include <vector>
using namespace std;

// 合并多个有序链表
// 思路：两个一合并，一共合并n-1次
// 空间复杂度O(1)

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode *a, ListNode *b) {
        if ((!a) || (!b)) return a ? a : b;
        ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
        while (aPtr && bPtr) {
            if (aPtr->val < bPtr->val) {
                tail->next = aPtr; aPtr = aPtr->next;
            } else {
                tail->next = bPtr; bPtr = bPtr->next;
            }
            tail = tail->next;
        }
        tail->next = (aPtr ? aPtr : bPtr);
        return head.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ans = nullptr;
        for (size_t i = 0; i < lists.size(); ++i) {
            ans = mergeTwoLists(ans, lists[i]);
        }
        return ans;
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
    vector<ListNode*> arr;
    ListNode node1_1(11);
    ListNode node1_2(8, &node1_1);
    ListNode node1_3(6, &node1_2);
    ListNode node1_4(5, &node1_3);
    ListNode node1_5(4, &node1_4);
    ListNode node1_6(1, &node1_5);

    ListNode node2_1(27);
    ListNode node2_2(19, &node2_1);
    ListNode node2_3(12, &node2_2);
    ListNode node2_4(7, &node2_3);
    ListNode node2_5(3, &node2_4);
    ListNode node2_6(1, &node2_5);

    ListNode node3_1(20);
    ListNode node3_2(18, &node3_1);
    ListNode node3_3(15, &node3_2);
    ListNode node3_4(12, &node3_3);
    ListNode node3_5(2, &node3_4);
    ListNode node3_6(1, &node3_5);

    arr.push_back(&node1_6);
    arr.push_back(&node2_6);
    arr.push_back(&node3_6);

    Solution s;
    ListNode *ret = s.mergeKLists(arr);

    print_list(ret);
}

void test2(void)
{

    vector<ListNode*> arr;
    arr.push_back(nullptr);
    arr.push_back(nullptr);
    arr.push_back(nullptr);
    Solution s;
    ListNode *ret = s.mergeKLists(arr);

    print_list(ret);
}


int main(void)
{
    test1();
    test2();

    return 0;
}