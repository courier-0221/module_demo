#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
	val(x), left(NULL), right(NULL) {}
};
/*思路：参考剑指offer
1、首先设置标志位result = false，因为一旦匹配成功result就设为true，
剩下的代码不会执行，如果匹配不成功，默认返回false
2、递归思想，如果根节点相同则递归调用DoesTree1HaveTree2（），
如果根节点不相同，则判断tree1的左子树和tree2是否相同，
再判断右子树和tree2是否相同
3、注意null的条件，HasSubTree中，如果两棵树都不为空才进行判断，
DoesTree1HasTree2中，如果Tree2为空，则说明第二棵树遍历完了，即匹配成功，
tree1为空有两种情况（1）如果tree1为空&&tree2不为空说明不匹配，
（2）如果tree1为空，tree2为空，说明匹配。

*/
class Solution 
{
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		bool result = false;
		//当Tree1和Tree2都不为零的时候，才进行比较。否则直接返回false
		if (pRoot1 != NULL && pRoot2 != NULL)
		{
			//如果找到了对应Tree2的根节点的点
			if (pRoot1->val == pRoot2->val)
			{
				//以这个根节点为为起点判断是否包含Tree2
				result = DoesTree1HaveTree2(pRoot1, pRoot2);
			}
			//如果找不到，那么就再去root的左儿子当作起点，去判断时候包含Tree2
			if (!result)
			{ 
				result = HasSubtree(pRoot1->left, pRoot2);
			}
			//如果还找不到，那么就再去root的右儿子当作起点，去判断时候包含Tree2
			if (!result)
			{ 
				result = HasSubtree(pRoot1->right, pRoot2); 
			}
		}
		return result;
	}
	bool DoesTree1HaveTree2(TreeNode *root1, TreeNode *root2)
	{
		//如果Tree2还没有遍历完，Tree1却遍历完了。返回false
		if (root1 == NULL && root2 != NULL)
		{
			return false;
		}
		//如果Tree2已经遍历完了都能对应的上，返回true
		if (root2 == NULL)
		{
			return true;
		}
		//如果其中有一个点没有对应上，返回false
		if (root1->val != root2->val)
		{
			return false;
		}
		//如果根节点对应的上，那么就分别去子节点里面匹配
		return DoesTree1HaveTree2(root1->left, root2->left) && DoesTree1HaveTree2(root1->right, root2->right);
	}
};

int main(void)
{
	Solution s;




	system("pause");
	return 0;
}