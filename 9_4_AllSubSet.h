#include <iostream>

using namespace std;

void SubSet(int a[], int n);

void SubSetDFS(int a[], int n, int m, int ans[], int step, int from);

void TestSubSet();

/*
	����2��
		n��Ԫ��һ���У�1<<(n-1)�����
*/
void SubSet2(int a[], int n);
