#include <iostream>

using namespace std;

void Reverse(char *str)
{
	if (str == NULL)
		return;
	char *pStart = str;
	char *pEnd = str + strlen(str) - 1;

	while (pStart < pEnd)
	{
		swap(*pStart, *pEnd);
		/*char ch = *pStart;
		*pStart = *pEnd;
		*pEnd = ch;*/
		++pStart;
		--pEnd;
	}
}

void TestReverseString()
{
	char str[256];	
	strcpy(str, "abc");
	Reverse(str);
	cout << str << endl;
}