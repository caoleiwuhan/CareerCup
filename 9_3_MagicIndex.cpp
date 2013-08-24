#include <iostream>

#include "9_3_MagicIndex.h"

using namespace std;

int MagicIndex(int a[], int n)
{
	if (a == NULL || n <= 0)
		return -1;
	return MagicIndexHelp(a, 0, n - 1);
}

int MagicIndexHelp(int a[], int start, int to)
{
	int mid = start + (to - start) / 2;
	if (a[mid] == mid)
	{
		return mid;
	}
	else if (a[mid] > mid)
	{
		return MagicIndexHelp(a, start, mid - 1);
	}
	else
	{
		return MagicIndexHelp(a, mid + 1, to);
	}
}

int MagicIndexHelp2(int a[], int start, int to)
{
	while (start + 1 < to)
	{
		int mid = start + (to - start) / 2;
		if (a[mid] == mid)
		{
			return mid;
		}
		else if (a[mid] < mid)
		{
			start = mid;
		}
		else
		{
			to = mid;
		}
	}
	if (a[start] == start)
		return start;
	if (a[to] == to)
		return to;
	return -1;
}

int MagicIndexHelp3(int a[], int start, int to)
{
	if (start < 0 || to < start || a == NULL)
	{
		return -1;
	}
	
	int mid = start + (to - start) / 2;
	if (a[mid] == mid)
	{
		return mid;
	}
	int leftSide = min(a[mid], mid - 1);
	int tmp = MagicIndexHelp3(a, start, leftSide);
	if (tmp != -1)
	{
		return tmp;
	}
	int rightSide = max(a[mid], mid + 1);
	tmp = MagicIndexHelp3(a, rightSide, to);
	if (tmp != -1)
		return tmp;
	return -1;
}