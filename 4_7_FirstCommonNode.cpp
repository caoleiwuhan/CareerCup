#include <iostream>

#include "4_7_FirstCommonNode.h"

using namespace std;

// 不是二叉查找树
// 假设p1和p2一定在tree中

/*
	1：如果有父节点的指针，则直接向上索引
	2：
*/
// 每个节点可能被访问多次
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

// 每个节点被访问一次
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

