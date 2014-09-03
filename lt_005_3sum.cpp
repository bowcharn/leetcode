/*
Given an array S of n integers, are there elements a, b, c in S such that 
a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;


class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
      size_t sz = num.size();
      set<vector<int> > store_set;
      vector<vector<int> > ret_vec;
      vector<int> add_vec;
      sort(num.begin(), num.end());
      if(sz <= 2)
	return ret_vec;

      for(size_t i = 0; i < sz-2; i++)   // i : first index
 	{
	  size_t j = i + 1;       // j : second index
	  size_t k = sz - 1;       // k : third index
	  while(j < k)
	    {
	      int sum = num[i] + num[j] + num[k];
	      if(sum == 0) 
		{
		  add_vec.clear();
		  add_vec.push_back(num[i]);
		  add_vec.push_back(num[j]);
		  add_vec.push_back(num[k]);
		  store_set.insert(add_vec);

		  k--; j++;
		}
	      else if (sum < 0)
		j++;
	      else
		k--;
	    }
	}
      
       ret_vec.assign(store_set.begin(), store_set.end()); 
       return ret_vec;
    }
};


void print_res(const vector<vector<int> >& num)
{
  size_t sz1= num.size();
  for(size_t i = 0; i< sz1; i++)
    {
      size_t sz2 = num[i].size();
      for(size_t j = 0; j < sz2; j++)
	cout<<num[i][j]<<" ";
      cout<<endl;
    }
}
int main()
{
  vector<int> num = {-1 ,0 ,1 ,2 ,-1 ,-4};
  vector<vector<int> > res =  Solution().threeSum(num);
  print_res(res);
  cout<<"size::"<<res.size()<<endl;
  return 0;
}
