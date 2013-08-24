#include <iostream>

#include "2_7_IsListPalin.h"
#include <stack>

using namespace std;

/*
	1:计算链表长度
	2:如果为偶数，将后半段逆置
	3:判断是否相同
*/
bool IsListPalin(ListNode *pHead)
{
	if (pHead == NULL)
		return false;
	ListNode *pSlow = pHead;
	ListNode *pFast = pHead;
	while (pFast)
	{
		pSlow = pSlow->next;
		pFast = pFast->next;
		if (pFast == NULL)
			break;
		pFast = pFast->next;
	}
	ListNode *pReverse = ReverseList(pSlow);
	ListNode *p1 = pReverse;
	ListNode *p2 = pHead;
	bool bAns = true;
	while (p1)
	{
		if (p1->key != p2->key)
		{
			bAns = false;
			break;
		}
		p1 = p1->next;
		p2 = p2->next;
	}
	DestroyList(pReverse);

	return bAns;
}

ListNode *ReverseList(ListNode *pHead)
{
	stack<ListNode *> listStack;
	while (pHead)
	{
		listStack.push(pHead);
		pHead = pHead->next;
	}
	ListNode *pAns = NULL;
	ListNode *pCur = NULL;
	while (!listStack.empty())
	{
		ListNode *pTmp = new ListNode(listStack.top()->key, NULL);
		listStack.pop();
		if (pAns == NULL)
		{
			pCur = pTmp;
			pAns = pCur;
		}
		else
		{
			pCur->next = pTmp;
			pCur = pCur->next;
		}
	}
	return pAns;
}

void TestIsListPalin()
{
	/*ListNode *n7 = new ListNode(1, NULL);
	ListNode *n6 = new ListNode(2, n7);
	ListNode *n5 = new ListNode(7, n6);
	ListNode *n4 = new ListNode(1, NULL);*/
	ListNode *n3 = new ListNode(1, NULL);
	ListNode *n2 = new ListNode(2, n3);
	ListNode *n1 = new ListNode(1, n2);

	PrintList(n1);
	cout << IsListPalin(n1) << endl;	
}