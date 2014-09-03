/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].

*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
  static bool cmp(const Interval& a, const Interval& b) {
    return a.start < b.start;
  }

#define max(x,y) ((x) > (y) ? (x) : (y))

  vector<Interval> merge(vector<Interval> &intervals) {
    sort(intervals.begin(), intervals.end(), cmp);
    vector<Interval> ret;
    vector<Interval>::iterator iter_fast , iter_last;
    iter_fast =  iter_last =  intervals.begin();

    
    while(iter_fast != intervals.end())
      {
	
	if(iter_fast + 1 != intervals.end())
	  {
	    if(iter_fast->end >=  (iter_fast + 1)->start)
	      {
		(iter_fast + 1)->end = max(iter_fast ->end, (iter_fast+1)->end);
		iter_fast++;		
	      }

	    else
	      {
		//	cout<<"Enter into ...1\n";
		ret.push_back(Interval(iter_last->start,
				       max(iter_fast->end, iter_last->end)));
		iter_last = ++iter_fast;
	      }	      	    	      
	  }
	else
	  {
	    //	    cout<<"Enter into ...2\n";
	   ret.push_back(Interval(iter_last->start, 
				  max(iter_fast->end, iter_last->end)));
	    break;
	  }	  
      }
    return ret;
  }

 void create_interval(int arr[], int n, vector<Interval>& inter)
  {
    for (int i = 0 ; i <n; i +=2)
	inter.push_back(Interval(arr[i], arr[i+1]));
  }

  void print_interval(const vector<Interval>& intervals)
  {
    for(vector<Interval>::const_iterator iter = intervals.begin();
	iter != intervals.end(); iter++)
      std::cout<<iter->start<<" "<<iter->end<<std::endl;
  }
};


int main()
{
  int arr[] = { 2,3,4,5,6,7,8,91,1, 10};
  Solution solu;
  vector<Interval> intervals;
  solu.create_interval(arr, 10 , intervals);
  solu.print_interval(solu.merge(intervals));
  return 0;
}
