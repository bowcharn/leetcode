/*
A robot is located at the top-left corner of a m x n grid 
(marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid 
(marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
      int N = (m -1) + (n -1);   // total steps should be 
      int k = m-1;               // number of step need to go down
      double res = 1.0;
      
      // here we calculate the total possible path number 
      // Combination(N, k) = Combination(N, N - k)
      for(int i = 1; i <=k; i++)
	res = res*(N-k+i) / i;
      return (int)res;
    }
};
