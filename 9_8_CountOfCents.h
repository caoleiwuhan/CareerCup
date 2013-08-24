#include <iostream>

using namespace std;

/*
	1：背包问题
	前i种钱表示j，总数为f(i,j)
	f(i,j) = 
*/
// arr中存放m中面值的钱币，n总钱数
// 1:f[i][j] = f[i-1][j] + f[i][j-arr[i]]
int CountOfCents1(int arr[], int m, int n);

// 2:f[i][j] = f[i-1][j] + f[i][j-k*arr[i]] (k > 0 && (j-k*arr[i] >= 0))
int CountOfCents2(int arr[], int m, int n);

// 3:记忆数组
int CountOfCents3(int arr[], int m, int n);

int CountOfCents3Help(int **f, int arr[], int m, int n);

int CountOfCents4(int n);

int CountOfCents4Help(int n, int denom);

// 4:滚动数组


int CountOfCents5(int arr[], int m, int n);

void TestCountOfCents();

