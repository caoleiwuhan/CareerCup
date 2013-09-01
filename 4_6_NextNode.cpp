#include <iostream>

#include "4_6_NextNode.h"

using namespace std;

TreeNode2 *NextNode(TreeNode2 *pNode)
{
	if (pNode == NULL)
		return NULL;

	if (pNode->right != NULL)
	{
		return MostLeft(pNode->right);
	}

	return FirstLeftChild(pNode);
}

// Ñ°ÕÒ×î×ó±ßµÄº¢×Ó
TreeNode2 *MostLeft(TreeNode2 *pNode)
{	
	while (pNode->left != NULL)
	{
		pNode = pNode->left;
	}
	return pNode;
}

TreeNode2 *FirstLeftChild(TreeNode2 *pNode)
{
	TreeNode2 *pParent = pNode->parent;
	while (pParent != NULL && pNode == pParent->right)
	{
		pNode = pParent;
		pParent = pParent->parent;
	}
	return pParent;
}

void TestNextNode()
{
	TreeNode2 n1(1);
	TreeNode2 n2(2);	
	TreeNode2 n3(3);
	TreeNode2 n4(4);
	TreeNode2 n5(5);
	TreeNode2 n6(6);
	TreeNode2 n7(7);
	TreeNode2 n8(8);
	TreeNode2 n9(9);
	TreeNode2 n10(10);
	TreeNode2 n11(11);

	n1.parent = NULL;
	n1.left = &n2;
	n2.parent = &n1;
	n1.right = &n3;
	n3.parent = &n1;

	n2.left = &n4;
	n4.parent = &n2;

	n2.right = &n5;
	n5.parent = &n2;

	n5.right = &n6;
	n6.parent = &n5;

	n6.right = &n7;
	n7.parent = &n6;

	n3.left = &n8;
	n8.parent = &n3;

	n8.right = &n9;
	n9.parent = &n8;

	n9.right = &n10;
	n10.parent = &n9;

	n3.right = &n11;
	n11.parent = &n3;

	cout << NextNode(&n1)->val << endl;
	cout << NextNode(&n2)->val << endl;
	cout << NextNode(&n3)->val << endl;
	cout << NextNode(&n4)->val << endl;
	cout << NextNode(&n5)->val << endl;
	cout << NextNode(&n6)->val << endl;
	cout << NextNode(&n7)->val << endl;
	cout << NextNode(&n8)->val << endl;
	cout << NextNode(&n9)->val << endl;
	cout << NextNode(&n10)->val << endl;
	cout << NextNode(&n11) << endl;


}



