/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/


#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
      int a_len = a.length();
      int b_len = b.length();
      if(a_len == 0)
	return b;
      else if (b_len == 0)
	return a;

      const char* short_ptr = a.c_str() + a_len -1;
      const char* long_ptr = b.c_str() + b_len -1;
      
      int diff = abs(a_len - b_len);
      int short_len = (a_len < b_len ? a_len : b_len);
      if(a_len > b_len)
	{
	  const char* temp_ptr = short_ptr;
	  short_ptr = long_ptr;
	  long_ptr =temp_ptr;
	}
      
      string res;
      int carry = 0;
      while(--short_len >= 0)
	{
	  int short_bit = *short_ptr - '0';
	  int long_bit  = *long_ptr - '0';
	  int add_sum = short_bit + long_bit + carry;
	  if(add_sum >= 2)
	    {
	      carry = 1;
	      res.insert(0, 1, (char)((add_sum-2) + '0'));
	    }
	  else
	    {
	      carry = 0;
	      res.insert(0, 1, (char)((add_sum) + '0'));
	    }
	  short_ptr--;
	  long_ptr--;
	}
      
      while(--diff >= 0)
	{
	  int long_bit  = *long_ptr - '0';
	  int add_sum =  long_bit + carry;
	  if(add_sum >= 2)
	    {
	      carry = 1;
	      res.insert(0, 1, (char)((add_sum-2) + '0'));
	    }
	  else
	    {
	      carry = 0;
	      res.insert(0, 1, (char)((add_sum) + '0'));
	    }
	  long_ptr--;
	}
      if(carry == 1)
	res.insert(0,1,(char)(carry + '0'));
      return res;
    }
};


int main()
{
  string a = "110";
  string b = "1110";
  Solution s;
  string res = s.addBinary(a, b);
  std::cout<<res<<std::endl;

  std::cout<<(char)(5 + '0')<<endl;

  return 0;
}
