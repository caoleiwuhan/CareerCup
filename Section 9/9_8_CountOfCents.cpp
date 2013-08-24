#include <iostream>

#include "9_8_CountOfCents.h"

using namespace std;

// 1:f[i][j] = f[i-1][j] + f[i][j-arr[i]]
int CountOfCents1(int arr[], int m, int n)
{
	int **f = new int*[m + 1];
	for (int i = 0; i <= m; ++i)
	{
		f[i] = new int[n + 1];
	}
	for (int i = 0; i <= m; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			f[i][j] = 0;
		}
	}
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			f[i][j] = f[i-1][j];
			if (j - arr[i] >= 0)
			{
				f[i][j] += (f[i][j - arr[i]] == 0 ? 1 : f[i][j - arr[i]]);
			}
		}
	}
	int ans = f[m][n];


	for (int i = 0; i <= m; ++i)
	{
		delete []f[i];
	}
	delete []f;

	return ans;
}

int CountOfCents2(int arr[], int m, int n)
{
	int **f = new int*[m + 1];
	for (int i = 0; i <= m; ++i)
	{
		f[i] = new int[n + 1];
	}
	for (int i = 0; i <= m; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			f[i][j] = 0;
		}
	}
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			f[i][j] += f[i-1][j];
			for (int k = 1; (j - k * arr[i]) >= 0; ++k)
			{
				int tmp = j - k * arr[i];
				f[i][j] += (f[i][tmp] == 0 ? 1 : f[i][tmp]);
			}
		}
	}
	int ans = f[m][n];


	for (int i = 0; i <= m; ++i)
	{
		delete []f[i];
	}
	delete []f;

	return ans;
}

int CountOfCents3(int arr[], int m, int n)
{
	int **f = new int*[m + 1];
	for (int i = 0; i <= m; ++i)
	{
		f[i] = new int[n + 1];
	}
	for (int i = 0; i <= m; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			f[i][j] = 0;
		}
	}
	
	int ans = CountOfCents3Help(f, arr, m, n);


	for (int i = 0; i <= m; ++i)
	{
		delete []f[i];
	}
	delete []f;

	return ans;
}

int CountOfCents3Help(int **f, int arr[], int m, int n)
{
	if (f[m][n] != 0)
	{
		return f[m][n];
	}
	if (m == 0)
	{		
		return 0;
	}
	if (n == 0 && m > 0)
	{
		return 1;
	}
	f[m][n] = CountOfCents3Help(f, arr, m - 1, n);
	if (n - arr[m] >= 0)
	{
		f[m][n] += CountOfCents3Help(f, arr, m, n - arr[m]);
	}
	return f[m][n];
}

int CountOfCents4(int n)
{
	return CountOfCents4Help(n, 25);
}

int CountOfCents4Help(int n, int denom)
{
	int next = 0;
	if (denom == 25)
	{
		next = 10;
	}
	else if (denom == 10)
	{
		next = 5;
	}
	else if (denom == 5)
	{
		next = 1;
	}
	else if (denom == 1)
	{
		return 1;
	}
	int ways = 0;
	for (int i = 0; i * denom <= n; i++)
	{
		ways += CountOfCents4Help(n - i * denom, next);
	}
	return ways;
}

/*
	f[i] = f[i] + f[i-arr[j]]
*/
int CountOfCents5(int arr[], int m, int n)
{
	int f[1001];
	memset(f, 0, sizeof(f));
	f[0] = 1;
	int tmp = arr[0];
	while (tmp <= n)
	{
		f[tmp] = 1;
		tmp += arr[0];
	}
	for (int i = 1; i < m; ++i)
	{
		for (int j = arr[i]; j <= n; ++j)
		{
			if (j - arr[i] == 0)
			{
				f[j] += 1;
			}
			else
			{
				f[j] += f[j - arr[i]];
			}
		}
	}
	return f[n];
}

void TestCountOfCents()
{
	//int arr[] = {0, 1, 2, 3, 4};
	int arr[] = {0, 1, 5, 10, 25};
	/*cout << CountOfCents1(arr, 4, 10) << endl;
	cout << CountOfCents1(arr, 4, 11) << endl;
	cout << CountOfCents1(arr, 4, 25) << endl;*/


	cout << CountOfCents3(arr, 4, 10) << endl;
	cout << CountOfCents3(arr, 4, 11) << endl;
	cout << CountOfCents3(arr, 4, 25) << endl;

	cout << CountOfCents4(10) << endl;
	cout << CountOfCents4(11) << endl;
	cout << CountOfCents4(25) << endl;

	int arr2[] = {1, 5, 10, 25};
	//cout << CountOfCents5(arr2, 4, 10) << endl;
	//cout << CountOfCents5(arr2, 4, 11) << endl;
	cout << CountOfCents5(arr2, 4, 25) << endl;
}