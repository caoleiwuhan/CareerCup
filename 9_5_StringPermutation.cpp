#include <iostream>

#include "9_5_StringPermutation.h"

using namespace std;

void StringPermutation(string str)
{
	if (str == "")
		return;

	StringPermutationDFS2(str, 0);
}

void StringPermutationDFS(string str, int step)
{
	if (step == str.size())
	{
		cout << str << endl;
		return;
	}
	int size = str.size();
	for (int i = step; i < size; ++i)
	{
		swap(str[step], str[i]);
		StringPermutationDFS(str, step + 1);
		swap(str[step], str[i]);
	}
}

void TestStringPermutation()
{
	string str = "1223";
	StringPermutation(str);
}

void StringPermutationDFS2(string str, int step)
{
	if (step == str.size())
	{
		cout << str << endl;
		return;
	}
	int size = str.size();
	for (int i = step; i < size; ++i)
	{
		bool bSwap = true;
		for (int j = step; j < i; ++j)
		{
			if (str[j] == str[i])
			{
				bSwap = false;
				break;
			}
		}
		if (bSwap)
		{
			swap(str[step], str[i]);		
			StringPermutationDFS2(str, step + 1);		
			swap(str[step], str[i]);
		}		
	}
}