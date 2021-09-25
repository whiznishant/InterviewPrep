using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class KthSmallestInMSortedArrays {
 public:
  struct minHeapcompare 
  {
    bool operator()( pair<int,int> &lhs, pair<int,int> &rhs )
    {
      return lhs.second > rhs.second;
    }
  };

  static int findKthSmallest(const vector<vector<int>> &lists, int k) {
    int result = -1;
    // TODO: Write your code here
    priority_queue<pair<int,int>,vector<pair<int,int>>,minHeapcompare> pq;
    vector<int> headNodeIdx(lists.size(),0);
    for(int i=0;i<lists.size();i++)
    {
      if(headNodeIdx[i]< lists[i].size())
      {
        pq.push(make_pair(i, lists[i][headNodeIdx[i]]));
        headNodeIdx[i]++;
      }
    }
    int numSeen = 0;
    while(!pq.empty() && numSeen <= k)
    {
       pair<int,int> tempRes = pq.top();
       pq.pop();
       numSeen += 1;
       if( numSeen == k )
       {
         result = tempRes.second;
         break;
       }
       int listIdxPopped = tempRes.first;

       if( headNodeIdx[listIdxPopped] < lists[listIdxPopped].size())
       {
          pq.push(make_pair(listIdxPopped,lists[listIdxPopped][headNodeIdx[listIdxPopped]]));
          headNodeIdx[listIdxPopped] += 1;
       }
    }

    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> lists = {{2, 6, 8}, {3, 6, 7}, {1, 3, 4}};
  int result = KthSmallestInMSortedArrays::findKthSmallest(lists, 5);
  cout << "Kth smallest number is: " << result;
}
