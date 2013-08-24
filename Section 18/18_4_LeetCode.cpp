#include <iostream>
#include <map>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <stack>

#include "18_4_LeetCode.h"

using namespace std;

vector<vector<string> > partition(string s)
{
	int len = s.length();
	bool **f = new bool *[len];
	for (int i = 0; i < len; ++i)
	{
		f[i] = new bool[len];
		memset(f[i], 0, sizeof(bool) * (len));
	}
	for (int i = 0; i < len; ++i)
	{
		f[i][i] = true;
	}
	for (int k = 1; k < len; ++k)
	{
		for (int i = 0; i < (len - k); ++i)
		{
			int j = i + k;
			if (i + 1 < j - 1)
			{
				f[i][j] = (f[i+1][j-1] && (s[i] == s[j]));
			}
			else
			{
				f[i][j] = (s[i] == s[j]);
			}
		}
	}
	vector<string> tmp;
	vector<vector<string> > ans;
	pDFS(s, s.length(), f, 0, tmp, ans);

	for (int i = 0; i < len; ++i)
	{
		delete []f[i];
	}
	delete []f;
	return ans;
}

void pDFS(string &s, int len, bool **f, int step, vector<string> &tmp, vector<vector<string> > &ans)
{
	if (step == len)
	{
		ans.push_back(tmp);
		return;
	}
	for (int i = step; i < len; ++i)
	{
		if (f[step][i])
		{
			string str = s.substr(step, i - step + 1);
			tmp.push_back(str);
			pDFS(s, len, f, i + 1, tmp, ans);
			tmp.erase(tmp.end() - 1);
		}
	}
}

void TestPartition()
{
	string str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	//vector<vector<string> > ans = partition(str);
	//for (int i = 0; i < ans.size(); ++i)
	//{
	//	for (int j = 0; j < ans[i].size(); ++j)
	//	{
	//		cout << ans[i][j] << "   ";
	//	}
	//	cout << endl;
	//}

	/*vector<string> ans = partition2(str);
	for (int i = 0; i < ans.size(); ++i)
	{
	cout << ans[i] << "   ";
	}
	cout << endl;*/
	int ans = minCut4(str);
	cout << ans << endl;

}


vector<string> partition2(string s)
{
	int len = s.length();
	bool **f = new bool *[len];
	for (int i = 0; i < len; ++i)
	{
		f[i] = new bool[len];
		memset(f[i], 0, sizeof(bool) * (len));
	}
	for (int i = 0; i < len; ++i)
	{
		f[i][i] = true;
	}
	for (int k = 1; k < len; ++k)
	{
		for (int i = 0; i < (len - k); ++i)
		{
			int j = i + k;
			if (i + 1 < j - 1)
			{
				f[i][j] = (f[i+1][j-1] && (s[i] == s[j]));
			}
			else
			{
				f[i][j] = (s[i] == s[j]);
			}
		}
	}
	vector<string> tmp;
	vector<string> ans;
	for (int i = 0; i < len; ++i)
	{
		string str(1, s[i]);
		ans.push_back(str);
	}
	pDFS2(s, len, f, 0, tmp, ans);
	//int ans = minCut(s); 
	for (int i = 0; i < len; ++i)
	{
		delete []f[i];
	}
	delete []f;
	return ans;
}

void pDFS2(string &s, int len, bool **f, int step, vector<string> &tmp, vector<string> &ans)
{
	if (step == len)
	{
		if (tmp.size() < ans.size())
		{
			ans.clear();
			for (int i = 0; i < tmp.size(); ++i)
			{
				ans.push_back(tmp[i]);
			}
		}
		return;
	}
	for (int i = step; i < len; ++i)
	{
		if (f[step][i])
		{
			string str = s.substr(step, i - step + 1);
			tmp.push_back(str);
			pDFS2(s, len, f, i + 1, tmp, ans);
			tmp.erase(tmp.end() - 1);
		}
	}
}

int minCut(string s)
{
	int len = s.length();
	bool **f = new bool *[len];
	for (int i = 0; i < len; ++i)
	{
		f[i] = new bool[len];
		memset(f[i], 0, sizeof(bool) * (len));
	}
	for (int i = 0; i < len; ++i)
	{
		f[i][i] = true;
	}
	for (int k = 1; k < len; ++k)
	{
		for (int i = 0; i < (len - k); ++i)
		{
			int j = i + k;
			if (i + 1 < j - 1)
			{
				f[i][j] = (f[i+1][j-1] && (s[i] == s[j]));
			}
			else
			{
				f[i][j] = (s[i] == s[j]);
			}
		}
	}
	if (f[0][len - 1])
		return 0;
	for (int i = 1; i < len; ++i)
	{
		if (pDFS3(s, len, f, 0, 0, i))
		{
			return i;
		}
	}
	return (len - 1);
}

bool pDFS3(string &s, int len, bool **f, int step, int cur, int num)
{
	if (cur == num)
	{
		if (step >= len)
			return true;
		if (f[step][len - 1])
		{
			return true;
		}
		return false;
	}
	for (int i = step; i < len; ++i)
	{
		if (f[step][i])
		{
			if (pDFS3(s, len, f, i + 1, cur + 1, num))
			{
				return true;
			}
		}
	}
	return false;
}

