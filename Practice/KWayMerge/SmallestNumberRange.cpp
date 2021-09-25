/* Problem Statement #
Given ‘M’ sorted arrays, find the smallest range that includes at least one number from each of the ‘M’ lists.

Example 1:

Input: L1=[1, 5, 8], L2=[4, 12], L3=[7, 8, 10]
Output: [4, 7]
Explanation: The range [4, 7] includes 5 from L1, 4 from L2 and 7 from L3.
Example 2:

Input: L1=[1, 9], L2=[4, 12], L3=[7, 10, 16]
Output: [9, 12]
Explanation: The range [9, 12] includes 9 from L1, 12 from L2 and 10 from L3. 

*/

using namespace std;

#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>

class SmallestRange {
 public:
  struct compare
  {
    bool operator()(pair<int,int> &lhs, pair<int,int> &rhs)
    {
      return lhs.second > rhs.second;
    }
  };

  static pair<int, int> findSmallestRange(const vector<vector<int>> &lists) 
  {
    priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
    vector<int> headIdx(lists.size(),0);
    // Add first elements in pq
    //Find the max number initially among the lists
    pair<int,int> maxValInPQ = make_pair(-1,INT_MIN); 
    for(int i=0;i < lists.size();i++ )
    { 
      pq.push(make_pair(i,lists[i][0]));
      if(lists[i][0] > maxValInPQ.second)
      {
        maxValInPQ = make_pair(i,lists[i][0]);
      }
      headIdx[i] += 1;
    }

    int minRange = INT_MAX;
    pair<int,int> minRangeVal;
    
    while(pq.size() == lists.size())
    {
      pair<int,int> temp = pq.top();
      pq.pop();
      if((maxValInPQ.second - temp.second) < minRange)
      {
        minRange = maxValInPQ.second - temp.second;
        minRangeVal  = make_pair(temp.second,maxValInPQ.second);
      }
      
      if( headIdx[temp.first] < (lists[temp.first]).size())
      {
        if(lists[temp.first][headIdx[temp.first]] > maxValInPQ.second)
        {
          maxValInPQ.first = temp.first;
          maxValInPQ.second = lists[temp.first][headIdx[temp.first]];
        }        
        pq.push(make_pair(temp.first, lists[temp.first][headIdx[temp.first]]));
         headIdx[temp.first] += 1;
      }
    }
    return minRangeVal;
  }
};


int main(int argc, char *argv[]) {
  vector<vector<int>> lists = {{1, 5, 8}, {4, 12}, {7, 8, 10}};
  auto result = SmallestRange::findSmallestRange(lists);
  cout << "Smallest range is: [" << result.first << ", " << result.second << "]";
}