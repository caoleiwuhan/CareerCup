#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>

#include "2_1_DeleteDuplicateListNode.h"
#include "18_2_LeetCode.h"

using namespace std;

/*
	3Sum
	Given an array S of n integers, are there elements a, b, c in S such that 
	a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
*/
vector<vector<int> >threeSum(vector<int> &num)
{
	sort(num.begin(), num.end());
	int size = num.size();
	vector<vector<int> > ans;
	vector<int> vec;
	vec.resize(3);
	int last = 0x7FFFFFFF;
	for (int i = 0; i < size; ++i)
	{
		if (last == num[i])
		{
			continue;
		}
		last = num[i];
		vec[0] = num[i];
		int left = i + 1;
		int right = size - 1;
		while (left < right)
		{
			int sum = num[i] + num[left] + num[right];
			if (sum == 0)
			{
				vec[1] = num[left];
				vec[2] = num[right];
				ans.push_back(vec);
				int tmp = num[right];
				--right;
				while (right > left && num[right] == tmp)
				{
					--right;
				}
				tmp = num[left];
				++left;
				while (left < right && num[left] == tmp)
				{
					++left;
				}
			}
			else if (sum > 0)
			{
				int tmp = num[right];
				--right;
				while (right > left && num[right] == tmp)
				{
					--right;
				}
			}
			else
			{
				int tmp = num[left];
				++left;
				while (left < right && num[left] == tmp)
				{
					++left;
				}
			}
		}
	}
	return ans;
}

vector<vector<int> >threeSum2(vector<int> &num)
{
	sort(num.begin(), num.end());
	int size = num.size();
	vector<vector<int> > ans;
	vector<int> vec;
	vec.resize(3);
	int last = 0x7FFFFFFF;
	for (int i = 0; i < size; ++i)
	{
		if (last == num[i])
		{
			continue;
		}
		last = num[i];
		vec[0] = num[i];
		int left = i + 1;
		int right = size - 1;
		while (left < right)
		{
			int sum = num[i] + num[left] + num[right];
			if (sum == 0)
			{
				vec[1] = num[left];
				vec[2] = num[right];
				--right;								
				++left;
				int count = ans.size();
				if (count == 0 || 
					!(ans[count-1][0] == vec[0] && ans[count-1][1] == vec[1]))
				{
					ans.push_back(vec);				
				}				
			}
			else if (sum > 0)
			{
				--right;
			}
			else
			{				
				++left;			
			}
		}
	}
	return ans;
}

int threeSumClosest(vector<int> &num, int target)
{
	int size = num.size();
	if (size < 3)
	{
		int sum = 0;
		for (int i = 0; i < size; ++i)
		{
			sum += num[i];
		}
		return sum;
	}
	sort(num.begin(), num.end());	
	int best = num[0] + num[1] + num[2];
	int range = abs(best - target);
	for (int i = 0; i < size; ++i)
	{		
		int left = i + 1;
		int right = size - 1;
		while (left < right)
		{
			int sum = num[i] + num[left] + num[right];
			int tmp = abs(sum - target);
			if (sum == target)
			{
				return target;
			}
			else if (sum > target)
			{
				if (tmp < range)
				{
					best = sum;
					range = tmp;
				}
				--right;
			}
			else
			{
				if (tmp < range)
				{
					best = sum;
					range = tmp;
				}
				++left;
			}
		}
	}	
	return best;
}

vector<vector<int> > fourSum(vector<int> &num, int target)
{
	int size = num.size();
	vector<vector<int> > ans;
	if (size < 4)
	{
		return ans;
	}
	sort(num.begin(), num.end());
	vector<int> vec;
	vec.resize(4);
	int last = 0x7fffffff;
	for (int i = 0; i < size; ++i)
	{
		if (num[i] == last)
		{
			continue;
		}
		last = num[i];
		for (int j = i + 1; j < size; ++j)
		{
			vec[0] = num[i];
			vec[1] = num[j];
			int left = j + 1;
			int right = size - 1;
			while (left < right)
			{
				int sum = num[i] + num[j] + num[left] + num[right];
				if (sum == target)
				{
					vec[2] = num[left];
					vec[3] = num[right];					
					++left;
					--right;
					int count = ans.size();
					if (count == 0)
					{
						ans.push_back(vec);
					}
					else 
					{
						bool bOK = true;
						for (int k = 0; k < count; ++k)
						{
							if (ans[k][0] == vec[0] && ans[k][1] == vec[1]
									&& ans[k][2] == vec[2])
									{
										bOK = false;
										break;
									}
						}
						if (bOK)
						{
							ans.push_back(vec);
						}
					}									
				}
				else if (sum > target)
				{
					--right;
				}
				else
				{
					++left;
				}
			}
		}
	}
	return ans;
}

string longestCommonPrefix(vector<string> &strs)
{
	int size = strs.size();
	if (size == 0)
	{
		return "";
	}
	sort(strs.begin(), strs.end());
	string ans;
	if (strs[0] == "")
	{
		return "";
	}	
	int len = strs[0].length();
	for (int i = 0; i < len; ++i)
	{
		char ch = strs[0][i];
		for (int j = 1; j < size; ++j)
		{
			if (strs[j].length() <= i || (strs[j][i] != ch))
			{
				return ans;
			}
		}
		ans += ch;
	}
	return ans;
}

