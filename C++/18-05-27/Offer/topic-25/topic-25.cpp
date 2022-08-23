#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


struct RandomListNode 
{
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
	label(x), next(NULL), random(NULL) {}
};

/*
*����˼·��
*1��������������ÿ����㣬�縴�ƽ��A�õ�A1�������A1�嵽���A���棻
*2�����±������������Ͻ������ָ����½�㣬��A1.random = A.random.next;
*3�����������������Ϊԭ����͸��ƺ������
*/

class Solution 
{
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if (NULL == pHead)
		{
			return NULL;
		}
		RandomListNode *current = pHead;
		//1������ÿ����㣬�縴�ƽ��A�õ�A1�������A1�嵽���A���棻
		while (current != NULL)
		{
			RandomListNode *node = new RandomListNode(current->label);
			RandomListNode *next = current->next;
			current->next = node;
			node->next = next;
			current = next;
		}

		current = pHead;
		//2�����±������������Ͻ������ָ����½�㣬��A1.random = A.random.next;
		while (current != NULL)
		{
			RandomListNode *tmp;
			if (current->random == NULL)
			{
				tmp = NULL;
			}
			else
			{
				tmp = current->random->next;
			}
			current->next->random = tmp;
			current = current->next->next;
		}

		//3�����������������Ϊԭ����͸��ƺ������
		current = pHead;
		RandomListNode *pCloneHead = pHead->next;
		while (current != NULL)
		{
			RandomListNode *clonenode = current->next;
			current->next = clonenode->next;
			RandomListNode *tmp;
			if (clonenode->next == NULL)
			{
				tmp = NULL;
			}
			else
			{
				tmp = clonenode->next->next;
			}
			clonenode->next = tmp;
			current = current->next;
		}

		return pCloneHead;
	}
};

int main(void)
{
	Solution s;
	RandomListNode* current = NULL;
	RandomListNode tmp(-1);

	RandomListNode n1(1);
	RandomListNode n2(2);
	RandomListNode n3(3);
	RandomListNode n4(4);
	RandomListNode n5(5);
	n1.next = (RandomListNode*)&n2;
	n2.next = (RandomListNode*)&n3;
	n3.next = (RandomListNode*)&n4;
	n4.next = (RandomListNode*)&n5;

	n1.random = (RandomListNode*)&n2;
	n2.random = (RandomListNode*)&n3;

	cout << "source" << endl;
	current = &n1;
	while (current != NULL)
	{
		cout << current->label << "  ";
		current = current->next;
	}
	cout << endl;

	//cout << " n1->random." << (RandomListNode*)(n1.random)->label << endl;
	//cout << " n2->random." << (RandomListNode*)(n2.random)->label << endl;
	tmp = *(RandomListNode*)(n1.random);
	cout << " n1->random." << tmp.label << endl;
	tmp = *(RandomListNode*)(n2.random);
	cout << " n2->random." << tmp.label << endl;


	RandomListNode *recv = s.Clone(&n1);
	RandomListNode *recvTmp = recv;
	cout << "clone" << endl;
	while (recv != NULL)
	{
		cout << recv->label << "  ";
		recv = recv->next;
	}
	cout << endl;

	tmp = *(RandomListNode*)(recvTmp->random);
	cout << " n1->random." << tmp.label << endl;
	tmp = *(RandomListNode*)(recvTmp->next->random);
	cout << " n2->random." << tmp.label << endl;




	system("pause");
	return 0;
}