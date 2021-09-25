using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class KLargestNumbers {
 public:
  static vector<int> findKLargestNumbers(const vector<int>& nums, int k) {
    vector<int> result;
    // TODO: Write your code here
    vector<int> minHeap(nums.begin(),nums.begin()+k);
    make_heap(minHeap.begin(),minHeap.end(),std::greater<int>());

    for(int i= k ;i < nums.size(); i++)
    {
        if(minHeap.front() < nums[i])
        {
            pop_heap(minHeap.begin(),minHeap.end(), std::greater<int>());
            minHeap.pop_back();
            minHeap.push_back(nums[i]);
            push_heap(minHeap.begin(),minHeap.end(),std::greater<int>());
        }
    }
    result.resize(k);
    for(int i=k-1;i>=0;i--)
    {
        result[i] = minHeap.front();
        pop_heap(minHeap.begin(),minHeap.end(), std::greater<int>());
        minHeap.pop_back();
    }
    return result;
  }
};

int main(int argc, char* argv[]) {
  vector<int> result = KLargestNumbers::findKLargestNumbers(vector<int>{3, 1, 5, 12, 2, 11}, 3);
  cout << "Here are the top 3 numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = KLargestNumbers::findKLargestNumbers(vector<int>{5, 12, 11, -1, 12}, 3);
  cout << "Here are the top 3 numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}