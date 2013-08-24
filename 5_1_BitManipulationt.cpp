#include <iostream>

#include "5_1_BitManipulationt.h"

using namespace std;

int BitInsert(int n, int m, int i, int j)
{
	if (i < 0 || j < i)
		return 0;
	int mask = ~0;
	mask <<= (i + j - 1);
	int m2 = (1 << i) - 1;
	mask |= m2;

	n &= mask;

	m <<= i;

	m &= (~mask);

	n |= m;

	return n;
}

void TestBitInsert()
{
	int n = (1 << 10) + 8;
	int m = 21 + 32 + 64;
	cout << BitInsert(n, m, 2, 6) << endl;
}

void TestBitManipulation()
{
	//TestBitInsert();
	//TestPrintDoubleBinary();
	//TestNextNumber();
	//TestPrevNumber();
	TestDiffBitNum();

}

void PrintDoubleBinary(double dNum)
{
	if (dNum >= 1.0)
		return;
	unsigned char *pCh = (unsigned char *)(&dNum);
	for (int i = 0; i < 4; ++i)
	{
		PrintCharByte(*pCh++);
	}
}

void TestPrintDoubleBinary()
{
	double n1 = 0.625;
	//PrintDoubleBinary(n1);
	PrintDoubleBinary3(n1);

	double n2 = 0.8888888;
	PrintDoubleBinary3(n2);
}

void PrintCharByte(unsigned char ch)
{
	unsigned char mask = 1;
	for (int i = 0; i < 8; ++i)
	{
		cout << (ch & mask);
		ch >>= 1;
	}
}

void PrintDoubleBinary2(double dNum)
{
	double tmp = 0.5;
	int count = 0;
	string ans = "";
	while (dNum > EPSILON && count < 32)
	{
		if (dNum >= tmp)
		{
			ans += '1';
			dNum -= tmp;
		}
		else
		{
			ans += '0';
		}
		tmp /= 2.0;
		++count;
	}
	if (count >= 32)
	{
		cout << "ERROR" << endl;
	}
	else
	{
		cout << ans << endl;
	}	
}

void PrintDoubleBinary3(double dNum)
{
	string ans = "";
	while (true)
	{
		if (ans.size() > 32)
		{
			cout << "ERROR" << endl;
			break;
		}
		dNum *= 2.0;

		if (dNum >= 1.0)
		{
			ans += '1';
			dNum -= 1;
		}
		else
		{
			ans += '0';
		}
		if (dNum < EPSILON)
		{
			cout << ans << endl;
			break;
		}
	}
}

unsigned int NextNumber(unsigned int num)
{
	// 1.从后向前找到第一个01，位置为i
	// 2.从后往前找到第一个1，与找到的0互换
	// 3.将剩下的（i后面的）逆序
	int i = 1;
	for (; i < 32; ++i)
	{
		int b1 = GetBitOfIndex(num, i - 1);
		int b2 = GetBitOfIndex(num, i);
		if (b1 == 1 && b2 == 0)
		{
			break;
		}
	}
	if (i == 32)
	{ // 此时num已经是最大的了
		return num;
	}
	int j = 0;
	for (; j < 32; ++j)
	{
		if (GetBitOfIndex(num, j) & 1)
			break;
	}
	// 将i和j互换
	SetBitOfIndex(num, i);
	ClearBitOfIndex(num, j);
	
	// 从0到i-1逆置

	ReverseBit(num, 0, i - 1);

	return num;
}

inline int GetBitOfIndex(unsigned int num, int index)
{
	return (((num & (1 << index)) >> index) & 1);
}

inline void SetBitOfIndex(unsigned int &num, int index)
{
	num |= (1 << index);
}

inline void ClearBitOfIndex(unsigned int &num, int index)
{
	num &= (~(1 << index));
}

void ReverseBit(unsigned int &num, int from, int to)
{
	int size = (to - from + 1) / 2;
	for (int i = 0; i < size; ++i)
	{
		if (GetBitOfIndex(num, from + i) != GetBitOfIndex(num, to - i))
		{
			num ^= (1 << (from + i));
			num ^= (1 << (to - i));
		}
	}
}

void TestNextNumber()
{
	int num = 3;
	for (int i = 0; i < 16; ++i)
	{
		cout << num << endl;
		num = NextNumber(num);
	}
}

unsigned int PrevNumber(unsigned int num)
{
	// 1.从后向前找到第一个10，位置为i
	// 2.从后往前找到第一个1，与找到的0互换
	// 3.将剩下的（i后面的）逆序
	int i = 1;
	for (; i < 32; ++i)
	{
		int b1 = GetBitOfIndex(num, i - 1);
		int b2 = GetBitOfIndex(num, i);
		if (b1 == 0 && b2 == 1)
		{
			break;
		}
	}
	if (i == 32)
	{ // 此时num已经是最大的了
		return num;
	}
	int j = 0;
	for (; j < 32; ++j)
	{
		if ((GetBitOfIndex(num, j) & 1) == 0)
			break;
	}
	// 将i和j互换
	ClearBitOfIndex(num, i);
	SetBitOfIndex(num, j);
	
	// 从0到i-1逆置

	ReverseBit(num, 0, i - 1);

	return num;
}

void TestPrevNumber()
{
	unsigned int num = 24;
	while (num != 3)
	{
		num = PrevNumber(num);
		cout << num << endl;
	}
}

int DiffBitNum(int num1, int num2)
{
	unsigned diffBit = num1 ^ num2;
	return NumberOfOne(diffBit);
}

int NumberOfOne(unsigned num)
{
	int ans = 0;
	while (num != 0)
	{
		++ans;
		num &= (num - 1);
	}
	return ans;
}


void TestDiffBitNum()
{
	int num1 = 31;
	int num2 = 14;
	cout << DiffBitNum(num1, num2) << endl;

}


void SwapBit(int &num)
{
	unsigned mask1 = 0xAAAAAAAA;
	unsigned num1 = num & mask1;

	num >>= 1;
	unsigned mask2 = 0x55555555;
	num &= mask2;

	num |= num1;
}

int SwapBit2(int num)
{
	return ((((num & 0xAAAAAAAA) >> 1) & 0x55555555) | ((num & 0x55555555) << 1));
}


// (x1, y)->(x2,y)
void DrayLine(char screen[], int width, int x1, int x2, int y)
{
	int start = x1 * width + y;
	int end = x2 * width + y;
	for (int i = start; i <= end; i += width)
	{
		screen[i / 8] |= (1 << (i % 8));
	}
}