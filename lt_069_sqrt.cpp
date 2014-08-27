class Solution {
public:
    int sqrt(int x) {
      if(x < 0)
	return -1;
      if(x == 0 || x == 1)
	return x;
      
      int low = 1;
      int high = x;
      
      while(low <= high)
	{
	  int mid = (int)(low * 0.5 + high * 0.5);
	  int val_larger = x/mid;
	  int val_smaller = x/(mid +  1);
	  if(mid <= val_larger && mid+1 >val_smaller)
	    return mid;
	  if(mid > val_larger) 
	    high = mid  - 1;
	  else 
	    low = mid +1;
	}

      return 0;
    }
};


#include <iostream>

int main()
{
  std::cout<<Solution().sqrt(-1)<<" "<<Solution().sqrt(0)<<" "<<
    Solution().sqrt(1)<<" "<<Solution().sqrt(2)<<" "<<
    Solution().sqrt(3)<<" "<<Solution().sqrt(4)<<" "<<
    Solution().sqrt(5)<<" "<<Solution().sqrt(8)<<" "<<
    Solution().sqrt(9)<<" "<<Solution().sqrt(10)<<" "<<std::endl;

  return 0;
}