void TestThreeSum()
{
	vector<int> num;

	num.push_back(-5);
	num.push_back(-5);
	num.push_back(-5);
	num.push_back(-1);
	num.push_back(0);
	num.push_back(1);
	num.push_back(2);
	num.push_back(4);
	num.push_back(5);

	vector<vector<int> > ans = fourSum(num, -5);
}

int ladderLength(string start, string end, set<string> &dict)
{
	if (start == "" || end == "")
		return 0;

	queue<string> q;
	q.push(start);
	q.push("0");
	set<string> s;
	s.insert(start);
	int ans = 0;
	int len = start.length();
	while(!q.empty())
	{
		string str = q.front();
		q.pop();
		if (str == "0")
		{	
			if (q.empty())
			{
				return 0;
			}
			++ans;
			q.push("0");
			continue;
		}
		if (str == end)
		{
			++ans;
			return ans;
		}
		bool found = false;
		for (int i = 0; i < len; ++i)
		{
			char ch = str[i];
			string newStr = str;
			for (int j = 0; j < 26; ++j)
			{
				char newCh = 'a' + j;
				if (ch != newCh)
				{
					newStr[i] = newCh;
					if (s.find(newStr) == s.end() && dict.find(newStr) != dict.end())
					{	
						s.insert(newStr);
						q.push(newStr);						
					}
				}
			}
		}		
	}
	return 0;
}

void TestLadderLength()
{
	set<string> dict;
	dict.insert("ted");
	dict.insert("tex");
	dict.insert("red");
	dict.insert("tax");
	dict.insert("tad");
	dict.insert("den");
	dict.insert("rex");
	dict.insert("pee");

	findLadders("red", "tax", dict);
}

vector<vector<string>> findLadders(string start, string end, set<string> &dict) 
{
	vector<vector<string> > vVstr;
	if (start == "" || end == "")
		vVstr;
	
	vector<pair<string, int> > q;
	q.push_back(make_pair(start, -1));
	q.push_back(make_pair("0", -1));

	set<string> s;	
	s.insert(start);

	int size = 1;
	int len = start.length();
	int index = 0;
	int ans = 0x7FFFFFFF;

	set<string> levelSet;

	while(index < q.size())
	{
		string str = q[index].first;	
		int cur = index;
		++index;
		if (str == "0")
		{	
			if (index == q.size())
			{
				break;
			}			
			++size;
			levelSet.clear();

			q.push_back(make_pair("0", -1));			
			continue;
		}		
		if (str == end)
		{	
			if (size > ans)
			{
				break;
			}
			vector<string> vec;
			vec.resize(size);
			vec[size-1] = str;
			int father = q[cur].second;
			for (int i = size - 2; i >= 0; --i)
			{
				vec[i] = q[father].first;
				father = q[father].second;
			}
			vVstr.push_back(vec);
			ans = size;
			continue;
		}		

		for (int i = 0; i < len; ++i)
		{
			char ch = str[i];
			string newStr = str;
			for (int j = 0; j < 26; ++j)
			{
				char newCh = 'a' + j;
				if (ch != newCh)
				{
					newStr[i] = newCh;
					/*if (newStr == end)
					{
						q.push_back(make_pair(newStr, cur));
						continue;
					}*/
					// 如果在这一层已经生成过
					if (levelSet.find(newStr) != levelSet.end())
					{
						q.push_back(make_pair(newStr, cur));
					}
					else if (s.find(newStr) == s.end() && 
						dict.find(newStr) != dict.end())
					{
						s.insert(newStr);
						levelSet.insert(newStr);
						q.push_back(make_pair(newStr, cur));
					}
				}
			}
		}		
	}
	return vVstr;
}
    
string countAndSay(int n) 
{
    string ans = "1";
    if (n == 1)
        return ans;

	
    for (int i = 1; i < n; ++i)
    {
        string tmp;
        int len = ans.length();
		char last = ans[0];
		int count = 1;
        for (int j = 1; j < len; ++j)
        {
            char ch = ans[j];
            if (ch == last)
            {
                ++count;
            }
            else
            {                    
                tmp += (char)('0' + count);
                tmp += last;
                last = ch;
                count = 1;
            }
        }
        ans = tmp;
		ans += (char)('0' + count);
		ans += last;
    }
  
    return ans;
}

void TestCountAndSay()
{
	cout << countAndSay(4) << endl;
}

string MultiOne(string &num, char ch)
{
	string ans = "";
	int len = num.length();
	ans.resize(len);
	int mul = ch - '0';
	int carry = 0;
	int tmp = 0;
	for (int i = len - 1; i >= 0; --i)
	{
		tmp = (num[i] - '0') * mul + carry;
		carry = tmp / 10;
		tmp %= 10;
		ans[i] = tmp + '0';
	}
	if (carry != 0)
	{
		ans.insert(0, 1, '0' + carry);
	}	
	ClearZero(ans);
	return ans;
}

