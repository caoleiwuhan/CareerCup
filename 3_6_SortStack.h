#include <stack>

using namespace std;

/*
	Write a program to sort a stack in ascending order (with biggest items on top). 
	You may use additional stacks to hold items, but you may not copy the elements 
	into any other data structure (such as an array). The stack supports the 
	following operations: push, pop, peek, and isEmpty.
*/

void SortStack(stack<int> &s);

void SortStack2(stack<int> &s);

void SortStackHelp(stack<int> &s, int size);

void TestSortStack();

void PrintStack(stack<int> &s);