#include <iostream>
#include <cassert>
#include <algorithm>

#include "1_1_UniqueCharacter.h"
#include "1_3_TwoPermutation.h"


using namespace std;

bool IsTwoStringPermutation1(char str1[], char str2[])
{
	if (str1 == NULL && str2 == NULL)
	{
		return true;
	}
	if (str1 == NULL || str2 == NULL)
	{
		return false;
	}
	size_t len1 = strlen(str1);
	size_t len2 = strlen(str2);
	if (len1 != len2)
	{
		return false;
	}
	int hashMap1[CHAR_NUM];
	memset(hashMap1, 0, sizeof(hashMap1));
	int hashMap2[CHAR_NUM];
	memset(hashMap2, 0, sizeof(hashMap2));
	for (size_t i = 0; i < len1; ++i)
	{
		hashMap1[static_cast<unsigned char>(str1[i])]++;
	}
	for (size_t i = 0; i < len2; ++i)
	{
		hashMap2[static_cast<unsigned char>(str2[i])]++;
	}
	for (int i = 0; i < CHAR_NUM; ++i)
	{
		if (hashMap1[i] != hashMap2[i])
		{
			return false;
		}
	}
	return true;
}


void TestIsTwoStringPermutation()
{
	char str1[256];
	char str2[256];
	strcpy(str1, "aabc");
	strcpy(str2, "abca");
	assert(IsTwoStringPermutation3(str1, str2) == 1);

	strcpy(str1, "abc");
	strcpy(str2, "abca");
	assert(IsTwoStringPermutation3(str1, str2) == 0);

	strcpy(str1, "");
	strcpy(str2, "abca");
	assert(IsTwoStringPermutation3(str1, str2) == 0);

	strcpy(str1, "aabcsssss");
	strcpy(str2, "asbscsssa");
	assert(IsTwoStringPermutation3(str1, str2) == 1);
}

bool IsTwoStringPermutation2(char str1[], char str2[])
{
	if (str1 == NULL && str2 == NULL)
	{
		return true;
	}
	if (str1 == NULL || str2 == NULL)
	{
		return false;
	}
	size_t len1 = strlen(str1);
	size_t len2 = strlen(str2);
	if (len1 != len2)
	{
		return false;
	}
	sort(str1, str1 + len1);
	sort(str2, str2 + len2);
	for (size_t i = 0; i < len1; ++i)
	{
		if (str1[i] != str2[i])
		{
			return false;
		}
	}
	return true;
}

bool IsTwoStringPermutation3(char str1[], char str2[])
{
	if (str1 == NULL && str2 == NULL)
	{
		return true;
	}
	if (str1 == NULL || str2 == NULL)
	{
		return false;
	}
	size_t len1 = strlen(str1);
	size_t len2 = strlen(str2);
	if (len1 != len2)
	{
		return false;
	}
	int hashMap[CHAR_NUM];
	memset(hashMap, 0, sizeof(hashMap));
	
	for (size_t i = 0; i < len1; ++i)
	{
		hashMap[(str1[i])]++;
	}
	for (size_t i = 0; i < len2; ++i)
	{
		char ch = str2[i];
		if (hashMap[ch] == 0)
		{
			return false;
		}
		hashMap[ch]--;
	}
	
	return true;
}