/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
      if(head == NULL)
	return NULL;

      ListNode* ret_head = new ListNode(0);
      ListNode* phead = ret_head;
      ListNode* pfirst = head;
      ListNode* psecond = head->next;
      while(pfirst != NULL)
	{
	  if(psecond == NULL)	   
	    {
	      phead->next = pfirst;
	      break;
	    }
	      
	  else{
	    ListNode* store_ptr = psecond->next;
	    phead->next = psecond;
	    phead = phead->next;

	    pfirst -> next = store_ptr;

	    phead->next = pfirst;
	    phead = phead->next;

	    pfirst = store_ptr;
	     if(pfirst == NULL) 

		break;	
	     
	    psecond = pfirst->next;
	  }	   
	}
      return ret_head->next;
    }
};


void print_list(ListNode* head)
{
  while(head)
    {
      std::cout<<head->val<<" ";
      head = head->next;
    }
}
int main()
{
  ListNode* head= new ListNode(1);
  ListNode* l2 = new ListNode(2);
  ListNode* l3 = new ListNode(3);
  ListNode* l4 = new ListNode(4);
    head->next = l2;
    l2->next = l3;
    l3->next = l4;
  

   print_list(head);
  std::cout<<std::endl;
  Solution solu;


  print_list(  solu.swapPairs(head));
  std::cout<<std::endl;
  return 0;
}
