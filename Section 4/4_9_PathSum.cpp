#include <iostream>

#include "4_9_PathSum.h"

using namespace std;

bool PathSum2(TreeNode *pNode, int sum, vector<TreeNode *> &vec)
{
	if (pNode == NULL)
	{
		if (sum == 0)
			return true;
		return false;
	}		
	if (pNode->val == sum)
	{
		vec.push_back(pNode);
		PrintTreeNode(vec);
		vec.erase(vec.end() - 1);

		return true;
	}
	vec.push_back(pNode);
	bool bLeft = false;
	bool bRight = false;
	if (pNode->left != NULL)
	{
		bLeft = PathSum2(pNode->left, sum - pNode->val, vec);		
	}
	if (pNode->right != NULL)
	{
		bRight = PathSum2(pNode->right, sum - pNode->val, vec);		
	}
	vec.erase(vec.end() - 1);

	return bLeft || bRight;
}

void FindPathSum2(TreeNode *root, int sum)
{
	if (root == NULL)
		return;
	vector<TreeNode *> vec;
	FindPathSumHelp2(root, sum, vec);
}

void FindPathSumHelp2(TreeNode *root, int sum, vector<TreeNode *> &vec)
{
	if (root == NULL)
		return;
	PathSum2(root, sum, vec);
	
	FindPathSumHelp2(root->left, sum, vec);
	FindPathSumHelp2(root->right, sum, vec);
}

void PrintTreeNode(vector<TreeNode *> &vec)
{
	size_t size = vec.size();
	for (size_t i = 0; i < size; ++i)
	{
		cout << vec[i]->val << ' ';
	}
	cout << endl;
}

void TestPathSum2()
{
	TreeNode n10(10);
	TreeNode n51(5);	
	TreeNode n52(5);
	TreeNode n20(20);
	TreeNode n11(10);
	TreeNode n53(5);
	TreeNode n8(8);
	TreeNode n9(9);
	TreeNode n3(3);
	TreeNode n111(11);
	TreeNode n1(1);


	n10.left = &n51;
	n10.right = &n20;
	n51.left = &n52;
	n51.right = &n11;
	n11.left = &n53;

	n20.left = &n8;
	n8.left = &n9;
	n9.right = &n3;

	n8.right = &n111;
	n111.right = &n1;
	
	//FindPathSum2(&n10, 20);

	vector<TreeNode *> vec;
	vec.push_back(&n10);
	FindPathSum3(&n10, 20, vec, 1);

}

void FindPathSum3(TreeNode *root, int sum, vector<TreeNode *> &vec, int length)
{
	if (root == NULL)
		return;
	int tmp = sum;
	for (int i = length - 1; i >= 0; --i)
	{
		tmp -= vec[i]->val;
		if (tmp == 0)
		{
			PrintTreeNode(vec, i, length - 1);
		}
	}
	
	if (root->left != NULL)
	{
		vec.push_back(root->left);
		FindPathSum3(root->left, sum, vec, length + 1);
		vec.erase(vec.end() - 1);
	}
	if (root->right != NULL)
	{
		vec.push_back(root->right);
		FindPathSum3(root->right, sum, vec, length + 1);
		vec.erase(vec.end() - 1);
	}
}

void PrintTreeNode(vector<TreeNode *> &vec, int from, int to)
{
	int size = vec.size();
	if (from < 0 || to >= size)
		return;
	for (int i = from; i <= to; ++i)
	{
		cout << vec[i]->val << ' ';
	}
	cout << endl;
}