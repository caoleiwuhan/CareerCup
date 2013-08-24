#include <iostream>

#include "9_4_AllSubSet.h"

using namespace std;

void SubSet(int a[], int n)
{
	if (a == NULL || n <= 0)
		return;

	int *ans = new int[n + 1];
	for (int i = 1; i <= n; ++i)
	{
		SubSetDFS(a, n, i, ans, 0, 0);
	}
}

void SubSetDFS(int a[], int n, int m, int ans[], int step, int from)
{
	if (step == m)
	{
		for (int i = 0; i < m; ++i)
		{
			cout << ans[i] << ' ';
		}
		cout << endl;
	}
	else
	{
		for (int i = from; i < n; ++i)
		{
			ans[step] = a[i];
			SubSetDFS(a, n, m, ans, step + 1, i + 1);
		}
	}
}

void TestSubSet()
{
	//int a[] = {3, 5, 7, 11, 2, 4};
	//SubSet(a, 6);

	int a[] = {1, 2, 3, 4};
	//SubSet(a, 4);
	SubSet2(a, 4);
}

void SubSet2(int a[], int n)
{
	if (a == NULL || n <= 0)
		return;
	int num = (1 << n);
	for (int i = 1; i < num; ++i)
	{
		unsigned k = i;
		int index = 0;
		while (k)
		{
			if (k & 1)
			{
				cout << a[index] << ' ';
			}
			k >>= 1;
			++index;
		}
		cout << endl;
	}
}