int minCut2(string s)
{
	int len = s.length();
	if (len == 0)
		return 0;

	bool **f = new bool *[len];
	int **a = new int *[len];
	for (int i = 0; i < len; ++i)
	{
		f[i] = new bool[len];
		a[i] = new int[len];
		memset(f[i], 0, sizeof(bool) * (len));
		memset(a[i], 0, sizeof(int) * len);
	}
	for (int i = 0; i < len; ++i)
	{
		f[i][i] = true;
		a[i][i] = 0;
	}
	for (int k = 1; k < len; ++k)
	{
		for (int i = 0; i < (len - k); ++i)
		{
			int j = i + k;
			if (i + 1 < j - 1)
			{
				f[i][j] = (f[i+1][j-1] && (s[i] == s[j]));
			}
			else
			{
				f[i][j] = (s[i] == s[j]);
			}
		}
	}
	cout << f[0][len-1] << endl;
	for (int k = 1; k < len; ++k)
	{
		for (int i = 0; i < (len - k); ++i)
		{
			int j = i + k;			
			if (f[i][j])
			{
				a[i][j] = 0;
				continue;
			}
			a[i][j] = 0x7FFFFFFF;
			for (int mid = i; mid < j; ++mid)
			{
				a[i][j] = min(a[i][j], a[i][mid] + a[mid + 1][j] + 1);
			}
		}
	}
	int ans = a[0][len - 1];
	for (int i = 0; i < len; ++i)
	{
		delete []f[i];
		delete []a[i];
	}
	delete []f;
	delete []a;
	return ans;
}

int minCut3(string s)
{
	int len = s.length();
	if (len == 0)
		return 0;

	//bool f[1500][1500];
	bool **f = new bool*[len];
	int *a = new int[len];

	for (int i = 0; i < len; ++i)
	{		
		f[i] = new bool[len];
		memset(f[i], 0, sizeof(bool) * (len));		
	}
	for (int i = 0; i < len; ++i)
	{
		f[i][i] = true;		
	}

	for (int i = 0; i < len; ++i)
	{
		a[i] = i;
		for (int j = 0; j <= i; ++j)
		{
			// 判断从j到i是否是回文数
			if (s[i] == s[j] && (i - j < 2 || f[j+1][i-1]))
			{
				if (j == 0)
				{
					a[i] = 0;
				}
				else
				{
					a[i] = min(a[i], a[j-1] + 1);
					f[j][i] = true;
				}
			}
		}
	}

	for (int i = 0; i < len; ++i)
	{		
		delete[] f[i];
	}
	delete[] f;

	return a[len-1];
}


int minCut4(string s) 
{
	int len = s.size();
	int *dp = new int[len];
	bool **p = new bool*[len];
	for(int i=0; i<len; i++)
		p[i] = new bool[len];
	for(int i=0; i<len; i++) dp[i]=i;
	for(int i=0; i<len; i++)
		for(int j=0; j<len; j++)
			if(i == j) p[i][j] = true;
			else p[i][j] = false;
			for(int i=1; i<len; i++){
				for(int j=0; j<=i; j++){
					if(s[i] == s[j] && (i-j<2 || p[j+1][i-1])){
						p[j][i] = true;
						if(j == 0){
							dp[i] = 0;
							break;
						} else {
							dp[i] = min(dp[i],dp[j-1]+1);
						}
					}
				}
			}
			return dp[len-1];
}

vector<string> anagrams(vector<string> &strs)
{
	vector<string> ans;
	map<string, vector<string> > ss;
	for (int i = 0; i < strs.size(); ++i)
	{
		string tmp(strs[i]);
		sort(tmp.begin(), tmp.end());
		ss[tmp].push_back(strs[i]);
	}
	for (map<string, vector<string> >::iterator itr = ss.begin(); itr != ss.end(); ++itr)
	{
		if (itr->second.size() > 1)
		{
			ans.insert(ans.end(), itr->second.begin(), itr->second.end());
		}
	}
	return ans;
}

int maxProfit4(vector<int> &prices)
{
	if (prices.size() == 0)
		return 0;
	vector<int> f1;
	f1.resize(prices.size());
	vector<int> f2;
	f2.resize(prices.size());
	
	int minPrice = prices[0];
	f1[0] = 0;
	for (int i = 1; i < prices.size(); ++i)
	{
		minPrice = min(minPrice, prices[i]);
		f1[i] = max(f1[i-1], prices[i] - minPrice);
	}
	int maxPrice = prices[prices.size() - 1];
	f2[prices.size() - 1] = 0;
	for (int i = prices.size() - 2; i >= 0; --i)
	{
		maxPrice = max(maxPrice, prices[i]);
		f2[i] = max(f2[i + 1], maxPrice - prices[i]);
	}
	int ans = 0;
	for (int i = 0; i < prices.size(); ++i)
	{
		ans = max(ans, f1[i] + f2[i]);
	}
	return ans;
}

void TestMaxProfit2()
{
	vector<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	cout << maxProfit4(arr) << endl;
}

int numDistinct(string s, string t)
{
	int len1 = s.length();
	int len2 = t.length();

	int **f = new int* [len1 + 1];
	for (int i = 0; i <= len1; ++i)
	{
		f[i] = new int[len2 + 1];
		memset(f[i], 0, sizeof(int) * (len2 + 1));
	}
	f[0][0] = 1;
	for (int i = 1; i <= len1; ++i)
	{
		f[i][0] = 1;
		for (int j = 1; j <= min(len2, i); ++j)
		{
			f[i][j] = f[i-1][j];
			if (s[i-1] == t[j-1])
			{
				f[i][j] += f[i-1][j-1];
			}
		}
	}
	int ans = f[len1][len2];
	for (int i = 0; i <= len1; ++i)
	{
		delete [] f[i];
	}
	delete []f;
	return ans;
}

