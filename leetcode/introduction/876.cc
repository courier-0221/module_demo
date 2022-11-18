#include <iostream>
#include <vector>
using namespace std;

//leetcode 算法入门 第五天 双指针

// 可以使用单指针方法，对链表进行两次遍历。第一次遍历时，我们统计链表中的元素个数 N；第二次遍历时，我们遍历到第 N/2 个元素（链表的首节点为第 0 个元素）时，将该元素返回即可
// 这里使用快慢指针， slow 一次走一步，fast 一次走两步。那么当 fast 到达链表的末尾时，slow 必然位于中间。
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head, *slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
};

int main(void)
{
    ListNode ln6(6);
    ListNode ln5(5, &ln6);
    //ListNode ln5(5);
    ListNode ln4(4, &ln5);
    ListNode ln3(3, &ln4);
    ListNode ln2(2, &ln3);
    ListNode ln1(1, &ln2);
    Solution s;
    ListNode* ret1 = s.middleNode(&ln1);
    printf("%d\n", ret1->val);

    return 0;
}