// 去掉开头的0
void ClearZero(string &num)
{
	while (num.length() != 0 && num[0] == '0')
	{
		num.erase(0, 1);
	}
	if (num.length() == 0)
	{
		num += '0';
	}
}

string AddTwoNum(string& num1, string &num2)
{
	if (num1 == "")
		return num2;
	if (num2 == "")
		return num1;
	int len1 = num1.length();
	int len2 = num2.length();
	int i = len1 - 1;
	int j = len2 - 1;
	int tmp = 0;
	int carry = 0;
	string ans;
	ans.resize(max(len1, len2));
	int count = max(len1, len2) - 1;

	while (i >= 0 || j >= 0)
	{
		tmp = carry;
		if (i >= 0)
		{
			tmp += (num1[i] - '0');
			--i;
		}
		if (j >= 0)
		{
			tmp += (num2[j] - '0');
			--j;
		}
		carry = tmp / 10;
		tmp = tmp % 10;
		ans[count--] = (tmp + '0');
	}
	if (carry != 0)
	{
		ans.insert(0, 1, '1');
	}
	ClearZero(ans);
	return ans;
}

string multiply(string num1, string num2)
{
	if (num1 == "")
		return num2;
	if (num2 == "")
		return num1;
	int len1 = num1.length();
	int len2 = num2.length();
	string ans;
	for (int i = len2 - 1, count = 0; i >= 0; --i, ++count)
	{
		string tmp = MultiOne(num1, num2[i]);
		for (int j = 0; j < count; ++j)
		{
			tmp.push_back('0');
		}
		ans = AddTwoNum(tmp, ans);
	}
	ClearZero(ans);
	return ans;
}

void TestMultiply()
{
	string s1 = "123456789";
	string s2 = "987654321";
	cout << multiply(s1, s2) << endl;
}


int trap(int arr[], int n)
{
	if (arr == NULL || n <= 0)
	{
		return 0;
	}
	int ans = 0;
	int *a = new int[n];
	memset(a, 0, sizeof(int) * n);
	int *b = new int[n];
	memset(b, 0, sizeof(int) * n);
	int left = arr[0];
	int right = arr[n - 1];
	for (int i = 1, j = n - 2; i < n; ++i, --j)
	{
		a[i] = left;
		left = max(left, arr[i]);
		b[j] = right;
		right = max(right, arr[j]);
	}

	for (int i = 1; i < n - 1; ++i)
	{
		int high = min(a[i], b[i]);
		if (arr[i] < high)
		{
			ans += (high - arr[i]);
		}
	}

	delete []a;
	delete []b;
	return ans;

}

void TestTrap()
{
	int arr[] = 
	{
		0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2
	};
	cout << trap(arr, sizeof(arr) / sizeof(int)) << endl;
}

vector<vector<int> > combinationSum(vector<int> &arr, int target) 
{
    vector<vector<int> > ans;
	int size = arr.size();
	if (size == 0)
		return ans;

	sort(arr.begin(), arr.end());
	vector<pair<int, vector<int> > > vec;
	int *indexArr = new int[size];
	for (int i = 0; i < size; ++i)
	{
		indexArr[i] = i;
		vector<int> tmp;
		tmp.push_back(arr[i]);
		if (arr[i] == target)
		{
			ans.push_back(tmp);
		}
		else
		{
			vec.push_back(make_pair(arr[i], tmp));
		}
	}
	int end = vec.size();
	int index = 0;
	while (index < vec.size())
	{
		for (int i = 0; i < size; ++i)
		{
			int curNum = arr[i];
			int from = indexArr[i];
			indexArr[i] = vec.size();
			// 如果是最后一个，就到第0个
			int to = end;
			for (int j = from; j < to; ++j)
			{
				int sum = vec[j].first;
				++index;
				vector<int> tmp = vec[j].second;				
				if (sum + curNum <= target)
				{					
					tmp.push_back(curNum);
					if (sum + curNum == target)
					{
						sort(tmp.begin(), tmp.end());
						ans.push_back(tmp);
					}
					else
					{
						vec.push_back(make_pair(sum + curNum, tmp));
					}
				}
			}
		}
		index = end;
		end = vec.size();
	}
	return ans;
}

void TestCombinationSum()
{
	//vector<int> arr;
	//arr.push_back(1);
	//arr.push_back(1);
	//arr.push_back(1);
	//arr.push_back(3);
	//arr.push_back(3);	
	//arr.push_back(5);
	//vector<vector<int> > ans = combinationSum(arr, 7);
	//arr.push_back(3);
	//arr.push_back(4);
	//arr.push_back(7);
	//arr.push_back(8);


//	vector<vector<int> > ans = combinationSum2(arr, 8);
	int arr[] =
	{
		2
	};
	cout << removeElement(arr, 1, 3);
	
}