void TestNumDistinct()
{
	/*string s = "rabbbit";
	string t = "rabbit";
	cout << numDistinct(s, t) << endl;*/
	TreeNode t1(1);
	TreeNode t2(2);
	TreeNode t3(3);
	TreeNode t4(4);
	TreeNode t5(5);
	TreeNode t6(6);

	//t1.left = &t2;
	//t1.right = &t5;
	//t2.left = &t3;
	//t2.right = &t4;
	//t5.right = &t6;

	t1.right = &t2;
	t2.left = &t3;

	flatten(&t1);


}


void flatten(TreeNode *root)
{
	FlattenHelp(root);
}

void FlattenHelp(TreeNode *node)
{
	if (node == NULL)
	{
		return;
	}
	TreeNode *pRight = node->right;
	if (node->left)
	{		
		TreeNode *pLeft = node->left;
		node->left = NULL;
		if (pLeft)
		{
			FlattenHelp(pLeft);
			TreeNode *ptmp = pLeft;
			while (ptmp->right)
			{
				ptmp = ptmp->right;
			}			
			node->right = pLeft;
			ptmp->right = pRight;
			
		}
	}
	if (pRight)
	{
		FlattenHelp(pRight);
	}
}

int longestConsecutive(vector<int> &num) 
{
	unordered_set<int> hash;
	for (int i = 0; i < num.size(); ++i)
	{
		hash.insert(num[i]);
	}
	int ans = 0;
	for (int i = 0; i < num.size(); ++i)
	{
		int n = num[i];
		unordered_set<int>::iterator itr = hash.find(n);
		if (itr != hash.end())
		{
			hash.erase(itr);
			int tmp = 1;
			tmp += countNum(hash, n + 1, 1);
			tmp += countNum(hash, n - 1, -1);
			ans = max(ans, tmp);
		}
	}
	return ans;
}

int countNum(unordered_set<int> &hash, int n, int step)
{
	int ans = 0;
	unordered_set<int>::iterator itr = hash.find(n);
	while (itr != hash.end())
	{
		++ans;
		hash.erase(itr);
		n += step;
		itr = hash.find(n);
	}
	return ans;
}

void TestLongestConsecutive()
{
	int arr[] = {100, 4, 200, 1, 3, 2};
	vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
	cout << longestConsecutive(vec) << endl;

}


string minWindow(string s, string t)
{	
	int len1 = s.length();
	int len2 = t.length();
	int hash[256];
	memset(hash, 0, sizeof(hash));
	for (int i = 0; i < len2; ++i)
	{
		hash[t[i]]++;
	}
	int arr[256];
	memset(arr, 0, sizeof(arr));
	int left = -1;
	int right = -1;
	bool ok = false;
	int length = len1;
	int start = -1;
	
	while (!ok)
	{
		if (right >= len1)
		{
			return "";
		}
		++right;
		if (hash[s[right]] != 0)
		{
			arr[s[right]]++;
		}
		ok = true;
		for (int i = 0; i < 256; ++i)
		{
			if (hash[i] != 0 && hash[i] > arr[i])
			{
				ok = false;
				break;
			}
		}
	}
	length = right + 1;
	start = 0;
	char ch;
	while (right < len1 && (left <= right))
	{
		if (!ok)
		{
			++right;
			if (right >= len1)
				break;

			if (hash[s[right]] != 0)
			{
				arr[s[right]]++;
				if (s[right] == ch)
				{
					ok = true;
					int cur = right - left;
					if (cur < length)
					{
						length = cur;
						start = left + 1;
					}
				}
			}
		}
		else
		{
			++left;
			if (hash[s[left]] != 0)
			{
				arr[s[left]]--;
				if (hash[s[left]] > arr[s[left]])
				{
					ok = false;
					ch = s[left];
				}
			}
			if (ok)
			{
				int cur = right - left;
				if (cur < length)
				{
					length = cur;
					start = left + 1;
				}
			}
		}
	}
	string ans = s.substr(start, length);
	return ans;
}

void TestMinWindow()
{
	string s = "ADOBECODEBANC";
	string t = "ABC";
	cout << minWindow(s, t) << endl;

}

void recoverTree(TreeNode *root)
{
	if (root == NULL)
	{
		return;
	}
	TreeNode *n1 = NULL;
	TreeNode *n2 = NULL;
	TreeNode *prev = NULL;
	recoverTreeHelp(root, n1, n2, prev);
	if (n1 && n2)
	{
		int tmp = n1->val;
		n1->val = n2->val;
		n2->val = tmp;
	}
}

void recoverTreeHelp(TreeNode *root, TreeNode * &n1, TreeNode * &n2, TreeNode * &prev)
{
	if (root == NULL)
		return;
	recoverTreeHelp(root->left, n1, n2, prev);
	if (prev && prev->val > root->val)
	{
		n2 = root;
		if (!n1)
		{
			n1 = prev;
		}
	}
	prev = root;
	recoverTreeHelp(root->right, n1, n2, prev);
}

void TestRecoverTree()
{
	TreeNode t1(1);
	TreeNode t2(2);
	TreeNode t3(3);
	TreeNode t4(4);
	TreeNode t5(5);
	TreeNode t6(6);

	//t1.left = &t2;
	//t1.right = &t5;
	//t2.left = &t3;
	//t2.right = &t4;
	//t5.right = &t6;

	t1.left = &t2;
	recoverTree(&t1);
}

