using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class Interval {
 public:
  int start = 0;
  int end = 0;

  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class MergeIntervals {
 public:
  static vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> mergedIntervals;
    // TODO: Write your code here
    sort(intervals.begin(),intervals.end(),[](Interval &lhs, Interval &rhs){ return lhs.start < rhs.start;});
    int sz = intervals.size();
    mergedIntervals.push_back(intervals[0]);
    int mergeIdx = 0;
    for(int i=1;i<sz;i++)
    {
      if(intervals[i].start < mergedIntervals[mergeIdx].end )
      { 
        if(intervals[i].end > mergedIntervals[mergeIdx].end )
        {
          mergedIntervals[mergeIdx].end = intervals[i].end;
        }
      }
      else 
      {
          mergedIntervals.push_back(intervals[i]);
          mergeIdx++;
      }
    }
    return mergedIntervals;
  }
};

int main(int argc, char *argv[]) {
  vector<Interval> input = {{1, 3}, {2, 5}, {7, 9}};
  cout << "Merged intervals: ";
  for (auto interval : MergeIntervals::merge(input)) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  input = {{6, 7}, {2, 4}, {5, 9}};
  cout << "Merged intervals: ";
  for (auto interval : MergeIntervals::merge(input)) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  input = {{1, 4}, {2, 6}, {3, 5}};
  cout << "Merged intervals: ";
  for (auto interval : MergeIntervals::merge(input)) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;
}