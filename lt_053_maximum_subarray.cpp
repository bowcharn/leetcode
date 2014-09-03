/*
Find the contiguous subarray within an array (containing at least one number) 
which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using 
the divide and conquer approach, which is more subtle.
*/

class Solution {
public:
#define max(x,y) ((x) > (y) ? (x) : (y))

    int maxSubArray(int A[], int n) {
      

      if(n == 0) return 0;

      int max_sofar = A[0];
      int maxret  = A[0];

      for(int i = 1; i < n; i++)
	{
	  max_sofar = max(max_sofar + A[i] , A[i]);
	  maxret = max(max_sofar,maxret);
	}
      return maxret;
    }
};

#include <iostream>
int main()
{
  int A[] = {-2,-1,-3};
  std::cout<<Solution().maxSubArray(A, 3)<<std::endl;
  return 0;
}
