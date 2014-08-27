#include <iostream>
#include <cstring>


using namespace std;

class Solution {
public:
  int lengthOfLastWord(const char *s) {
    int str_len = strlen(s);
    if(str_len == 0) return 0;
    const char* scan_ptr = s + str_len - 1;
    int count = 0;

    while(*scan_ptr == ' ' && scan_ptr >= s)
      scan_ptr--;

    //    cout<<"first word : "<<*scan_ptr<<endl;

    while(*scan_ptr != ' ' && scan_ptr >= s)
      {
	count++;
	scan_ptr--;	  
      }
	  

    return count;
  }
};




int main()
{
  Solution s;

  const char* s1 = "Hello World";
  cout<<"Length of last word:: "<<s.lengthOfLastWord(s1)<<endl;

  const char* s2 = "Hello World  ";
  cout<<"Length of last word:: "<<s.lengthOfLastWord(s2)<<endl;

  const char* s3 = " ";
  cout<<"Length of last word:: "<<s.lengthOfLastWord(s3)<<endl;


  return 0;
}
