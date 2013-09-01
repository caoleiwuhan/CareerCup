#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <ctype.h>
#include <vector>

#include "18_1_Hard.h"

using namespace std;

/*
write a function that add two number, can not use + operation
*/
int AddNumber(int a, int b)
{
	int c = a & b;
	int d = a ^ b;
	while (c)
	{
		c <<= 1;
		a = c;
		b = d;
		c = a & b;
		d = a ^ b;
	}
	return d;
}

void TestAddNumber()
{
	//cout << AddNumber(11, 7) << endl;
	//cout << AddNumber(4, 8) << endl;
	//cout << AddNumber(1, 5) << endl;
	for (int i = 0; i < 16; ++i)
	{
		for (int j = 0; j < 16; ++j)
		{
			cout << i << " + " << j << " = " << AddNumber(i, j) << endl;
		}
	}
}

void ShuffleCard(int card[], int n)
{
	srand(time(NULL));
	// 初始化
	for (int i = 0; i < n; ++i)
	{
		card[i] = i;
	}
	for (int i = 0; i < n - 1; ++i)
	{
		int remain = n - 1 - i;
		// 从[i+1,n-1]中随机选一个位置
		int index = (rand() % (n - 1 - i)) + (i + 1);
		//swap<int>(card[i], card[index]);
		int num = card[i];
		card[i] = card[index];
		card[index] = num;
	}
}

void TestShuffleCard()
{
	int card[CARD_NUM];
	ShuffleCard(card, CARD_NUM);	
	for (int i = 0; i < CARD_NUM; ++i)
	{
		cout << card[i] << " ";
		if ((i + 1) % 10 == 0)
		{
			cout << endl;
		}
	}
	cout << endl;
}

//void ChooseNumberRandomly(int arr[], int n, int ans[], int m)
//{
//	int ch;
//	if (isalpha(ch))
//	{
//	}
//}
//