vector<vector<int> > combinationSum2(vector<int> &num, int target) 
{
    vector<vector<int> > ans;
	int size = num.size();
	if (size == 0)
	{
		return ans;
	}

    sort(num.begin(), num.end());
	int remain = 0;
	for (int i = 0; i < size; ++i)
	{
		remain += num[i];
	}
	vector<int> vec;
	DFS(ans, num, 0, target, vec, size, 0, remain);
	sort(ans.begin(), ans.end());
	int total = ans.size();
	for (int i = 1; i < total; ++i)
	{
		int t1 = ans[i-1].size();
		int t2 = ans[i].size();
		bool isSame = true;
		if (t1 != t2)
		{
			continue;
		}
		for (int j = 0; j < t1; ++j)
		{
			if (ans[i-1][j] != ans[i][j])
			{
				isSame = false;
				break;
			}
		}
		if (isSame)
		{
			ans.erase(ans.begin() + i);
			--total;
			--i;
		}
			
	}
	return ans;
}

void DFS(vector<vector<int> >& ans, vector<int> &num, int sum, 
	int target, vector<int> &vec, int size, int from, int remain)
{
	for (int i = from; i < size; ++i)
	{			
		if (sum + num[i] <= target)
		{			
			vec.push_back(num[i]);
			if (sum + num[i] == target)
			{
				ans.push_back(vec);
				vec.erase(vec.end() - 1);
				break;
			}
			DFS(ans, num, sum + num[i], target, vec, size, i + 1, remain - num[i]);
			vec.erase(vec.end() - 1);
		}

	}
}


int searchInsert(int arr[], int n, int target) 
{
    int left = 0;
    int right = n - 1;
    while (left + 1 < right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] <= target)
        {
            left = mid;
        }
        else 
        {
            right = mid;
        }
    }
    if (left == right)
    {
        if (target < arr[0])
        {
            return 0;
        }
        if (target > arr[0])
        {
            return 1;
        }
    }
    if (target > arr[right])
    {
        return (right + 1);
    }
    else if (target == arr[right])
    {
        return right;
    }
    else if (target > arr[left])
    {
        return (left + 1);
    }
    else if (target <= arr[left])
    {
        return left;
    }        
}


int findFirst(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;
    while (left + 1 < right)
    {
        int mid = (left + right) / 2;
        if (target <= arr[mid])
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }
    if (arr[right] == target)
        return right;
    if (arr[left] == target)
        return left;
    return -1;
}
    
int findLast(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;
    while (left + 1 < right)
    {
        int mid = (left + right) / 2;
        if (target >= arr[mid])
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }
    if (arr[left] == target)
        return left;
    if (arr[right] == target)
        return right;
    return -1;
        
}
vector<int> searchRange(int arr[], int n, int target) 
{
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<int> ans;
    ans.push_back(-1);
    ans.push_back(-1);
    int from = findFirst(arr, n, target);
    int to = findLast(arr, n, target);
    if (from == -1 || to == -1)
        return ans;
    ans[0] = from;        
    ans[1] = to;
    return ans;            
}

int removeElement(int arr[], int n, int elem) 
{
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (n == 0)
        return 0;
    int ans = n;
    int index = 0;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] != elem)
        {
            if (index != i)
            {
                arr[index] = arr[i];
            }
            ++index;
        }
    }
    return index;
}

void nextPermutation(vector<int> &num) 
{
	int size = num.size();
	if (size == 0)
		return;
	int i = size - 2;
	for (; i >= 0; --i)
	{
		if (num[i] < num[i+1])
			break;
	}
	if (i == -1)
	{
		for (int i = 0; i < (size >> 1); ++i)
		{
			swap(num[i], num[size - 1 - i]);
		}
		return;
	}
	int j = size - 1;
	int minNum = num[i + 1];
	int index = i + 1;
	for (; j > i; --j)
	{
		if (num[j] > num[i])
		{
			if (num[j] < minNum)
			{
				minNum = num[j];
				index = j;
			}
		}
	}
	swap(num[i], num[index]);
	sort(num.begin() + i + 1, num.end());
}

void TestNextPermutation2()
{
	vector<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);

	for (int i = 0; i < 26; ++i)
	{
		for (int j = 0; j < arr.size(); ++j)
		{
			cout << arr[j];
		}
		cout << endl;
		nextPermutation(arr);
	}
}

void TestStrStr()
{
	char str1[] = "mississippi";
	char str2[] = "issi";
	char *ans = strStr(str1, str2);
	if (ans != NULL)
	{
		cout << ans << endl;
	}

}

char *strStr(char *str1, char *str2) 
{
    if (str1 == NULL)
		return NULL;
	if (str2 == NULL)
		return str1;

	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int end = len1 - len2 + 1;
	for (int i = 0; i < end; ++i)
	{
		bool found = true;
		for (int j = 0; j < len2; ++j)
		{
			if (str1[i + j] != str2[j])
			{
				found = false;
				break;
			}
		}
		if (found)
		{
			return (str1 + i);
		}
	}
	return NULL;
}

 ListNode *swapPairs(ListNode *head) 
 {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    ListNode *p1 = head;
    if (p1 == NULL)
        return head;
    ListNode *p2 = p1->next;
    if (p2 == NULL)
        return head;
	ListNode *tail = p1;

    p1->next = p2->next;
    p2->next = p1;	
    head = p2;
    p1 = p1->next;
    if (p1 == NULL)
        return head;
    p2 = p1->next;
    if (p2 == NULL)
        return head;
    while (true)
    {
		tail->next = p2;
		tail = p1;
        p1->next = p2->next;
        p2->next = p1;
        p1 = p1->next;
        if (p1 == NULL)
            break;
        p2 = p1->next;
        if (p2 == NULL)
            break;
    }
    return head;
}

