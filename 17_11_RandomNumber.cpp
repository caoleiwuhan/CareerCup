#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

// 0-4
int Rand5()
{
	Sleep(128);
	srand(time(NULL));
	int num = rand();
	return (num % 5);
}

int Rand7()
{
	// ����0��24��һ��25������ֻҪ0��20����21����
	int num = Rand5() * 5 + Rand5();
	while (num > 20)
	{
		num = Rand5() * 5 + Rand5();
	}
	num /= 3;
	return num;
}

void TestRand()
{
	for (int i = 0; i < 10; ++i)
	{
		cout << Rand7() << endl;
	}
}