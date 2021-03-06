/*
Given a collection of candidate numbers (C) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. 
(ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
      vector<vector<int> > ret;
      if(candidates.size() <=0 || target <=0)
	return ret;
      
      sort(candidates.begin(), candidates.end());
      vector<int> add_vec;
      combination_sum_rec(candidates, 0 , target, add_vec, ret);
      
      return ret;
    }
  void combination_sum_rec(const vector<int> & candinates, 
			   size_t start_idx, int target, vector<int> add_vec,
			   vector<vector<int> > & ret)
  {
    if(target < 0)
      return;
    if(target == 0){
      if(ret.end() == find(ret.begin(), ret.end(), add_vec))
	ret.push_back(add_vec);
      return;
    }     
    for(size_t i = start_idx; i < candinates.size(); ++i)
      {
	add_vec.push_back(candinates[i]);
	combination_sum_rec(candinates, i+1, target - candinates[i], 
			    add_vec, ret);
	add_vec.pop_back();
      }
  }
};


void print_vec(vector<vector<int> > vec)
{
  size_t sz1 = vec.size();
  for(size_t i = 0; i < sz1; ++i)
    {
      size_t sz2 = vec[i].size();
      for(size_t j = 0; j < sz2; j++)
	std::cout<< vec[i][j]<<" ";
      std::cout<<std::endl;
    }
}

int main()
{
  vector<int> candidates = {10,1,2,7,6,1,5};
  print_vec(Solution().combinationSum2(candidates, 8));

  return 0;
}
