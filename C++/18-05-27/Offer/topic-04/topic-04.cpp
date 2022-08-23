#include <iostream>
#include <vector>
using namespace std;


struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) 
	{
		vector<int> left_pre, right_pre, left_in, right_in;
		int index = 0;
		int i = 0;

		if (0 == pre.size() || 0 >= vin.size())
		{
			return NULL;
		}

		TreeNode * tmp = new TreeNode(pre[0]);

		//先序第一个元素在中序中的位置。
		for (i = 0; i < vin.size(); i++)
		{
			if (pre[0] == vin[i])
			{
				index = i;
				break;
			}
		}

		//
		for (i = 0; i < index; i++)
		{
			left_pre.push_back(pre[i + 1]);
			left_in.push_back(vin[i]);
		}

		for (int i = index + 1; i < vin.size(); i++)
		{
			right_in.push_back(vin[i]);
			right_pre.push_back(pre[i]);
		}


		tmp->left = reConstructBinaryTree(left_pre, left_in);
		tmp->right = reConstructBinaryTree(right_pre, right_in);

		return tmp;
	}
};

void BtreePostorder(TreeNode *tree)
{
	if (tree == NULL)
	{
		return;
	}
	else
	{
		BtreePostorder(tree->left);
		BtreePostorder(tree->right);
		//printf("%d\t", tree->val);
		cout << tree->val << "   ";
	}
}

int main(void)
{
	TreeNode *tree;
	Solution s;
	vector <int> pre;
	vector <int> vin;
	pre.push_back(1);
	pre.push_back(2);
	pre.push_back(4);
	pre.push_back(7);
	pre.push_back(3);
	pre.push_back(5);
	pre.push_back(6);
	pre.push_back(8);

	//4,7,2,1,5,3,8,6
	vin.push_back(4);
	vin.push_back(7);
	vin.push_back(2);
	vin.push_back(1);
	vin.push_back(5);
	vin.push_back(3);
	vin.push_back(8);
	vin.push_back(6);

	tree = s.reConstructBinaryTree(pre, vin);

	BtreePostorder(tree);

	system("pause");
	return 0;
}