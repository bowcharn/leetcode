/*
Given an array and a value, remove all instances of that value in place and 
return the new length.

The order of elements can be changed. It doesn't matter what you leave 
beyond the new length.
*/

#include <cstdio>

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
      if(n == 0)
	return 0;
      int* front = A;
      int* end = A+n-1;
      int length = n;
      while(front <= end)
	{
	  if(*front == elem)
	    {
	      while(end > front)
		{
		  if(*end != elem)
		    break;
		  else
		    {
		      end--;
		      length--;
		    }
		
		}
	      *front = *end;
	      //	      if(*end != elem)
		end--;
	      length--;
	    }
	  front++;
	}
      //   if(*front == elem)
      //length--;
      
      return length;
      
    }
};

void print_elems(int A[], int n);
int main()
{
  //  int A[7] = {2,4,5,4,6,0,7};
   int A[7] = {3,3,3,3,3,3,3};
  Solution s;
  int remain_num = 0;
  remain_num = s.removeElement(A, 7, 3);
  printf("1 case: %d remain...\n",remain_num);
  print_elems(A,remain_num);


  int B[1] = {5};
  printf("2 case: %d remain...\n", s.removeElement(B, 1, 3));

  printf("3 case: %d remain....\n", s.removeElement(B,1,5));

  int C[4] = {2,3,45,6};
   printf("3 case: %d remain....\n", s.removeElement(C,4,5));

   int D[3] = {2,3,3};
   printf("3 case: %d remain....\n", s.removeElement(D,3,3));
   return 0;
}

void print_elems(int A[], int n)
{
  for(int i =0; i<n; ++i)
    printf("%d ", A[i]);
  printf("\n");
}
