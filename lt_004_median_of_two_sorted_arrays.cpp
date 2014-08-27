#include <cstdio>
#include <algorithm>
#include <climits>
#include <cassert>
class Solution {
public:

#define min(x , y) ((x < y) ? (x) : (y))
#define max(x , y) ((x > y) ? (x) : (y))

	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		if(m == 0)
			return median(B, n);

		if(n == 0)
			return median(A, m);

		if(m < n)
			return findMedianRecur(A, B, 0, m-1, m , n);
		else
			return findMedianRecur(B, A, 0, n-1, n , m);
	}

	double findMedianRecur(int A[], int B[], int left, int right, int m, int n)
	{
		if(left > right) 
		{
     //  printf("enter into ... \n ");
			return findMedianRecur(B, A, max(0, (m + n)/2 -m),
				min(n-1, (m + n)/2 ), n, m);	
		}

  // printf("left = %d , right = %d\n", left, right);
		int i = (left + right) / 2;
		int j = (m + n)/2 - i -1;
  
		if(j >= 0 && A[i] < B[j])
			return findMedianRecur(A, B, i+1, right, m, n);
		else if(j < n -1 && A[i] > B[j+1])
			return findMedianRecur(A, B, left, i-1, m, n);
		else
		{
			/*if(((m + n) & 1) == 1) 
				return A[i];
			else if(i > 0) 
				return (A[i] + max(B[j], A[i-1]))/2.0;
			else
				return (A[i] + B[j]) / 2.0;*/

					if(((m + n) & 1) == 1) 
				return A[i];
			else if(i > 0)
			{
				if(j == -1)
					return (A[i] + A[i-1])/2.0;
				else
					return (A[i] + max(B[j], A[i-1]))/2.0;
			} 				
			else
			{
				if(j == -1)
					return (A[i] + A[i-1]);
				else
					return (A[i] + B[j] ) / 2.0;
			}

		}
	}

	double median(int arr[], int n)
	{
		if((n & 1) == 0)
			return (arr[n/2] + arr[n/2 - 1])/ 2.0;
		else
			return arr[n/2];
	}
};


int main()
{
	Solution solu;

	int ar1[] = {};
	int ar2[] = {9};
	int ar3[] = {3};
	int ar4[] = {4};

	int n1 = sizeof(ar1)/sizeof(ar1[0]);
	int n2 = sizeof(ar2)/sizeof(ar2[0]);
	int n3 = sizeof(ar3)/sizeof(ar3[0]);
	int n4 = sizeof(ar4)/sizeof(ar4[0]);
	printf("Median is %f\n", solu.findMedianSortedArrays(ar1, n1, ar2, n2));
	printf("Median is %f\n", solu.findMedianSortedArrays(ar3, n3, ar4, n4));
	return 0;
}
