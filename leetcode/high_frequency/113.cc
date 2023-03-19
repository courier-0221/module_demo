#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 路径总和ii
// 在112 路径总和i的基础上加入回溯方式实现。

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
    vector<vector<int>> result;
    vector<int> path;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return result;
        path.push_back(root->val);
        traversal(root, targetSum - root->val);
        return result;
    }

private:
    void traversal(TreeNode* cur, int count)
    {
        // 遇到叶子节点，并且计数为0
        if (cur->left == nullptr && cur->right == nullptr && count == 0)
        {
            result.push_back(path);
            return;
        }
            
        // 遇到叶子节点直接返回
        if (cur->left == nullptr && cur->right == nullptr)
            return;
        
        if (cur->left != nullptr)
        {
            path.push_back(cur->left->val);
            traversal(cur->left, count - cur->left->val);
            path.pop_back();
        }

        if (cur->right != nullptr)
        {
            path.push_back(cur->right->val);
            traversal(cur->right, count - cur->right->val);
            path.pop_back();
        }
    }
};

void printVec(vector<vector<int>> && nums)
{
    for (auto arr : nums)
    {
        for (auto num : arr)
        {
            printf("%d\t", num);
        }
        printf("\n");
    }
    printf("\n");
}

void test1()
{
    TreeNode node1(7);
    TreeNode node2(2);
    TreeNode node3(11, &node1, &node2);
    TreeNode node4(4, &node3, nullptr);
    TreeNode node5(1);
    TreeNode node5_2(5);
    TreeNode node6(4, &node5_2, &node5);
    TreeNode node7(13);
    TreeNode node8(8, &node7, &node6);
    TreeNode node9(5, &node4, &node8);

    Solution s;
    printVec(s.pathSum(&node9, 22));
}

int main(void)
{
    test1();
    return 0;
}