void TestSwapPairs()
{
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(4);

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;

	ListNode *ans = swapPairs(&n1);
}

void ReverseList2(ListNode *&head, ListNode *&tail)
{
	ListNode *p1 = head;
	if (p1 == NULL)
		return;
	ListNode *p2 = head->next;
	ListNode *pEnd = tail;
	tail = head;
	head = pEnd;
	pEnd->next = NULL;
	while (p2 != NULL)
	{
		ListNode *pTmp = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = pTmp;
	}
}


ListNode *reverseKGroup(ListNode *head, int k) 
{
	if (head == NULL)
		return head;

	if (k < 2)
	{
		return head;
	}
	ListNode *p1 = head;
	ListNode *start = p1;
	ListNode *end = p1;	
	for (int i = 1; i < k && (end != NULL); ++i)
	{
		end = end->next;
	}
	if (end == NULL)
		return head;
	ListNode *pPrev = start;
	ListNode *pNext = end->next;
	head = end;	
	while (true)
	{
		ReverseList2(start, end);
		end->next = NULL;
		start = pNext;		
		if (start == NULL)
			break;		
		end = start;
		ListNode *pEndPrev = start;
		for (int i = 1; i < k && (end != NULL); ++i)
		{			
			end = end->next;
		}
		if (end == NULL)
		{
			pPrev->next = pEndPrev;
			break;
		}
		pPrev->next = end;
		pPrev = start;
		pNext = end->next;
	}
	return head;
}

void TestReverseKGroup()
{
	for (int i = 1; i < 7; ++i)
	{
		ListNode n1(1);
		ListNode n2(2);
		//ListNode n3(3);
		//ListNode n4(4);
		//ListNode n5(5);
		//ListNode n6(6);
		//ListNode n7(7);

		n1.next = &n2;
		//n2.next = &n3;
		//n3.next = &n4;
		//n4.next = &n5;
		//n5.next = &n6;
		//n6.next = &n7;
		ListNode *ans = reverseKGroup(&n1, 2);
		cout << i << " : ";
		while (ans != NULL)
		{
			cout << ans->key << " ";
			ans = ans->next;
		}
		cout << endl;
	}

}

ListNode *mergeKLists(vector<ListNode *> &lists) 
{
	ListNode *ans = NULL;
	int size = lists.size();
	if (size == 0)
		return ans;
	int index = -1;
	int minNum = 0x7FFFFFFF;
	for (int i = 0; i < size; ++i)
	{
		if (lists[i] != NULL)
		{
			if (lists[i]->key < minNum)
			{
				index = i;
				minNum = lists[i]->key;
			}
		}
	}
	ans = lists[index];
	lists[index] = lists[index]->next;
	ListNode *p = ans;

	while (true)
	{
		index = -1;
		minNum = 0x7FFFFFFF;
		for (int i = 0; i < size; ++i)
		{
			if (lists[i] != NULL)
			{
				if (lists[i]->key < minNum)
				{
					index = i;
					minNum = lists[i]->key;
				}
			}
		}
		if (index == -1)
			break;
		p->next = lists[index];
		lists[index] = lists[index]->next;
		p = p->next;
	}		

	return ans;
}

bool isMatchStr(char ch1, char ch2)
{
	if (ch1 == '(')
	{
		if (ch2 == ')')
			return true;		
		return false;
	}
	if (ch1 == '[')
	{
		if (ch2 == ']')
			return true;
		return false;
	}
	if (ch1 == '{')
	{
		if (ch2 == '}')
		{
			return true;
		}
		return false;
	}
	return false;
}
bool isValid(string str) 
{	
	if (str == "")
		return true;
	stack<char> s;
	int size = str.length();
	for (int i = 0; i < size; ++i)
	{
		char ch = str[i];
		if (s.empty())
		{
			s.push(ch);
		}
		else
		{
			char topCh = s.top();
			if (isMatchStr(topCh, ch))
			{
				s.pop();
			}
			else
			{
				s.push(ch);
			}
		}
	}
	if (s.empty())
	{
		return true;
	}
	return false;
}

void TestIsStrValid()
{
	string str = "()";
	cout << isValid(str) << endl;;
}


int phoneCount[10] =
{
	0, 0, 3, 3, 3, 3, 3, 4, 3, 4
};

char phoneMap[10][4] = 
{
	{'0', '0', '0', '0'},
	{'0', '0', '0', '0'},
	{'a', 'b', 'c', '0'},
	{'d', 'e', 'f', '0'},
	{'g', 'h', 'i', '0'},
	{'j', 'k', 'l', '0'},
	{'m', 'n', 'o', '0'},
	{'p', 'q', 'r', 's'},
	{'t', 'u', 'v', '0'},
	{'w', 'x', 'y', 'z'},
};

