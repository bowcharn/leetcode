#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
      vector<vector<int> > ret;
      vector<int> to_add;
      
      size_t sz = S.size();
      if(sz <= 0) return ret;

      sort(S.begin(), S.end());
      
      subsets_rec(0, sz,S, to_add, ret);
      return ret;
    }

  void subsets_rec(size_t start, size_t sz, const vector<int> & S,
		   vector<int> to_add,vector<vector<int> > &ret)
  {
    ret.push_back(to_add);

    for(size_t i = start; i<sz; i++)
      {
	to_add.push_back(S[i]);
	subsets_rec(i +1, sz, S, to_add, ret);
	to_add.pop_back();
      }
  }
 
};


void print_subsets(vector<vector<int> > ret)
{
  size_t sz1 = ret.size();
  for(size_t i = 0; i < sz1; i++)
    {
      size_t sz2 = ret[i].size();
      for(size_t j = 0; j <sz2; j++)
	std::cout<<ret[i][j]<<" ";
      std::cout<<std::endl;
    }

  std::cout<<"total count :: "<<sz1<<std::endl;
}

int main()
{
  vector<int> S = {5,2,1};
  print_subsets(Solution().subsets(S));
  return 0;
}
