#include <iostream>
#include <set>

#include "2_1_DeleteDuplicateListNode.h"

using namespace std;

void DeleteDuplicateListNode(ListNode *head)
{
	ListNode *pCur = head;
	while (pCur != NULL)
	{
		ListNode *pNext = pCur->next;
		ListNode *pPrev = pCur;
		while (pNext != NULL)
		{
			if (pCur->key == pNext->key)
			{
				DeleteNode(pPrev, pNext);
				pNext = pPrev->next;
			}
			else
			{
				pPrev = pNext;
				pNext = pNext->next;
			}
		}
		pCur = pCur->next;
	}	
}

void DeleteNode(ListNode *pPrev, ListNode *pDel)
{
	pPrev->next = pDel->next;
	delete pDel;
}

void TestDeleteDuplicateListNode()
{
	ListNode *n7 = new ListNode(2, NULL);
	ListNode *n6 = new ListNode(2, n7);
	ListNode *n5 = new ListNode(2, n6);
	ListNode *n4 = new ListNode(2, n5);
	ListNode *n3 = new ListNode(2, n4);
	ListNode *n2 = new ListNode(2, n3);
	ListNode *n1 = new ListNode(2, n2);

	PrintList(n1);
	DeleteDuplicateListNode2(n1);
	PrintList(n1);

}

void PrintList(ListNode *pList)
{
	if (!pList)
		return;

	cout << pList->key;
	pList = pList->next;

	while (pList)
	{
		cout << "->" << pList->key;
		pList = pList->next;
	}
	cout << endl;
}

void DeleteDuplicateListNode2(ListNode *head)
{
	if (!head)
		return;

	set<int> nSet;
	ListNode *pCur = head->next;
	nSet.insert(head->key);
	ListNode *pPrev = head;
	while (pCur)
	{
		if (nSet.find(pCur->key) != nSet.end())
		{
			DeleteNode(pPrev, pCur);
			pCur = pPrev->next;
		}
		else
		{
			nSet.insert(pCur->key);
			pPrev = pCur;
			pCur = pCur->next;
		}
	}
}

void DestroyList(ListNode *pList)
{
	while (pList)
	{
		ListNode *pTmp = pList;
		pList = pList->next;
		delete pTmp;
	}
}