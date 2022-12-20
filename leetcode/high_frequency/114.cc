#include <iostream>
#include <vector>
#include <list>
using namespace std;

// 二叉树展开为链表 -- 先序遍历的顺序展开链表
// 思路：
// 先序遍历，将根节点保存进vector中，然后对vector中的每一个树节点重新赋值左右孩子指针

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
    void flatten(TreeNode* root) {
        vector<TreeNode*> result;
        preorder_print(root, result);

        int i = 0;
        for (i = 1; i < result.size(); i++)
        {
            result[i-1]->left = nullptr;
            result[i-1]->right = result[i];
        }
    }

    void preorder_print(TreeNode* root, vector<TreeNode*> &result)
    {
        if (nullptr == root)
        {
            return;
        }
        
        result.push_back(root);
        preorder_print(root->left, result);
        preorder_print(root->right, result);
    }
};

void print(TreeNode* root)
{
    if (nullptr == root)
    {
        return;
    }

    printf("%d\t", root->val);
    printf("%p\t", root->left);
    print(root->left);
    print(root->right);
}

void test1(void)
{
    TreeNode node1_1(1);
    TreeNode node1_2(2);
    TreeNode node1_3(3, &node1_1, &node1_2);
    TreeNode node1_4(4);
    TreeNode node1_5(5, &node1_3, &node1_4);


    Solution s;
    s.flatten(&node1_5);

    print(&node1_5);
    printf("\n");
}

void test2(void)
{
    TreeNode node2_1(1);
    TreeNode node2_2(2);
    TreeNode node2_3(3);
    TreeNode node2_4(4, &node2_1, &node2_2);
    TreeNode node2_5(5, &node2_3, &node2_4);

    Solution s;
    s.flatten(&node2_5);

    print(&node2_5);
    printf("\n");
}

int main(void)
{
    test1();
    test2();
    return 0;
}