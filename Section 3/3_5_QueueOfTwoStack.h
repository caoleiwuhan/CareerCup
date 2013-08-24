/*
	Implement a MyQueue class which implements a queue using two stacks.
*/

#include <stack>
using namespace std;
template <typename T>
class MyQueue
{
public:
	void Enqueue(const T& val);
	T &Dequeue() const;
	T &Dequeue();
private:
	stack<T> s1;
	stack<T> s2;

	void DequeueHelp();
};

void TestQueueOfTwoStack();