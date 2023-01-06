#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// 验证二叉搜索树
/*
二叉搜索树性质：
如果该二叉树的左子树不为空，则左子树上所有节点的值均小于它的根节点的值； 若它的右子树不空，则右子树上所有节点的值均大于它的根节点的值；它的左右子树也为二叉搜索树。
*/

/*
思路：
中序遍历(左根右)，如果中序遍历的结果是递增的说明是二叉搜索树，否则不是
*/

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
    bool isValidBST(TreeNode* root) {
        helper(root);
        for (int i = 1; i < result.size(); i++)
        {
            if (result[i-1] >= result[i])
                return false;
        }
        return true;
    }

private:
    vector<int> result;
    // 中序遍历
    void helper(TreeNode* root)
    {
        if (nullptr == root)
            return;
        
        helper(root->left);
        result.push_back(root->val);
        helper(root->right);
    }
};

void test1(void)
{
    Solution s;
    TreeNode node1(3);
    TreeNode node2(6);
    TreeNode node3(4, &node1, &node2);
    TreeNode node4(1);
    TreeNode node5(5, &node4, &node3);
    cout << s.isValidBST(&node5) << endl;
}

void test2(void)
{
    Solution s;
    TreeNode node1(3);
    TreeNode node2(1);
    TreeNode node3(2, &node2, &node1);
    cout << s.isValidBST(&node3) << endl;
}

int main(void)
{   
    test1();
    test2();
    return 0;
}