bool isScramble2(string s1, string s2)
{
	int len1 = s1.length();
	int len2 = s2.length();
	if (len1 != len2)
	{
		return false;
	}
	if (len1 == 0)
	{
		return true;
	}
	vector<vector<vector<bool> > > f(len1, vector<vector<bool> >(len1, vector<bool>(len1, false)));
	for (int i = 0; i < len1; ++i)
	{
		for (int j = 0; j < len1; ++j)
		{
			f[i][j][0] = (s1[i] == s2[j]);
		}
	}

	for (int k = 1; k < len1; ++k)
	{
		for (int i = 0; i < (len1 - k); ++i)
		{
			for (int j = 0; j < (len1 - k); ++j)
			{
				for (int m = 1; m <= k; ++m)
				{
					if ((f[i][j][m - 1] && f[i + m][j + m][k - m]) ||
						(f[i][j + k + 1 - m][m - 1] && f[i + m][j][k - m]))
					{
						f[i][j][k] = true;
						break;
					}
				}
			}
		}
	}
	return f[0][0][len1 - 1];
}

void TestIsScramble2()
{
	string s1 = "abb";
	string s2 = "bba";
	cout << isScramble2(s1, s2) << endl;
}


vector<int> findSubstring(string s, vector<string> &vec)
{
	int len1 = s.length();
	int len2 = 0;
	int size = vec.size();
	for (int i = 0; i < size; ++i)
	{
		len2 += vec[i].length();
	}
	vector<int> ans;
	if (len1 == 0 || len2 > len1)
	{
		return ans;
	}
	
	vector<vector<bool> > f(len1, vector<bool>(size, false));
	for (int i = 0; i < len1; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (i + vec[j].size() > len1)
			{
				continue;
			}
			string str = s.substr(i, vec[j].size());
			if (str.compare(vec[j]) == 0)
			{
				f[i][j] = true;
			}
		}
	}
	
	for (int i = 0; i <= (len1 - len2); ++i)
	{
		vector<bool> arr(size, false);
		if (findSubDFS(f, vec, i, arr, 0))
		{
			ans.push_back(i);
		}
	}
	return ans;
}

bool findSubDFS(vector<vector<bool> > &f, vector<string> &vec, int index, vector<bool> arr, int step)
{
	if (step == vec.size())
	{
		return true;
	}
	for (int i = 0; i < vec.size(); ++i)
	{
		if (!arr[i] && f[index][i])
		{
			arr[i] = true;
			if (findSubDFS(f, vec, index + vec[i].length(), arr, step + 1))
			{
				return true;
			}
			arr[i] = false;
		}
	}
	return false;
}

void TestfindSubstring()
{
	string str = "barfoothefoobarman";
	vector<string> vec;
	vec.push_back("foo");
	vec.push_back("bar");

	cout << findSubstring2(str, vec).size() << endl;

}

/*
	判断一个字符串是不是若干个的拼接！
*/
vector<int> findSubstring2(string s, vector<string> &vec)
{
	int len1 = s.length();
	int size = vec.size();
	vector<int> ans;
	if (size == 0)
	{
		return ans;
	}
	int strLen = vec[0].length();
	if (len1 < size * strLen)
	{
		return ans;
	}
	map<string, int> vecMap;
	map<string, int> curMap;
	for (int i = 0; i < size; ++i)
	{
		vecMap[vec[i]]++;
	}
	for (int i = 0; i <= (len1 - size * strLen); ++i)
	{
		curMap.clear();
		int j = 0;
		for (; j < size; ++j)
		{
			string str = s.substr(i + j * strLen, strLen);
			if (vecMap.find(str) == vecMap.end())
			{
				break;
			}
			curMap[str]++;
			if (curMap[str] > vecMap[str])
			{
				break;
			}
		}
		if (j == size)
		{
			ans.push_back(i);
		}
	}
	return ans;
}

void solve(vector<vector<char>> &board)
{
	int row = board.size();
	if (row == 0)
		return;
	int col = board[0].size();
	vector<vector<bool> > visited(row, vector<bool>(col, false));
		
	int path[4][2] = 
	{
		-1, 0,
		0, 1,
		1, 0,
		0, -1
	};

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			
			if (!visited[i][j] && board[i][j] == 'O')
			{		
				visited[i][j] = true;
				// 边界
				if (i == 0 || i == (row - 1) || j == 0 || j == (col - 1))
				{
					continue;
				}
				queue<pair<int, int> > que;
				que.push(make_pair(i, j));
				vector<vector<bool> > f(row, vector<bool>(col, false));
				f[i][j] = true;
				
				bool isOK = true;
				while (!que.empty())
				{
					int x = que.front().first;
					int y = que.front().second;
					que.pop();
					// 如果是边界
					if (x == 0 || x == (row - 1) || y == 0 || y == (col - 1))
					{
						isOK = false;
						continue;
					}
					for (int k = 0; k < 4; ++k)
					{
						int nx = x + path[k][0];
						int ny = y + path[k][1];
						if (visited[nx][ny] && !f[nx][ny] && board[nx][ny] == 'O')
						{
							isOK = false;
							continue;
						}
						if (!visited[nx][ny] && board[nx][ny] == 'O')
						{
							que.push(make_pair(nx, ny));
							f[nx][ny] = true;
							visited[nx][ny] = true;
						}
					}
				}
				if (isOK)
				{
					for (int m = 0; m < row; ++m)
					{
						for (int n = 0; n < col; ++n)
						{
							if (f[m][n])
								board[m][n] = 'X';
						}
					}
				}
			}
		}
	}
	
}

