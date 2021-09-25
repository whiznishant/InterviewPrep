using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class Meeting {
 public:
  int start = 0;
  int end = 0;

  Meeting(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class MinimumMeetingRooms {
 public:
 
/*static int findMinimumMeetingRooms(vector<Meeting> &meetings) {
    // TODO: Write your code here
    sort(meetings.begin(),meetings.end(),
    [](Meeting &lhs,Meeting &rhs){
      if(lhs.start != rhs.start )
      {
       return lhs.start < rhs.start;
      }
      else
      {
        return lhs.end < rhs.end;  
      }});
    
    vector<int> endTimes;
    endTimes.push_back(meetings[0].end);
    for(int i=1;i<meetings.size();i++)
    {
      int j = 0;
      for(;j < endTimes.size();j++)
      {
        if(meetings[i].start >= endTimes[j])
        {
          endTimes[j] = meetings[i].end;
          break;
        }        
      }
      if( j == endTimes.size())
        endTimes.push_back(meetings[i].end);
    }
    return endTimes.size();
  }
}; */

static int findMinimumMeetingRooms(vector<Meeting> &meetings) {
    // TODO: Write your code here
    sort(meetings.begin(),meetings.end(),
    [](Meeting &lhs,Meeting &rhs){
      if(lhs.start != rhs.start )
      {
       return lhs.start < rhs.start;
      }
      else
      {
        return lhs.end < rhs.end;  
      }});
    
    priority_queue<int,vector<int>,std::greater<int>> endTimes;
    endTimes.push(meetings[0].end);
    for(int i=1;i<meetings.size();i++)
    {
        if(meetings[i].start >= endTimes.top())
        {
          int t = endTimes.top();
          endTimes.pop();
          endTimes.push(meetings[i].end);          
        }
        else
        {
          endTimes.push(meetings[i].end);
        }        
    }
    return endTimes.size();
  }
}; 




int main(int argc, char *argv[]) {
  vector<Meeting> input = {{4, 5}, {2, 3}, {2, 4}, {3, 5}};
  int result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

  input = {{1, 4}, {2, 5}, {7, 9}};
  result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

  input = {{6, 7}, {2, 4}, {8, 12}};
  result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

  input = {{1, 4}, {2, 3}, {3, 6}};
  result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

  input = {{4, 5}, {2, 3}, {2, 4}, {3, 5}};
  result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;
}