bool isPalindrome(string s) 
{
	if (s == "")
		return true;
	int len = s.length();
	int size = len >> 1;
	int left = 0;
	int right = len - 1;
	while (left < right)
	{
		while ((left <= right) && !isalnum(s[left]))
		{
			++left;
		}
		while ((right >= left) && !isalnum(s[right]))
		{
			--right;
		}
		if (left >= right)
			break;

		if (isdigit(s[left]) && isdigit(s[right]))
		{
			if (s[left] != s[right])
				return false;
			else
			{
				++left;
				--right;
			}
		}
		else if (isalpha(s[left]) && isalpha(s[right]))
		{
			if (tolower(s[left]) == tolower(s[right]))
			{
				++left;
				--right;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	return true;
}

void TestIsPalindrome()
{
	string str = ".,";
	cout << isPalindrome(str) << endl;
}



void connect(TreeLinkNode *root) 
{
	if (root == NULL)
		return;
	if (root->left != NULL)
	{
		if (root->right != NULL)
		{
			root->left->next = root->right;
		}
		else 
		{
			TreeLinkNode *p = root->next;
			while((p != NULL) && (p->left == NULL) && (p->right == NULL))
			{
				p = p->next;
			}
			if (p != NULL)
			{            

				if (p->left != NULL)
				{
					root->left->next = p->left;
				}
				else if (p->right != NULL)
				{
					root->left->next = p->right;
				}
			}
		}
	}
	if (root->right != NULL)
	{
		TreeLinkNode *p = root->next;
		while((p != NULL) && (p->left == NULL) && (p->right == NULL))
		{
			p = p->next;
		}
		if (p != NULL)
		{            

			if (p->left != NULL)
			{
				root->right->next = p->left;
			}
			else if (p->right != NULL)
			{
				root->right->next = p->right;
			}
		}
	}
	connect(root->right);
	connect(root->left);    
}

void TestConnect()
{
	TreeLinkNode n2(2);
	TreeLinkNode n1(1);
	TreeLinkNode n3(3);
	TreeLinkNode n0(0);
	TreeLinkNode n7(7);
	TreeLinkNode n9(9);
	TreeLinkNode n11(1);
	TreeLinkNode n22(2);
	TreeLinkNode n12(1);
	TreeLinkNode n01(0);
	TreeLinkNode n8(8);
	TreeLinkNode n81(8);
	TreeLinkNode n72(7);

	n2.left = &n1;
	n2.right = &n3;

	n1.left = &n0;
	n1.right = &n7;

	n3.left = &n9;
	n3.right = &n11;

	n0.left = &n22;
	n7.left = &n12;
	n7.right = &n01;

	n11.left = &n8;
	n11.right = &n81;

	n01.left = &n72;

	connect(&n2);
}

void TesIsBinarySearchTree2()
{
	TreeNode n3(3);
	TreeNode n1(1);
	TreeNode n5(5);
	TreeNode n0(0);
	TreeNode n2(2);
	TreeNode n4(4);
	TreeNode n6(6);
	TreeNode n31(3);

	n3.left = &n1;
	n3.right = &n5;
	n1.left = &n0;
	n1.right = &n2;
	n5.left = &n4;
	n5.right = &n6;
	n4.right = &n31;

	cout << IsBinarySearchTree2(&n3) << endl;
}

bool IsBinarySearchTree2(TreeNode *root)
{
	int minNum = 0x80000000;
	int maxNum = 0x7FFFFFFF;
	return IsBinarySearchTreeHelp(root, minNum, maxNum);	
}

bool IsBinarySearchTreeHelp(TreeNode *root, int minNum, int maxNum)
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
		if (!IsBinarySearchTreeHelp(root->left, leftMin, leftMax))
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
		if (!IsBinarySearchTreeHelp(root->right, rightMin, rightMax))
			return false;
	}
	return true;
}


ListNode *ReverseList(ListNode * &from, ListNode * &to)
{
	ListNode *ans = from;
	ListNode *next = ans->next;        
	while (next != to)
	{
		ListNode *tmp = next->next;
		next->next = ans;
		ans = next;
		next = tmp;
	}
	next->next = ans;
	ans = next;

	return ans;
}
ListNode *reverseBetween(ListNode *head, int m, int n) 
{
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (head == NULL)
		return NULL;
	if (m == n)
	{
		return head;
	}

	ListNode *pParent1 = NULL;
	ListNode *p1 = head;
	m--;
	while (m--)
	{
		pParent1 = p1;
		p1 = p1->next;
	}
	n--;        
	ListNode *p2 = head;
	ListNode *pNext = p2->next;
	while (n--)
	{            
		p2 = p2->next;
		pNext = p2->next;
	}
	ListNode * pRev = ReverseList(p1, p2);
	if (pParent1 == NULL)
	{
		head = pRev;
	}
	else
	{
		pParent1->next = pRev;
	}    
	p1->next = pNext;

	return head;
}

void TestReverseBetween()
{
	//ListNode n1(1);
	//ListNode n2(2);
	//ListNode n3(3);
	//ListNode n4(4);
	//ListNode n5(5);

	//n1.next = &n2;
	//n2.next = &n3;
	//n3.next = &n4;
	//n4.next = &n5;
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	n1.next = &n2;
	n2.next = &n3;
	ListNode *ans;
	//ans = reverseBetween(&n1, 2, 2);
	//ans = reverseBetween(&n1, 1, 2);
	//ans = reverseBetween(&n1, 2, 3);
	ans = reverseBetween(&n1, 1, 3);

}

void subsetsWithoutDup(vector<vector<int> > &ans, vector<int> &s)
{
	vector<int> empty;
	ans.push_back(empty);
	int size = s.size();
	if (size == 0)
	{
		return;
	}
	for (int i = 0; i < size; ++i)
	{
		int num = s[i];
		int len = ans.size();
		for (int j = 0; j < len; ++j)
		{
			vector<int> tmp = ans[j];
			tmp.push_back(num);
			ans.push_back(tmp);
		}
	}
}

vector<vector<int> > subsetsWithDup(vector<int> &s) 
{
	vector<vector<int> > ans;
	if (s.size() == NULL)
	{
		return ans;
	}
	sort(s.begin(), s.end());
	int size = s.size();
	vector<int> dup;
	int last = s[0];
	int count = 1;
	int i = 1;
	for (; i < size; ++i)
	{
		if (s[i] == last)
		{
			++count;
			--size;
			--i;
			s.erase(s.begin() + i);                
		}
		else
		{
			if (count > 1)
			{
				dup.push_back(last);
				dup.push_back(count);
				--i;
				s.erase(s.begin() + i);
				--size;
			}
			last = s[i];
			count = 1;
		}
	}
	if (count > 1)
	{
		dup.push_back(last);
		dup.push_back(count);
		--i;
		s.erase(s.begin() + i);
		--size;
	}
	subsetsWithoutDup(ans, s);
	int num = 0;
	int total = dup.size();
	while (num < total)
	{
		int size = ans.size();
		int nNum = dup[num];
		int nCount = dup[num + 1];
		num += 2;
		for (int i = 0; i < nCount; ++i)
		{
			int start = ans.size() - size;
			int end = ans.size();
			for (int j = start; j < end; ++j)
			{
				vector<int> tmp = ans[j];
				tmp.push_back(nNum);
				ans.push_back(tmp);
			}
		}
	}
	int ansNum = ans.size();
	for (int i = 0; i < ansNum; ++i)
	{
		sort(ans[i].begin(), ans[i].end());
	}
	return ans;
}

void TestSubsetsWithDup()
{
	vector<int> s;
	s.push_back(1);
	s.push_back(1);
	s.push_back(2);
	s.push_back(2);
	//s.push_back(3);
	//s.push_back(3);
	//s.push_back(3);
	//s.push_back(4);
	//s.push_back(3);
	//s.push_back(4);
	//s.push_back(5);
	//s.push_back(5);

	vector<vector<int> > ans = subsetsWithDup(s);
	//vector<vector<int> > ans;
	//vector<int> s2;
	//s2.push_back(1);
	//s2.push_back(2);
	//s2.push_back(3);
	//subsetsWithoutDup(ans, s2);
}

int DFS(string &s, int step, int len)
{
	if (step == len)
	{
		return 1;
	}
	int count = 0;
	if (s[step] != '0')
	{           
		// 解析一个，只有下一个不为0才可以
		if (!(step + 1 < len && s[step + 1] == '0'))
		{

			count += DFS(s, step + 1, len);    
		}        
		// 解析两个，只有s[step] <= 2 
		if (step + 1 < len && s[step - 1] > '0')
		{
			string tmp = s.substr(step - 1, 2);
			if (atoi(tmp.c_str()) <= 26)
				count += DFS(s, step + 2, len);
		}
	}
	return count;
}
int numDecodings(string s) 
{
	if (s == "")
		return 0;

	int len = s.length();
	return DFS(s, 0, len);
}

int numDecodings2(string s)
{
	if (s == "")
		return 0;
	int size = s.length();
	int ans = 0;
	int *f = new int[size + 2];
	f[0] = 1;
	f[1] = 1;

	for (int i = 0; i < size; ++i)
	{
		f[i+2] = 0;
		if (s[i] == '0')
		{
			if (i == 0 || s[i-1] == '0' || s[i-1] > '2')
			{
				return 0;
			}
			else
			{
				f[i+2] += f[i];
			}
		}
		else
		{
			// 一个
			f[i+2] += f[i+1];

			// 两个			
			if (i > 0 && s[i-1] > '0')
			{
				string tmp = s.substr(i-1, 2);
				if (atoi(tmp.c_str()) <= 26)
				{
					f[i+2] += f[i];				
				}
			}
		}            
	}
	ans = f[size + 1];        
	delete []f;
	return ans;
}

void TestNumDecoding()
{
	//cout << numDecodings("0") << endl;
	//cout << numDecodings("00") << endl;
	//cout << numDecodings("102") << endl;
	//cout << numDecodings("1026") << endl;
	//string str = "7541387519572282368613553811323167125532172369624572591562685959575371877973171856836975137559677665";

	cout << numDecodings2("19963") << endl;

}

string SwapString(string s)
{
	int size = s.length();
	int left = 0;
	int right = size - 1;
	while (left < right)
	{
		char ch = s[left];
		s[left] = s[right];
		s[right] = ch;
		++left;
		--right;
	}
	return s;
}

bool isScramble(string s1, string s2)
{
	if (s1 == "" && s2 == "")
	{
		return true;
	}
	int size = s1.length();
	if (size == 1)
	{
		if (s1.compare(s2) == 0)
		{
			return true;
		}
		else 
			return false;
	}
	for (int i = 1; i < size; ++i)
	{
		string a1 = s1.substr(0, i);
		string b1 = s1.substr(i);
		// case 1
		string nStr = s1;
		if (nStr.compare(s2) == 0)
		{
			return true;
		}
		nStr = b1 + a1;
		if (nStr.compare(s2) == 0)
		{
			return true;
		}
		string swapA = SwapString(a1);
		string swapB = SwapString(b1);
		// case 2
		nStr = swapA + b1;
		if (nStr.compare(s2) == 0)
		{
			return true;
		}
		nStr = b1 + swapA;
		if (nStr.compare(s2) == 0)
		{
			return true;
		}
		// case 3
		nStr = a1 + swapB;
		if (nStr.compare(s2) == 0)
		{
			return true;
		}
		nStr = swapB + a1;
		if (nStr.compare(s2) == 0)
		{
			return true;
		}
		// case 4
		nStr = swapA + swapB;
		if (nStr.compare(s2) == 0)
		{
			return true;
		}
		nStr = swapB + swapA;
		if (nStr.compare(s2) == 0)
		{
			return true;
		}
	}
	return false;
}

vector<int> grayCode(int n) 
{
	vector<int> ans;
	if (n == 0)
		return ans;

	int size = 1;
	for (int i = 0; i < n; ++i)
	{
		size *= 2;
	}

	//bool *f = new bool[size];
	//memset(f, 0, sizeof(int) * size);
	vector<bool> f;
	f.resize(size);	
	ans.resize(size);
	ans[0] = 0;
	f[0] = true;
	DFS(ans, size, 1, f, 0, n);               
	//delete[] f;    
	return ans;
}

bool DFS(vector<int> &ans, int total, int step, vector<bool> &f, int num, int N)
{
	if (step == total)
	{
		return true;    
	}
	for (int i = 0; i < N; ++i)
	{
		int tmp = (num ^ (1 << i));
		if (!f[tmp])
		{
			f[tmp] = true;
			ans[step] = tmp;
			if (DFS(ans, total, step + 1, f, tmp, N))
			{
				return true;
			}
			f[tmp] = false;
		}
	}
	return false;  
}

void TestGrayCode()
{
	vector<int> ans;
	ans = grayCode(4);
	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << endl;
	}
	//ans.reserve(10);
	//ans.resize(10);
	//ans[0] = 1;
	//ans[1] = 1;
	//ans[1] = 1;

}

