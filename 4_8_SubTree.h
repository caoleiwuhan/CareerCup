#include <iostream>

#include "4_1_IsBalanceTree.h"

using namespace std;

/*
	˼·��
		������Ǻܴ�����t1/t2ǰ�������string��Ȼ��t2���Ƿ���t1��
		��κܴ�����Ҫ���棺O(n + k*m) k��t2��root��t1�г��ֵĴ���
*/
bool IsSubTree(TreeNode *t1, TreeNode *t2);

bool IsSameTree(TreeNode *t1, TreeNode *t2);

void TestIsSubTree();