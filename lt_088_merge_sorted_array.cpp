/*
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space (size that is greater or equal to m + n) 
to hold additional elements from B. The number of elements initialized in 
A and B are m and n respectively.
*/
public:
class Solution {
    void merge(int A[], int m, int B[], int n) {
      int a_idx = m -1;
      int b_idx = n -1;
      int k = m + n -1;
      while(a_idx >=0 && b_idx >= 0)
	{
	  if(A[a_idx] > B[b_idx])
	      A[k--] = A[a_idx--];	     
	  else
	      A[k--] = B[b_idx--];	      
	}
      while(b_idx >= 0) A[k--] = B[b_idx--];      
    }
};
