/*
Implement pow(x, n).
*/
class Solution {
public:
    double pow(double x, int n) {
      if(n == 0) 
	return 1.0;
      
      double ret = 1.0;
      bool neg = n < 0 ? true : false;
      
     
      int half_n = (n < 0) ? -(n/2) : (n/2);
      ret = (n & 1)? pow(x*x, half_n)*x : pow(x*x, half_n);
      
      return neg ? 1.0/ret : ret;     
    }
};

#include <iostream>


int main()
{
  std::cout<<Solution().pow(2.0,3)<<" "<<Solution().pow(2.0, -3)<<" "
	   <<Solution().pow(2.0,0)<<" "<<Solution().pow(-2.0, -3)<<" "
	   <<Solution().pow(-2.0, 3)<<" "<<Solution().pow(-2.0, -4)<<std::endl;
  return 0;
}
