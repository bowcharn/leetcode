/*
Given a sorted array and a target value, return the index if the 
target is found. If not, return the index where it would be 
if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

*/

#include <iostream>

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
      int low = 0;
      int high = n -1;
      int mid = -1;
      while(low <= high)
	{
	  mid = (high + low) / 2;	 
	  if(A[mid] < target)
	     low = mid + 1;	   
	  else if (A[mid] == target)
	    return mid;
	  else
	      high = mid - 1;
	}
      return low;
    }
};


int main()
{
  Solution solu;
  int arr[] = {1,3,5,7};
  std::cout<<
    solu.searchInsert(arr, 4, 0)<< " "<<
    solu.searchInsert(arr, 4, 1)<< " "<<
    solu.searchInsert(arr, 4, 2)<< " "<<
    solu.searchInsert(arr, 4, 3)<< " "<<
    solu.searchInsert(arr, 4, 4)<< " "<<
    solu.searchInsert(arr, 4, 5)<< " "<<
    solu.searchInsert(arr, 4, 6)<< " "<<
    solu.searchInsert(arr, 4, 7)<< " "<<
    solu.searchInsert(arr, 4, 8)<< " "<<
    std::endl;

  return 0;
}