void LetterCombinationsDFS(string &str, string &tmp, vector<string> &ans, int size, int step)
{
	if (step == size)
	{
		ans.push_back(tmp);
		return;
	}
	char ch = str[step];
	int index = ch - '0';
	int pCount = phoneCount[index];
	for (int i = 0; i < pCount; ++i)
	{
		tmp[step] = phoneMap[index][i];
		LetterCombinationsDFS(str, tmp, ans, size, step + 1);
	}
}

vector<string> letterCombinations(string str) 
{
	vector<string> ans;
	int size = str.length();
	if (size == 0)
	{
		ans.push_back("");
		return ans;
	}
	string tmp;
	tmp.resize(size);
	LetterCombinationsDFS(str, tmp, ans, size, 0);
	return ans;
}

void TestLetterCombinations()
{
	string str = "23";
	vector<string> ans = letterCombinations(str);
	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << endl;
	}

}

int moveMap[][2] =
{
	{-1, 0},
	{0, 1},
	{1, 0},
	{0, -1}
};

bool wordFindDFS(vector<vector<char> > &board, int row, int col, bool **used, string &word, int step, int curX, int curY)
{
	if (step == word.size())
	{
		return true;
	}
	for (int i = 0; i < 4; ++i)
	{
		int newX = curX + moveMap[i][0];
		int newY = curY + moveMap[i][1];
		if (0 <= newX && newX < row && 0 <= newY && newY < col)
		{
			if (board[newX][newY] == word[step] && !used[newX][newY])
			{
				used[newX][newY] = true;
				if (wordFindDFS(board, row, col, used, word, step + 1, newX, newY))
				{
					return true;
				}
				used[newX][newY] = false;
			}
		}
	}
	return false;
}

bool exist(vector<vector<char> > &board, string word) 
{	
	int row = board.size();
	if (row == 0)
	{
		if (word == "")
			return true;
		return false;
	}
	int col = board[0].size();

	bool **used = new bool*[row];
	for (int i = 0; i < row; ++i)
	{
		used[i] = new bool[col];
		memset(used[i], 0, sizeof(bool) * col);
	}
	bool ans = false;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (board[i][j] == word[0])
			{
				used[i][j] = true;
				ans = wordFindDFS(board, row, col, used, word, 1, i, j);
				if (ans)					
				{
					break;
				}
				used[i][j] = false;
			}
		}
		if (ans)
			break;
	}
	

	for (int i = 0; i < row; ++i)
	{
		delete [] used[i];
	}
	delete []used;

	return ans;
}

void TestWordFind()
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
	cout << exist(board, "ABCCED") << endl;
	cout << exist(board, "SEE") << endl;
	cout << exist(board, "ABCB") << endl;
}

int minPathSum(vector<vector<int> > &grid) 
{
	int row = grid.size();
	if (row == 0)
		return 0;
	int col = grid[0].size();
	int **used = new int*[row];
	int ** dist = new int*[row];
	for (int i = 0; i < row; ++i)
	{
		used[i] = new int[col];
		memset(used[i], 0, sizeof(int) * col);
		dist[i] = new int[col];
		for (int j = 0; j < col; ++j)
		{
			dist[i][j] = 0x7FFFFFFF;
		}
	}

	dist[0][0] = grid[0][0];
	used[0][0] = 1;
	int curX = 0;
	int curY = 0;
	int ans = dist[0][0];
	while (true)
	{
		if (curX == (row - 1) && curY == (col - 1))
		{
			break;
		}
		// 扩展它的邻居
		for (int i = 0; i < 4; ++i)
		{
			int newX = moveMap[i][0] + curX;
			int newY = moveMap[i][1] + curY;
			if (0 <= newX && newX < row && 0 <= newY && newY < col)
			{
				// 没有被扩展过/或者有更短路径
				if (used[newX][newY] != 2)
				{
					used[newX][newY] = 1;
					if (dist[curX][curY] + grid[newX][newY] < dist[newX][newY])
					{
						dist[newX][newY] = dist[curX][curY] + grid[newX][newY];
					}
				}				
			}
		}
		// 扩展完成
		used[curX][curY] = 2;
		// 寻找最短路
		int minLen = 0x7FFFFFFF;
		int tmpX = -1;
		int tmpY = -1;
		for (int i = row - 1; i >= 0; --i)
		{
			for (int j = col - 1; j >= 0; --j)
			{
				if (used[i][j] == 1)
				{
					if (dist[i][j] < minLen)
					{
						minLen = dist[i][j];
						tmpX = i;
						tmpY = j;
					}
				}
			}
		}
		if (tmpX == -1)
		{
			break;
		}
		ans = minLen;
		curX = tmpX;
		curY = tmpY;
	}

	for (int i = 0; i < row; ++i)
	{
		delete[] used[i];
		delete[] dist[i];
	}
	delete[] used;
	delete[] dist;
	return ans;
}

void TestMinPathSum()
{
	vector<vector<int> > board;
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(1);
	board.push_back(v1);
	
	vector<int> v2;
	v2.push_back(1);
	v2.push_back(5);
	v2.push_back(1);
	board.push_back(v2);
	
	vector<int> v3;
	v3.push_back(4);
	v3.push_back(2);
	v3.push_back(1);
	board.push_back(v3);

	cout << minPathSum(board) << endl;

}

