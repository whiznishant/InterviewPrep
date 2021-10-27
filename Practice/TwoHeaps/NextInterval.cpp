/*
Next Interval (hard) #
Given an array of intervals, find the next interval of each interval. In a list of intervals, for an interval ‘i’ its next interval ‘j’ will have the smallest ‘start’ greater than or equal to the ‘end’ of ‘i’.

Write a function to return an array containing indices of the next interval of each input interval. If there is no next interval of a given interval, return -1. It is given that none of the intervals have the same start point.

Example 1:

Input: Intervals [[2,3], [3,4], [5,6]]
Output: [1, 2, -1]
Explanation: The next interval of [2,3] is [3,4] having index ‘1’. Similarly, the next interval of [3,4] is [5,6] having index ‘2’. There is no next interval for [5,6] hence we have ‘-1’.

Example 2:

Input: Intervals [[3,4], [1,5], [4,6]]
Output: [2, -1, -1]
Explanation: The next interval of [3,4] is [4,6] which has index ‘2’. There is no next interval for [1,5] and [4,6].
*/



using namespace std;

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

class Interval {
 public:
  int start = 0;
  int end = 0;

  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};
// Not using Heap ----- 
// Binary search the minimum next interval and add to the result
class NextInterval {
 public:
  // Returns the correct Index
  static int binarySearch(vector<pair<Interval,int>> &sortedIntervals, int x )
  {
    int len = sortedIntervals.size();
    if(x > sortedIntervals[len -1].first.start)
      return -1;
    int l=0,r = len-1;
    while(l<=r)
    {
      int mid = l + (r-l)/2;
      if(sortedIntervals[mid].first.start == x)
        return mid;
      if(sortedIntervals[mid].first.start < x )
        l = mid + 1;
      else
        r = mid - 1;
    }
    return sortedIntervals[l].second;
  }

  static vector<int> findNextInterval(const vector<Interval> &intervals) {
    // TODO: Write your code here
    vector<pair<Interval,int>> sortedIntervals;
    for(int i=0;i<intervals.size();i++)
    {
      sortedIntervals.push_back(make_pair(intervals[i],i));
    }
    sort(sortedIntervals.begin(),
      sortedIntervals.end(),[](pair<Interval,int> &lhs,pair<Interval,int> &rhs){ return lhs.first.start < rhs.first.start;});
    
    vector<int> result(intervals.size(),-1);

    for(int i=0;i< intervals.size();i++)
    {
      result[i] = binarySearch(sortedIntervals,intervals[i].end);
    }
    return result;    
  }
};

int main(int argc, char *argv[]) {
  //vector<Interval> intervals = {{2, 3}, {3, 4}, {5, 6}};
  vector<Interval> intervals = {{1,12},{2,9},{3,10},{13,14},{15,16},{16,17}};
  vector<int> result = NextInterval::findNextInterval(intervals);
  cout << "Next interval indices are: ";
  for (auto index : result) {
    cout << index << " ";
  }
  cout << endl;
  
  intervals = {{3, 4}, {1, 5}, {4, 6}};
  result = NextInterval::findNextInterval(intervals);
  cout << "Next interval indices are: ";
  for (auto index : result) {
    cout << index << " ";
  }
}
