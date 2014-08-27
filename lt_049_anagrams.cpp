#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
      std::map<string, vector<string> > str_map;
      std::vector<string> ret;
      for(vector<string> :: iterator itr = strs.begin();
	  itr != strs.end(); itr++)
	{
	  string sort_str = *itr;
	  sort(sort_str.begin(), sort_str.end());
	  str_map[sort_str].push_back(*itr);
	}
      for(map<string, vector<string> >::iterator itr = str_map.begin();
	  itr != str_map.end(); itr++)
	if(itr->second.size() >= 2)
	  ret.insert(ret.end(), itr->second.begin(), itr->second.end());

      return ret;
    }
  
};

void print_strs(vector<string> strs)
{
  for(vector<string>::iterator itr = strs.begin();
      itr != strs.end(); itr++)
    cout<<*itr<<" ";
}
int main()
{
  vector<string> strs = {"erd", "edr"};
  print_strs(Solution().anagrams(strs));
  cout<<endl;
  return 0;
}
