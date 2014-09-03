/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. 
Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
      int row = matrix.size();
      if(row == 0) return ;
      int col = matrix[0].size();
      
      bool first_row_has_zeroes = false;
      bool first_col_has_zeroes = false;
      
      for(int i = 0; i < col; i++) 
	if(matrix[0][i] == 0) {
	    first_row_has_zeroes = true;
	    break;
	  }

      for(int i = 0; i < row; i++)
	  if(matrix[i][0] == 0){
	      first_col_has_zeroes = true;
	      break;
	    }

      for(int i = 1; i < row; i++)
	for(int j = 1; j < col; j++){
	    if(matrix[i][j] == 0){
		matrix[0][j] = 0;
		matrix[i][0] = 0;
	      }
	  }

      for(int i = 1; i < row; i++)
	for(int j = 1; j < col; j++)
	  if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
	   

      if(first_row_has_zeroes){
	for(int i = 0 ; i < col; i++)
	  matrix[0][i] = 0;
      }
      
      if(first_col_has_zeroes){
	for(int i = 0; i < row; i++)
	  matrix[i][0] = 0;
      }
    }
};
