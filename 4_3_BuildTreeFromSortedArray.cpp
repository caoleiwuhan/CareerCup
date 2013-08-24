#include <iostream>

#include "4_3_BuildTreeFromSortedArray.h"

using namespace std;


TreeNode *BuildTreeFromSortedArray(int arr[], int size)
{
	return BuildTreeFromSortedArrayHelp(arr, 0, size - 1);	
}
TreeNode *BuildTreeFromSortedArrayHelp(int arr[], int from, int to)
{
	if (from > to)
	{
		return NULL;
	}
	TreeNode *pNode = NULL;
	if (from == to)
	{
		pNode = new TreeNode(arr[from]);
		return pNode;
	}
	int mid = from + (to - from) / 2;
	pNode = new TreeNode(arr[mid]);
	TreeNode *pLeft = BuildTreeFromSortedArrayHelp(arr, from, mid - 1);
	TreeNode *pRight = BuildTreeFromSortedArrayHelp(arr, mid + 1, to);
	pNode->left = pLeft;
	pNode->right = pRight;

	return pNode;
}

void TestBuildTreeFromSortedArray()
{
	int arr[] = {1, 2, 3};
	TreeNode *pNode = BuildTreeFromSortedArray(arr, 3);

}