/*
Given n pairs of parentheses, write a function to generate all combinations of 
well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

注：函数parens利用了bit pattern ， 简直好的不得了
A bit pattern like:

    10101100

Can be intepreted as:

    ()()(())

The function cycles through all bit patterns of the appropriate length and
eliminates those that fail the three tests described below.

The tests depend on calculating the sums of the bit patterns,
with 0 being replaced by -1.

    e.g. sum(1100) = 1 + 1 - 1 - 1 = 0 

Here are the tests:

(1) sum(bitpattern) = 0

Here is an example which fails:

    sum(1110) = 1 + 1 + 1 - 1 = 2

(2) All partial sums must be >= 0.

Here is an example which fails:

    bitpattern = 1001

    sum(1) = 1

    sum(10) = 1 - 1 = 0

    sum(100) = 1 - 1 - 1 = -1 *

    sum(1001) = 1 - 1 - 1 + 1 = 0

(3) All partial sums must <= pairs/2

Here is an exmple which fails:

    bitpattern = 1110

    sum(1) = 1

    sum(11) = 1 + 1 = 2

    sum(111) 1 + 1 + 1 = 3 *

    sum(111) = 1 + 1 + 1 - 1 = 2

To make the code a little bit more efficient, we ignore the first and 
last parantheses, because the first will always be 
'(' and the last will always be ')'.

*/
#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
      vector<string> res;
      if(n == 0)
	return res;
    
      solve_rec(n, 1, 0, "(", res);
      return res;
      
    }

  void solve_rec(int n , int l_n , int r_n, string str, vector<string>& res)
  {
    if(l_n == r_n && l_n == n){
      res.push_back(str);	
      return;
      }

    if(l_n < n)
      {
	      solve_rec(n, l_n +1, r_n, str + "(", res);
	      //	      cout<<"l-> "<<str + "("<<"\n";
      }

    
    if(r_n < l_n)
      {
	
      solve_rec(n, l_n , r_n +1, str + ")", res);	
      //          cout<<"r-> "<<str + ")"<<"\n";
      }


  }
};


void parens(int pairs)
{
    int i, j, s, n = 2*(pairs - 1);

    for (i = 0; i < 1 << n; i++) {
        for (s = 1, j = 0; (j < n) && (s >= 0) && (s <= pairs); j++)
            s += ((i >> j) & 1) ? 1 : -1;
	cout<<"i = "<<i<<", j = "<<j<<", s = "<<s<<endl;
        if ((j != n) || (s != 1))
            continue;
        putchar('(');
        for (j = 0; j < n; j++)
            ((i >> j) & 1) ? putchar('(') : putchar(')');
        printf(")\n");
    }
}

int main(){
  Solution solu;
  solu.generateParenthesis(1);
  parens(3);
  return 0;
}

