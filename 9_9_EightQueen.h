#include <iostream>

using namespace std;

int QueenNum(int n);

// step:��ǰ���ڴ������
// arr[i]:��i�зŵ���arr[i]��λ��
int QueenDFS(int arr[], int n, int step);

// ����step�еĻʺ����λ��pos�Ƿ����
bool QueenOK(int arr[], int n, int step, int pos);

void PrintBoard(int arr[], int n);

void TestQueenNum();

