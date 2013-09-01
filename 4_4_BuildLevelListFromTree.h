#include "2_1_DeleteDuplicateListNode.h"

#include "4_1_IsBalanceTree.h"

struct TreeListNode
{
	TreeNode *treeNode;
	TreeListNode *next;

	TreeListNode(TreeNode *_tNode) : treeNode(_tNode), next(NULL) {}

};

vector<TreeListNode *>BuildLeverListFromTree(TreeNode *tree);

void TestBuildLeverListFromTree();

int Help(TreeNode *root, int &sum);

/*
	Given a binary tree, find the maximum path sum.
	The path may start and end at any node in the tree.
*/

int maxPathSum(TreeNode *root);

int Help(TreeNode *root, int &sum);


vector<vector<int> > pathSum(TreeNode *root, int sum);

void pathSumHelp(TreeNode *root, int sum, vector<int> &vec, vector< vector<int> > & ans);

void TestPahtSum();

/*
	Given a binary tree, check whether it is a mirror of itself 
	(ie, symmetric around its center).
*/
// µ›πÈ µœ÷:
bool isSame(TreeNode *left, TreeNode *right);
bool isSymmetric(TreeNode *root);

void InOrderTree(TreeNode *root);

void TestInOrderTree();

void PostOrderTree(TreeNode *root);
