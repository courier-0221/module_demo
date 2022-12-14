#include <iostream>
#include <vector>
using namespace std;

// 合并二叉树
// 思路：
// 两棵树同步访问每个位置的节点，然后构造新的树节点，自顶向下构建

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr) {
            return t2;
        }
        if (t2 == nullptr) {
            return t1;
        }
        // 创建新节点 初始化val
        TreeNode* merged = new TreeNode(t1->val + t2->val);
        // 新节点的left
        merged->left = mergeTrees(t1->left, t2->left);
        // 新节点的right
        merged->right = mergeTrees(t1->right, t2->right);
        return merged;
    }
};

// 先序遍历二叉树
void preorder_print(TreeNode *root)
{
    if (nullptr == root)
    {
        return;
    }

    printf("%d\t", root->val);
    preorder_print(root->left);
    preorder_print(root->right);
}

void test1(void)
{
    TreeNode node1_1(1);
    TreeNode node1_2(2);
    TreeNode node1_3(3, &node1_1, &node1_2);
    TreeNode node1_4(4);
    TreeNode node1_5(5, &node1_3, &node1_4);

    TreeNode node2_1(1);
    TreeNode node2_2(2);
    TreeNode node2_3(3);
    TreeNode node2_4(4, &node2_1, &node2_2);
    TreeNode node2_5(5, &node2_3, &node2_4);

    Solution s;
    TreeNode* ret = s.mergeTrees(&node1_5, &node2_5);

    preorder_print(ret);
    printf("\n");
}

int main(void)
{
    test1();
    return 0;
}