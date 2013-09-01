#include <iostream>

#include "3_6_SortStack.h"

using namespace std;

// push, pop, peek, and isEmpty.

void SortStack(stack<int> &s)
{
	SortStackHelp(s, s.size());
}

void SortStackHelp(stack<int> &s, int size)
{
	if (size <= 1)
	{
		return;
	}

	stack<int> sHelp;
	int minNum = 0x7FFFFFFF;
	int count = 0;
	for (int i = 0; i < size; ++i)
	{
		int num = s.top();
		s.pop();
		sHelp.push(num);
		//minNum = min(minNum, num);
		if (num == minNum)
		{
			++count;
		}
		if (num < minNum)
		{
			minNum = num;
			count = 1;
		}
	}
	for (int i = 0; i < count; ++i)
	{
		s.push(minNum);
	}
	while (!sHelp.empty())
	{
		int num = sHelp.top();
		sHelp.pop();
		if (num != minNum)
		{
			s.push(num);
		}
	}
	SortStackHelp(s, size - count);
}

void TestSortStack()
{
	stack<int> s;
	s.push(3);
	s.push(1);
	s.push(2);
	s.push(5);
	s.push(2);
	s.push(3);
	s.push(2);
	s.push(1);

	PrintStack(s);

	SortStack2(s);

	PrintStack(s);
}

void PrintStack(stack<int> &s)
{
	stack<int> sHelp;
	while (!s.empty())
	{
		int num = s.top();
		s.pop();
		sHelp.push(num);
		cout << num << " ";
	}
	cout << endl;
	while (!sHelp.empty())
	{
		int num = sHelp.top();
		sHelp.pop();
		s.push(num);
	}
}
/*
	用一个辅助栈s2：并维持s2中从栈顶到栈底是从小到大的顺序
	不断从s中取数，如果小于s2
*/
void SortStack2(stack<int> &s)
{
	stack<int> s2;
	while (!s.empty())
	{
		int tmp = s.top();
		s.pop();
		if (s2.empty() || s2.top() >= tmp)
		{
			s2.push(tmp);
		}
		else
		{
			while (!s2.empty() && s2.top() < tmp)
			{
				s.push(s2.top());
				s2.pop();
			}
			s2.push(tmp);
		}
	}
	while (!s2.empty())
	{
		s.push(s2.top());
		s2.pop();
	}
}