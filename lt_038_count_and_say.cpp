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
