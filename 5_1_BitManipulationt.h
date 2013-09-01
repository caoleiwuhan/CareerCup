#ifndef _BIT_MANI_
#define _BIT_MANI_

#include <iostream>
#include <string>

using namespace std;

const double EPSILON = 2e-31;

int BitInsert(int n, int m, int i, int j);

void TestBitManipulation();

void TestBitInsert();

void PrintDoubleBinary(double dNum);

void PrintDoubleBinary2(double dNum);

void PrintDoubleBinary3(double dNum);

void TestPrintDoubleBinary();

void PrintCharByte(unsigned char ch);

unsigned int NextNumber(unsigned int num);

inline int GetBitOfIndex(unsigned int num, int index);

// 
inline void SetBitOfIndex(unsigned int &num, int index);

inline void ClearBitOfIndex(unsigned int &num, int index);

void TestNextNumber();

void TestPrevNumber();

unsigned int PrevNumber(unsigned int num);

void ReverseBit(unsigned int &num, int from, int to);

int DiffBitNum(int num1, int num2);

int NumberOfOne(unsigned num);

void TestDiffBitNum();

void SwapBit(int &num);

int SwapBit2(int num);

void DrayLine(char screen[], int width, int x1, int x2, int y);


#endif