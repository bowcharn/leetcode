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
