#include <iostream>
#include <vector>

#include "4_1_IsBalanceTree.h"

using namespace std;

bool PathSum2(TreeNode *pNode, int sum, vector<TreeNode *> &vec);

void FindPathSum2(TreeNode *root, int sum);

void FindPathSumHelp2(TreeNode *root, int sum, vector<TreeNode *> &vec);

void PrintTreeNode(vector<TreeNode *> &vec);

void TestPathSum2();

/*
	思路：
		1.DFS（深度优先遍历）整棵树，将每个节点的当前路径保存在vec中
		2.根据当前节点的深度（depth），向上遍历路径，如何结果为0，说明是一个结果
*/
void FindPathSum3(TreeNode *root, int sum, vector<TreeNode *> &vec, int depth);

void PrintTreeNode(vector<TreeNode *> &vec, int from, int to);


