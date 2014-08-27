/*
  "Insert Interval "

  Given a set of non-overlapping intervals, insert a new interval into the 
  intervals (merge if necessary).

  You may assume that the intervals were initially sorted according to their
  start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in 
as [1,2],[3,10],[12,16].   
This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
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


#include <vector>
#include <iostream>

using namespace std;

  struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
  };
class Solution {
public:
   vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
     size_t start_pos, end_pos;
     bool start_flag = search_insert_pos(intervals, 
					 newInterval.start, start_pos);
     bool end_flag = search_insert_pos(intervals, newInterval.end, end_pos);

     Interval insert_ival;
     if(start_flag)
       newInterval.start = intervals[start_pos].start;
     if(end_flag)
       newInterval.end = intervals[end_pos].end;

     insert_ival.start = newInterval.start;
     insert_ival.end = newInterval.end;

     intervals.erase(intervals.begin() + start_pos,
		     intervals.begin() + end_pos+ (end_flag ? 1 : 0));
     intervals.insert(intervals.begin() + start_pos, insert_ival);

     return intervals;
    }
  
  bool search_insert_pos(const vector<Interval>& intervals, 
			 int com,
			 size_t& pos)
  {
    int sz = intervals.size();

    int l = 0;
    int  u= sz -1;
    while(l <= u)
      {
	int  m = (l + u) / 2;
	
	if(intervals[m].end < com)
	  l = m +1;
	else if(intervals[m].start > com)
	  u = m -1;
	else
	  {
	    pos = m;
	    return true;
	  }
      }
    pos = (size_t)l;
    return false;
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
  Solution solu;
  vector<Interval> intervals;
  // int arr[] = {1,2,3,5,6,7,8,10,12,16};
  // Interval newInterval(4,9);
   int arr[] = {1,5};
   Interval newInterval(6,8);
  
  solu.create_interval(arr, 2, intervals);


  
  size_t pos;
  bool valid_pos; 
  valid_pos =  solu.search_insert_pos(intervals, newInterval.start, pos);
  std::cout<< (valid_pos ? ("true") : ("false")) <<"  " <<pos<<endl;

  valid_pos =  solu.search_insert_pos(intervals, newInterval.end, pos);
  std::cout<< (valid_pos ? ("true") : ("false")) <<"  " <<pos<<endl;
  

  solu.print_interval(solu.insert(intervals, newInterval));
  return 0;
}
