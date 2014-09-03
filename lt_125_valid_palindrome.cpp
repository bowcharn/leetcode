/*
Given a string, determine if it is a palindrome, considering only alphanumeric
 characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to 
ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/
#include <string>
#include <cctype>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
      if(s.empty())
	return true;
      
      size_t len = s.length();
      const char* pbegin = s.c_str();
      const char* pend = pbegin + len - 1;
      
      while(pbegin < pend)
	{
	  while(!isalnum(*pbegin) && pbegin <= s.c_str() + len -1)
	    pbegin++;
	  
	  while(!isalnum(*pend) && pend >= s.c_str())
	    pend--;
	  
	  if(isdigit(*pbegin))
	    {
	      if(*pbegin != *pend)			  
		  return false;	        		
	    }
	  else{
	    char begin_ch = *pbegin;
	    char end_ch = *pend;
	    begin_ch = tolower(begin_ch);
	    end_ch = tolower(end_ch);
	    if(begin_ch != end_ch)
	      return false;
	  }	      
	  pbegin++;
	  pend--;
	}
      return true;
    }
};

int main()
{
  string str1 = "A man, a plan, a canal: Panama";
  string str2 = "race a car";
  string str3 = " 454    .....///";
  std::cout<<(Solution().isPalindrome(str1) ? ("true") : ("false"))<<" "<<
    (Solution().isPalindrome(str2) ? ("true") : ("false"))<<" "<<
    (Solution().isPalindrome(str3) ? ("true") : ("false"))<<" "<<std::endl;

  return 0;
}
