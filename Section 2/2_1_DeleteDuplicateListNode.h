/*
	Write code to remove duplicates from an unsorted linked list.
	FOLLOW UP
	How would you solve this problem if a temporary buffer is not allowed?
*/

#ifndef _DELETE_DUPLICATE_LIST_NODE_
#define _DELETE_DUPLICATE_LIST_NODE_

struct ListNode
{
	int key;
	ListNode *next;

	ListNode(int _key, ListNode *_next) : key(_key), next(_next)
	{}
	ListNode(int _key) : key(_key), next(NULL) {}
};

void DeleteDuplicateListNode(ListNode *head);

void DeleteDuplicateListNode2(ListNode *head);

void DeleteNode(ListNode *pPrev, ListNode *pDel);

void TestDeleteDuplicateListNode();

void PrintList(ListNode *pList);

void DestroyList(ListNode *pList);

#endif