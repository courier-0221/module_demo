#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 路径总和
// 使用递归方式实现，思考下先序遍历，也是使用递归方式实现，递归调用左子树，然后再递归调用右子树
// 需要注意的事当访问到叶子结点时判断targetsum是否满足路径值，路径值采用传参的方式没到一个节点减去相应节点的值。

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#if 1
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return false;
        return traversal(root, targetSum - root->val);
    }
private:
    bool traversal(TreeNode* cur, int count)
    {
        printf("%d\n", cur->val);
        // 遇到叶子节点，并且计数为0
        if (cur->left == nullptr && cur->right == nullptr && count == 0)
            return true;
        // 遇到叶子节点直接返回
        if (cur->left == nullptr && cur->right == nullptr)
            return false;
        
        if (cur->left != nullptr)
        {
            if (traversal(cur->left, count - cur->left->val))
                return true;
        }

        if (cur->right != nullptr)
        {
            if (traversal(cur->right, count - cur->right->val))
                return true;
        }
        return false;
    }
};
#endif

void test1()
{
    TreeNode node1(7);
    TreeNode node2(2);
    TreeNode node3(11, &node1, &node2);
    TreeNode node4(4, &node3, nullptr);
    TreeNode node5(1);
    TreeNode node6(4, nullptr, &node5);
    TreeNode node7(13);
    TreeNode node8(8, &node7, &node6);
    TreeNode node9(5, &node4, &node8);

    Solution s;
    cout << s.hasPathSum(&node9, 22) << endl;
}

int main(void)
{
    test1();
    return 0;
}