/* Problem Statement #
Given an array of numbers and a number ‘k’, find the median of all the ‘k’ sized sub-arrays (or windows) of the array.

Example 1:

Input: nums=[1, 2, -1, 3, 5], k = 2
Output: [1.5, 0.5, 1.0, 4.0]
Explanation: Lets consider all windows of size ‘2’:

[1, 2, -1, 3, 5] -> median is 1.5
[1, 2, -1, 3, 5] -> median is 0.5
[1, 2, -1, 3, 5] -> median is 1.0
[1, 2, -1, 3, 5] -> median is 4.0
Example 2:

Input: nums=[1, 2, -1, 3, 5], k = 3
Output: [1.0, 2.0, 3.0]
Explanation: Lets consider all windows of size ‘3’:

[1, 2, -1, 3, 5] -> median is 1.0
[1, 2, -1, 3, 5] -> median is 2.0
[1, 2, -1, 3, 5] -> median is 3.0

*/

using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class SlidingWindowMedian {
 public:
  SlidingWindowMedian()
  {
      maxHeapActualSize = 0;
      minHeapActualSize = 0;
  }
  
  class HeapElement {
    public: 
    int element;
    int index;
    HeapElement(int elem,int idx):element(elem),index(idx)
    {}
  };

  struct maxHeapComparator
  {
    bool operator()(HeapElement &lhs, HeapElement &rhs )
    {
      return lhs.element<rhs.element;
    }
  };

  struct minHeapComparator
  {
    bool operator()(HeapElement &lhs, HeapElement &rhs )
    {
      return lhs.element>rhs.element;
    }
  };

  priority_queue<HeapElement,vector<HeapElement>, maxHeapComparator> maxHeap;
  priority_queue<HeapElement,vector<HeapElement>, minHeapComparator> minHeap;
  int maxHeapActualSize;
  int minHeapActualSize;
  
  void ReBalanceHeaps( int windowStart )
  {
      if( maxHeapActualSize == 0 && minHeapActualSize == 0)
         return;

      if( maxHeapActualSize > minHeapActualSize + 1)
      {
          minHeap.push(maxHeap.top());
          maxHeap.pop();
          minHeapActualSize++;
          maxHeapActualSize--;
      }
      else if ( minHeapActualSize > maxHeapActualSize )
      {
          maxHeap.push(minHeap.top());
          minHeap.pop();
          minHeapActualSize--;
          maxHeapActualSize++;
      }

      if( maxHeap.size() > 0 && maxHeap.top().index < windowStart )
      {
          maxHeap.pop();
          ReBalanceHeaps( windowStart );
      }

      if( minHeap.size() > 0 && minHeap.top().index < windowStart )
      {
          minHeap.pop();
          ReBalanceHeaps(windowStart);
      }
  }

  virtual vector<double> findSlidingWindowMedian(const vector<int> &nums, int k) {
    vector<double> result;//(nums.size() - k + 1);
    // TODO: Write your code here
    while(!maxHeap.empty())
        maxHeap.pop();
    while(!minHeap.empty())
        minHeap.pop();   
    minHeapActualSize = 0;
    maxHeapActualSize = 0;
    
    int windowStart = 0;
    for(int i=0;i < nums.size();i++)
    {
      if ( minHeapActualSize != 0 && maxHeapActualSize == 0 )
      {
         while(minHeap.top().index < windowStart)
            minHeap.pop();
         maxHeap.push(minHeap.top());
         maxHeapActualSize++;
         minHeap.pop();
         minHeapActualSize--;
         ReBalanceHeaps(windowStart);
      }
      
      HeapElement toPush(nums[i],i);
      if(maxHeapActualSize == 0 || nums[i] < (maxHeap.top()).element )
      {      
        maxHeap.push(toPush);
        maxHeapActualSize++;
      }
      else
      {
        minHeap.push(toPush);
        minHeapActualSize++;
      }

      //Rebalance heap 
      ReBalanceHeaps( windowStart );
      
      if( ((i + 1 - windowStart) % k ) == 0 ) // Window reached 
      {
          if( maxHeapActualSize == minHeapActualSize )
          {
              result.push_back( (maxHeap.top().element + minHeap.top().element) / 2.0 );
          }
          else
          {
              result.push_back( maxHeap.top().element );
          }

          // move the window. 
          windowStart++;
          //Check which heap the evicted number belongs.
          if( nums[windowStart-1] <= maxHeap.top().element )  
          {
              maxHeapActualSize--;
          }
          else
          {
              minHeapActualSize--;
          }
      }
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  SlidingWindowMedian slidingWindowMedian;
  vector<double> result =
     // slidingWindowMedian.findSlidingWindowMedian(vector<int>{1, 2, -1, 3, 5}, 2);
     slidingWindowMedian.findSlidingWindowMedian(vector<int>{2147483647,1,2,3,4,5,6,7,2147483647},2) ;
  cout << "Sliding window medians are: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  /*slidingWindowMedian = SlidingWindowMedian();
  result = slidingWindowMedian.findSlidingWindowMedian(vector<int>{1, 2, -1, 3, 5}, 3);
  cout << "Sliding window medians are: ";
  for (auto num : result) {
    cout << num << " ";
  }*/
}