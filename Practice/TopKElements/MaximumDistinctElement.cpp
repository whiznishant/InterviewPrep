/*
Given an array of numbers and a number ‘K’, we need to remove ‘K’ numbers from the array such that we are left with maximum distinct numbers.

Example 1:

Input: [7, 3, 5, 8, 5, 3, 3], and K=2
Output: 3
Explanation: We can remove two occurrences of 3 to be left with 3 distinct numbers [7, 3, 8], we have to skip 5 because it is not distinct and appeared twice. 

Another solution could be to remove one instance of '5' and '3' each to be left with three distinct numbers [7, 5, 8], in this case, we have to skip 3 because it appeared twice.
Example 2:

Input: [3, 5, 12, 11, 12], and K=3
Output: 2
Explanation: We can remove one occurrence of 12, after which all numbers will become distinct. Then we can delete any two numbers which will leave us 2 distinct numbers in the result.
Example 3:

Input: [1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5], and K=2
Output: 3
Explanation: We can remove one occurrence of '4' to get three distinct numbers.

*/

using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class MaximumDistinctElements {
 public:
  struct compare
  {
    bool operator()( pair<int,int> &lhs, pair<int,int> &rhs)
    {
      return lhs.second > rhs.second;
    }
  };
  static int findMaximumDistinctElements(const vector<int> &nums, int k) {
    int distinctElementsCount = 0;
    // TODO: Write your code here
    unordered_map<int,int> freqMap; 
    for(auto x:nums)
      freqMap[x] += 1;
    
    //push the elements with atleast 2 elements to the minheap
    priority_queue<pair<int,int>,vector<pair<int,int>>, compare >  minHeap;
    for(auto x:freqMap)
    {
      if(x.second > 1)
        minHeap.push(x);
    }

    int numOfUniqueElements = freqMap.size()-minHeap.size();

    //Now from the min heap try to make uniqueElements till we exhaust k;  
    int toRemove = k;
    while(toRemove > 0 && minHeap.size() > 0 )
    {
      auto top = minHeap.top();
      toRemove -=  top.second - 1;
      if( toRemove < 0 ) // we cannot fully make this number unique, so break;
        break;      
      numOfUniqueElements += 1;
      minHeap.pop();     
    }

    if( toRemove > 0 )
      numOfUniqueElements -= toRemove;

    distinctElementsCount = numOfUniqueElements;

    return distinctElementsCount;
  }
};

int main(int argc, char *argv[]) {
  int result = MaximumDistinctElements::findMaximumDistinctElements(vector<int>{7, 3, 5, 8, 5, 3, 3}, 2);  
  cout << "Maximum distinct numbers after removing K numbers: " << result << endl;
  result = MaximumDistinctElements::findMaximumDistinctElements(vector<int>{3, 5, 12, 11, 12}, 3);      
  cout << "Maximum distinct numbers after removing K numbers: " << result << endl;
  result = MaximumDistinctElements::findMaximumDistinctElements(
      vector<int>{1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5}, 2);
  cout << "Maximum distinct numbers after removing K numbers: " << result << endl;

  result = MaximumDistinctElements::findMaximumDistinctElements(
      vector<int>{1, 2, 3, 4, 5}, 2);
  cout << "Maximum distinct numbers after removing K numbers: " << result << endl;
}

