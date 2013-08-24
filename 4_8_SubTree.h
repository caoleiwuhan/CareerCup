#include <iostream>

#include "4_1_IsBalanceTree.h"

using namespace std;

/*
	思路：
		如果不是很大，生成t1/t2前序、中序的string，然后看t2的是否在t1中
		如何很大，则需要下面：O(n + k*m) k是t2的root在t1中出现的次数
*/
bool IsSubTree(TreeNode *t1, TreeNode *t2);

bool IsSameTree(TreeNode *t1, TreeNode *t2);

void TestIsSubTree();