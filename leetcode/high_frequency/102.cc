#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 二叉树层次遍历

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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector <vector <int>> ret;
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
            ret.push_back(currentLevelData);
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
    vector<vector<int>> ret = s.levelOrder(&node7);
    for (auto i : ret)
    {
        for (auto j : i)
        {
            printf("%d\t", j);
        }
        printf("\n");
    }

    return 0;
}