bool isPalindrome(int x) 
{
	if (x < 0)
		return false;
	if (x == 0)
		return true;
	int len = 0;
	int num = x;
	while (num)
	{
		++len;
		num /= 10;
	}
	int midLen = len / 2;
	int powTen = 1;
	for (int i = 0; i < midLen; ++i)
	{
		powTen *= 10;
	}
	int low = x % powTen;
	int high = x / powTen;
	if (len & 1)
	{
		high /= 10;
	}
	powTen /= 10;
	for (int i = 0; i < midLen; ++i)
	{
		int lowNum = low % 10;
		low /= 10;
		int highNum = (high / powTen) % 10;
		powTen /= 10;
		if (lowNum != highNum)
		{
			return false;
		}
	}
	return true;
}
void TestIsIntPalindrome()
{
	int num1 = 123321;
	cout << isPalindrome(num1) << endl;
	cout << isPalindrome(1234321) << endl;
}

string getPermutation2(int n, int k) 
{
	string ans;
	ans.resize(n);
	bool used[10];
	memset(used, 0, sizeof(used));
	// 用0到n-1代表（1，n）
	for (int i = n; i <= 9; ++i)
	{
		used[i] = true;
	}
	int count = 1;
	for (int i = 1; i <= n - 1; ++i)
	{
		count *= i;
	}
	int num = 0;
	--k;
	while (k)
	{
		int index = k / count;
		int visited = 0;
		for (int i = 0; i < n; ++i)
		{
			if (!used[i])
			{
				if (visited == index)
				{
					ans[num++] = i + '0' + 1;
					used[i] = true;
					break;
				}
				else
				{
					++visited;
				}
			}
		}
		k = k % count;
		if (k == 0)
			break;

		count = count / (n - num);
	}
	if (num < n)
	{
		for (int i = 0; i < n; ++i)
		{
			if (!used[i])
			{
				ans[num++] = i + '0' + 1;
			}
		}
	}
    return ans;
}


void TestGetPermutation2()
{
	for (int i = 0; i < 24; ++i)
		cout << getPermutation2(4, i + 1) << endl;
}

string getPermutation3(int n, int k) 
{
    vector<int> vec;
    for (int i = 1; i <= n; ++i)
    {
    	vec.push_back(i);
    }
    for (int i = 2; i <= k; ++i)
    {
    	nextPermutation(vec);
    }
    string ans;
    for (int i = 0; i < n; ++i)
    {
        ans += vec[i];
    }
    return ans;
}

int longestValidParentheses(string str) 
{
    if (str == "")
		return true;
	stack<char> s;
	int size = str.length();
	for (int i = 0; i < size; ++i)
	{
		char ch = str[i];
		if (s.empty())
		{
			s.push(ch);
		}
		else
		{
			char topCh = s.top();
			if (isMatchStr(topCh, ch))
			{
				s.pop();
			}
			else
			{
				s.push(ch);
			}
		}
	}
	int len = s.size();
	int ans = size - len;
    return ans; 
}

string intToRoman(int num) 
{
	char romanNum[] = 
	{ // 0-7
		'I', 'I', 'V', 'X', 'L', 'C', 'D', 'M'
	};
	int decom = 1000;
	string ans;
	int base = 8;
	while (num)
	{
		int index = ((num / decom) % 10);
		if (index == 9)
		{
			ans += romanNum[base - 1];
			ans += romanNum[base + 1];
		}
		else if (index >= 5)
		{ // 5-8
			ans += romanNum[base];
			index -= 5;
			while (index--)
			{
				ans += romanNum[base - 1];
			}
		}
		else if (index == 4)
		{
			ans += romanNum[base - 1];
			ans += romanNum[base];
		}
		else if (index > 0)
		{ // 1-3
			while (index--)
			{
				ans += romanNum[base - 1];
			}
		}
		num %= decom;
		decom /= 10;
		base -= 2;
	}
	return ans;
}

void TestIntToRoman()
{
	cout << intToRoman(3999) << " : MMMCMXCIX" << endl;
	cout << intToRoman(34) << " : XXXIV" << endl;
	cout << intToRoman(65) << " : LXV" << endl;

	cout << intToRoman(100) << endl;
	cout << intToRoman(200) << endl;
	cout << intToRoman(300) << endl;
	cout << intToRoman(400) << endl;
	cout << intToRoman(500) << endl;
	cout << intToRoman(900) << endl;
	cout << intToRoman(700) << endl;
	cout << intToRoman(800) << endl;
	cout << intToRoman(999) << endl;

	cout << intToRoman(1888) << endl;
	cout << intToRoman(1899) << endl;
	cout << intToRoman(1900) << endl;
	cout << intToRoman(1976) << endl;

}