void TestIsScramble()
{
	string s1;
	string s2;
	s1 = "aa";
	s2 = "aa";
	cout << isScramble(s1, s2) << endl;
}

void SwapInt(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void sortColors(int arr[], int n)
{
	if (arr == NULL || n <= 0)
	{
		return;
	}
	int p0 = 0;
	int p1 = 0;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] == 0)
		{
			if (i != p0)
			{
				SwapInt(arr[p0], arr[i]);
				++p0;
				if (p1 < p0)
				{
					p1 = p0;
				}
				i--;
			}
			else
			{
				++p0;
				if (p1 < p0)
				{
					p1 = p0;
				}
			}
		}
		else if(arr[i] == 1)
		{
			if (i != p1)
			{
				SwapInt(arr[p1], arr[i]);
				++p1;
				--i;
			}
			else
			{
				++p1;
			}
		}
	}
}

void sortColors2(int arr[], int n)
{
	if (arr == NULL || n <= 0)
		return;
	int p0 = 0;
	int p1 = 0;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] == 0)
		{
			if (p0 != i)
			{
				SwapInt(arr[i], arr[p0]);                    
			}
			++p0;
			if (p0 > p1)
			{
				p1 = p0;
			}
		}
		if (arr[i] == 1)
		{
			if (p1 != i)
			{
				SwapInt(arr[i], arr[p1]);                    
			}
			++p1;
		}
	}
}