void TestRegion()
{
	/*vector<vector<char> > board(7, vector<char>(7, 'O'));
	board[0][0] = 'X';
	board[0][2] = 'X';
	board[1][0] = 'X';
	board[2][0] = 'X';
	board[2][5] = 'X';
	board[3][4] = 'X';
	board[3][6] = 'X';
	board[4][1] = 'X';
	board[6][1] = 'X';*/

	vector<vector<char> > board(3, vector<char>(3, 'X'));
	board[1][1] = 'O';
/*
	board[0][0] = 'X';
	board[0][1] = 'X';
	board[0][2] = 'X';
	board[0][3] = 'X';

	board[1][0] = 'X';
	board[1][1] = 'O';
	board[1][2] = 'O';
	board[1][3] = 'X';

	board[2][0] = 'X';
	board[2][1] = 'X';
	board[2][2] = 'O';
	board[2][3] = 'X';

	board[3][0] = 'X';
	board[3][1] = 'O';
	board[3][2] = 'X';
	board[3][3] = 'X';*/

	solve(board);
}


vector<pair<int,int>> BFS(int curX, int curY, vector<vector<char>> &board, vector<vector<bool>>& visited, bool& bFilp)
{
	int n = board.size();
	int m = board[0].size();
	int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
	queue<pair<int, int>> q;
	visited[curX][curY] = true;
	q.push(make_pair(curX, curY));
	vector<pair<int,int>> path;
	while (!q.empty())
	{
		int x = q.front().first; 
		int y = q.front().second;
		path.push_back(q.front());
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int nextX = x+dir[i][0];
			int nextY = y+dir[i][1];
			if(nextX >= 0 && nextX < n && nextY >= 0 && nextY < m)
			{
				if(!visited[nextX][nextY] && board[nextX][nextY] == 'O')
				{
					q.push(make_pair(nextX, nextY));
					visited[nextX][nextY] = true;
				}
					
			}
			else bFilp = false;
				
		}
	}
	return path;
}
void solve2(vector<vector<char>> &board) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	int n = board.size();
	if(n == 0) return;
	int m = board[0].size();
	vector<vector<bool>> visited;
	visited.resize(n);
	for(int i = 0; i < n; ++i)
		visited[i].assign(m, false);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(!visited[i][j] && board[i][j] == 'O')
			{
				bool bFlip = true;
				vector<pair<int,int>> path = BFS(i, j, board, visited, bFlip);
				if(bFlip)
				{
					for (int pIdx = 0; pIdx < path.size(); ++pIdx)
						board[path[pIdx].first][path[pIdx].second] = 'X';
				}
			}
		}
	}
}

vector<string> fullJustify(vector<string> &words, int L)
{
	int size = words.size();
	vector<string> ans;
	if (size == 0)
	{
		return ans;
	}
	vector<int> length(size + 1);
	length[0] = 0;
	for (int i = 1; i <= size; ++i)
	{
		length[i] = length[i-1] + words[i - 1].length(); 
	}
	vector<int> f(size + 1, 0x7FFFFFFF);
	f[0] = 0;
	for (int i = 1; i <= size; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			int len = 0;
			len = length[i] - length[j];
			len += (i - j - 1);
			if (len <= L)
			{
				f[i] = min(f[i], f[j] + 1);
			}
		}
	}
	int line = f[size];	
	int curLine = 1;
	int start = 1;
	for (int i = 1; i <= size; ++i)
	{
		if (f[i] != curLine)
		{
			int strLen = length[i - 1] - length[start - 1];
			int spaceNum = L - strLen;
			int count = i - start - 1;
			if (count == 0)
			{
				count = 1;
			}
			int perSpace = spaceNum / count;
			int remain = spaceNum - perSpace * count;
			string str;
			int cur = 0;
			for (int j = start; j < i - 1; ++j)
			{
				str += words[j - 1];
				for (int k = 0; k < perSpace; ++k)
				{
					str += ' ';
				}
				if (cur < remain)
				{
					str += ' ';
					cur++;
				}
			}
			str += words[i - 2];

			int remain2 = L - str.length();
			for (int t = 0; t < remain2; ++t)
			{
				str += ' ';
			}

			ans.push_back(str);			
			curLine++;
			start = i;
		}
	}
	if (start <= size)
	{
		string str = words[start - 1];
		for (int i = start + 1; i <= size; ++i)
		{
			str += ' ';
			str += words[i - 1];
		}

		int remain = L - str.length();
		for (int i = 0; i < remain; ++i)
		{
			str += ' ';
		}
	
		ans.push_back(str);
	}
	return ans;
}

void TestfullJustify()
{
	vector<string> words;
	/*words.push_back("This");
	words.push_back("is");
	words.push_back("an");
	words.push_back("example");
	words.push_back("of");
	words.push_back("text");
	words.push_back("justification.");
	words.push_back("a");

	fullJustify(words, 16);*/

	words.push_back("a");
	
	fullJustify(words, 2);
}

vector<TreeNode *> generateTrees3(int n)
{
	vector<TreeNode *> ans = generateTreesHelp(1, n);
	return ans;
}

