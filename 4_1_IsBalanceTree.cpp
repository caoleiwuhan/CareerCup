#include <iostream>
#include <vector>
#include <queue>

#include "4_1_IsBalanceTree.h"

using namespace std;

bool IsBalanced(TreeNode *root)
{
	int deep = 0;
	return IsBalancedHelp(root, deep);
}

bool IsBalancedHelp(TreeNode *root, int &deep)
{
	if (root == NULL)
	{
		deep = 0;
		return true;
	}
	int leftDeep = 0;
	bool isLeftB = IsBalancedHelp(root->left, leftDeep);
	if (!isLeftB)
	{
		return false;
	}

	int rightDeep = 0;
	bool isRightB = IsBalancedHelp(root->right, rightDeep);
	if (!isRightB)
	{
		return false;
	}
	int maxDeep = max(leftDeep, rightDeep);
	int minDeep = min(leftDeep, rightDeep);
	if (maxDeep - minDeep > 1)
	{
		return false;
	}
	deep = maxDeep + 1;
	return true;
}

void TestIsBalanced()
{
	TreeNode n1(1);
	TreeNode n2(2);
	n1.left = &n2;

	levelOrderBottom(&n1);

	//TreeNode n20(20);
	//TreeNode n3(3);
	//TreeNode n8(8);
	////TreeNode n15(15);
	//TreeNode n25(25);

	//n10.left = &n5;
	//n10.right = &n20;
	//n5.left = &n3;
	//n5.right = &n8;
	////n20.left = &n15;
	//n20.right = &n25;

	//vector<vector<int> > ans = levelOrder(&n10);

	// cout << isBalanced(&n10) << endl;
}

int DeepOfTree(TreeNode *root)
{
	if (root == NULL)
	{
		return 0;
	}
	int left = DeepOfTree(root->left);
	int right = DeepOfTree(root->right);
	return (max(left, right) + 1);

}

bool isBalanced(TreeNode *root) 
{
	if (root == NULL)
		return true;

	bool isLeftB = isBalanced(root->left);
	if (!isLeftB)
		return false;
	bool isRightB = isBalanced(root->right);
	if (!isRightB)
		return false;

	int leftDeep = DeepOfTree(root->left);
	int rightDeep = DeepOfTree(root->right);
	if (abs(leftDeep - rightDeep) > 1)
		return false;

	return true;
}

vector<vector<int> > levelOrder(TreeNode *root) 
{
	vector< vector<int> > ans;

	if (root == NULL)
		return ans;        

	vector<int> *vTmp = NULL;
	queue<TreeNode *> q;

	q.push(NULL);
	q.push(root);        

	while (q.size() > 1)
	{
		TreeNode *pTmp = q.front();
		q.pop();
		if (pTmp == NULL)
		{
			if (vTmp != NULL)
			{
				ans.push_back(*vTmp);
			}
			vTmp = new vector<int>;
			q.push(NULL);
		}
		else
		{
			vTmp->push_back(pTmp->val);
			if (pTmp->left != NULL)
			{
				q.push(pTmp->left);
			}
			if (pTmp->right != NULL)
			{
				q.push(pTmp->right);
			}
		}
	}
	ans.push_back(*vTmp);
	return ans;
}

double powHelp(double x, unsigned n) 
{
	if (n == 1)
		return x;
	if (n & 1)
	{
		return powHelp(x, n - 1) * x;
	}
	else
	{
		double ans = powHelp(x, n >> 1);
		return ans * ans;
	}
}
double MyPow(double x, int n) 
{       
	if (n == 0)
	{
		return 1.0;
	}
	bool bNeg = false;
	unsigned num = n;
	if (n < 0)
	{
		num = -n;
		bNeg = true;
	}

	double ans = powHelp(x, num);
	if (bNeg)
	{
		ans = 1.0 / ans;
	}
	return ans;
}

double powHelp2(double x, unsigned n)
{
	double ans = 1.0;
	double tmp = x;
	while (n)
	{
		if (n & 1)
		{
			ans *= tmp;
		}
		tmp *= tmp;
	}
	return ans;
}

vector<vector<int> > levelOrderBottom(TreeNode *root)
{
	vector <vector<int> > ans;
	if (root == NULL)
		return ans;

	vector<TreeNode *> vec;
	vec.push_back(root);
	vec.push_back(NULL);
	int start = 0;
	int end = 1;
	while (start < end)
	{
		TreeNode *pNode = vec[start++];
		if (pNode == NULL)
		{
			if (start == end && vec[end] == NULL)
				break;

			vec.push_back(NULL);
			end++;

			continue;
		}

		if (pNode->right != NULL)
		{
			vec.push_back(pNode->right);
			end++;
		}
		if (pNode->left != NULL)
		{
			vec.push_back(pNode->left);
			end++;
		}            
	}

	vector<int> *pV = NULL;
	while (end >= 0)
	{
		TreeNode *pNode = vec[end--];
		if (pNode == NULL)
		{
			if (pV != NULL)
			{
				ans.push_back(*pV);
			}
			pV = new vector<int>;                
		}
		else
		{
			pV->push_back(pNode->val);
		}
	}
	if (pV != NULL)
	{
		ans.push_back(*pV);
	}
	return ans;

}