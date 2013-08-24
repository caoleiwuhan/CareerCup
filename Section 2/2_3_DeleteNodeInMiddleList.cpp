#include <iostream>

#include "2_3_DeleteNodeInMiddleList.h"

using namespace std;

// must make sure that the node is not the tail of the list
void DeleteNodeInMiddleList(ListNode *pDelNode)
{
	if (pDelNode == NULL)
		return;

	ListNode *pTmp = pDelNode->next;
	pDelNode->key = pTmp->key;
	pDelNode->next = pTmp->next;

	delete pTmp;
}

void TestDeleteNodeInMiddleList()
{
	ListNode *n7 = new ListNode(7, NULL);
	ListNode *n6 = new ListNode(6, n7);
	ListNode *n5 = new ListNode(5, n6);
	ListNode *n4 = new ListNode(4, n5);
	ListNode *n3 = new ListNode(3, n4);
	ListNode *n2 = new ListNode(2, n3);
	ListNode *n1 = new ListNode(1, n2);

	PrintList(n1);
	DeleteNodeInMiddleList(n6);
	PrintList(n1);
}