#include <stack>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
      const char* pstr = s.c_str();
      std::stack<char> stack;
      while(*pstr != '\0')
	{
	  if(*pstr == '(' || *pstr == '[' || *pstr == '{')
	    stack.push(*pstr);
	  else if(*pstr == ')' || *pstr == ']' || *pstr == '}')
	    {
	      if(stack.empty()) return false;
	      char tmp_ch = stack.top();

	      if((*pstr == ')') && (tmp_ch == '('))
		stack.pop();
	      else if((*pstr == ']') && (tmp_ch == '['))
		stack.pop();
	      else if((*pstr == '}') && (tmp_ch == '{'))
		stack.pop();
	      else
		return false;
	    }
	  pstr++;
	}
      
      if(!stack.empty())
	return false;
      
      return true;
    }
};


int main()
{
  string str = "[](})";
  std::cout<<(Solution().isValid(str) ? ("true") : ("false"))<<std::endl;
  return 0;
}
