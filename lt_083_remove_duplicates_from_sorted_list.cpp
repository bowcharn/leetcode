/*
Given a sorted linked list, delete all duplicates such that 
each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
      ListNode* ret_head = head;
      ListNode* cur_position = head;
      ListNode* scan_position = head;
      
      if(head == NULL)
	return ret_head;
      
      while(scan_position != NULL)
	{
	  if(scan_position->val > cur_position->val)
	    {
	      cur_position->next = scan_position;
	      cur_position = scan_position;
	    }
	      

	  scan_position = scan_position->next;
	    
	}
      cur_position->next = NULL;
      
      return ret_head;
      
    }
};
