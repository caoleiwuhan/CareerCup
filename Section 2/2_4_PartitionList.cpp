#include <iostream>

#include "2_4_PartitionList.h"

using namespace std;

void PartitionList(ListNode *pHead, int x)
{
	if (pHead == NULL)
	{
		return;
	}
	ListNode *p1 = pHead;
	ListNode *p2 = pHead;
	// 第一个指针，找到比x大的位置
	while (p1 && p1->key <= x)
	{
		p1 = p1->next;
	}
	if (p1 == NULL)
		return;
	p2 = p1->next;

	while (p2)
	{
		if (p2->key > x)
		{
			p2 = p2->next;
		}
		else
		{
			/*if (p1->key > x)
			{
			int tmp = p1->key;
			p1->key = p2->key;
			p2->key = tmp;
			}*/
			int tmp = p1->key;
			p1->key = p2->key;
			p2->key = tmp;
			p1 = p1->next;
			p2 = p2->next;
		}
	}
}

void PartitionList2(ListNode *pHead, int x)
{
	if (pHead == NULL)
		return;
	ListNode *p1 = pHead;
	ListNode *pPrev = NULL;
	// 找到第一个大于的位置
	while (p1 && p1->key < x)
	{
		pPrev = p1;
		p1 = p1->next;
	}
	ListNode *pParent = pPrev;
	while (p1)
	{
		if (p1->key >= x)
		{
			pParent = p1;
			p1 = p1->next;
		}
		else
		{
			ListNode *pTmp = p1;
			pParent->next = p1->next;
			p1 = pParent->next;
			if (pPrev == NULL)
			{
				pTmp->next = pHead;
				pHead = pTmp;
			}
			else
			{
				pTmp->next = pPrev->next;
				pPrev->next = pTmp;
			}
			pPrev = pTmp;
		}
	}
	/*
	if (head == NULL)
	return NULL;

	ListNode *p1 = head;
	ListNode *pPrev = NULL;
	while (p1 && p1->val < x)
	{
	pPrev = p1;
	p1 = p1->next;
	}
	ListNode *pParent = pPrev;
	while (p1)
	{
	if (p1->val >= x)
	{
	pParent = p1;
	p1 = p1->next;
	}
	else
	{
	ListNode *pTmp = p1;
	pParent->next = p1->next;
	p1 = pParent->next;
	if (pPrev == NULL)
	{
	pTmp->next = head;
	head = pTmp;
	}
	else
	{
	pTmp->next = pPrev->next;
	pPrev->next = pTmp;
	}
	pPrev = pTmp;
	}
	}
	return head;
	*/

}

void TestPartitionList()
{
	//ListNode *n7 = new ListNode(1, NULL);
	ListNode *n6 = new ListNode(2, NULL);
	ListNode *n5 = new ListNode(5, n6);
	ListNode *n4 = new ListNode(2, n5);
	ListNode *n3 = new ListNode(3, n4);
	ListNode *n2 = new ListNode(4, n3);
	ListNode *n1 = new ListNode(1, n2);

	PrintList(n1);
	PartitionList2(n1, 3);
	PrintList(n1);
}

/*
// delete dublicate listNode

class Solution {
public:
ListNode *deleteDuplicates(ListNode *head) 
{
// Start typing your C/C++ solution below
// DO NOT write int main() function
if (head == NULL)
return NULL;

ListNode *p1 = head;
ListNode *p2 = p1->next;
while (p2)
{
ListNode *pTmp = head;
bool bDel = false;
while (pTmp != p2)
{
if (pTmp->val == p2->val)
{
bDel = true;
break;
}
pTmp = pTmp->next;
}
if (!bDel)
{
p1 = p2;
p2 = p2->next;
}
else
{
p1->next = p2->next;
ListNode *pDelNode = p2;
p2 = p1->next;
delete pDelNode;
}
}

return head;
}
};

*/


ListNode *deleteDuplicates(ListNode *head) 
{
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if (head == NULL)
	{
		return NULL;
	}
	ListNode *pAns = NULL;
	ListNode *pCur = NULL;
	ListNode *p1 = head;
	ListNode *p2 = p1;
	// find first that is only one 
	int count = 0;
	while (p2 != NULL)
	{
		while (p1 && p2 && (p1->key == p2->key))
		{
			++count;
			p2 = p2->next;
		}
		if (count == 1)
		{
			if (pAns == NULL)
			{
				pAns = p1;
				pCur = p1;
				pCur->next = NULL;
			}             
			else
			{
				pCur->next = p1;
				pCur = p1;
				pCur->next = NULL;
			}
		}
		if (count > 1)
		{
			ListNode *pDel = p1;
			while (pDel != p2)
			{                   
				p1 = p1->next;
				delete pDel;
				pDel = p1;
			}
		}
		p1 = p2;
		count = 0;
	}
	return pAns;       
}

/*
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL)
        {
            return NULL;
        }
        ListNode *pAns = NULL;
        ListNode *pCur = NULL;
        ListNode *p1 = head;
        ListNode *p2 = p1;
        // find first that is only one 
        int count = 0;
        while (p2 != NULL)
        {
            while (p1 && p2 && (p1->val == p2->val))
            {
                ++count;
                p2 = p2->next;
            }
            if (count == 1)
            {
                if (pAns == NULL)
                {
                    pAns = p1;
                    pCur = p1;
                    pCur->next = NULL;
                }             
                else
                {
                    pCur->next = p1;
                    pCur = p1;
                    pCur->next = NULL;
                }
            }
            if (count > 1)
            {
               ListNode *pDel = p1;
               while (pDel != p2)
               {                   
                   p1 = p1->next;
                   delete pDel;
                   pDel = p1;
               }
            }
            p1 = p2;
            count = 0;
        }
        return pAns;       
    }
};
*/
void TestDeleteDuplicates()
{
	/*ListNode *n7 = new ListNode(5, NULL);
	ListNode *n6 = new ListNode(4, n7);
	ListNode *n5 = new ListNode(3, n6);
	ListNode *n4 = new ListNode(3, n5);*/
	ListNode *n3 = new ListNode(2, NULL);
	ListNode *n2 = new ListNode(2, n3);
	ListNode *n1 = new ListNode(1, n2);

	PrintList(n1);
	ListNode *pAns = deleteDuplicates(n1);
	PrintList(pAns);
}

/*
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if (head == NULL)
            return NULL;
            
        ListNode *p1 = head;
        while (n--)
        {
            p1 = p1->next;
        }
        ListNode *pPrev = NULL;
        ListNode *p2 = head;
        while (p1)
        {
            p1 = p1->next;
            pPrev = p2;
            p2 = p2->next;            
        }
        
        if (pPrev == NULL)
        {
            head = head->next;
            delete p2;
        }
        else
        {
            pPrev->next = p2->next;
            delete p2;
        }
        return head;
    }
};
*/
