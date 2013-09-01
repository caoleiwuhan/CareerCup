#include <iostream>
#include <cassert>

#include "3_2_StackOfMin.h"

using namespace std;

void MyStack::Push(int num)
{
	s1.push(num);
	if (sMin.empty() || num <= sMin.top())
	{
		sMin.push(num);
	}
}

void MyStack::Pop()
{
	if (s1.empty())
	{
		throw new exception("The stack is empty!");		
	}
	int num = s1.top();
	s1.pop();
	if (num == sMin.top())
	{
		sMin.pop();
	}
}

int MyStack::Top()
{
	if (s1.empty())
	{
		throw new exception("The stack is empty!");		
	}
	int num = s1.top();	
	return num;
}

int MyStack::Min()
{
	if (s1.empty())
	{
		throw new exception("The stack is empty!");		
	}
	return sMin.top();
}

void TestStackOfMin()
{
	MyStack s;
	s.Push(10);
	assert(s.Min() == 10);
	assert(s.Top() == 10);

	s.Push(5);
	assert(s.Min() == 5);
	assert(s.Top() == 5);

	s.Push(8);
	assert(s.Min() == 5);
	assert(s.Top() == 8);

	s.Push(5);

	assert(s.Min() == 5);
	assert(s.Top() == 5);

	s.Push(3);
	assert(s.Min() == 3);
	assert(s.Top() == 3);

	s.Pop();
	assert(s.Min() == 5);
	assert(s.Top() == 5);

	s.Pop();
	assert(s.Min() == 5);
	assert(s.Top() == 8);
}