vector<TreeNode *> generateTreesHelp(int start, int to)
{
	vector<TreeNode *> ans;
	if (start > to)
	{
		ans.push_back(NULL);
		return ans;
	}
	if (start == to)
	{
		TreeNode *node = new TreeNode(to);
		ans.push_back(node);
		return ans;
	}
	for (int i = start; i <= to; ++i)
	{		
		vector<TreeNode *> left = generateTreesHelp(start, i - 1);
		vector<TreeNode *> right = generateTreesHelp(i + 1, to);
		for (int m = 0; m < left.size(); ++m)
		{
			for (int n = 0; n < right.size(); ++n)
			{
				TreeNode *root = new TreeNode(i);
				root->left = left[m];
				root->right = right[n];
				ans.push_back(root);
			}
		}
	}
	return ans;
}

void TestGenerateTrees3()
{
	vector<TreeNode *> ans = generateTrees3(3);
}


bool isNumber(const char *s)
{
	if (s == NULL)
		return false;
	int len = strlen(s);
	if (len == 0)
		return false;
	int pos = 0;
	while (s[pos] == ' ')
	{
		++pos;
	}
	if (pos >= len)
	{
		return false;
	}
	int end = len - 1;
	// 去除末尾的' '
	while (s[end] == ' ')
	{
		end--;
	}
	++end;	
	if (s[pos] == '+' || s[pos] == '-')
	{
		++pos;
	}
	if (pos >= end)
	{
		return false;
	}
	int cur = pos;
	readNumbers(s, pos, end);
	if (pos >= end)
	{
		return true;
	}
	bool before = (cur != pos);	

	char ch = s[pos];
	if (s[pos] != '.' && s[pos] != 'e' && s[pos] != 'E')
	{
		return false;
	}	
	++pos;
	if (pos >= end && s[pos-1] == '.' && before)
	{
		return true;
	}
	if (s[pos-1] != '.' && !before)
	{
		return false;
	}

	if (s[pos] == '+' || s[pos] == '-') 
	{
		if (s[pos - 1] != 'e' && s[pos - 1] != 'E')
		{
			return false;
		}
		++pos;
	}
	cur = pos;
	readNumbers(s, pos, end);
	bool after = (cur != pos);
	if (ch == '.')
	{
		if (!before && !after)
		{
			return false;
		}
	}
	else
	{
		if (!before || !after)
			return false;
	}

	if (ch == '.' && (s[pos] == 'e' || s[pos] == 'E'))
	{
		++pos;
		if (s[pos] == '+' || s[pos] == '-')
			++pos;

		cur = pos;
		readNumbers(s, pos, end);
		if (cur == pos)
		{
			return false;
		}
		if (pos >= end)
		{
			return true;
		}
		return false;
	}
	else if (pos >= end)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void readNumbers(const char *s, int &pos, int len)
{
	while (s[pos] >= '0' && s[pos] <= '9')
	{
		++pos;
	}
}

void TestIsNumber()
{
	char *str = "32.e-80123";
	cout << isNumber(str) << endl;

}

int wordMap[4][2] = 
{
	-1, 0,
	0, 1,
	1, 0,
	0, -1
};

bool exist3(vector<vector<char> > &board, string word)
{
	if (word.size() == 0)
		return true;

	vector<vector<bool> > used(board.size(), vector<bool>(board[0].size(), false));
	for (int i = 0; i < board.size(); ++i)
	{
		for (int j = 0; j < board[0].size(); ++j)
		{
			if (board[i][j] == word[0])
			{
				used[i][j] = true;
				if (wordSearchDFS(board, word, 1, used, i, j))
				{
					return true;
				}
				used[i][j] = false;
			}
		}
	}
	return false;
}

bool wordSearchDFS(vector<vector<char> > &board, string &word, int step, vector<vector<bool> >&used, int x, int y)
{
	if (step >= word.length())
	{
		return true;
	}
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + wordMap[i][0];
		int ny = y + wordMap[i][1];
		if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size())
		{
			if (word[step] == board[nx][ny] && !used[nx][ny])
			{
				used[nx][ny] = true;
				if (wordSearchDFS(board, word, step + 1, used, nx, ny))
				{
					return true;
				}
				used[nx][ny] = false;
			}
		}
	}
	return false;
}

void TestWordSearch()
{
	vector<vector<char> > board;
	vector<char> v1;
	v1.push_back('A');
	v1.push_back('B');
	v1.push_back('C');
	v1.push_back('E');
	board.push_back(v1);

	vector<char> v2;
	v2.push_back('S');
	v2.push_back('F');
	v2.push_back('C');
	v2.push_back('S');
	board.push_back(v2);

	vector<char> v3;
	v3.push_back('A');
	v3.push_back('D');
	v3.push_back('E');
	v3.push_back('E');
	board.push_back(v3);
	cout << exist3(board, "ABCCED") << endl;
	cout << exist3(board, "SEE") << endl;
	cout << exist3(board, "ABCB") << endl;
}


vector<vector<string>> findLadders3(string start, string end, unordered_set<string> &dict)
{
	vector<vector<string> > ans;
	vector<string> vec;
	unordered_set<string> s;

	queue<string> q;
	q.push(start);
	s.insert(start);
	
	while (!q.empty())
	{
		string str = q.front();
		q.pop();
		vec.push_back(str);
		if (!ans.empty() && ans[0].size() <= vec.size())
		{
			break;
		}

		for (int i = 0; i < str.size(); ++i)
		{
			for (int j = 0; j < 26; ++j)
			{
				string nStr = str;
				nStr[i] = 'a' + j;
				if (nStr.compare(end) == 0)
				{
					vec.push_back(end);
					ans.push_back(vec);
					vec.pop_back();
					vec.pop_back();
					continue;								
				}
				if (dict.find(nStr) != dict.end() && s.find(nStr) == s.end())
				{
					s.insert(nStr);
					q.push(nStr);
				}
			}
		}
	}
	return ans;
}

