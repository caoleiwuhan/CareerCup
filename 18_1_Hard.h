#include <iostream>

#include "2_1_DeleteDuplicateListNode.h"
#include "4_1_IsBalanceTree.h"

using namespace std;

/*
	write a function that add two number, can not use + operation
*/
int AddNumber(int a, int b);

void TestAddNumber();

const int CARD_NUM = 52;

/*
	发牌程序
*/
void ShuffleCard(int card[], int n);

void TestShuffleCard();

/*
	从n个数中随机选出m个数，每一个数被选中的概率相同
*/
void ChooseNumberRandomly(int arr[], int n, int ans[], int m);

void TestChooseNumberRandomly();

 struct TreeLinkNode
 {
	 int val;
	 TreeLinkNode *left;
	 TreeLinkNode *right;
	 TreeLinkNode *next;

	 TreeLinkNode(int num) : val(num), left(NULL), right(NULL), next(NULL) {}
 };

void connect(TreeLinkNode *root);

void TestConnect();

bool IsBinarySearchTree2(TreeNode *root);

bool IsBinarySearchTreeHelp(TreeNode *root, int minNum, int maxNum);

void TesIsBinarySearchTree2();

bool isPalindrome(string s);
void TestIsPalindrome();

ListNode *ReverseList(ListNode * &from, ListNode * &to);

ListNode *reverseBetween(ListNode *head, int m, int n);

void TestReverseBetween();

vector<vector<int> > subsetsWithDup(vector<int> &s);

void TestSubsetsWithDup();

void subsetsWithoutDup(vector<vector<int> > &ans, vector<int> &s);

int numDecodings(string s);
int numDecodings2(string s);

int DFS(string &s, int step, int len);

void TestNumDecoding();

bool DFS(vector<int> &ans, int total, int step, vector<bool> &f, int num, int N);
vector<int> grayCode(int n);
void TestGrayCode();

bool isScramble(string s1, string s2);

string SwapString(string s);

void TestIsScramble();


void sortColors(int arr[], int n);
void sortColors2(int arr[], int n);

void TestSortColor();

/*
	Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
	You have the following 3 operations permitted on a word:
	a) Insert a character
	b) Delete a character
	c) Replace a character
*/
int minDistance(string word1, string word2);

void TestMinDistance();

int minDistance2(string s1, string s2);


string simplifyPath(string path);
void TestSimplifyPath();

int IntSqrt(int x);
void TestIntSqrt();

vector<int> plusOne(vector<int> &arr);
void TestPlusOne();

string addBinary(string a, string b);
void TestAddBinary();

int uniquePaths(int m, int n);
int uniquePathsWithObstacles(vector<vector<int> > &vec);

void DFS(vector<string> &vec, string &s, int len, int step, int k, int index);
string getPermutation(int n, int k);


struct Interval 
{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval);

int FindFirstOfEndBegin(vector<Interval> &intervals, Interval newInterval);

int FindLastOfStartEnd(vector<Interval> &intervals, Interval newInterval);

bool canJump(int arr[], int n);
bool canJump2(int arr[], int n);
bool canJump3(int arr[], int n);

void TestCanJump();

void rotate(vector<vector<int> > &matrix);

vector<vector<int> > permute(vector<int> &num);

void DFS(vector<vector<int> > &ans, vector<int> &vec, int n, int step);

void TestPermute();

int jump(int arr[], int n);

void TestJump();

bool isMatch(const char *s, const char *p);


bool MatchDFS(const char *s, const char *p);

bool isMatch(const char *s, const char *p);

bool isMatch2(const char *s, const char *p);

void TestIsMatch();

bool isMatch3(const char *s, const char *p);


int CountNumberTwo(int num);

vector<Interval> merge3(vector<Interval> &intervals);

bool IntervalCompare(const Interval & i1, const Interval & i2);

struct IntervalComp
{
	bool operator()(const Interval &i1, const Interval &i2) const
	{
		return (i1.start < i2.start);
	}
};

void TestMergeIntervals();