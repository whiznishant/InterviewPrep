/*
Employee Free Time (hard) #
For ‘K’ employees, we are given a list of intervals representing the working hours of each employee. Our goal is to find out if there is a free interval that is common to all employees. You can assume that each list of employee working hours is sorted on the start time.

Example 1:

Input: Employee Working Hours=[[[1,3], [5,6]], [[2,3], [6,8]]]
Output: [3,5]
Explanation: Both the employees are free between [3,5].
Example 2:

Input: Employee Working Hours=[[[1,3], [9,12]], [[2,4]], [[6,8]]]
Output: [4,6], [8,9]
Explanation: All employees are free between [4,6] and [8,9].
Example 3:

Input: Employee Working Hours=[[[1,3]], [[2,4]], [[3,5], [7,9]]]
Output: [5,7]
Explanation: All employees are free between [5,7].
*/


using namespace std;

#include <iostream>
#include <queue>
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

class EmployeeFreeTime {
 public:
  struct comp{
    bool operator() ( pair<int,Interval> &lhs , pair<int,Interval> &rhs )
    {
      return lhs.second.start > rhs.second.start;
    }
  };
  static vector<Interval> findEmployeeFreeTime(const vector<vector<Interval>> &schedule) {
    vector<Interval> result;
    // TODO: Write your code here
    vector<int> currIdx(schedule.size(),0);
    vector<int> finalIdx;
    for(auto x:schedule)
    {
      finalIdx.push_back(x.size()-1);
    }
    priority_queue<pair<int,Interval>, vector<pair<int,Interval>> ,comp> intPQ;
    for( int i=0;i< schedule.size();i++ )
    {
      intPQ.push(make_pair(i,schedule[i][0]));
    }

    Interval runningInterval = intPQ.top().second;
    while(intPQ.size() != 0)
    {
      pair<int,Interval> popped = intPQ.top();
      intPQ.pop();
      int poppedEmpIdx = popped.first;
      if( currIdx[poppedEmpIdx] < finalIdx[poppedEmpIdx])
      {
        currIdx[poppedEmpIdx]++;
        intPQ.push(make_pair(poppedEmpIdx,schedule[poppedEmpIdx][currIdx[poppedEmpIdx]]));        
      }

      if(popped.second.start > runningInterval.end)
      {
        result.push_back(Interval(runningInterval.end, popped.second.start));
        runningInterval.start = popped.second.start;
        runningInterval.end = popped.second.end;
      }
      else if ( popped.second.end > runningInterval.end)
      {
        runningInterval.end = popped.second.end;
      }
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<Interval>> input = {{{1, 3}, {5, 6}}, {{2, 3}, {6, 8}}};
  vector<Interval> result = EmployeeFreeTime::findEmployeeFreeTime(input);
  cout << "Free intervals: ";
  for (auto interval : result) {
    cout << "[" << interval.start << ", " << interval.end << "] ";
  }
  cout << endl;

  input = {{{1, 3}, {9, 12}}, {{2, 4}}, {{6, 8}}};
  result = EmployeeFreeTime::findEmployeeFreeTime(input);
  cout << "Free intervals: ";
  for (auto interval : result) {
    cout << "[" << interval.start << ", " << interval.end << "] ";
  }
  cout << endl;

  input = {{{1, 3}}, {{2, 4}}, {{3, 5}, {7, 9}}};
  result = EmployeeFreeTime::findEmployeeFreeTime(input);
  cout << "Free intervals: ";
  for (auto interval : result) {
    cout << "[" << interval.start << ", " << interval.end << "] ";
  }
}
