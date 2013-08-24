#include <iostream>

#include "9_9_EightQueen.h"

using namespace std;

int QueenNum(int n)
{
	if (n <= 0)
		return 0;
	int *arr = new int[n + 1];

	int ans = QueenDFS(arr, n, 0);

	delete []arr;

	return ans;
}

int QueenDFS(int arr[], int n, int step)
{
	if (step == n)
	{
		PrintBoard(arr, n);
		return 1;
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		if (QueenOK(arr, n, step, i))
		{
			arr[step] = i;
			ans += QueenDFS(arr, n, step + 1);
		}
	}
	return ans;
}

bool QueenOK(int arr[], int n, int step, int pos)
{
	
	for (int i = 0; i < step; ++i)
	{
		// 列不能冲突
		if (arr[i] == pos)
		{
			return false;
		}
		// 对角线不能冲突
		if (abs(i - step) == abs(arr[i] - pos))
		{
			return false;
		}
	}
	
	return true;
}

void TestQueenNum()
{
	cout << QueenNum(5) << endl;
}

void PrintBoard(int arr[], int n)
{
	cout << "--------------------------------" << endl;
	for (int i = 0; i < n; ++i)
	{
		int col = arr[i];
		for (int j = 0; j < col; ++j)
		{
			cout << 'X';
		}
		cout << 'O';
		for (int j = col + 1; j < n; ++j)
		{
			cout << 'X';
		}
		cout << endl;
	}
}