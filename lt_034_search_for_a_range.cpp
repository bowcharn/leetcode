/*
Given a sorted array of integers, find the starting and ending position of a 
given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
     vector<int> searchRange(int A[], int n, int target) {
       vector<int> ret = {-1, -1};
       if(A == NULL || n <= 0)
	 return ret;
       ret[0] = search_left_bound(A, n, target);
       ret[1] = search_right_bound(A, n , target);
       return ret;
    }

  int search_left_bound(int A[], int n, int target)
  {
    int low = -1;
    int high = n;
    while(low+1 != high)
      {
	int mid = (low + high) / 2;
	if(A[mid] < target)
	  low = mid;
	else
	  high = mid;
      }
    if(high >= n || A[high] != target)
      return -1;
    return high;   
  }
  
  int search_right_bound(int A[], int n , int target)
  {
    int low = -1;
    int high = n;
    while(low + 1 != high)
      {
	int mid = (low + high) / 2;
	if(A[mid] > target)
	  high = mid;
	else
	  low = mid;
      }
    if(low <= -1 || A[low] != target)
      return -1;
    return low;
  }
};

int main()
{
  int A[] = {5, 7, 7, 8, 8, 10};
  std::cout<<Solution().search_left_bound(A, 6, 2)<<std::endl
	   <<Solution().search_right_bound(A, 6, 2)<<std::endl;
  return 0;
}
