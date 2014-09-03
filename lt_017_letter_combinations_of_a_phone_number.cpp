/*
Given a digit string, return all possible letter combinations that the number 
could represent.


Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer 
could be in any order you want.
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
      vector<string> ret;
      if(digits.length() == 0)
	return (ret.push_back(string()), ret);
      vector<string> numMap = {"abc", "def","ghi","jkl",
			       "mno","pqrs","tuv","wxyz"};      
      string add_str;
      letter_rec(numMap, digits, 0, add_str, ret);
      return ret;
    }

  void letter_rec(const vector<string>& numMap, const string& digits,
		  int dig_sz, string add_str, vector<string>& ret)
  {
    if(dig_sz == (int)digits.length())
	ret.push_back(add_str);
    else
      {
	string str = numMap[digits[dig_sz] - '2'];
	size_t str_sz = str.length();
	for(size_t i = 0; i < str_sz; ++i)
	  {
	    add_str += str[i];
	    letter_rec(numMap, digits, dig_sz+1, add_str, ret);
	    add_str.pop_back();
	  }
      }
  }
};

void print_strs(vector<string> strs)
{
  size_t sz = strs.size();
  for(size_t i = 0; i < sz; i++)
    std::cout<<strs[i]<<" ";
}

int main()
{
  print_strs(Solution().letterCombinations(""));
   std::cout<<std::endl;
  return 0;
}
