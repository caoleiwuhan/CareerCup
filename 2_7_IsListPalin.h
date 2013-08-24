/*
	Implement a function to check if a linked list is a palindrome.
*/
#include "2_1_DeleteDuplicateListNode.h"

bool IsListPalin(ListNode *pHead);

void TestIsListPalin();

// 逆置list，但不破坏它，而是重新生成一个
ListNode *ReverseList(ListNode *pHead);