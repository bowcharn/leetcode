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