void TestSortColor()
{
	int arr[] = {2, 1, 2, 1, 0};
	sortColors2(arr, sizeof(arr) / sizeof(int));
}

int minDistance(string s1, string s2)
{
	int len1 = s1.length();
	int len2 = s2.length();
	if (len1 == 0)
		return len2;
	if (len2 == 0)
		return len1;

	int **f = new int *[len1 + 1];
	for (int i = 0; i <= len1; ++i)
	{
		f[i] = new int[len2 + 1];
	}
	// 初始化 
	for (int i = 0; i <= len1; ++i)
	{
		f[i][0] = i;
	}
	for (int j = 0; j <= len2; ++j)
	{
		f[0][j] = j;
	}

	for (int i = 1; i <= len1; ++i)
	{
		for (int j = 1; j <= len2; ++j)
		{
			if (s1[i-1] == s2[j-1])
			{
				f[i][j] = f[i-1][j-1];
			}
			else
			{
				int tmp = f[i-1][j-1];
				tmp = min(f[i-1][j], tmp);
				tmp = min(f[i][j-1], tmp);
				f[i][j] = tmp + 1;
			}            
		}
	}
	int ans = f[len1][len2];
	for (int i = 0; i <= len1; ++i)
	{
		delete []f[i];
	}
	delete []f;
	return ans;
}

void TestMinDistance()
{
	string s1 = "a";
	string s2 = "ab";
	cout << minDistance2(s1, s2) << endl;
}

