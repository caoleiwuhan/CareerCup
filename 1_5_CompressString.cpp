#include <iostream>

#include "1_5_CompressString.h"

using namespace std;

void CompressString(char str[])
{
	if (str == NULL)
	{
		return;
	}
	size_t len = strlen(str);
	if (len < 3)
	{
		return;
	}

	char *destStr = new char[len * 2 + 1];
	if (destStr == NULL)
	{
		cerr << "Allocate Space failed" << endl;
		exit(-1);
	}

	char ch = str[0];
	int count = 1;
	char numCharArr[16];
	size_t i = 1, j = 0;
	for (; i < len && j < len; ++i)
	{
		if (str[i] == ch)
		{
			count++;
		}
		else
		{
			destStr[j++] = ch;
			itoa(count, numCharArr, 10);
			size_t numCharLen = strlen(numCharArr);
			for (size_t k = 0; k < numCharLen; ++k)
			{
				destStr[j++] = numCharArr[k];
			}
			ch = str[i];
			count = 1;
		}
	}
	if (j < len)
	{
		destStr[j++] = ch;
		itoa(count, numCharArr, 10);
		size_t numCharLen = strlen(numCharArr);
		for (size_t k = 0; k < numCharLen; ++k)
		{
			destStr[j++] = numCharArr[k];
		}
		destStr[j] = '\0';
	}
	if (j < len)
	{
		strcpy(str, destStr);		
	}

	delete []destStr;
}

string CompressString2(const string &str)
{
	if (str == "")
	{
		return "";
	}
	size_t len = str.length();
	char ch = str[0];
	int count = 1;
	string ansStr;
	char numCharArr[16];
	size_t i = 1;
	for ( ; i < len; )
	{
		while (str[i] == ch)
		{
			++count;
			++i;
		}
		ansStr += ch;		
		ansStr += itoa(count, numCharArr, 10);
		ch = str[i];
		count = 1;
		++i;
	}

	if (ansStr.length() < len)
	{
		return ansStr;
	}
	return str;
}

void TestCompressString()
{
	char str[256];
	strcpy(str, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
	CompressString(str);
	cout << str << endl;

	strcpy(str, "abcd");
	CompressString(str);
	cout << str << endl;

	strcpy(str, "aaaaaaaaaaaaaaabbbbbbbbbbbbb");
	CompressString(str);
	cout << str << endl;

	strcpy(str, "aabcccccaaa");
	CompressString(str);
	cout << str << endl;

}

void TestCompressString2()
{
	string str1 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	cout << CompressString2(str1) << endl;

	str1 = "abcd";
	cout << CompressString2(str1) << endl;


	str1 = "aaaaaaaaaaaaaaabbbbbbbbbbbbb";
	cout << CompressString2(str1) << endl;

	str1 = "aabcccccaaa";
	cout << CompressString2(str1) << endl;

}