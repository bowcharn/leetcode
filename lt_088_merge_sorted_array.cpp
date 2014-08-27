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
