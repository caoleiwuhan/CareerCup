#include <iostream>

using namespace std;

void SubSet(int a[], int n);

void SubSetDFS(int a[], int n, int m, int ans[], int step, int from);

void TestSubSet();

/*
	方法2：
		n个元素一共有（1<<(n-1)种情况
*/
void SubSet2(int a[], int n);
