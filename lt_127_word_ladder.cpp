/*
Given two words (start and end), and a dictionary, find the length of shortest 
transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

#include <unordered_set>
#include <string>
#include <queue>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
private:
  enum COLOR {WHITE, GRAY, BLACK};
  struct word{
    word(string w, COLOR c, int d):word_self(w), color(c), dis(d){}
    string word_self;
    COLOR color;
    int dis;
  };
public:
  int ladderLength(string start, string end, unordered_set<string> &dict) {

    queue<word> process;
    unordered_set<string> visited;

    size_t word_len = start.length();
    word start_word(start, GRAY,1);
    process.push(start_word);

    while(!process.empty())
      {
	word cur_word =  process.front();
	process.pop();
	char change_ch;
	for(size_t i = 0; i <word_len; ++i)
	  {
	    change_ch = cur_word.word_self[i];
	    for(char ch = 'a'; ch <= 'z' ; ch++)
	      {		  
		if(ch == change_ch) continue;
		cur_word.word_self[i] = ch;
		if(cur_word.word_self == end) 
		  return cur_word.dis + 1;

		unordered_set<string> ::iterator iter;
		if( /*visited.find(cur_word.word_self) == visited.end() && */
		   (iter =dict.find(cur_word.word_self)) != dict.end() )
		  {
		    word to_add(*iter, GRAY, cur_word.dis +1);
		    if(*iter == end)
		      return to_add.dis;
		    process.push(to_add); 

		    dict.erase(iter);
		  }
	      }
	    cur_word.word_self[i] = change_ch;
	  }
      }
    return 0;
  }
};


int main()
{
  unordered_set<string> dict = {"hot","dot","dog","lot","log"};
  string start = "hit";
  string end = "cog";

  cout<<Solution().ladderLength(start, end, dict)<<endl;

  return 0;
}
