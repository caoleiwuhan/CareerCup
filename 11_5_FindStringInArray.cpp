#include <iostream>

#include "11_5_FindStringInArray.h"

using namespace std;

// arr中的string都是排好序的，只是中间插入了若干""
int FindString(vector<string> &arr, string str)
{
	if (arr.size() == 0)
	{
		return -1;
	}
	int left = 0;
	int right = arr.size() - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (str.compare(arr[mid]) == 0)
		{
			return mid;
		}
		// 向左找到第一个不为""的地方
		while (left < mid && (arr[mid].compare("") == 0))
		{
			mid--;
		}
		// 没找到
		if (mid == left && (arr[mid].compare("") == 0))
		{
			//left = mid + 1;
			// 向右找
			while (mid < right && (arr[mid].compare("") == 0))
			{
				mid++;
			}
			if (mid == right && (arr[mid].compare("") == 0))
			{
				return -1;
			}
			else
			{
				left = mid;
			}
		}
		else
		{
			int comp = arr[mid].compare(str);
			if (comp == 0)
			{
				return mid;
			}
			else if (comp > 0)
			{
				if (mid == left)
					return -1;
				right = mid - 1;
			}
			else
			{				
				left = mid + 1;
			}
		}
	}
	return -1;
}


int FindString2(vector<string> &arr, string str)
{
	if (arr.size() == 0)
	{
		return -1;
	}
	int left = 0;
	int right = arr.size() - 1;
	while (left <= right)
	{
		while (left <= right && (arr[right].compare("") == 0))
		{
			right--;
		}
		if (right < left)
			return -1;
		int mid = (left + right) >> 1;
		while (arr[mid].compare("") == 0)
		{
			++mid;
		}
		int comp = arr[mid].compare(str);
		if (comp == 0)
			return mid;
		else if (comp > 0)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return -1;
}

void TestFindString()
{
	string arr[] = {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
	
	vector<string> vec(arr, arr + 13);
	cout << FindString2(vec, "at") << endl;
	cout << FindString2(vec, "ball") << endl;
	cout << FindString2(vec, "car") << endl;
	cout << FindString2(vec, "dad") << endl;

	cout << FindString(vec, "at") << endl;
	cout << FindString(vec, "ball") << endl;
	cout << FindString(vec, "car") << endl;
	cout << FindString(vec, "dad") << endl;
}