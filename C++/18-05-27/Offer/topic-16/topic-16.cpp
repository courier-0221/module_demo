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
/*˼·���ο���ָoffer
1���������ñ�־λresult = false����Ϊһ��ƥ��ɹ�result����Ϊtrue��
ʣ�µĴ��벻��ִ�У����ƥ�䲻�ɹ���Ĭ�Ϸ���false
2���ݹ�˼�룬������ڵ���ͬ��ݹ����DoesTree1HaveTree2������
������ڵ㲻��ͬ�����ж�tree1����������tree2�Ƿ���ͬ��
���ж���������tree2�Ƿ���ͬ
3��ע��null��������HasSubTree�У��������������Ϊ�ղŽ����жϣ�
DoesTree1HasTree2�У����Tree2Ϊ�գ���˵���ڶ������������ˣ���ƥ��ɹ���
tree1Ϊ�������������1�����tree1Ϊ��&&tree2��Ϊ��˵����ƥ�䣬
��2�����tree1Ϊ�գ�tree2Ϊ�գ�˵��ƥ�䡣

*/
class Solution 
{
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		bool result = false;
		//��Tree1��Tree2����Ϊ���ʱ�򣬲Ž��бȽϡ�����ֱ�ӷ���false
		if (pRoot1 != NULL && pRoot2 != NULL)
		{
			//����ҵ��˶�ӦTree2�ĸ��ڵ�ĵ�
			if (pRoot1->val == pRoot2->val)
			{
				//��������ڵ�ΪΪ����ж��Ƿ����Tree2
				result = DoesTree1HaveTree2(pRoot1, pRoot2);
			}
			//����Ҳ�������ô����ȥroot������ӵ�����㣬ȥ�ж�ʱ�����Tree2
			if (!result)
			{ 
				result = HasSubtree(pRoot1->left, pRoot2);
			}
			//������Ҳ�������ô����ȥroot���Ҷ��ӵ�����㣬ȥ�ж�ʱ�����Tree2
			if (!result)
			{ 
				result = HasSubtree(pRoot1->right, pRoot2); 
			}
		}
		return result;
	}
	bool DoesTree1HaveTree2(TreeNode *root1, TreeNode *root2)
	{
		//���Tree2��û�б����꣬Tree1ȴ�������ˡ�����false
		if (root1 == NULL && root2 != NULL)
		{
			return false;
		}
		//���Tree2�Ѿ��������˶��ܶ�Ӧ���ϣ�����true
		if (root2 == NULL)
		{
			return true;
		}
		//���������һ����û�ж�Ӧ�ϣ�����false
		if (root1->val != root2->val)
		{
			return false;
		}
		//������ڵ��Ӧ���ϣ���ô�ͷֱ�ȥ�ӽڵ�����ƥ��
		return DoesTree1HaveTree2(root1->left, root2->left) && DoesTree1HaveTree2(root1->right, root2->right);
	}
};

int main(void)
{
	Solution s;




	system("pause");
	return 0;
}