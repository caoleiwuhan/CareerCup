#include <iostream>

using namespace std;

/*
	1����������
	ǰi��Ǯ��ʾj������Ϊf(i,j)
	f(i,j) = 
*/
// arr�д��m����ֵ��Ǯ�ң�n��Ǯ��
// 1:f[i][j] = f[i-1][j] + f[i][j-arr[i]]
int CountOfCents1(int arr[], int m, int n);

// 2:f[i][j] = f[i-1][j] + f[i][j-k*arr[i]] (k > 0 && (j-k*arr[i] >= 0))
int CountOfCents2(int arr[], int m, int n);

// 3:��������
int CountOfCents3(int arr[], int m, int n);

int CountOfCents3Help(int **f, int arr[], int m, int n);

int CountOfCents4(int n);

int CountOfCents4Help(int n, int denom);

// 4:��������


int CountOfCents5(int arr[], int m, int n);

void TestCountOfCents();

