/*
Given a sorted array, remove the duplicates in place such that each element 
appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place 
with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].
*/
#include <cstdio>

class Solution {
public:
  int removeDuplicates(int A[], int n) {
    if(n == 0 ) return 0;

    int* position_ptr = A;
    int* scan_ptr = A;
    int* end_ptr = A + n - 1;
    while(scan_ptr <= end_ptr)
      {
	if(*scan_ptr > *position_ptr)
	  *(++position_ptr) = *(scan_ptr++);
	else
	  scan_ptr++;
      }
		  	  

    return position_ptr- A + 1;
  }
};


void print_elems(int A[], int n)
{
  for(int i =0; i<n; ++i)
    printf("%d ", A[i]);
  printf("\n");
}

int main()
{
  Solution s;
  int remain_num = 0;

  int A[7] = {1,2,3,4,5,6,7};
  remain_num =  s.removeDuplicates(A, 7);
  print_elems(A, remain_num);

  int B[7] = {1,1,3,4,4,5,7};
  remain_num =  s.removeDuplicates(B, 7);
  print_elems(B, remain_num);

  int C[7] = {1,1,2,2,2,2,2};
  remain_num =  s.removeDuplicates(C, 7);
  print_elems(C, remain_num);

  int D[7] = {1,1,1,1,1,1,1};
  remain_num =  s.removeDuplicates(D, 7);
  print_elems(D, remain_num);

  return 0;
}
