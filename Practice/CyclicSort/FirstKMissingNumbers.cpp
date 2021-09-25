/*
Find the First K Missing Positive Numbers (hard)#
Given an unsorted array containing numbers and a number ‘k’, find the first ‘k’ missing positive numbers in the array.

Example 1:

Input: [3, -1, 4, 5, 5], k=3
Output: [1, 2, 6]
Explanation: The smallest missing positive numbers are 1, 2 and 6.
Example 2:

Input: [2, 3, 4], k=3
Output: [1, 5, 6]
Explanation: The smallest missing positive numbers are 1, 5 and 6.
Example 3:

Input: [-2, -3, 4], k=2
Output: [1, 2]
Explanation: The smallest missing positive numbers are 1 and 2.
*/

using namespace std;

#include <iostream>
#include <unordered_set>
#include <vector>

class FirstKMissingPositive {
 public:
  static vector<int> findNumbers(vector<int> &nums, int k) {
    vector<int> missingNumbers;
    
    unordered_set<int> overFlowNums;
    // TODO: Write your code here  
    int i = 0;
    while ( i < nums.size() )
    {
      if(nums[i] != i+1 && nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] -1])
      {
        int temp = nums[nums[i]-1];
        nums[nums[i]-1] = nums[i];
        nums[i] = temp;
      }
      else
      {
        if(nums[i] > nums.size() ) 
        {
          overFlowNums.insert(nums[i]);
        }
        i++;      
      }
    }

    for(int i=0;i < nums.size() && missingNumbers.size() < k;i++)
    {
      if(nums[i] != i+1)
      {
        missingNumbers.push_back(i+1);
      }
    }
    if(missingNumbers.size() < k)
    {
      int curr = nums.size() + 1 ;
      while( missingNumbers.size() != k)
      {
        if( overFlowNums.find(curr) == overFlowNums.end())
        {
          missingNumbers.push_back(curr);
        }
        curr+=1;
      }
    }

    return missingNumbers;
  }
};


int main(int argc, char *argv[]) {
  vector<int> v1 = {3, -1, 4, 5, 5};
  vector<int> missingNumbers = FirstKMissingPositive::findNumbers(v1, 3);
  cout << "Missing numbers: ";
  for (auto num : missingNumbers) {
    cout << num << " ";
  }
  cout << endl;

  v1 = {2, 3, 4};
  missingNumbers = FirstKMissingPositive::findNumbers(v1, 3);
  cout << "Missing numbers: ";
  for (auto num : missingNumbers) {
    cout << num << " ";
  }
  cout << endl;

  v1 = {-2, -3, 4};
  missingNumbers = FirstKMissingPositive::findNumbers(v1, 2);
  cout << "Missing numbers: ";
  for (auto num : missingNumbers) {
    cout << num << " ";
  }
  cout << endl;


  v1 = {6, 100, 123};
  missingNumbers = FirstKMissingPositive::findNumbers(v1, 7);
  cout << "Missing numbers: ";
  for (auto num : missingNumbers) {
    cout << num << " ";}
    
}
