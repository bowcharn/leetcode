#include <vector>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
      int ret = 0;
      if(n == 0)
	return ret;
      vector<int>  board(n, -1);
      NQueens_rec(n, 0, board, ret);
      return ret;
    }
  
  void NQueens_rec(int n, int row, 
		   vector<int>& board,
		   int & ret)
  {
    if(row == n)  // has solved the problem
      ret++;
    for(int i = 0; i < n; i++)
      {
	board[row] = i;        // "set"
	if(check(row, board)) // if checK return true, we can go further
	  NQueens_rec(n, row+1, board, ret); 
	board[row] = -1;      //"reset"
      }   
  }
  bool check(int row, vector<int> board)
  {
    for(int i = 0; i < row; ++i)
      if(board[row] == board[i] || abs(board[row] - board[i]) == row -i)
	return false;
    return true;
  }
};


int main()
{
  std::cout<<Solution().totalNQueens(3)<<std::endl;
  return 0;
}
