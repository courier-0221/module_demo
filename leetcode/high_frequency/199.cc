#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 二叉树右视图
// 使用层次遍历，依次记录每一层最后的那一个元素

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
    vector<int> rightSideView(TreeNode* root) 
    {
        vector <int> ret;
        if (!root) 
        {
            return ret;
        }

        queue <TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int currentLevelSize = q.size();
            vector<int> currentLevelData;
            for (int i = 1; i <= currentLevelSize; ++i)
            {
                TreeNode* node = q.front(); q.pop();
                currentLevelData.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ret.push_back(currentLevelData.back());
        }
        
        return ret;
    }
};

int main(void)
{
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5, &node1, &node2);
    TreeNode node6(6, &node3, &node4);
    TreeNode node7(7, &node5, &node6);

    Solution s;
    vector<int> ret = s.rightSideView(&node7);
    for (auto i : ret)
    {
        printf("%d\t", i);
    }
    printf("\n");

    return 0;
}