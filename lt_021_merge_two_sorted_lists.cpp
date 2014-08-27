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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
      ListNode* head = new  ListNode(0);
      
      ListNode* pfirst = l1;
      ListNode* psecond = l2;
      ListNode* phead = head;
      while(pfirst != NULL && psecond != NULL)
	{
	  if(pfirst->val < psecond->val)
	    {
	      phead->next = pfirst;
	      pfirst = pfirst->next;
	      phead = phead->next;
	    }
	  else
	    {
	      phead->next = psecond;
	      psecond = psecond->next;
	      phead = phead->next;
	    }
	}
      
      while(pfirst != NULL)
	{
	  phead->next = pfirst;
	  pfirst = pfirst->next;
	  phead = phead->next;
	}
      while(psecond != NULL)
	{
	  phead->next = psecond;
	  psecond = psecond->next;
	  phead = phead->next;
	}
      
      return head->next;
    }
};
