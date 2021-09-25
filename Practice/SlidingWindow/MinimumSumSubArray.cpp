/*

Problem Statement #
Given an array of positive numbers and a positive number ‘S,’ find the length of the smallest contiguous subarray whose sum is greater than or equal to ‘S’. Return 0 if no such subarray exists.

Example 1:

Input: [2, 1, 5, 2, 3, 2], S=7 
Output: 2
Explanation: The smallest subarray with a sum greater than or equal to '7' is [5, 2].
Example 2:

Input: [2, 1, 5, 2, 8], S=7 
Output: 1
Explanation: The smallest subarray with a sum greater than or equal to '7' is [8].
Example 3:

Input: [3, 4, 1, 1, 6], S=8 
Output: 3
Explanation: Smallest subarrays with a sum greater than or equal to '8' are [3, 4, 1] 
or [1, 1, 6].

*/



using namespace std;

#include <iostream>
#include <limits>
#include <vector>
#include <limits.h>

class MinSizeSubArraySum {
 public:
  static int findMinSubArray(int S, const vector<int>& arr) {
    // TODO: Write your code here
    int minimum = INT_MAX;
    int left = 0,right = 0;int currSum = 0;
    while(left <= right && right < arr.size())
    {
      currSum += arr[right];
      while( currSum >= S && left <= right)
      {
        minimum = min(minimum, (right-left+1));
        currSum -= arr[left];
        left++;
      }  
      right++;            
    }

    if(minimum == INT_MAX)
      minimum = 0;
    return minimum;
  }
};

int main()
{
    vector<int> inp = {2,1,5,2,8};
    int out = MinSizeSubArraySum::findMinSubArray(7,inp);
    cout<<out;
}