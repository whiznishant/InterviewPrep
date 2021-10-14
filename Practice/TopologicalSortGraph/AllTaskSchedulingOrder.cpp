/*
There are ‘N’ tasks, labeled from ‘0’ to ‘N-1’. Each task can have some prerequisite tasks which need to be completed before it can be scheduled. Given the number of tasks and a list of prerequisite pairs, write a method to print all possible ordering of tasks meeting all prerequisites.

Example 1:
Input: Tasks=3, Prerequisites=[0, 1], [1, 2]
Output: [0, 1, 2]
Explanation: There is only possible ordering of the tasks.

Example 2:
Input: Tasks=4, Prerequisites=[3, 2], [3, 0], [2, 0], [2, 1]
Output: 
1) [3, 2, 0, 1]
2) [3, 2, 1, 0]
Explanation: There are two possible orderings of the tasks meeting all prerequisites.

Example 3:
Input: Tasks=6, Prerequisites=[2, 5], [0, 5], [0, 4], [1, 4], [3, 2], [1, 3]
Output: 
1) [0, 1, 4, 3, 2, 5]
2) [0, 1, 3, 4, 2, 5]
3) [0, 1, 3, 2, 4, 5]
4) [0, 1, 3, 2, 5, 4]
5) [1, 0, 3, 4, 2, 5]
6) [1, 0, 3, 2, 4, 5]
7) [1, 0, 3, 2, 5, 4]
8) [1, 0, 4, 3, 2, 5]
9) [1, 3, 0, 2, 4, 5]
10) [1, 3, 0, 2, 5, 4]
11) [1, 3, 0, 4, 2, 5]
12) [1, 3, 2, 0, 5, 4]
13) [1, 3, 2, 0, 4, 5]

*/
using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class AllTaskSchedulingOrders {
 public:
  static void printOrders(int tasks, vector<vector<int>> &prerequisites){
    // TODO: Write your code here
    vector<int> sortedOrder;
    // TODO: Write your code here
    //Create a adjaceny list and populate indegree
    unordered_map<int,vector<int>> adjMat;
    vector<int> inDegree(tasks);
    vector<bool> visited(tasks);
    
    for(int i=0;i < tasks;i++)
    {
      inDegree[i] = 0;
      visited[i] = false;
      adjMat[i] = {}; 
    }
    for(auto x:prerequisites)
    {
      adjMat[x[0]].push_back(x[1]);
      inDegree[x[1]]++;
    }    
    vector<int> out;
    PrintRecursive(tasks,adjMat,inDegree,visited, out);
  }

  static void PrintRecursive(int &tasks,unordered_map<int,vector<int>> &adjMat, vector<int> &inDegrees, vector<bool> &visited,vector<int> &out)
  {
    if(out.size() == tasks)
    {
      cout<<endl;
      for(auto x: out)
        cout<< x<<" ";
      return;
    }
    for(int i=0;i<tasks;i++)
    {
      if(inDegrees[i] == 0 && visited[i] == false )
      {
        out.push_back(i);
        visited[i] = true;
        for(auto x: adjMat[i])
        {
          inDegrees[x]--;
        }
        PrintRecursive(tasks,adjMat,inDegrees,visited,out);
        out.pop_back();
        visited[i] = false;
        for(auto x: adjMat[i])
        {
          inDegrees[x]++;
        }
      }
    }
  }

};



int main(int argc, char *argv[]) {
  vector<vector<int>> vec = {{0, 1}, {1, 2}};
  AllTaskSchedulingOrders::printOrders(3, vec);
  cout << endl;

  vec = {{3, 2}, {3, 0}, {2, 0}, {2, 1}};
  AllTaskSchedulingOrders::printOrders(4, vec);
  cout << endl;

  vec = {{2, 5}, {0, 5}, {0, 4}, {1, 4}, {3, 2}, {1, 3}};
  AllTaskSchedulingOrders::printOrders(6, vec);
  cout << endl;
}