void TestFindLadders3()
{
	unordered_set<string> dict;
	dict.insert("hot");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");

	vector<vector<string> > ans = findLadders4("hit", "cog", dict);

	/*unordered_set<string> dict;
	dict.insert("a");
	dict.insert("b");
	dict.insert("c");
	
	vector<vector<string> > ans = findLadders4("a", "c", dict);*/

	/*unordered_set<string> dict;
	dict.insert("ted");
	dict.insert("tex");
	dict.insert("red");
	dict.insert("tax");
	dict.insert("tad");
	dict.insert("den");
	dict.insert("rex");
	dict.insert("pee");

	vector<vector<string> > ans = findLadders4("red", "tax", dict);*/
}

vector<vector<string>> findLadders4(string start, string end, unordered_set<string> &dict)
{
	map<string, unordered_set<string> >iMap;
	for (unordered_set<string>::iterator it = dict.begin(); it != dict.end(); ++it)
	{
		iMap[*it] = unordered_set<string>();
	}

	vector<vector<string> > ans;
	vector<string> q;
	unordered_set<string> s;
	unordered_set<string> levelSet;

	int left = 0;
	int right = 0;
	q.push_back(start);
	s.insert(start);
	int level = 0;
	int total = 0;
	bool isFound = false;
	while (left <= right)
	{
		string str = q[left++];
		if (isFound && level > total)
		{
			break;
		}
		
		for (int i = 0; i < str.size(); ++i)
		{
			for (int j = 0; j < 26; ++j)
			{
				string nStr = str;
				nStr[i] = 'a' + j;
				if (nStr.compare(end) == 0)
				{
					if (!isFound) 
					{
						isFound = true;
						total = level;
					}
					if (level <= total)
					{
						iMap[nStr].insert(str);
					}			
					
					continue;								
				}
				if (dict.find(nStr) != dict.end() && s.find(nStr) == s.end())
				{
					iMap[nStr].insert(str);
					levelSet.insert(nStr);
					q.push_back(nStr);
					
				}
			}
		}
		if (left > right && left < q.size())
		{
			right = q.size() - 1;
			++level;
			s.insert(levelSet.begin(), levelSet.end());
			levelSet.clear();
		}
	}
	if (iMap[end].size() != 0)
	{
		vector<string> strVec(total + 2, "");
		strVec[total + 1] = end;
		BuildLadderAnswerDFS(iMap, end, ans, strVec, total);
	}

	return ans;
}

void BuildLadderAnswerDFS(map<string, unordered_set<string> > & iMap, string str, vector<vector<string> >& ans, vector<string> & vec, int step)
{
	if (step == -1)
	{
		ans.push_back(vec);
		return;
	}
	unordered_set<string> tmp = iMap[str];
	for (unordered_set<string>::iterator it = tmp.begin(); it != tmp.end(); ++it)
	{
		vec[step] = *it;
		BuildLadderAnswerDFS(iMap, *it, ans, vec, step - 1);
	}
}


/*
	维护一个单调递增的栈，
	如果不满足条件，就要出栈：
		1：将边加到上一个上面！:谁大加到谁上面！
		2：更新最大面积
*/
int largestRectangleArea(vector<int> &height)
{
	stack<Point> s;
	Point p;
	p.x = -1;
	p.y = 0;
	s.push(p);

	int ans = 0;
	for (int i = 0; i < height.size(); ++i)
	{
		int h = height[i];
		int len = 1;		
		while (s.top().x >= h)
		{				
			Point pTmp = s.top();
			s.pop();
			int tmp = pTmp.x * pTmp.y;
			ans = max(ans, tmp);

			if (s.top().x == -1 || pTmp.x == h || s.top().x == 0)
			{
				len += pTmp.y;					
			}
			else
			{
				s.top().y += pTmp.y;
			}
		}		
		Point p2;
		p2.x = h;
		p2.y = len;
		s.push(p2);		
	}
	while (s.top().x != -1)
	{
		Point pTmp = s.top();
		s.pop();
		int tmp = pTmp.x * pTmp.y;
		ans = max(ans, tmp);
		if (s.top().x != -1)
		{
			s.top().y += pTmp.y;
		}
	}
	return ans;
}

int largestRectangleArea2(vector<int> &height)
{
	stack<Point> s;
	Point p;
	p.x = 0;
	p.y = 0;
	s.push(p);

	unsigned ans = 0;
	for (int i = 0; i < height.size(); ++i)
	{
		unsigned h = height[i] + 1;
		unsigned len = 1;		
		while (s.top().x >= h)
		{				
			Point pTmp = s.top();
			s.pop();
			unsigned tmp = (pTmp.x - 1) * pTmp.y;
			ans = max(ans, tmp);

			if (s.top().x == 0 || s.top().x == 1 || pTmp.x == h)
			{
				len += pTmp.y;					
			}
			else
			{
				s.top().y += pTmp.y;
			}
		}		
		Point p2;
		p2.x = h;
		p2.y = len;
		s.push(p2);		
	}
	while (s.top().x != 0)
	{
		Point pTmp = s.top();
		s.pop();
		unsigned tmp = (pTmp.x - 1) * pTmp.y;
		ans = max(ans, tmp);
		if (s.top().x != 0)
		{
			s.top().y += pTmp.y;
		}
	}
	return ans;
}


