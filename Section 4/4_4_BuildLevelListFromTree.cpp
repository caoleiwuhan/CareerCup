#include <iostream>
#include <stack>


#include "4_4_BuildLevelListFromTree.h"

using namespace std;

vector<TreeListNode *>BuildLeverListFromTree(TreeNode *tree)
{
	vector<TreeListNode *> ans;
	if (tree == NULL)
		return ans;

	int level = 0;
	TreeListNode *pList = new TreeListNode(tree);
	ans.push_back(pList);

	while (true)
	{
		TreeListNode *p1 = ans[level];		
		TreeListNode *p2 = p1;
		TreeListNode *p3 = NULL;
		TreeListNode *pCur = NULL;
		while (p2)
		{
			if (p2->treeNode->left != NULL)
			{				
				if (p3 == NULL)
				{
					p3 = new TreeListNode(p2->treeNode->left);
					pCur = p3;
				}
				else
				{
					pCur->next = new TreeListNode(p2->treeNode->left);
					pCur = pCur->next;
				}
			}
			if (p2->treeNode->right != NULL)
			{
				if (p3 == NULL)
				{
					p3 = new TreeListNode(p2->treeNode->right);
					pCur = p3;
				}
				else
				{
					pCur->next = new TreeListNode(p2->treeNode->right);
					pCur = pCur->next;
				}
			}
			p2 = p2->next;
		}
		if (p3 == NULL)
		{
			break;
		}
		ans.push_back(p3);
		level++;
	}

	return ans;
}

void TestBuildLeverListFromTree()
{
	TreeNode n10(10);
	TreeNode n5(5);	
	TreeNode n20(20);
	TreeNode n3(3);
	TreeNode n8(8);
	TreeNode n15(15);
	TreeNode n25(25);

	n10.left = &n5;
	n10.right = &n20;
	n5.left = &n3;
	n5.right = &n8;
	n20.left = &n15;
	n20.right = &n25;

	vector<TreeListNode *> ans = BuildLeverListFromTree(&n10);

}


// sum 子节点单向的最大和
int Help(TreeNode *root, int &sum)
{
	if (root == NULL)
	{
		return 0;
		sum = 0;
	}

	if (root->left == NULL && root->right == NULL)
	{
		sum = root->val;
		return root->val;
	}

	int left = 0;
	int leftSum = 0;
	bool hasLeft = false;
	if (root->left)
	{
		left = Help(root->left, leftSum);
		hasLeft = true;
	}
	int right = 0;
	int rightSum = 0;
	bool hasRight = false;
	if (root->right)
	{
		right = Help(root->right, rightSum);
		hasRight = true;
	}
	int ans = 0x80000000;
	sum = root->val;
	if (hasLeft && hasRight)
	{
		int num = max(leftSum, rightSum);
		if (num > 0)
		{
			sum += num;
		}
		ans = max(left, right);
		int tmp = root->val;
		if (leftSum > 0)
		{
			tmp += leftSum;
		}
		if (rightSum > 0)
		{
			tmp += rightSum;
		}
		ans = max(ans, tmp);
	}
	else if (hasLeft)
	{ // 只有左子树
		if (leftSum > 0)
		{
			sum += leftSum;
		}
		ans = left;
		ans = max(ans, sum);
	}
	else
	{ // 只有右子树
		if (rightSum > 0)
		{
			sum += rightSum;
		}
		ans = right;
		ans = max(ans, sum);
	}
	return ans;
}

int maxPathSum(TreeNode *root)
{
	// Start typing your C/C++ solution below
	// DO NOT write int main() function

	int sum = 0;
	return Help(root, sum);        

}


void pathSumHelp(TreeNode *root, int sum, vector<int> &vec, vector< vector<int> > & ans) {
	if (root == NULL)
	{
		return;
	}
	if (root->left == NULL && root->right == NULL)
	{
		if (root->val == sum)
		{
			vec.push_back(root->val);
			int size = vec.size();
			vector<int> *pV = new vector<int>(size);			
			for (int i = 0; i < size; ++i)
			{
				(*pV)[i] = vec[i];
			}
			ans.push_back(*pV);
			vec.pop_back();
		}
		return;
	}
	vec.push_back(root->val);

	if (root->left != NULL)
	{
		pathSumHelp(root->left, sum - root->val, vec, ans);
	}
	if (root->right != NULL)
	{
		pathSumHelp(root->right, sum - root->val, vec, ans);
	}
	vec.pop_back();
}

vector<vector<int> > pathSum(TreeNode *root, int sum) 
{
	vector<int >vec;
	vector<vector<int> > ans;
	pathSumHelp(root, sum, vec, ans);
	return ans;
}

void TestPahtSum()
{
	TreeNode n5(5);

	TreeNode n4(4);	
	TreeNode n8(8);

	TreeNode n11(11);
	TreeNode n13(13);
	TreeNode n42(4);

	TreeNode n7(7);
	TreeNode n2(2);
	TreeNode n52(5);
	TreeNode n1(1);

	n5.left = &n4;
	n5.right = &n8;

	n4.left = &n11;
	n8.left = &n13;
	n8.right = &n42;

	n11.left = &n7;
	n11.right = &n2;
	n42.left = &n52;
	n42.right = &n1;

	vector < vector <int> > ans = pathSum(&n5, 22);
}

bool isSame(TreeNode *left, TreeNode *right)
{
    if (left == NULL && right == NULL)
    {
        return true;
    }
    else if (left != NULL && right != NULL)
    {
        if (left->val != right->val)
        {
            return false;
        }
            
        bool isLeft = isSame(left->left, right->right);
        if (!isLeft)
            return false;
        bool isRight = isSame(left->right, right->left);
        return isRight;
    }
    else // 有一个为空
    {
        return false;
    }
}

bool isSymmetric(TreeNode *root)
{
    if (root == NULL)
        return true;
    return isSame(root->left, root->right);
}

/*
	如果有左孩子，将当前节点置为左孩子
	否则，出栈，访问节点，将右节点置为当前节点
*/

void InOrderTree(TreeNode *root)
{
	stack<TreeNode *> s;	
	TreeNode *pNode = root;

	while (!s.empty() || pNode)
	{			
		while (pNode)
		{
			s.push(pNode);
			pNode = pNode->left;
		}
		if (!s.empty())
		{
			pNode = s.top();
			s.pop();
			cout << pNode->val << endl;
			pNode = pNode->right;			
		}
	}
}

void PostOrderTree(TreeNode *root)
{
	stack<TreeNode *> s;
	s.push(root);
	TreeNode *cur = root;
	TreeNode *pre = NULL;
	while (!s.empty())
	{
		cur = s.top();
		if ((cur->left == NULL && cur->right == NULL) || 
			(pre != NULL && (pre == cur->left || pre == cur->right)))
		{
			cout << cur->val << endl;
			s.pop();
			pre = cur;
		}
		else
		{
			if (cur->right)
			{
				s.push(cur->right);
			}
			if (cur->left)
			{
				s.push(cur->left);
			}
		}
	}
}
void TestInOrderTree()
{
	TreeNode n1(1);

	TreeNode n2(2);	
	TreeNode n3(3);

	TreeNode n4(4);

	n1.left = &n2;
	n1.right = &n4;
	n2.left = &n3;

	//InOrderTree(&n1);
	PostOrderTree(&n1);
	
}

