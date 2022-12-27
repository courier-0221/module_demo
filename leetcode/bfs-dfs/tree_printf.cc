#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 使用bfs和dfs的原理遍历二叉树
// 原理一搜一大堆，简单讲就是bfs先从和自己相连的节点开始遍历这一层走完之后再走下一层，dfs是把每一个和自己相连的节点都一条路走到黑一直向下走

// 和层次遍历效果一样，原理是使用一个队列，把左右孩子节点加入到队列中，然后利用先入先出的特点一次操作左右孩子
class BFS
{
public:
    list<int> traversal_no_recursion(TreeNode *root) 
    {
        list<int> L;
        if (nullptr == root)
            return L;
 
        queue<TreeNode*> Q;
    
        Q.push(root);
    
        while (!Q.empty())
        {
            TreeNode *node = Q.front();
    
            L.push_back(node->val);

            if (nullptr != node->left)
            {
                Q.push(node->left);
            }
            if (nullptr != node->right)
            {
                Q.push(node->right);
            }
            Q.pop();
        }
        return L;
    }

};

// 和二叉树的先序遍历一样
class DFS
{
public:
    list<int> traversal_recursion(TreeNode *root) 
    {
        DFS_Recursive(root);
        return L;
    }

private:
    list<int> L;
    
    // DFS的递归实现
    void DFS_Recursive(TreeNode* root)
    {
        if (root == NULL)
            return;
    
        L.push_back(root->val);
    
        if (root->left!=NULL) 
            DFS_Recursive(root->left);
    
        if (root->right!=NULL)
            DFS_Recursive(root->right);
    }
};


void bfs_traversal_no_recursion_test(void)
{
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5, &node1, &node2);
    TreeNode node6(6, &node3, &node4);
    TreeNode node7(7, &node5, &node6);

    BFS bfs;
    list<int> ret = bfs.traversal_no_recursion(&node7);
    for (list<int>::iterator it = ret.begin(); it != ret.end(); it++)
    {
        printf("%d\t", *it);
    }
    printf("\n");
}

void dfs_traversal_recursion_test(void)
{
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5, &node1, &node2);
    TreeNode node6(6, &node3, &node4);
    TreeNode node7(7, &node5, &node6);

    DFS dfs;
    list<int> ret = dfs.traversal_recursion(&node7);
    for (list<int>::iterator it = ret.begin(); it != ret.end(); it++)
    {
        printf("%d\t", *it);
    }
    printf("\n");
}

int main(void)
{
    bfs_traversal_no_recursion_test();
    dfs_traversal_recursion_test();
    return 0;
}