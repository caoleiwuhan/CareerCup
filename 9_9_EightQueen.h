#include <iostream>

using namespace std;

int QueenNum(int n);

// step:当前正在处理的行
// arr[i]:第i行放到了arr[i]的位置
int QueenDFS(int arr[], int n, int step);

// 将第step行的皇后放在位置pos是否合适
bool QueenOK(int arr[], int n, int step, int pos);

void PrintBoard(int arr[], int n);

void TestQueenNum();

