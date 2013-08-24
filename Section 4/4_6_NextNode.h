#ifndef _NEXT_NODE_
#define _NEXT_NODE_

#include <iostream>

using namespace std;

struct TreeNode2
{
	int val;
	TreeNode2 *left;
	TreeNode2 *right;
	TreeNode2 *parent;

	TreeNode2(int _val) : val(_val), left(NULL), right(NULL), parent(NULL) {}
};

TreeNode2 *NextNode(TreeNode2 *pNode);

void TestNextNode();


TreeNode2 *MostLeft(TreeNode2 *pNode);

TreeNode2 *FirstLeftChild(TreeNode2 *pNode);

#endif