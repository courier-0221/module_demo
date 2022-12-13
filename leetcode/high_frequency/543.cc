#include <iostream>
#include <vector>
using namespace std;

// 二叉树的直径
// 思路：
// 左子树的最大深度 + 右子树的最大深度

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int ans;
    int depth(TreeNode* rt){
        if (rt == NULL) {
            return 0; // 访问到空节点了，返回0
        }
        int L = depth(rt->left); // 左儿子为根的子树的深度
        int R = depth(rt->right); // 右儿子为根的子树的深度
        ans = max(ans, L + R + 1); // 计算d_node即L+R+1 并更新ans
        return max(L, R) + 1; // 返回该节点为根的子树的深度
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        depth(root);
        return ans - 1;
    }
};

void test1(void)
{
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3, &node1, &node2);
    TreeNode node4(4);
    TreeNode node5(5, &node3, &node4);

    Solution s;
    printf("%d\n", s.diameterOfBinaryTree(&node5));
}

int main(void)
{
    test1();
    return 0;
}