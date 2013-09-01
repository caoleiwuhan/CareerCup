#include <iostream>
#include <cassert>
#include <algorithm>

#include "1_1_UniqueCharacter.h"

using namespace std;


void TestUniqueCharacer()
{
	
	char str[256];
	
	strcpy(str, "acdefghibbjklmnopqrstuvwxyzz");
	cout << (IsStringUniqueChar4(str) ? "True" : "False") << endl;

	strcpy(str, "abcdefghijklmnopqrstuvwxyz");
	cout << (IsStringUniqueChar4(str) ? "True" : "False") << endl;

	strcpy(str, "abcdefggijklmnopprstuvwxyz");
	cout << (IsStringUniqueChar4(str) ? "True" : "False") << endl;



}

void TestBitMap()
{
	int num1 = 31;
	int byteNum = BYTENUM(num1);
	assert(byteNum == 4);
	unsigned char *bitMap = new unsigned char[byteNum];
	memset(bitMap, 0, sizeof(bitMap));
	
	SETBIT(bitMap, 0);
	assert(GETBIT(bitMap, 0) == 1);
	CLRBIT(bitMap, 0);
	assert(GETBIT(bitMap, 0) == 0);

	SETBIT(bitMap, 3);
	assert(GETBIT(bitMap, 3) == 1);
	CLRBIT(bitMap, 3);
	assert(GETBIT(bitMap, 3) == 0);

	SETBIT(bitMap, 7);
	assert(GETBIT(bitMap, 7) == 1);
	CLRBIT(bitMap, 7);
	assert(GETBIT(bitMap, 7) == 0);

	SETBIT(bitMap, 8);
	assert(GETBIT(bitMap, 8) == 1);
	CLRBIT(bitMap, 8);
	assert(GETBIT(bitMap, 8) == 0);

	SETBIT(bitMap, 15);
	assert(GETBIT(bitMap, 15) == 1);
	CLRBIT(bitMap, 15);
	assert(GETBIT(bitMap, 15) == 0);
		
	delete []bitMap;
}

bool IsStringUniqueChar(char str[])
{
	if (str == NULL)
	{
		return false;
	}
	bool bHashArr[CHAR_NUM] = {0};
	size_t len = strlen(str);
	for (size_t i = 0; i < len; ++i)
	{
		unsigned char ch = static_cast<unsigned char>(str[i]);
		if (bHashArr[ch])
		{
			return false;
		}
		bHashArr[ch] = true;
	}
	return true;
}

bool IsStringUniqueChar2(char str[])
{
	if (str == NULL)
	{
		return false;
	}
	size_t len = strlen(str);
	int byteNum = BYTENUM(CHAR_NUM);
	unsigned char *bitMap = new unsigned char[byteNum];
	if (bitMap == NULL)
	{
		cerr << "Allocate memory failed" << endl;
		exit(-1);
	}
	memset(bitMap, 0, sizeof(unsigned char) * byteNum);
	bool ans = true;
	for (size_t i = 0; i < len; ++i)
	{
		unsigned char ch = static_cast<unsigned char>(str[i]);
		if (GETBIT(bitMap, ch) == 1)
		{
			ans = false;
			break;
		}
		SETBIT(bitMap, ch);
	}
	delete []bitMap;
	return ans;
}

bool IsStringUniqueChar3(char str[])
{
	if (str == NULL)
	{
		return false;
	}
	size_t len = strlen(str);
	for (size_t i = 0; i < len; ++i)
	{
		char ch = str[i];
		for (size_t j = i + 1; j < len; ++j)
		{
			if (ch == str[j])
			{
				return false;
			}
		}
	}
	return true;
}

bool IsStringUniqueChar4(char str[])
{
	if (str == NULL)
	{
		return false;
	}
	size_t len = strlen(str);
	sort(str, str + len);
	for (size_t i = 1; i < len; ++i)
	{
		if (str[i - 1] == str[i])
		{
			return false;
		}
	}
	return true;
}