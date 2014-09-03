/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
      vector<vector<int> > res;
      int sz = num.size();
      if(sz <= 1)
	return (sz == 1 ? (res.push_back(num), res) : res);
      
      permutation_rec(num, 0, sz, res);

      return res;
	
    }
void permutation_rec(vector<int> & num, int i, 
		     int sz, vector<vector<int> > & res)
  {
    if( i == sz -1)
      res.push_back(num);
    else
      {
	for(int j = i; j < sz; j++)
	  {
	    swap(num[i], num[j]);
	    permutation_rec(num, i+1, sz, res);
	    swap(num[i], num[j]);;
	  }
      }     
  }

  void swap(int & a, int &b)
  {
    int temp = a;
    a = b;
    b = temp;
  }

  void print_permutation(vector<vector<int> >  res)
  {
    int sz1 = res.size();
    for(int i = 0 ; i < sz1; i++)
      {
	int sz2 = res[i].size();
	for(int j = 0; j < sz2; j++)
	  std::cout<<res[i][j]<<" ";
	std::cout<<std::endl;
      }
  }
};


int main()
{
  vector<int> num = {1,2,3,4,5,6,7,8};
   Solution solu;
  solu.permute(num);
  // solu.print_permutation(solu.permute(num));

  return 0;
}
