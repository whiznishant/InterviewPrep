/*

You are given a list of tasks that need to be run, in any order, on a server. Each task will take one CPU interval to execute but once a task has finished, it has a cooling period during which it can’t be run again. If the cooling period for all tasks is ‘K’ intervals, find the minimum number of CPU intervals that the server needs to finish all tasks.

If at any time the server can’t execute any task then it must stay idle.

Example 1:

Input: [a, a, a, b, c, c], K=2
Output: 7
Explanation: a -> c -> b -> a -> c -> idle -> a
Example 2:

Input: [a, b, a], K=3
Output: 5
Explanation: a -> b -> idle -> idle -> a

*/


using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class TaskScheduler {
 public:
  struct compare
  {
      bool operator()( pair<char,int> &lhs, pair<char,int> &rhs )
      {
          return lhs.second < rhs.second;
      }
  };
  static int scheduleTasks(vector<char> &tasks, int k) {
    // TODO: Write your code here
    if(k==0)
        return tasks.size();

    unordered_map<char,int> freqMap;
    for(auto x:tasks)
        freqMap[x] += 1;

    priority_queue<pair<char,int>,vector<pair<char,int>>, compare>  maxHeap;
    for(auto x: freqMap)
        maxHeap.push(x);

    // Now the maxsize will be defined by interval * (max-1) for the max occuring element.
    // Let us say we have maximum 4 A's and interval is 2, then the least size we need is 
    // A _ _ A _ _ A _ _ A   =  6 holes  + 4 A's = 10 ;

    int maxFreq = maxHeap.top().second;
    int initialHoles = (( maxFreq - 1) * k);
    int initialEstimate = maxFreq + initialHoles;
    maxHeap.pop();
    while( maxHeap.top().second == maxFreq && !maxHeap.empty())
    {
        initialHoles -= maxFreq -1;
        initialEstimate++;
        maxHeap.pop();
    }

    // Find number of elements left in heap
    int remaining = 0;
    while(!maxHeap.empty())
    {
        remaining += maxHeap.top().second;
        maxHeap.pop();
    }

    if( remaining < initialHoles )
        return initialEstimate;
    else
        return initialEstimate + (remaining - initialHoles);
  }
};

int main(int argc, char *argv[]) {
  vector<char> tasks = {'a', 'a', 'a', 'b', 'b', 'b', 'c', 'c', 'c', 'd', 'd', 'e','e','e'};
  cout << "Minimum intervals needed to execute all tasks: "
       << TaskScheduler::scheduleTasks(tasks, 2) << endl;

  tasks = {'a', 'b', 'c', 'd', 'e', 'a', 'b', 'c', 'd', 'e'};
  cout << "Minimum intervals needed to execute all tasks: "
       << TaskScheduler::scheduleTasks(tasks, 4) << endl;

  tasks = {'a', 'a', 'a', 'b', 'c', 'c'};
  cout << "Minimum intervals needed to execute all tasks: "
       << TaskScheduler::scheduleTasks(tasks, 2) << endl;

  tasks = vector<char>{'a', 'b', 'a'};
  cout << "Minimum intervals needed to execute all tasks: "
       << TaskScheduler::scheduleTasks(tasks, 3) << endl;

  tasks = vector<char>{'A','A','A','B','B','B'};
  cout << "Minimum intervals needed to execute all tasks: "
       << TaskScheduler::scheduleTasks(tasks, 0) << endl; 
}


