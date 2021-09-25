/*

Given a set with distinct elements, find all of its distinct subsets.

Example 1:

Input: [1, 3]
Output: [], [1], [3], [1,3]
Example 2:

Input: [1, 5, 3]
Output: [], [1], [5], [3], [1,5], [1,3], [5,3], [1,5,3]

*/



using namespace std;

#include <iostream>
#include <vector>

class Subsets {
 public:
  static vector<vector<int>> findSubsets(const vector<int>& nums) {
    vector<vector<int>> subsets;
    subsets.push_back({});
    // TODO: Write your code here
    for(int i = 0; i< nums.size(); i++)
    {
      int sz = subsets.size();
      for(int j = 0;j < sz;j++)
      {
        vector<int> temp = subsets[j];
        temp.push_back(nums[i]);
        subsets.push_back(temp);
      }
    }
    return subsets;
  }
};

int main(int argc, char* argv[]) {
  vector<vector<int>> result = Subsets::findSubsets(vector<int>{1, 3});
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }

  result = Subsets::findSubsets(vector<int>{1, 5, 3});
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
