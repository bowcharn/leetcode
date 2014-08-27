class Solution {
public:
    int reverse(int x) {
      //      int sign = x < 0 ? -1 : 1;

      int ret = 0;
      while(x)
	{
	  ret = ret*10 + (x % 10);
	  x = x / 10;
	}
      return ret;
    }
};

#include <iostream>
int main()
{
  std::cout<<Solution().reverse(123)<<std::endl<<
    Solution().reverse(-1)<<std::endl<<
    Solution().reverse(120)<<std::endl<<
    Solution().reverse(1254622344)<<std::endl;
}
