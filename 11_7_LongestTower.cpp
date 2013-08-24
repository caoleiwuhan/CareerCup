#include <iostream>
#include <vector>
#include <algorithm>

#include "11_7_LongestTower.h"

using namespace std;

vector<Person> LongestTower(vector<Person> &vec)
{
	vector<Person> ans;
	if (vec.size() == 0)
	{
		return ans;
	}

	sort(vec.begin(), vec.end());
	int size = vec.size();
	vector<int> f;
	vector<int> last;
	f.push_back(1);
	last.push_back(-1);
	for (int i = 1; i < size; ++i)
	{
		f.push_back(1);
		last.push_back(-1);
		for (int j = i - 1; j >= 0; --j)
		{
			if (vec[i].weight > vec[j].weight)
			{
				if (f[i] < f[j] + 1)
				{
					f[i] = f[j] + 1;
					last[i] = j;
				}
			}
		}
	}

	int num = f[0];
	int index = last[0];
	for (int i = 1; i < size; ++i)
	{
		if (f[i] > num)
		{
			num = f[i];
			index = i;
		}
	}
//	ans.insert(ans.begin(), vec[index]);	
	while (index != -1)
	{
		ans.insert(ans.begin(), vec[index]);
		index = last[index];
	}

	return ans;
}

void TestLongestTower()
{
	vector<Person> vec;
	Person p1(1, 65, 100);
	Person p2(2, 70, 150);
	Person p3(3, 56, 90);
	Person p4(4, 75, 190);
	Person p5(5, 60, 95);
	Person p6(6, 68, 110);
	Person p7(7, 68, 100);
	Person p8(8, 68, 120);

	vec.push_back(p1);
	vec.push_back(p2);
	vec.push_back(p3);
	vec.push_back(p4);
	vec.push_back(p5);
	vec.push_back(p6);
	//vec.push_back(p7);
	//vec.push_back(p8);

	vector<Person> ans = LongestTower(vec);
}

int LongestIncreaseSequence(int arr[], int n)
{
	/*
		f[i] = max{f[j] + 1} : arr[i] >= arr[j] && 0 <= j < i
	*/
	if (arr == NULL || n <= 0)
		return 0;

	int f[1024];
	memset(f, 0, sizeof(f));
	f[0] = 1;
	for (int i = 1; i < n; ++i)
	{
		for (int j = i - 1; j >= 0; --j)
		{
			if (arr[i] >= arr[j])
			{
				f[i] = max(f[i], f[j] + 1);
			}
		}
	}
	return f[n - 1];
}

int ** my2DAlloc(int rows, int cols)
{
	int *ptr = new int[rows * cols + rows];
	if (ptr == NULL)
	{
		return NULL;
	}
	for (int i = 0; i < rows; ++i)
	{
		*(int **)(ptr + i) = (ptr + rows + cols * i);
	}
	return (int **)ptr;
}


void TestMy2DAlloc()
{
	int row = 3;
	int col = 3;
	int **ptr = my2DAlloc(row, col);
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			ptr[i][j] = (i + 1) * (j + 1);
			//cout << ptr[i][j] << endl;
		}
	}
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cout << ptr[i][j] << ' ';
		}
		cout << endl;
	}
}

int ** my2DAlloc2(int rows, int cols)
{
	return NULL;	
}