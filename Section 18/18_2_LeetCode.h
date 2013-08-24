#ifndef _18_2_LEET_CODE_
#define _18_2_LEET_CODE_

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <stack>

#include "2_1_DeleteDuplicateListNode.h"

using namespace std;

/*
	3Sum
	Given an array S of n integers, are there elements a, b, c in S such that 
	a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
*/
vector<vector<int> >threeSum(vector<int> &num);
vector<vector<int> >threeSum2(vector<int> &num);


/*
	Given an array S of n integers, find three integers in S such that the sum 
	is closest to a given number, target. Return the sum of the three integers. 
	You may assume that each input would have exactly one solution.
*/
int threeSumClosest(vector<int> &num, int target);

/*
	Given an array S of n integers, are there elements a, b, c, and d in S such that 
	a + b + c + d = target? Find all unique quadruplets in the array which gives 
	the sum of target.
*/
vector<vector<int> >fourSum(vector<int> &num, int target);

/*
	Write a function to find the longest common prefix string amongst an array of strings.
*/
string longestCommonPrefix(vector<string> &strs);

void TestThreeSum();

int ladderLength(string start, string end, set<string> &dict);

void TestLadderLength();

vector<vector<string>> findLadders(string start, string end, set<string> &dict);

string countAndSay(int n);

void TestCountAndSay();

string multiply(string num1, string num2);

string MultiOne(string &num, char ch);

void ClearZero(string &num);

void TestMultiply();

int trap(int A[], int n);

void TestTrap();

vector<vector<int> > combinationSum(vector<int> &candidates, int target);
void TestCombinationSum();

void DFS(vector<vector<int> >& ans, vector<int> &num, int sum, 
	int target, vector<int> &vec, int size, int from, int remain);

vector<vector<int> > combinationSum2(vector<int> &num, int target);

int searchInsert(int arr[], int n, int target);


int findFirst(int arr[], int n, int target);
int findLast(int arr[], int n, int target);
vector<int> searchRange(int arr[], int n, int target);

int removeElement(int arr[], int n, int elem);

void nextPermutation(vector<int> &num);

void TestNextPermutation2();

char *strStr(char *haystack, char *needle);

void TestStrStr();

ListNode *swapPairs(ListNode *head);
void TestSwapPairs();

ListNode *reverseKGroup(ListNode *head, int k);

void ReverseList2(ListNode *&head, ListNode *&tail);

void TestReverseKGroup();

ListNode *mergeKLists(vector<ListNode *> &lists);

void TestMergeKLists();
void TestIsStrValid();
bool isMatchStr(char ch1, char ch2);

//
//int phoneCount[10] =
//{
//	0, 0, 3, 3, 3, 3, 3, 4, 3, 4
//};
//
//char phoneMap[10][4] = 
//{
//	{'0', '0', '0', '0'},
//	{'0', '0', '0', '0'},
//	{'a', 'b', 'c', '0'},
//	{'d', 'e', 'f', '0'},
//	{'g', 'h', 'i', '0'},
//	{'j', 'k', 'l', '0'},
//	{'m', 'n', 'o', '0'},
//	{'p', 'q', 'r', 's'},
//	{'t', 'u', 'v', '0'},
//	{'w', 'x', 'y', 'z'},
//};

vector<string> letterCombinations(string digits);


void LetterCombinationsDFS(string &str, string &tmp, vector<string> &ans, int size, int step);

void TestLetterCombinations();

bool exist(vector<vector<char> > &board, string word);

bool wordFindDFS(vector<vector<char> > &board, int row, int col, bool **used, string &word, int step, int curX, int curY);

void TestWordFind();

int minPathSum(vector<vector<int> > &grid);

void TestMinPathSum();

bool isPalindrome(int x);

void TestIsIntPalindrome();

string getPermutation2(int n, int k);

void TestGetPermutation2();
string getPermutation3(int n, int k);


int longestValidParentheses(string s);

int romanToInt(string s);

void TestRomanToInt();

string intToRoman(int num);

void TestIntToRoman();

string longestPalindrome(string s);

void TestLongestPalindrome();

string longestPalindrome2(string s);


#endif