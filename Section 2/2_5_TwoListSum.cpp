#include <iostream>

#include "2_5_TwoListSum.h"

#include <stack>

using namespace std;


ListNode *TwoListSum(ListNode *p1, ListNode *p2)
{
	if (p1 == NULL)
	{
		return p2;
	}
	if (p2 == NULL)
	{
		return p1;
	}
	ListNode *pAns = NULL;
	ListNode *pCur= NULL;
	ListNode *pHead1 = p1;
	ListNode *pHead2 = p2;
	int carry = 0;
	while (pHead1 && pHead2)
	{
		int tmpSum = pHead1->key + pHead2->key + carry;
		carry = tmpSum / 10;
		tmpSum %= 10;
		ListNode *pTmp = new ListNode(tmpSum, NULL);
		if (pAns == NULL)
		{
			pAns = pTmp;
			pCur = pTmp;
		}
		else
		{
			pCur->next = pTmp;
			pCur = pTmp;
		}
		pHead1 = pHead1->next;
		pHead2 = pHead2->next;
	}
	while (pHead1)
	{
		int tmpSum = pHead1->key + carry;
		carry = tmpSum / 10;
		tmpSum %= 10;
		ListNode *pTmp = new ListNode (tmpSum, NULL);
		pCur->next = pTmp;
		pCur = pTmp;
		pHead1 = pHead1->next;
	}
	while (pHead2)
	{
		int tmpSum = pHead2->key + carry;
		carry = tmpSum / 10;
		tmpSum %= 10;
		ListNode *pTmp = new ListNode (tmpSum, NULL);
		pCur->next = pTmp;
		pCur = pTmp;
		pHead2 = pHead2->next;
	}
	if (carry > 0)
	{
		ListNode *pTmp = new ListNode (1, NULL);
		pCur->next = pTmp;
		pCur = pTmp;
	}
	return pAns;
}

void TestTwoListSum()
{
	
	ListNode *n3 = new ListNode(9, NULL);
	ListNode *n2 = new ListNode(9, n3);
	ListNode *n1 = new ListNode(9, n2);
	
	ListNode *n6 = new ListNode(9, NULL);
	ListNode *n5 = new ListNode(9, n6);
	ListNode *n4 = new ListNode(9, n5);

	PrintList(n1);
	PrintList(n4);
	ListNode *pAns = TwoListSum4(n1, n4);

	PrintList(pAns);
	DestroyList(pAns);

}

ListNode *TwoListSum2(ListNode *p1, ListNode *pCur1, ListNode *p2, ListNode *pCur2, int carry)
{
	ListNode *pAns = NULL;
	if (pCur1 == NULL && pCur2 == NULL)
	{
		if (carry > 0)
		{
			pAns = new ListNode(1, NULL);
			return pAns;
		}
		else
		{
			return NULL;
		}
	}
	if (pCur1 == NULL)
	{
		int tmpSum = pCur2->key + carry;
		carry = tmpSum / 10;
		tmpSum %= 10;
		ListNode *pTmp = new ListNode(tmpSum, NULL);
	}
}

ListNode *TwoListSum3(ListNode *p1, ListNode *p2)
{
	if (p1 == NULL)
		return p2;
	if (p2 == NULL)
		return p1;

	stack<ListNode *> s1;
	while (p1)
	{
		s1.push(p1);
		p1 = p1->next;
	}

	stack<ListNode *> s2;
	while (p2)
	{
		s2.push(p2);
		p2 = p2->next;
	}
	stack<ListNode *> sAns;
	ListNode *pAns = NULL;
	ListNode *pCur= NULL;
	int carry = 0;
	while (!s1.empty() && !s2.empty())
	{
		ListNode *pTmp1 = s1.top();
		s1.pop();
		ListNode *pTmp2 = s2.top();
		s2.pop();
		int tmpSum = pTmp1->key + pTmp2->key + carry;
		carry = tmpSum / 10;
		tmpSum %= 10;
		ListNode *pNode = new ListNode(tmpSum, NULL);
		sAns.push(pNode);
	}
	while (!s1.empty())
	{
		ListNode *pTmp1 = s1.top();
		s1.pop();
		int tmpSum = pTmp1->key + carry;
		carry = tmpSum / 10;
		tmpSum %= 10;
		ListNode *pTmp = new ListNode (tmpSum, NULL);
		sAns.push(pTmp);
	}

	while (!s2.empty())
	{
		ListNode *pTmp2 = s2.top();
		s2.pop();
		int tmpSum = pTmp2->key + carry;
		carry = tmpSum / 10;
		tmpSum %= 10;
		ListNode *pTmp = new ListNode (tmpSum, NULL);
		sAns.push(pTmp);
	}
	if (carry > 0)
	{
		ListNode *pTmp = new ListNode (1, NULL);
		sAns.push(pTmp);		
	}
	pAns = sAns.top();
	sAns.pop();
	ListNode *pAnsHelp = pAns;
	while (!sAns.empty())
	{
		pAnsHelp->next = sAns.top();
		sAns.pop();
		pAnsHelp = pAnsHelp->next;
	}
	return pAns;
}

ListNode *TwoListSum4(ListNode *p1, ListNode *p2)
{
	if (p1 == NULL)
	{
		return p2;
	}
	if (p2 == NULL)
	{
		return p1;
	}
	ListNode *pAns = NULL;
	ListNode *pCur= NULL;
	int carry = 0;
	while (p1 || p2)
	{		
		int tmpSum = carry;
		if (p1)
		{
			tmpSum += p1->key;
			p1 = p1->next;
		}
		if (p2)
		{
			tmpSum += p2->key;
			p2 = p2->next;
		}
		carry = tmpSum / 10;
		tmpSum %= 10;
		ListNode *pTmp = new ListNode(tmpSum, NULL);
		if (pAns == NULL)
		{
			pAns = pTmp;
			pCur = pTmp;
		}
		else
		{
			pCur->next = pTmp;
			pCur = pTmp;
		}		
	}	
	if (carry > 0)
	{
		ListNode *pTmp = new ListNode (1, NULL);
		pCur->next = pTmp;
		pCur = pTmp;
	}
	return pAns;
}