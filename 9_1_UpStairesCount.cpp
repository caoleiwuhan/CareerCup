#include <iostream>

#include "9_1_UpStairesCount.h"

using namespace std;

int UpStairesCount(int N)
{
	if (N <= 0)
		return 0;
	if (N == 1)
		return 1;
	if (N == 2)
		return 2;
	if (N == 3)
		return 4;
	int num1 = 1;
	int num2 = 2;
	int num3 = 4;
	// f(n) = f(n-1) + f(n-2) + f(n-3)
	for (int i = 4; i <= N; ++i)
	{
		int tmp = num3 + num2 + num1;
		num1 = num2;
		num2 = num3;
		num3 = tmp;
	}
	return num3;
}

void TestUpStairesCount()
{
	//cout << UpStairesCount(1) << endl;
	//cout << UpStairesCount(2) << endl;
	//cout << UpStairesCount(3) << endl;
	cout << UpStairesCount(4) << endl;
	cout << UpStairesCount(5) << endl;
	cout << UpStairesCount(6) << endl;
	cout << UpStairesCount(7) << endl;
	cout << UpStairesCount(8) << endl;
	cout << UpStairesCount(9) << endl;
	cout << UpStairesCount(10) << endl;
}