#include <iostream>

#include "1_8_SubStringOfRotate.h"

using namespace std;

bool IsRotateString(const string &str1, const string &str2)
{
	string buildStr = str1 + str1;
	if (buildStr.find(str2) != string::npos)
	{
		return true;
	}
	return false;
}

void TestIsRotateString()
{
	string str1 = "waterbottle";
	string str2 = "erbottlewat";
	cout << IsRotateString(str1, str2) << endl;
}