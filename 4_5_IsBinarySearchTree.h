#include <vector>
#include <string>

#include "4_1_IsBalanceTree.h"

using namespace std;

bool IsBinarySearchTree(TreeNode *pNode);

bool IsBinarySearchTree3(TreeNode *root);

bool IsBinarySearchTree3Help(TreeNode *root, int minNum, int maxNum);

void TestIsBinarySearchTree();

bool isInterleave(string s1, string s2, string s3);

bool isInterleaveDFS(string &s1, string &s2, string &s3, int p1, int p2, int p3);

bool isInterleave2(string s1, string s2, string s3);

void TestIsInterleave();


int C(int n, int m);

vector<TreeNode *> generateTrees(int n);

void generateTreesHelp(vector<TreeNode *> &ans, vector<TreeNode *> &vec, int left, 
	int right, int N, TreeNode *&root);

vector<string> restoreIpAddresses(string s);

void RestoreIPDFS(vector<string> &ans, string vS[], int count, string &s, int step);

void TestRestoreIpAddresses();

