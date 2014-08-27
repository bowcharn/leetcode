#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    int carry = 1;
    size_t dig_size = digits.size();
    vector<int> newVec;
    newVec.assign(dig_size+1, 1);
    copy(digits.begin(), digits.end(), newVec.begin()+1);
    
    for(size_t i = dig_size ; i >= 1; --i)
      {
	if((newVec[i] += carry) >= 10)
	  {
	    carry = 1;
	    newVec[i] %=10;
	  }
	else
	  {
	    carry = 0;
	    break;
	  }	   
      }

    if(carry == 0)
      newVec.erase(newVec.begin());

    return newVec;
  }
};


void print_vec(const std::vector<int>& vec)
{
  vector<int>::const_iterator itr;
  for (itr = vec.begin(); itr!= vec.end(); itr++) {
    std::cout << ' ' << *itr;
  }
  std::cout << '\n';
}

int main()
{
  Solution s;
  vector<int> vec{0};

  vector<int> ret =  s.plusOne(vec);
  print_vec(ret);

  return 0;
}
