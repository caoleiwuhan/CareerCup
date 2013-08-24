#ifndef _IS_BALANCE_TREE_
#define _IS_BALANCE_TREE_

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool IsBalanced(TreeNode *root);

bool IsBalancedHelp(TreeNode *root, int &deep);

void TestIsBalanced();

int DeepOfTree(TreeNode *root);
bool isBalanced(TreeNode *root);

vector<vector<int> > levelOrder(TreeNode *root);

double MyPow(double x, int n);

double powHelp(double x, unsigned n);

double powHelp2(double x, unsigned n);

vector<vector<int> > levelOrderBottom(TreeNode *root);

#endif