int minDistance2(string s1, string s2) 
{
	int len1 = s1.length();
	int len2 = s2.length();

	if (len1 == 0)
		return len2;
	if (len2 == 0)
		return len1;

	int **f = new int*[2];
	f[0] = new int[len2 + 1];
	f[1] = new int[len2 + 1];
	for (int i = 0; i <= len1; ++i)
	{
		f[0][i] = i;		
	}
	for (int i = 0; i <= len2; ++i)
	{
		f[1][i] = i;		
	}

	int flag = 0;
	for (int i = 1; i <= len1; ++i)
	{
		f[flag][0] = i;
		for (int j = 1; j <= len2; ++j)
		{
			f[1-flag][0] = j;
			if (s1[i-1] == s2[j-1])
			{
				/*if (j == 1)
				{
				f[1-flag][j] = i - 1;
				}
				else*/
				{
					f[1-flag][j] = f[flag][j-1];
				}				
			}
			else
			{
				/*if (i == 1)
				{
				f[1-flag][j] = j;
				}
				else*/
				{
					int tmp = f[flag][j-1];				
					tmp = min(tmp, f[1-flag][j-1]);
					tmp = min(tmp, f[flag][j]);
					f[1-flag][j] = tmp + 1;
				}
			}
		}
		flag = 1 - flag;
	}
	int ans = f[flag][len2];
	//delete []f[0];
	//delete []f[1];
	//delete []f;
	return ans;
}

string simplifyPath(string path) 
{
	if (path == "")
		return "";
	vector<string> vec;
	// 假设最大为100级
	vec.resize(100);
	vec[0] = "/";
	// 假设都是从'/'开始的
	int len = path.length();
	if (len == 1 && path[0] == '/')
		return "/";
	int pos = 1;
	int last = 0;
	if (path[len - 1] != '/')
	{
		path += '/';
		++len;
	}
	for (; pos < len; ++pos)
	{
		int index = path.find("/", pos);
		string subStr = path.substr(pos, index - pos);
		pos = index;
		if (subStr == "")
			continue;

		if (subStr == ".")
		{
		}
		else if (subStr == "..")
		{
			--last;
			if (last < 0)
			{
				last = 0;
			}
		}
		else
		{
			string str = vec[last];
			if (last != 0)
			{
				str += '/';
			}
			str += subStr;
			vec[++last] = str;			
		}
	}

	return vec[last];
}

void TestSimplifyPath()
{
	string path = "/a/./b///../c/../././../d/..//../e/./f/./g/././//.//h///././/..///";
	cout << simplifyPath(path) << endl;
}

int IntSqrt(int x)
{
	int i = 0;
	int j = x;
	while (i + 1 < j)
	{
		int mid = i + ((j - i) >> 1);		
		if (mid > (x / mid))
		{
			j = mid;
			continue;
		}
		int tmp = mid * mid;
		if (tmp == x)
			return mid;
		else if (tmp < x)
			i = mid;
		else
			j = mid;
	}	
	if (x / j == j)
		return j;
	return i;      
}

void TestIntSqrt()
{
	int num = 2147483647;
	cout << IntSqrt(num) << endl;
}

vector<int> plusOne(vector<int> &arr) 
{
	vector<int> ans;
	int size = arr.size();
	if (size == 0)
		return ans;
	ans.resize(size);
	int carry = 1;
	int i = size - 1;
	while (i >= 0)
	{
		int tmp = arr[i] + carry;
		carry = tmp / 10;
		tmp %= 10;		
		ans[i] = tmp;            
		//ans.push_back(tmp);
		--i;
	}
	if (carry == 1)
	{
		ans.insert(ans.begin(), 1);
	}
	return ans;
}

void TestPlusOne()
{
	vector<int> vec;
	vec.push_back(99);
	vector<int> ans = plusOne(vec);
}

string addBinary(string a, string b) 
{
	if (a == "")
		return b;
	if (b == "")
		return a;
        
	int len1 = a.length();
	int len2 = b.length();
	int len3 = max(len1, len2);
	string ans(len3, '0');
	int carry = 0;
	int i = len1 - 1;
	int j = len2 - 1;
	while ((i >= 0) || (j >= 0))
	{
		char ca = '0';
		if (i >= 0)
		{
			ca = a[i--];
		}
		char cb = '0';
		if (j >= 0)
		{
			cb = b[j--];
		}
		int tmp = (ca - '0') + (cb - '0') + carry;
		carry = tmp / 2;
		tmp = tmp % 2;
		ans[--len3] = tmp + '0';
	}
	if (carry == 1)
	{
		ans.insert(0, 1, '1');
	}
	return ans;
}

