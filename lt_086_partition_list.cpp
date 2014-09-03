/*
Given a linked list and a value x, partition it such that all nodes less 
than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in 
each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/
#include <iostream>

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
    ListNode *partition(ListNode *head, int x) {
      if(head == NULL)
	return head;
      ListNode* dummy_node = new ListNode(0); 
      ListNode* pdummy_node = dummy_node;
      ListNode* pfast = head;
      ListNode* pslow = dummy_node;
      while(pfast != NULL)
	{
	  if(pfast->val < x){
	    ListNode* paddnode = pfast;
	    pfast = pfast->next;                //store pfast as original list
	    ListNode * pslow_next = pslow->next;
	    pslow->next = paddnode;
	    paddnode->next = pslow_next;
	    pslow = pslow->next; 
	    if(dummy_node->next)
	      dummy_node = pslow;
	  }
	  else
	    {
	      dummy_node->next = pfast;
	      pfast = pfast->next;
	      dummy_node = dummy_node->next;
	      dummy_node->next = NULL;
	    }
	}
      return pdummy_node->next;
    }
};


void print_list(const ListNode* head)
{
  const ListNode* phead = head;
  while(phead){
    std::cout<<phead->val<<" ";
    phead = phead->next;
  }
}
int main()
{
  ListNode* head = new ListNode(1);
  ListNode* l1 = new ListNode(4);
  ListNode* l2 = new ListNode(3);
  ListNode* l3 = new ListNode(2);
  ListNode* l4 = new ListNode(5);
  ListNode* l5 = new ListNode(2);
  head->next = l1;
  l1->next = l2;
  l2->next = l3;
  l3->next = l4;
  l4->next = l5;
  print_list(Solution().partition(head,5));
  std::cout<<std::endl;
  return 0;
}
