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
	˼·��
		1.DFS��������ȱ���������������ÿ���ڵ�ĵ�ǰ·��������vec��
		2.���ݵ�ǰ�ڵ����ȣ�depth�������ϱ���·������ν��Ϊ0��˵����һ�����
*/
void FindPathSum3(TreeNode *root, int sum, vector<TreeNode *> &vec, int depth);

void PrintTreeNode(vector<TreeNode *> &vec, int from, int to);