void TestAddBinary()
{
	/*string a = "1";
	string b = "1";
	cout << addBinary(a, b) << endl;*/
	//cout << uniquePaths(1, 2) << endl;
	/*vector<vector<int> > vec;
	vector<int> v;
	v.push_back(1);
	v.push_back(0);
	vec.push_back(v);
	cout << uniquePathsWithObstacles(vec) << endl;*/
	cout << getPermutation(9, 296662) << endl;

}

 int uniquePaths(int m, int n) 
 {
    int f[101][101];
    for (int i = 0; i < 101; ++i)
    {
        for (int j = 0;j < 101; ++j)
        {
            f[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {			
            f[i][j] = max(1, f[i-1][j] + f[i][j-1]);            
        }
    }   
    return f[m][n];
}

int uniquePathsWithObstacles(vector<vector<int> > &vec) 
 {
    int f[101][101];
    for (int i = 0; i < 101; ++i)
    {
        for (int j = 0;j < 101; ++j)
        {
            f[i][j] = 0;
        }
    }
    int m = vec.size();
    int n = vec[0].size();
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (vec[i-1][j-1] == 0)
            {
                f[i][j] = f[i-1][j] + f[i][j-1];
				if (i == 1 && j == 1)
				{
					f[i][j] = 1;
				}
            }
            else
            {
                f[i][j] = 0;
            }
        }
    }   
    return f[m][n];
}

void DFS(vector<string> &vec, string &s, int len, int step, int k, int index)
{
    if (step == len)
    {
		vec.push_back(s);                
    }
    for (int i = index; i < len; ++i)
    {
        char tmp = s[step];
        s[step] = s[i];
        s[i] = tmp;
        DFS(vec, s, len, step + 1, k, step + 1);        
        tmp = s[step];
        s[step] = s[i];
        s[i] = tmp;
    }	
}
string getPermutation(int n, int k) 
{
    string s;
    for (int i = 1; i <= n; ++i)
    {
        s += i + '0';
    }
	vector<string> vec;
    int num = 0;
    DFS(vec, s, n, 0, k, 0);
	sort(vec.begin(), vec.end());
    return vec[k-1];
}


vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) 
{
	vector<Interval> vec;
	int findFirst = FindFirstOfEndBegin(intervals, newInterval);
	if (findFirst != -1)
	{
		Interval int1 = intervals[findFirst];
		if (int1.end == newInterval.start)
		{			
			vec.push_back(Interval(int1.start, newInterval.end));
		}
		else if (int1.start < newInterval.end && int1.end > newInterval.end)
		{
			vec.push_back(int1);	
		}
		else if (int1.start == newInterval.start)
		{
		}		
		else if (int1.start < newInterval.start)
		{
			vec.push_back(Interval(newInterval.start, int1.end));
		}		
	}
	int findLast = FindLastOfStartEnd(intervals, newInterval);
	if (findLast == -1)
	{
		intervals.insert(intervals.end(), newInterval);
		return intervals;
	}

	// 删除
}

int FindFirstOfEndBegin(vector<Interval> &intervals, Interval newInterval)
{
	int i = 0;
	int j = intervals.size();
	int start = newInterval.start;
	while (i + 1 < j)
	{
		int mid = i + (j - i) / 2;
		int end = intervals[mid].end;
		if (end > start)
		{
			j = mid;
		}
		else if (end == start)
		{
			return mid;
		}
		else
		{
			i = mid;
		}
	}
	if (intervals[j].end >= start)
	{
		return j;
	}
	if (intervals[i].end >= start)
	{
		return i;
	}
	return -1;
}

int FindLastOfStartEnd(vector<Interval> &intervals, Interval newInterval)
{
	int i = 0;
	int j = intervals.size();
	int end = newInterval.end;
	while (i + 1 < j)
	{
		int mid = i + (j - i) / 2;
		int start = intervals[mid].start;
		if (start < end)
		{
			i = mid;
		}
		else if (end == start)
		{
			return mid;
		}
		else
		{
			j = mid;
		}
	}
	if (intervals[i].start >= end)
	{
		return i;
	}
	if (intervals[j].start >= end)
	{
		return j;
	}
	return -1;
}

bool canJump(int arr[], int n) 
{
	int f[101][101];
	for (int i = 0; i < 101; ++i)
	{
		f[i][i] = true;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int k = 1; k < n; ++k)
		{
			int j = i + k;
			f[i][j] = false;
			for (int t = i; t <= j; ++t)
			{
				if (t == i)
				{
					if ((j - t) <= arr[t])
					{
						f[i][j] = true;
						break;
					}
				}
				if (t == j)
				{
					if ((t - i) <= arr[i])
					{
						f[i][j] = true;
						break;
					}
				}
				if (f[i][t] && f[t][j] && ((t - i) <= arr[i]) &&
					((j - t) <= arr[t]))
				{
					f[i][j] = true;
					break;
				}
			}
		}
	}
	return f[0][n-1];
}

