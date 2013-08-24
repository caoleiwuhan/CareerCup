#include <iostream>

#include "2_6_BeginningLoopNode.h"

using namespace std;


ListNode *BeginningLoopNode(ListNode *pHead)
{
	if (pHead == NULL)
		return NULL;
	// ÊÇ·ñÓÐ»·
	ListNode *p1 = pHead;	
	ListNode *p2 = pHead->next;
	if (p2 == NULL)
		return NULL;
	p1 = p1->next;
	p2 = p2->next;

	while (p2 != NULL)
	{
		if (p1 == p2)
		{
			break;
		}
		p1 = p1->next;
		p2 = p2->next;
		if (p2 == NULL)
		{
			return NULL;
		}
		p2 = p2->next;
	}
	if (p2 == NULL)
	{
		return NULL;
	}
	p1 = pHead;
	while (p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}

void TestBeginningLoopNode()
{	
	//ListNode *n6 = new ListNode(6, n3);
	ListNode *n5 = new ListNode(5, NULL);
	ListNode *n4 = new ListNode(4, n5);
	ListNode *n3 = new ListNode(3, n4);
	ListNode *n2 = new ListNode(2, n3);
	ListNode *n1 = new ListNode(1, n2);

	n5->next = n3;

	cout << BeginningLoopNode(n1)->key << endl;

	
}
