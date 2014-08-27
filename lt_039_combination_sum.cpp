#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
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
      ret.push_back(add_vec);
      return;
    }     
    for(size_t i = start_idx; i < candinates.size(); ++i)
      {
	if(candinates[i] == candinates[i-1])
	  continue;
	add_vec.push_back(candinates[i]);
	combination_sum_rec(candinates, i, target - candinates[i], 
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
  vector<int> candidates = {2,2};
  print_vec(Solution().combinationSum(candidates, 3));

  return 0;
}