bool canJump2(int arr[], int n) 
{
	bool f[2001][2001];
	for (int i = 0; i < 2001; ++i)
	{
		f[i][i] = true;
	}
	for (int k = 1; k < n; ++k)
	{
		for (int i = 0; i < (n - k); ++i)
		{
			int j = i + k;
			f[i][j] = false;
			for (int t = i; t <= j; ++t)
			{
				if (t == i)
				{
					if ((j - t) <= arr[t])
					{
						f[i][j] = true;
						break;
					}
				}
				else if (t == j)
				{
					if ((t - i) <= arr[i])
					{
						f[i][j] = true;
						break;
					}
				}
				else if (f[i][t] && f[t][j])
				{
					f[i][j] = true;
					break;
				}
			}
		}
	}	
	return f[0][n-1];
}

bool canJump3(int arr[], int n) 
{
	bool *f = new bool[n];
	memset(f, 0, sizeof(bool) * n);
	f[0] = true;
	for (int i = 1; i < n; ++i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			if (f[j] && (i - j <= arr[j]))
			{
				f[i] = true;
				break;
			}
		}
	}
	return f[n-1];
}


void rotate(vector<vector<int> > &matrix) 
{
	int row = matrix.size();	
	int count = row / 2;
	for (int i = 0; i <= count; ++i)
	{
		// start = i;
		int num = row - 1 - i * 2;
		for (int j = 0; j < num; ++j)
		{
			int tmp = matrix[i][i + j];
			matrix[i][i + j] = matrix[row - 1 - i - j][i];
			matrix[row - 1 - i - j][i] = matrix[row - 1 - i][row - 1 - i - j];
			matrix[row - 1 - i][row - 1 - i - j] = matrix[i + j][row - 1 - i];
			matrix[i + j][row - 1 - i] = tmp;
		}
	}
}

void DFS(vector<vector<int> > &ans, vector<int> &vec, int n, int step)
{
	if (step == n)
    {
        ans.push_back(vec);
    }
    else
    {
        for (int i = step; i < n; ++i)
        {            
			swap(vec[step], vec[i]);
            DFS(ans, vec, n, step + 1);
            swap(vec[step], vec[i]);
        }
    }
}
vector<vector<int> > permute(vector<int> &num) 
{
    vector<vector<int> > ans;
    int size = num.size();
    DFS(ans, num, size, 0);
    return ans;
}

void TestPermute()
{
	vector<int> num;
	num.push_back(1);
	permute(num);
}

int jump(int arr[], int n) 
{
    int *f = new int[n];
    memset(f, 0, sizeof(int) * n);
    for (int i = 1; i < n; ++i)
    {
        int tmp = 0x7FFFFFFF;
		if (arr[0] >= i)
		{
			f[i] = 1;
			continue;
		}
        for (int j = 1; j < i; ++j)
        {
            if (f[j] != 0 && (i - j) <= arr[j])
            {
                f[i] = f[j] + 1;
				break;
            }
        }       
    }
    int ans = f[n - 1];
    delete []f;
    return ans;
}

void TestJump()
{
	int arr[] = 
	{
		1,2,3,4
	};
	cout << jump(arr, sizeof(arr) / sizeof(int));
}



void TestCanJump()
{
	int arr[] = 
	{
		1, 2, 3, 4
	};
	cout << jump(arr, sizeof(arr) / sizeof(int));
}

// DFS超时
bool MatchDFS(const char *s, const char *p)
{
	if (!(*s) && !(*p))
	{
		return true;
	}
	if (*s && !(*p))
	{
		return false;
	}
	if (!(*s) && *p)
	{
		while (*p)
		{
			if (*p != '*')
				return false;
			++p;
		}
		return true;
	}
	char ch1 = *s;
	char ch2 = *p;
	if (ch1 == ch2 || ch2 == '?')
	{ // 疑问：如果ch1也为*，ch2也为*呢？
		return MatchDFS(s + 1, p + 1);
	}
	if (ch2 == '*')
	{
		int i = 0;
		while (*(s + i))
		{// 匹配i个
			if (MatchDFS(s + i, p + 1))
			{
				return true;
			}
			++i;
		}
		// 全部匹配
		if (MatchDFS(s + i, p + 1))
			return true;
	}
	return false;
}

bool isMatch(const char *s, const char *p) 
{
	return MatchDFS(s, p);
}

