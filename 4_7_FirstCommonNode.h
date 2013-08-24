#include <istream>

#include "4_1_IsBalanceTree.h"

using namespace std;


TreeNode *FirstCommonNode(TreeNode *pNode, TreeNode *p1, TreeNode *p2);

TreeNode *FirstCommonNode2(TreeNode *pNode, TreeNode *p1, TreeNode *p2);

int NumberOfNode(TreeNode *pNode, TreeNode *p1, TreeNode *p2);

bool IsExist(TreeNode *root, TreeNode *pNode);

void TestFirstCommonNode();