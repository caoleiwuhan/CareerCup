#ifndef __LEET_CODE__
#define __LEET_CODE__

#include <iostream>

#include <vector>
#include <string>
#include <unordered_set>
#include <map>

#include "4_1_IsBalanceTree.h"

using namespace std;

 vector<vector<string>> partition(string s);

 void pDFS(string &s, int len, bool **f, int step, vector<string> &tmp, vector<vector<string> > &ans);

 void TestPartition();

vector<string> partition2(string s);

void pDFS2(string &s, int len, bool **f, int step, vector<string> &tmp, vector<string> &ans);

int minCut(string s);

bool pDFS3(string &s, int len, bool **f, int step, int cur, int num);

int minCut2(string s);

int minCut3(string s);

int minCut4(string s);

vector<string> anagrams(vector<string> &strs);

int maxProfit4(vector<int> &prices);

void TestMaxProfit2();

int numDistinct(string S, string T);

void TestNumDistinct();

//struct TreeNode {
//    int val;
//	TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};

void flatten(TreeNode *root);
void FlattenHelp(TreeNode *node);
 
int longestConsecutive(vector<int> &num);
int countNum(unordered_set<int> &hash, int n, int step);

void TestLongestConsecutive();


string minWindow(string S, string T);
void TestMinWindow();


void recoverTree(TreeNode *root);
 
void recoverTreeHelp(TreeNode *root, TreeNode * &n1, TreeNode * &n2, TreeNode * &prev);

void TestRecoverTree();

bool isScramble2(string s1, string s2);

void TestIsScramble2();

vector<int> findSubstring(string s, vector<string> &vec);

bool findSubDFS(vector<vector<bool> > &f, vector<string> &vec, int index, vector<bool> arr, int step);

void TestfindSubstring();

vector<int> findSubstring2(string s, vector<string> &vec);


void solve(vector<vector<char>> &board);

void TestRegion();

void solve2(vector<vector<char>> &board);
vector<pair<int,int>> BFS(int curX, int curY, vector<vector<char>> &board, vector<vector<bool>>& visited, bool& bFilp);

vector<string> fullJustify(vector<string> &words, int L);

void TestfullJustify();

vector<TreeNode *> generateTrees3(int n);

vector<TreeNode *> generateTreesHelp(int start, int to);

void TestGenerateTrees3();

bool isNumber(const char *s);

// 读取最长的数字串：如果碰到'.' 'e' 字母则停下
void readNumbers(const char *s, int &pos, int len);

void TestIsNumber();

bool exist3(vector<vector<char> > &board, string word);

bool wordSearchDFS(vector<vector<char> > &board, string &word, int step, vector<vector<bool> >&used, int x, int y);

void TestWordSearch();


vector<vector<string>> findLadders3(string start, string end, unordered_set<string> &dict);

vector<vector<string>> findLadders4(string start, string end, unordered_set<string> &dict);

void BuildLadderAnswerDFS(map<string, unordered_set<string> > & iMap, string str, vector<vector<string> >& ans, vector<string> & vec, int step);

void TestFindLadders3();

struct Point
{
	int x;
	int y;
};

int largestRectangleArea(vector<int> &height);

int largestRectangleArea2(vector<int> &height);

int largestRectangleArea3(vector<int> &height);
void TestLargestRectangleArea();

int maximalRectangle3(vector<vector<char> > &matrix);

void TestMaxRectangle();

bool isValidSudoku2(vector<vector<char> > &board);

void solveSudoku2(vector<vector<char> > &board);

bool sudokuDFS(vector<vector<char> > &board, int size, int step, vector<vector<bool> > &row, vector<vector<bool> > &col, vector<vector<bool> > &box); 

void TestSudokuSolve2();



#endif