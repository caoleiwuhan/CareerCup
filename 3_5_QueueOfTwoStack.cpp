#include <iostream>

#include "3_5_QueueOfTwoStack.h"

using namespace std;

template<typename T>
void MyQueue<T>::Enqueue(const T& val)
{
	s1.push(val);
}

template<typename T>
T & MyQueue<T>::Dequeue() const
{
	DequeueHelp();
	if (s2.empty())
	{
		throw new exception("Empty!");
	}
	T &ans = s2.top();
	s2.pop();
	return ans;
}

template<typename T>
T & MyQueue<T>::Dequeue()
{
	DequeueHelp();
	if (s2.empty())
	{
		throw new exception("Empty!");
	}
	T &ans = s2.top();
	s2.pop();
	return ans;
}

template<typename T>
void MyQueue<T>::DequeueHelp()
{
	if (s2.empty())
	{
		while (!s1.empty())
		{
			T &tmp = s1.top();
			s1.pop();
			s2.push(tmp);
		}
	}
}


void TestQueueOfTwoStack()
{
	MyQueue<int> q;
	q.Enqueue(1);
	q.Enqueue(2);
	int num = q.Dequeue();
	cout << num << endl;

	q.Enqueue(3);
	q.Enqueue(4);
	num = q.Dequeue();
	cout << num << endl;

	q.Enqueue(5);

	num = q.Dequeue();
	cout << num << endl;

	num = q.Dequeue();
	cout << num << endl;

	num = q.Dequeue();
	cout << num << endl;

}