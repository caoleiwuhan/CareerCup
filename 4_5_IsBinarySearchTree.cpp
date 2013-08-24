#include <iostream>
#include <vector>
#include <string>

#include "4_5_IsBinarySearchTree.h"

using namespace std;

/*
	思路：
		递归实现。判断左子树、右子树的情况
		有两种特殊情况要判断：
			1：左子树的右孩子必须小于自己
			2：右子树的左孩子必须大于自己
*/
bool IsBinarySearchTree(TreeNode *pNode)
{
	if (pNode == NULL)
		return true;
	if (pNode->left != NULL)
	{
		if (pNode->val <= pNode->left->val)
			return false;
		if (pNode->left->right != NULL && pNode->left->right->val >= pNode->val)
			return false;
		if (!IsBinarySearchTree(pNode->left))
			return false;		
	}
	if (pNode->right != NULL)
	{
		if (pNode->val >= pNode->right->val)
			return false;
		if (pNode->right->left != NULL && pNode->right->left->val <= pNode->val)
			return false;
		if (!IsBinarySearchTree(pNode->right))
			return false;
	}
	return true;
}

bool IsBinarySearchTree3(TreeNode *root)
{
	int minNum = 0x80000000;
	int maxNum = 0x7FFFFFFF;
	return IsBinarySearchTree3Help(root, minNum, maxNum);	
}
bool IsBinarySearchTree3Help(TreeNode *root, int minNum, int maxNum)
{
	if (root == NULL)
		return true;
	if (root->left != NULL)
	{
		int leftMin = minNum;
		int leftMax = min(root->val, maxNum);
		if (root->left->val <= leftMin || root->left->val >= leftMax)
		{
			return false;
		}
		if (!IsBinarySearchTree3Help(root->left, leftMin, leftMax))
		{
			return false;
		}
	}
	if (root->right != NULL)
	{
		int rightMin = max(minNum, root->val);
		int rightMax = maxNum;
		if (root->right->val <= rightMin || root->right->val >= rightMax)
		{
			return false;
		}
		if (!IsBinarySearchTree3Help(root->right, rightMin, rightMax))
			return false;
	}
	return true;
}

void TestIsBinarySearchTree()
{
	TreeNode n10(10);
	TreeNode n5(15);	
	TreeNode n20(20);
	TreeNode n3(3);
	TreeNode n8(8);
	TreeNode n15(15);
	TreeNode n25(25);

	n10.left = &n5;
	n10.right = &n20;
	n5.left = &n3;
	n5.right = &n8;
	n20.left = &n15;
	n20.right = &n25;

	cout << IsBinarySearchTree(&n10) << endl;
}


bool isInterleave(string s1, string s2, string s3) 
{ 
    if (s1.length() + s2.length() != s3.length())
        return false;
        
    return isInterleaveDFS(s1, s2, s3, 0, 0, 0);
}
    
bool isInterleaveDFS(string &s1, string &s2, string &s3, int p1, int p2, int p3)
{
    if (p3 == s3.length())
    {
        return true;
    }
    if (p1 < s1.length() && s1[p1] == s3[p3])
    {
        if (isInterleaveDFS(s1, s2, s3, p1 + 1, p2, p3 + 1))
        {
            return true;
        }
    }
    if (p2 < s2.length() && s2[p2] == s3[p3])
    {
        if (isInterleaveDFS(s1, s2, s3, p1, p2 + 1, p3 + 1))
        {
            return true;
        }
    }
    return false;
}

bool isInterleave2(string s1, string s2, string s3)
{
	int len1 = s1.length();
	int len2 = s2.length();
	int len3 = s3.length();
	if (len1 + len2 != len3)
		return false;
	bool f[256][256];
	memset(f, 0, sizeof(bool) * 256 * 256);
	if (s1[0] == s3[0])
	{
		f[1][0] = true;
	}
	else
	{
		f[1][0] = false;
	}
	for (int i = 2; i <= len1; ++i)
	{
		if (f[i-1][0] && (s1[i-1] == s3[i-1]))
		{
			f[i][0] = true;
		}
		else
		{
			f[i][0] = false;
		}
	}
	if (s2[0] == s3[0])
	{
		f[0][1] = true;
	}
	else
	{
		f[0][1] = false;
	}
	for (int i = 2; i <= len2; ++i)
	{
		if (f[0][i-1] && (s2[i-1] == s3[i-1]))
		{
			f[0][i] = true;
		}
		else
		{
			f[0][i] = false;
		}
	}
	for (int i = 1; i <= len1; ++i)
	{
		for (int j = 1; j <= len2; ++j)
		{
			f[i][j] = false;
			if (f[i-1][j] == true && s1[i-1] == s3[i+j-1])
			{
				f[i][j] = true;
			}
			if (f[i][j-1] == true && s2[j-1] == s3[i+j-1])
			{
				f[i][j] = true;
			}
		}
	}
	return f[len1][len2];
}