bool isMatch2(const char *s, const char *p)
{		
	int len1 = strlen(p);
	int len2 = strlen(s);
	if (len2 > 10000)
		return false;

	if (len1 == 0 && len2 == 0)
		return true;
	bool **f = new bool*[len1 + 1];
	for (int i = 0; i <= len1; ++i)
	{
		f[i] = new bool[len2 + 1];
		memset(f[i], 0, sizeof(bool) * (len2 + 1));
	}
	f[0][0] = true;
	// 初始化
	for (int i = 0; i < len1 && (*(p + i) == '*'); ++i)
	{
		f[i + 1][0] = true;
	}
	for (int i = 1; i <= len1; ++i)
	{
		for (int j = 1; j  <= len2; ++j)
		{
			char ch1 = p[i-1];
			char ch2 = s[j-1];
			if (ch1 == ch2 || ch1 == '?')
			{
				if (f[i-1][j-1])
				{
					f[i][j] = true;
				}
			}
			if (ch1 == '*')
			{
				for (int k = j; k >= 0; --k)
				{
					if (f[i-1][k])
					{
						f[i][j] = true;
						break;
					}
				}
			}
		}
	}
	bool ans = f[len1][len2];

	for (int i = 0; i <= len1; ++i)
	{
		delete[] f[i];
	}
	delete[] f;

	return ans;
}

// 滚动数组

bool isMatch3(const char *s, const char *p)
{		
	int len1 = strlen(p);
	int len2 = strlen(s);

	if (len1 == 0 && len2 == 0)
		return true;
	bool **f = new bool*[2];
	
	f[0] = new bool[len2 + 1];
	memset(f[0], 0, sizeof(bool) * (len2 + 1));
	
	f[1] = new bool[len2 + 1];
	memset(f[1], 0, sizeof(bool) * (len2 + 1));
	
//	f[0][0] = true;

	// 初始化
	for (int i = 0; i < len1 && (*(p + i) == '*'); ++i)
	{
		f[0][i] = true;
	}
	if (len2 == 0)
	{		
		for (int i = 0; i < len1; ++i)
		{
			if (p[i] != '*')
				return false;
		}
		return true;
	}	

	int flag = 0;
	for (int i = 1; i <= len1; ++i)
	{
		// 初始化
		f[flag][0] = true;
		for (int k = 0; k < (i - 1); ++k)
		{
			if (*(p + k) != '*')
			{
				f[flag][0] = false;
				break;
			}			
		}
		for (int j = 1; j  <= len2; ++j)
		{
			if (i == 1 && j == 1)
				f[flag][0] = true;

			char ch1 = p[i-1];
			char ch2 = s[j-1];
			if (ch1 == ch2 || ch1 == '?')
			{
				if (f[flag][j-1])
				{
					f[1-flag][j] = true;
				}
			}
			if (ch1 == '*')
			{
				for (int k = j; k >= 0; --k)
				{ 
					if (f[flag][k])
					{
						f[1-flag][j] = true;
						break;
					}
				}
			}
		}
		memset(f[flag], 0, sizeof(bool) * (len2 + 1));
		flag = 1 - flag;
	}
	bool ans = f[flag][len2];

	delete[] f[0];
	delete[] f[1];
	delete[] f;

	return ans;
}


void TestIsMatch()
{
	char s[] = "";
	char p[] = "*";

	cout << isMatch3(s, p) << endl;

}


void ChooseNumberRandomly(int arr[], int n, int ans[], int m)
{
	srand(time(NULL));
	int index = 0;
	int remain = n;
	for (int i = 0; i < n; ++i)
	{
		// 已经选择的个数
		if ((rand() % remain) < (m - index))
		{
			ans[index++] = arr[i];			
		}
		remain--;
	}
}

int CountNumberTwo(int num)
{
	return 0;
}


vector<Interval> merge(vector<Interval> &intervals)
{
	vector<Interval> ans;	
	int size = intervals.size();
	if (size == 0)
	{
		return ans;
	}
	//sort(intervals.begin(), intervals.end(), IntervalCompare);
	sort(intervals.begin(), intervals.end(), IntervalComp());
	for (int i = 0; i < size; ++i)
	{
		int tmp = ans.size();
		if (tmp == 0 || ans[tmp - 1].end < intervals[i].start)
		{
			ans.push_back(intervals[i]);
		}
		else
		{
			ans[tmp-1].end = max(ans[tmp-1].end, intervals[i].end);
		}
	}
	return ans;
}

bool IntervalCompare(const Interval & i1, const Interval & i2)
{
	if (i1.start < i2.start)
	{
		return true;
	}
	if (i1.start > i2.start)
	{
		return false;
	}
	if (i1.end < i2.start)
	{
		return true;
	}
	return false;
}


void TestMergeIntervals()
{

}