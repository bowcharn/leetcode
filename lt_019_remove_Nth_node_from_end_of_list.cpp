/*
Given a linked list, remove the nth node from the end of list and return 
its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 
   1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
      if(head == NULL)
	return NULL;
      if(n == 0)
	return head;

      ListNode dummy_node(0);
      dummy_node.next = head;
      ListNode* pfirst = &dummy_node;
      ListNode* psecond = &dummy_node;
      while(n--)
	pfirst = pfirst->next;
      
      while(pfirst!= NULL && pfirst->next!=NULL)
	{
	  pfirst = pfirst->next;
	  psecond = psecond->next;
	}

      psecond->next = psecond->next->next;
      return dummy_node.next;  
    }
};
