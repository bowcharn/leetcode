#include <vector>
#include <iostream>

using namespace std;

class Solution{
public:
  vector<vector<int> > combine(int n, int k)
  {
    vector<vector<int> > ret;
    vector<int> to_add;

    if(n < k || k < 0)
      return ret;
    combine_rec(1, n, k, to_add, ret);

    return ret;
  }
private:
  void combine_rec(int start, int n ,int k,
		   vector<int> to_add,vector<vector<int> > &ret)
  {
    if(to_add.size() == (size_t)k)
      {
	ret.push_back(to_add);
	return;
       }

    for(int i = start; i <= n; i++)
      {	
	to_add.push_back(i);
	combine_rec(i + 1, n , k, to_add, ret);
	to_add.pop_back();
      }
  }

  
};

void print_combine(vector<vector<int> > ret)
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
  print_combine(Solution().combine(4,2));
  return 0;
}
