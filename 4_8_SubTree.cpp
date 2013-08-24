#include <iostream>

#include "4_8_SubTree.h"

using namespace std;


bool IsSubTree(TreeNode *t1, TreeNode *t2)
{
	if (t2 == NULL)
		return true;
	if (t1 == NULL)
		return false;

	if (t1->val == t2->val)
	{
		if (IsSameTree(t1, t2))
			return true;
	}

	return IsSubTree(t1->left, t2) ||
			IsSubTree(t1->right, t2);
		
}

bool IsSameTree(TreeNode *t1, TreeNode *t2)
{
	if (t2 == NULL)
		return true;
	if (t1 == NULL)
		return false;
	if (t1->val != t2->val)
		return false;
	return IsSameTree(t1->left, t2->left) &&
			IsSameTree(t1->right, t2->right);
}

void TestIsSubTree()
{
}