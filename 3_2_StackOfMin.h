#include <iostream>
#include <stack>

using namespace std;


class MyStack
{
public:
	void Push(int num);
	void Pop();
	int Top();
	int Min();

private:
	stack<int> s1;
	stack<int> sMin;
};

void TestStackOfMin();