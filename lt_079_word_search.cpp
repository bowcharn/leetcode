/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring.
 The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
      size_t word_sz;
      if((word_sz=word.length()) == 0) return false;
      
      size_t m = board.size();
      size_t n = board[0].size();
      vector<vector<bool> > marked(m, vector<bool>(n, false));
      for(size_t i = 0; i < m; i++)
	{
	  for(size_t j = 0; j < n; j++)
	    {
	      if(board[i][j] == word[0])
		{
		  if(exist_dfs(i, j, m, n, 0, word, board, marked))
		    return true;
		}
	    }
	}
      return false;
    }
 
  bool exist_dfs(size_t i, size_t j, size_t m ,size_t n,
		 size_t ch_pos, const string word,
		 const vector<vector<char> > &board, 
		 vector<vector<bool> >& marked)
  {
    if(ch_pos >= word.size())  // get to the word end
      return true;

    if(i<0 || i >=m || j <0 || j >= n ) // bound for i and j
      return false;

    if(board[i][j] != word[ch_pos]) // char at ch_pos is equal to word[ch_pos]
      return false;

    if(marked[i][j])      // has visited
      return false;
    
    marked[i][j] = true;

    bool res = (exist_dfs(i-1, j, m, n, ch_pos +1, word, board, marked) ||  //up
		exist_dfs(i+1, j, m, n, ch_pos +1, word, board, marked) ||  //down
		exist_dfs(i, j-1, m, n, ch_pos +1, word, board, marked) ||  //left
		exist_dfs(i, j+1, m, n, ch_pos +1, word, board, marked)     //right
		);
    marked[i][j] = false;
   return res;
  }
};


int main()
{
  vector<vector<char> >  board = {vector<char> {'A', 'B', 'C', 'E'},
				  vector<char> {'S', 'F', 'C', 'S'},
				  vector<char> {'A', 'D', 'E', 'E'}};
  std::cout<<
    (Solution().exist(board, "ABCCED") ? ("true") : ("false"))<<
    std::endl<<
    (Solution().exist(board, "EEDFCSEC") ? ("true") : ("false"))<<
    std::endl<<
    (Solution().exist(board, "ABCB") ? ("true") : ("false"))<<
    std::endl;
  return 0;
}