int romanToInt(string s)
{
	map<char, int> romanNum;
	map<char, int> romanIndex;
	romanNum['I'] = 1;
	romanNum['V'] = 5;
	romanNum['X'] = 10;
	romanNum['L'] = 50;
	romanNum['C'] = 100;
	romanNum['D'] = 500;
	romanNum['M'] = 1000;


	romanIndex['I'] = 1;
	romanIndex['V'] = 2;
	romanIndex['X'] = 3;
	romanIndex['L'] = 4;
	romanIndex['C'] = 5;
	romanIndex['D'] = 6;
	romanIndex['M'] = 7;

	int len = s.length();
	int ans = 0;
	for (int i = 0; i < len - 1; ++i)
	{
		char ch = s[i];
		char nextCh = s[i + 1];
		int indexCh = romanIndex[ch];
		int indexNextCh = romanIndex[nextCh];
		if (indexNextCh > indexCh)
		{
			ans -= romanNum[ch];
		}
		else
		{
			ans += romanNum[ch];
		}
	}
	ans += romanNum[s[len - 1]];
	return ans;
}

void TestRomanToInt()
{
	//cout << "1000 : " << romanToInt("M") << endl;
	//cout << "1100 : " << romanToInt("MC") << endl;
	//cout << "1400 : " << romanToInt("MCD") << endl;
	//cout << "1500 : " << romanToInt("MD") << endl;
	//cout << "1600 : " << romanToInt("MDC") << endl;
	//cout << "1666 : " << romanToInt("MDCLXVI") << endl;
	//cout << "1899 : " << romanToInt("MDCCCXCIX") << endl;
	//cout << "1976 : " << romanToInt("MCMLXXVI") << endl;
	//cout << "1984 : " << romanToInt("MCMLXXXIV") << endl;
	//cout << "3999 : " << romanToInt("MMMCMXCIX") << endl;

	cout << "99 : " << romanToInt("XCIX") << endl;
	cout << "39 : " << romanToInt("XXXIX") << endl;
	cout << "34 : " << romanToInt("XXXIV") << endl;
	cout << "65 : " << romanToInt("LXV") << endl;
	


}

void TestLongestPalindrome()
{
	string str;

	str = "aa";
	cout << longestPalindrome2(str) << endl;
	str = "aaa";
	cout << longestPalindrome2(str) << endl;
	str = "ccd";
	cout << longestPalindrome2(str) << endl;

	str = "aba";
	cout << longestPalindrome2(str) << endl;

	str = "aaaa";
	cout << longestPalindrome2(str) << endl;

	str = "caba";
	cout << longestPalindrome2(str) << endl;

	str = "banana";
	cout << longestPalindrome2(str) << endl;
	str = "aaaabaaa";
	cout << longestPalindrome2(str) << endl;

	str = "aaaabbaaa";
	cout << longestPalindrome2(str) << endl;
}

string longestPalindrome(string s) 
{
	vector<string> vec;
	int len = s.length();
	string rStr = s;

	for (int i = 0; i < len / 2; ++i)
	{
		swap(rStr[i], rStr[len - 1 - i]);
	}
	s += '$';
	for (int i = 0; i < len; ++i)
	{
		vec.push_back(s.substr(i));
		vec.push_back(rStr.substr(i));
	}
	int size = vec.size();
	int ans = 0;
	string str;

	sort(vec.begin(), vec.end());

	for (int i = 1; i < size; ++i)
	{
		int tmp = 0;
		string str1 = vec[i-1];
		string str2 = vec[i];
		int cur = min(str1.length(), str2.length());
		for (int j = 0; j < cur; ++j)
		{
			if (str1[j] == str2[j])
			{
				++tmp;
			}
			else
			{
				break;
			}
		}
		if (tmp > ans)
		{
			bool b1 = (str1.find('$') == string::npos);
			bool b2 = (str2.find('$') == string::npos);
			if (b1 != b2)
			{
				//string ss = str1.substr(0, tmp);
				//bool bP = true;
				//for (int k = 0; k < tmp / 2; ++k)
				//{
				//	if (ss[k] != ss[tmp - 1 - k])
				//	{
				//		bP = false;
				//		break;
				//	}
				//}
				//if (bP)
				{
					ans = tmp;
					str = str1.substr(0, ans);
				}
			}
		}
	}
	return str;
}

string longestPalindrome2(string s)
{
	string ans;
	int maxLen = 0;
	int len = s.length();
	for (int i = 0; i < len; ++i)
	{
		// 以s[i]为中心
		int tmp1 = 1;
		int len1 = min(i, len - i - 1);
		for (int j = 1; j <= len1; ++j)
		{
			if (s[i - j] != s[i + j])
			{
				break;
			}
			tmp1 += 2;
		}
		if (tmp1 > maxLen)
		{
			ans = s.substr(i - tmp1 / 2, tmp1);
			maxLen = tmp1;
		}
		// 以s[i], s[i+1]为中心		
		if (i + 1 < len && s[i] == s[i + 1])
		{
			int tmp2 = 2;
			int len2 = min(i, len - i - 2);
			for (int j = 1; j <= len2; ++j)
			{
				if (s[i - j] != s[i + 1 + j])
				{
					break;
				}
				tmp2 += 2;
			}
			if (tmp2 > maxLen)
			{
				ans = s.substr(i + 1 - tmp2 / 2, tmp2);
				maxLen = tmp2;
			}
		}
	}
	return ans;
}