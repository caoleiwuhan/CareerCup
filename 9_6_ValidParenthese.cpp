#include <iostream>
#include <string>

#include "9_6_ValidParenthese.h"

using namespace std;

// ������DFS��Ҳ������stack
void PrintValidparenthese(int num)
{
	if (num <= 0)
		return;
	string str;
	str.reserve(num * 2 + 1);
	DFS(str, num * 2, 0, 0);
}

void DFS(string &str, int N, int left, int step)
{
	if (step == N)
	{		
		cout << str << endl;
	}
	else
	{
		// ��ǰ�����ŵ�����
		int right = step - left;
		// �����Ż������ŵ�������
		int total = N / 2;
		// 1�����ȼ���������
		if (left < total)
		{
			//str[step] = '(';
			str += '(';
			DFS(str, N, left + 1, step + 1);
			str.erase(str.size() - 1, 1);
		}
		// 2����������
		if (right < left)
		{
			//str[step + 1] = ')';
			str += ')';
			DFS(str, N, left, step + 1);
			str.erase(str.size() - 1, 1);
		}
	}
}

void TestPrintValidparenthese()
{
	PrintValidparenthese(3);

}