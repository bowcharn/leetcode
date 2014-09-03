/*
Divide two integers without using multiplication, division and mod operator.
*/

#include <iostream>
#include <climits>
#include <cmath>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {	
      if(divisor == 0)
	return INT_MIN;
      
      int ret = 0;
      if(dividend == INT_MIN)
	{
	  dividend += abs(divisor);
	  ret++;
	}
      if(divisor == INT_MIN)
	return ret;

      bool isNeg = ((dividend>>31) ^ (divisor>>31))? true : false;
      dividend = abs(dividend);
      divisor = abs(divisor);
      int digits = 0;
      while(divisor <= (dividend >>1))
	{
	  divisor <<= 1;
	  digits++;
	}
      while(digits >= 0)
	{
	  if(dividend >= divisor)
	    {
	      dividend -= divisor;
	      ret += 1<<digits;
	    }
	  divisor >>= 1;
	  digits--;
	}
      return isNeg? -ret : ret;
    }
};

int main()
{
  std::cout<<Solution().divide(INT_MAX,1)<<std::endl<<
    Solution().divide(5,2)<<std::endl<<
    Solution().divide(5,-2)<<std::endl<<
    Solution().divide(-5,2)<<std::endl;
  return 0;
}