void TestLargestRectangleArea()
{
	vector<int> arr;
	//arr.push_back(3);
	//arr.push_back(6);
	//arr.push_back(5);
	//arr.push_back(7);
	//arr.push_back(4);
	//arr.push_back(8);
	//arr.push_back(1);
	arr.push_back(0);

	cout << largestRectangleArea3(arr) << endl;
}

int largestRectangleArea3(vector<int> &height)
{
	stack<Point> s;
	Point p;
	p.x = -1;
	p.y = 0;
	s.push(p);

	int ans = 0;
	for (int i = 0; i < height.size(); ++i)
	{
		int h = height[i];
		int len = 1;
		int ascLen = 0;
		while (s.top().x >= h)
		{				
			Point pTmp = s.top();
			s.pop();
			ascLen += pTmp.y;
			int tmp = pTmp.x * ascLen;
			ans = max(ans, tmp);				
		}		
		Point p2;
		p2.x = h;
		p2.y = len + ascLen;
		s.push(p2);		
	}
	while (s.top().x != -1)
	{
		Point pTmp = s.top();
		s.pop();
		int tmp = pTmp.x * pTmp.y;
		ans = max(ans, tmp);
		if (s.top().x != -1)
		{
			s.top().y += pTmp.y;
		}
	}
	return ans;
}


int maximalRectangle3(vector<vector<char> > &matrix)
{
	int row = matrix.size();
	if (row == 0)
		return 0;
	int col = matrix[0].size();
	vector<vector<int> > arr(row, vector<int>(col, 0));
	for (int i = 0; i < col; ++i)
	{
		if (matrix[0][i] == '1')
		{
			arr[0][i] = 1;
		}
	}
	for (int i = 1; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (matrix[i][j] == '1')
			{
				arr[i][j] = arr[i-1][j] + 1;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < row; ++i)
	{
		int tmp = largestRectangleArea3(arr[i]);
		ans = max(ans, tmp);
	}
	return ans;
}

void TestMaxRectangle()
{
}


bool isValidSudoku2(vector<vector<char> > &board)
{
	int size = board.size();
	// 第row行是否出现x
	vector<vector<bool> >row(size, vector<bool>(size, false));
	// 第col行是否出现x
	vector<vector<bool> >col(size, vector<bool>(size, false));
	// 第box是否出现x
	vector<vector<bool> >box(size, vector<bool>(size, false));

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (board[i][j] == '.')
			{
				continue;
			}
			int num = board[i][j] - '1';
			int index = (i / 3) * 3 + (j / 3);
			if (row[i][num] || col[j][num] || box[index][num])
			{
				return false;
			}
			row[i][num] = col[j][num] = box[index][num] = true;
		}
	}
	return true;
}


void solveSudoku2(vector<vector<char> > &board)
{
	int size = board.size();
	vector<vector<bool> >row(size, vector<bool>(size, false));
	vector<vector<bool> >col(size, vector<bool>(size, false));
	vector<vector<bool> >box(size, vector<bool>(size, false));

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (board[i][j] == '.')
			{
				continue;
			}
			int num = board[i][j] - '1';
			int index = (i / 3) * 3 + (j / 3);
			row[i][num] = col[j][num] = box[index][num] = true;
		}
	}
	sudokuDFS(board, size, 0, row, col, box);

}

bool sudokuDFS(vector<vector<char> > &board, int size, int step, vector<vector<bool> > &row, vector<vector<bool> > &col, vector<vector<bool> > &box)
{
	if (step == size * size)
	{
		return true;
	}
	int x = step / size;
	int y = step % size;
	if (board[x][y] != '.')
	{
		if (sudokuDFS(board, size, step + 1, row, col, box))
		{
			return true;
		}
	}
	else
	{
		for (int i = 0; i < 9; ++i)
		{
			int index = (x / 3) * 3 + (y / 3);
			// 判断当前位置是否可以放置(i+1)
			if (row[x][i] || col[y][i] || box[index][i])
			{
				continue;
			}
			row[x][i] = col[y][i] = box[index][i] = true;
			board[x][y] = i + '1';
			if (sudokuDFS(board, size, step + 1, row, col, box))
			{
				return true;
			}
			row[x][i] = col[y][i] = box[index][i] = false;
			board[x][y] = '.';
		}
	}
	return false;
}

void TestSudokuSolve2()
{
	vector<vector<char> > board(9, vector<char>(9, '.'));
	board[0][0] = '5';
	board[0][1] = '3';
	board[0][4] = '7';

	board[1][0] = '6';
	board[1][3] = '1';
	board[1][4] = '9';
	board[1][5] = '5';

	board[2][1] = '9';
	board[2][2] = '8';
	board[2][7] = '6';

	board[3][0] = '8';
	board[3][4] = '6';
	board[3][8] = '3';

	board[4][0] = '4';
	board[4][3] = '8';
	board[4][5] = '3';
	board[4][8] = '1';

	board[5][0] = '7';
	board[5][4] = '2';
	board[5][8] = '6';

	board[6][1] = '6';
	board[6][6] = '2';
	board[6][7] = '8';

	board[7][3] = '4';
	board[7][4] = '1';
	board[7][5] = '9';
	board[7][8] = '5';

	board[8][4] = '8';
	board[8][7] = '7';
	board[8][8] = '9';

	solveSudoku2(board);
}