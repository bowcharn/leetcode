/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
      string res;
      string tmp_str;

      if(n == 0) return res;
      
      res = "1";
      while(--n > 0)
	{
	  const char* str_ptr = res.c_str();
	  const char *pSlow = str_ptr;
	  const char *pFast = str_ptr;
	  tmp_str.clear();
	  while(*pFast != '\0')
	    {
	      pFast++;
	      if(*pFast != *pSlow)
		{
		  tmp_str += std::to_string((int)(pFast - pSlow)) + *pSlow;  
		  pSlow = pFast;
		}
	    }
	  res = tmp_str;
	}
      return res;
    }
};


int main()
{
  Solution s;
  string res = s.countAndSay(0);

  cout<<res<<endl;
  return 0;
}
