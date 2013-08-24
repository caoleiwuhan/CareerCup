/*
	You have two numbers represented by a linked list, where each node 
	contains a single digit. The digits are stored in reverse order, such 
	that the 1's digit is at the head of the list. Write a function that 
	adds the two numbers and returns the sum as a linked list.
	EXAMPLE
	Input: (7 -> 1 -> 6) + (5 -> 9 -> 2). That is, 617 + 295
	Output: 2 -> 1 -> 9. That is, 912.

	FOLLOW UP
	Suppose the digits are stored in forward order. Repeat the above problem.
	EXAMPLE
	Input: (6 -> 1 -> 7) + (2 -> 9 -> 5). That is, 617 + 295.
	Output: 9 -> 1 -> 2. That is, 912.
*/
#include "2_1_DeleteDuplicateListNode.h"

ListNode *TwoListSum(ListNode *p1, ListNode *p2);

void TestTwoListSum();

ListNode *TwoListSum2(ListNode *p1, ListNode *pCur1, ListNode *p2, ListNode *pCur2, int carry);

ListNode *TwoListSum3(ListNode *p1, ListNode *p2);

ListNode *TwoListSum4(ListNode *p1, ListNode *p2);