#include <vector>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
      vector<vector<string> > ret;
      if(n == 0)
	return ret;
      vector<int>  board(n, -1);
      NQueens_rec(n, 0, board, ret);
      return ret;
    }

  void NQueens_rec(int n, int row, 
		   vector<int>& board,
		   vector<vector<string> >& ret)
  {
    if(row == n)  // has solved the problem
      {
	vector<string> ele(n, string(n,'.'));
	for(int i = 0; i < n; i++)
	  ele[i][board[i]] = 'Q';
	ret.push_back(ele);
	return;
      }
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

void print_vec(vector<vector<string> > vec)
{
  size_t sz1= vec.size();
  for(size_t i = 0; i < sz1; i++ )
    {
      std::cout<<i+1<<" queens configuration--->>>>\n";
      size_t sz2 = vec[i].size();
      for(size_t j = 0; j < sz2; ++j)
	std::cout<<vec[i][j]<<std::endl;
      std::cout<<std::endl;
    }
}

int main()
{
  print_vec(Solution().solveNQueens(5));
  return 0;
}
