#include <iostream>
#include <cassert>

#include "2_2_NthNodeOfList.h"

using namespace std;

ListNode *NthNodeOfList(ListNode *pHead, int k)
{
	if (pHead == NULL || k <= 0)
		return NULL;
	ListNode *p1 = pHead;
	ListNode *p2 = pHead;
	for (int i = 0; i < k; ++i)
	{
		if (p2 == NULL)
		{
			return NULL;
		}
		p2 = p2->next;
	}
	while (p2)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}

void TestNthNodeOfList()
{
	ListNode *n7 = new ListNode(7, NULL);
	ListNode *n6 = new ListNode(6, n7);
	ListNode *n5 = new ListNode(5, n6);
	ListNode *n4 = new ListNode(4, n5);
	ListNode *n3 = new ListNode(3, n4);
	ListNode *n2 = new ListNode(2, n3);
	ListNode *n1 = new ListNode(1, n2);

	PrintList(n1);
	cout <<"1:" << NthNodeOfList(n1, 1)->key << endl;
	cout <<"2:" << NthNodeOfList(n1, 2)->key << endl;
	cout <<"3:" << NthNodeOfList(n1, 3)->key << endl;
	cout <<"4:" << NthNodeOfList(n1, 4)->key << endl;
	cout <<"5:" << NthNodeOfList(n1, 5)->key << endl;
	cout <<"6:" << NthNodeOfList(n1, 6)->key << endl;
	cout <<"7:" << NthNodeOfList(n1, 7)->key << endl;
	assert(NthNodeOfList(n1, 8) == NULL);
	
}