void TestIsInterleave()
{
	/*string s1 = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa";
	string s2 = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab";

	string s3 = "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";

	cout << isInterleave(s1, s2, s3) << endl;
}*/
	/*string s1 = "aabcc";
	string s2 = "dbbca";
	string s3 = "aadbbcbcac";
	string s4 = "aadddbaccc";
	cout << isInterleave2(s1, s2, s3) << endl;
	cout << isInterleave2(s1, s2, s4) << endl;*/

	//cout << C(6, 3) << endl;
	vector<TreeNode *> ans = generateTrees(3);

}


int C(int n, int m)
{
    int ans = 1;
    int div = 2;
    for (int i = 0; i < m; ++i)
    {
        ans *= (n - i);
        while (div <= m)
        {
            if (ans % div == 0)
            {
                ans /= div;
                div++;
            }
            else
            {
                break;
            }
        }
    }
    return ans;
}

vector<TreeNode *> generateTrees(int n)
{
	vector<TreeNode *> ans;
	if (n == 0)
	{
		return ans;
	}
	vector<TreeNode *> vec;
	for (int i = 1; i <= n; ++i)
	{
		TreeNode *pNode = new TreeNode(i);
		vec.push_back(pNode);
		if (i != 1)
		{
			generateTreesHelp(ans, vec, 1, i - 1, n, pNode->left);
		}
		if (i != n)
		{
			generateTreesHelp(ans, vec, i + 1, n, n, pNode->right);
		}
		vec.erase(vec.end() - 1);
	}
	
	return ans;
}

void generateTreesHelp(vector<TreeNode *> &ans, vector<TreeNode *> &vec, int left, 
	int right, int N, TreeNode *&root)
{
	if (left == right)
	{
		root = new TreeNode(left);
		vec.push_back(root);
	}
	if (vec.size() == N)
	{
		ans.push_back(vec[0]);
		return;
	}
	for (int i = left; i <= right; ++i)
	{
		TreeNode *pNode = new TreeNode(i);
		vec.push_back(pNode);
		if (left <= i - 1)
		{
			generateTreesHelp(ans, vec, left, i - 1, N, pNode->left);
		}
		if (i + 1 <= right)
		{
			generateTreesHelp(ans, vec, i + 1, right, N, pNode->right);
		}
		vec.erase(vec.end() - 1);
	}
}

vector<string> restoreIpAddresses(string s)
{
	vector<string> ans;
	if (s == "" || s.length() > 12)
	{
		return ans;
	}
	string vS[4];
	RestoreIPDFS(ans, vS, 0, s, 0);
	return ans;
}

void RestoreIPDFS(vector<string> &ans, string vS[], int count, string &s, int step)
{
	if (count == 4)
	{
		if (step == s.length())
		{
			string str = vS[0];
			for (int i = 1; i < 4; ++i)
			{
				str += '.';
				str += vS[i];
			}
			ans.push_back(str);
		}
		return;
	}
	// 如果当前s中剩余的长度为[4-count, 3*(4-count)]则可以
	int remain = s.length() - step;
	if ((remain >= (4 - count)) && (remain <= (12 - 3 * count)))
	{// 此次解析i个字符
		for (int i = 1; i <= min(3, remain); ++i)
		{
			string tmp = s.substr(step, i);
			// 如果长度不为0，则第一个不能为0
			if (i > 1 && tmp[0] == '0')
			{
				continue;
			}
			if (atoi(tmp.c_str()) <= 255)
			{
				vS[count] = tmp;
				RestoreIPDFS(ans, vS, count + 1, s, step + i);
			}
		}
	}
}

void TestRestoreIpAddresses()
{
	//string s = "0000";
	//vector<string> ans = restoreIpAddresses(s);

	string s;	
	vector<string> ans;

	//s = "1111";
	//ans = restoreIpAddresses(s);

	//s = "010010";
	//ans = restoreIpAddresses(s);

	s = "101023";
	ans = restoreIpAddresses(s);

	s = "172162541";
	ans = restoreIpAddresses(s);

	s = "19216811";
	ans = restoreIpAddresses(s);

	s = "25525511135";
	ans = restoreIpAddresses(s);

	s = "255255255255";
	ans = restoreIpAddresses(s);

	s = "00003";
	ans = restoreIpAddresses(s);

	s = "000256";
	ans = restoreIpAddresses(s);

	s = "9999999";
	ans = restoreIpAddresses(s);

	s = "1231231231234";
	ans = restoreIpAddresses(s);
	
}