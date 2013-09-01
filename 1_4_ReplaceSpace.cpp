#include <iostream>

#include "1_4_ReplaceSpace.h"

using namespace std;

void ReplaceSpace(char str[], char ch, char dest[])
{
	if (str == NULL || dest == NULL)
	{
		return;
	}
	int len = strlen(str);	
	int dLen = strlen(dest);

	int count = 0;
	for (int i = 0; i < len; ++i)
	{
		if (str[i] == ch)
		{
			count++;
		}
	}
	int ansLen = len + (dLen - 1) * count;
	str[ansLen] = '\0';
	for (int i = len - 1, j = ansLen - 1; i >= 0; --i)
	{
		if (str[i] == ch)
		{
			for (int k = dLen - 1; k >= 0; --k)
			{
				str[j--] = dest[k];
			}
		}
		else
		{
			str[j--] = str[i];
		}
	}
}

void TestReplaceSpace()
{
	char str[256];
	char dest[256];
	
	strcpy(str, "a b c");
	strcpy(dest, "%2000");
	ReplaceSpace(str, ' ', dest);
	cout << str << endl;

	strcpy(str, "a b  c");
	ReplaceSpace(str, ' ', dest);
	cout << str << endl;

	strcpy(str, "ab  c ");
	ReplaceSpace(str, ' ', dest);
	cout << str << endl;

	strcpy(str, " a b  c");
	ReplaceSpace(str, ' ', dest);
	cout << str << endl;

	strcpy(str, " a b  c ");
	ReplaceSpace(str, ' ', dest);
	cout << str << endl;
}