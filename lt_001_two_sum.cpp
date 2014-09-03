/*
Given an array of integers, find two numbers such that they add up to a 
specific target number.

The function twoSum should return indices of the two numbers such that 
they add up to the target, where index1 must be less than index2. 
Please note that your returned answers (both index1 and index2) are not 
zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  struct idx_node {
    int index;
    int read_num;
  };

  struct Cmp
  {
    bool operator() (idx_node a , idx_node b)
    {
      return a.read_num < b.read_num;
    }
  }myCmp;

  vector<int> twoSum(vector<int> &numbers, int target) {
    size_t num_size = numbers.size();
    std::vector<idx_node> new_number_vec(num_size);
    for(size_t i = 0; i < num_size; ++i)
      {
	new_number_vec[i].index = (i+1);
	new_number_vec[i].read_num = numbers[i];
      }
      
    std::sort(new_number_vec.begin(), new_number_vec.end(), myCmp);
      
#if 0    ///first version to solve
    int i, j;
    for(i = 0 ; i< num_size; ++i)
      {
	idx_node sd;
	sd.read_num = target - new_number_vec[i].read_num;
	
	if(std::binary_search(new_number_vec.begin(), new_number_vec.end(), sd, myCmp)) break;
      }
    
    for(j = i+1; j < num_size; j++)
      if((new_number_vec[i].read_num+new_number_vec[j].read_num) == target) break;
   
    cout<<"i = "<<i <<" j = "<<j<<endl;
    std::vector<int> ret;
    if(i<num_size-1)
      {
	
	ret.push_back(std::min(new_number_vec[i].index, new_number_vec[j].index));
	ret.push_back(std::max(new_number_vec[i].index, new_number_vec[j].index));
      }
    
#else   ///second version to solve
    
    int i = 0;
    int j = num_size -1;
    int sum = 0;
    while(i < j)
      {
	sum = new_number_vec[i].read_num + new_number_vec[j].read_num;
	if(sum == target) break;
	else if(sum > target) j--;
	else i++;
      }
   

    cout<<"i = "<<i <<" j = "<<j<<endl;
    std::vector<int> ret;
    if(i != j)
      {
	
	ret.push_back(std::min(new_number_vec[i].index, new_number_vec[j].index));
	ret.push_back(std::max(new_number_vec[i].index, new_number_vec[j].index));
      }
#endif   
    return ret;
  }
};


int main()
{
  vector<int> test{2,7,11,5};
  Solution s;
  vector<int> ret = s.twoSum(test,16);
  cout<<"Index1 = "<<ret[0]<<" Index2 = " <<ret[1]<<endl;

  return 0;
}
