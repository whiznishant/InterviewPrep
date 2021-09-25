/*
Design a class to efficiently find the Kth largest element in a stream of numbers.
The class should have the following two things:
The constructor of the class should accept an integer array containing initial numbers from the stream and an integer ‘K’.
The class should expose a function add(int num) which will store the given number and return the Kth largest number.
Example 1:

Input: [3, 1, 5, 12, 2, 11], K = 4
1. Calling add(6) should return '5'.
2. Calling add(13) should return '6'.
2. Calling add(4) should still return '6'.
*/

using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class KthLargestNumberInStream {
 public:
  vector<int> minHeapContainer;
  KthLargestNumberInStream(const vector<int> &nums, int k) 
  {
    // TODO: Write your code here
    minHeapContainer.clear();
    for(int i=0;i<k;i++)
    {
        minHeapContainer.push_back(nums[i]);
    }

    make_heap(minHeapContainer.begin(),minHeapContainer.end(),std::greater<int>());

    for(int i=k;i<nums.size();i++)
    {
        if(nums[i] > minHeapContainer.front())
        {
           RemoveTopAndPushAnother(nums[i]);
        }
    }
  }

  void RemoveTopAndPushAnother(int num )
  {
    pop_heap(minHeapContainer.begin(),minHeapContainer.end(),std::greater<int>());
    minHeapContainer.pop_back();
    minHeapContainer.push_back(num);
    push_heap(minHeapContainer.begin(),minHeapContainer.end(),std::greater<int>());
  }

  virtual int add(int num) {
    // TODO: Write your code here
    if(num > minHeapContainer.front())
    {
        RemoveTopAndPushAnother(num);
    }
    return minHeapContainer.front();
  }
};

int main(int argc, char *argv[]) {
  KthLargestNumberInStream kthLargestNumber({3, 1, 5, 12, 2, 11}, 4);
  cout << "4th largest number is: " << kthLargestNumber.add(6) << endl;
  cout << "4th largest number is: " << kthLargestNumber.add(13) << endl;
  cout << "4th largest number is: " << kthLargestNumber.add(4) << endl;
}
