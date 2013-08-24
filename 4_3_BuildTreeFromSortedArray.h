#include "4_1_IsBalanceTree.h"

/*
	Given a sorted (increasing order) array, write an algorithmto create 
	a binary search tree with minimal height.
*/

TreeNode *BuildTreeFromSortedArray(int arr[], int size);
TreeNode *BuildTreeFromSortedArrayHelp(int arr[], int from, int to);

void TestBuildTreeFromSortedArray();

