/*	
	Write code to partition a linked list around a value x, 
	such that all nodes less than x come before all nodes greater than of equal to x.
*/

#include "2_1_DeleteDuplicateListNode.h"


void PartitionList(ListNode *pHead, int x);

void PartitionList2(ListNode *pHead, int x);

void TestPartitionList();

ListNode *deleteDuplicates(ListNode *head);

void TestDeleteDuplicates();

double findMedianSortedArrays(int A[], int m, int B[], int n);
