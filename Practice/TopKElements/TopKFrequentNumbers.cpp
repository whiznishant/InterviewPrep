
/*
Problem Statement#
Given an unsorted array of numbers, find the top ‘K’ frequently occurring numbers in it.

Example 1:

Input: [1, 3, 5, 12, 11, 12, 11], K = 2
Output: [12, 11]
Explanation: Both '11' and '12' apeared twice.
Example 2:

Input: [5, 12, 11, 3, 11], K = 2
Output: [11, 5] or [11, 12] or [11, 3]
Explanation: Only '11' appeared twice, all other numbers appeared once.
*/


using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class TopKFrequentNumbers {
  struct valueCompare
  {
    char operator()(const pair<int, int> &x, const pair<int, int> &y) 
    {
      return x.second > y.second;
    }
  };

 public:
  static vector<int> findTopKFrequentNumbers(const vector<int> &nums, int k) 
  {
    vector<int> topNumbers;
    unordered_map<int,int> freqMap;
    for(auto x: nums)
        freqMap[x] += 1;
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,valueCompare> minHeap;

    for(auto x:freqMap)                 //Revise this part correctly , did not figure this out on my own. 
    {
        minHeap.push(x);
        if(minHeap.size() > k)
        {
            minHeap.pop();
        }
    }
    while(!minHeap.empty())
    {
        topNumbers.push_back((minHeap.top()).first);
        minHeap.pop();
    }    
    // TODO: Write your code here
    return topNumbers;
  }
};

int main(int argc, char *argv[]) {
  vector<int> result =
      TopKFrequentNumbers::findTopKFrequentNumbers(vector<int>{1, 3, 5, 12, 11, 12, 11}, 2);
  cout << "Here are the K frequent numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = TopKFrequentNumbers::findTopKFrequentNumbers(vector<int>{5, 12, 11, 3, 11}, 2);
  cout << "Here are the K frequent numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
