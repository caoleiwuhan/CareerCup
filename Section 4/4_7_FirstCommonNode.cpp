#include <iostream>

#include "4_7_FirstCommonNode.h"

using namespace std;

// ���Ƕ��������
// ����p1��p2һ����tree��

/*
	1������и��ڵ��ָ�룬��ֱ����������
	2��
*/
// ÿ���ڵ���ܱ����ʶ��
TreeNode *FirstCommonNode(TreeNode *pNode, TreeNode *p1, TreeNode *p2)
{
	if (pNode == NULL || p1 == NULL || p2 == NULL)
		return false;

	bool l1 = IsExist(pNode->left, p1);
	bool l2 = IsExist(pNode->left, p2);
	bool r1 = IsExist(pNode->right, p1);
	bool r2 = IsExist(pNode->right, p2);
	if (l1 && l2)
	{
		return FirstCommonNode(pNode->left, p1, p2);
	}
	if (r1 && r2)
	{
		return FirstCommonNode(pNode->right, p1, p2);
	}
	if ((l1 || r1) && (l2 || r2))
	{
		return pNode;
	}
	return NULL;
}

bool IsExist(TreeNode *root, TreeNode *pNode)
{
	if (root == NULL)
		return false;
	if (root == pNode)
		return true;
	return IsExist(root->left, pNode) || IsExist(root->right, pNode);
}

// ÿ���ڵ㱻����һ��
int NumberOfNode(TreeNode *pNode, TreeNode *p1, TreeNode *p2)
{
	if (pNode == NULL)
		return 0;
	int ret = 0;
	if (pNode == p1 || pNode == p2)
		ret += 1;
	ret += NumberOfNode(pNode->left, p1, p2);
	ret += NumberOfNode(pNode->right, p1, p2);

	return ret;
}

TreeNode *FirstCommonNode2(TreeNode *pNode, TreeNode *p1, TreeNode *p2)
{
	if (pNode == NULL)
		return NULL;

	if (p1 == p2 && (pNode->left == p1 || pNode->right == p1))
		return pNode;	

	int left = NumberOfNode(pNode->left, p1, p2);
	if (left == 2)
	{
		return FirstCommonNode2(pNode->left, p1, p2);
	}

	if ((pNode == p1 || pNode == p2) && left == 1)
	{
		return pNode;
	}

	int right = NumberOfNode(pNode->right, p1, p2);
	if ((pNode == p1 || pNode == p2) && right == 1)
	{
		return pNode;
	}
	if (right == 2)
	{
		return FirstCommonNode2(pNode->right, p1, p2);
	}

	if (left + right == 2)
		return pNode;
	
}

