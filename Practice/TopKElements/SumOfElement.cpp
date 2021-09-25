/*
Problem Statement#
Given an array, find the sum of all numbers between the K1’th and K2’th smallest elements of that array.

Example 1:

Input: [1, 3, 12, 5, 15, 11], and K1=3, K2=6
Output: 23
Explanation: The 3rd smallest number is 5 and 6th smallest number 15. The sum of numbers coming
between 5 and 15 is 23 (11+12).
Example 2:

Input: [3, 5, 8, 7], and K1=1, K2=4
Output: 12
Explanation: The sum of the numbers between the 1st smallest number (3) and the 4th smallest 
number (8) is 12 (5+7).
*/

using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class SumOfElements {
 public:
  static int findSumOfElements(const vector<int> &nums, int k1, int k2) {
    int elementSum = 0;
    // TODO: Write your code here
    priority_queue<int> maxHeap;
    for(int i=0;i < k2-1; i++)
    {
        maxHeap.push(nums[i]);
    }

    for(int i=k2-1;i<nums.size();i++)
    {
        if(nums[i] < maxHeap.top())
        {
            maxHeap.pop();
            maxHeap.push(nums[i]);
        }
    }

    int popped = 0 ;
    int numsToPop = (k2-1)-(k1);
    while(popped < numsToPop )
    {
        elementSum += maxHeap.top();
        maxHeap.pop();
        popped += 1;
    }

    return elementSum;
  }
};

int main(int argc, char *argv[]) {
  int result = SumOfElements::findSumOfElements(vector<int>{1, 3, 12, 5, 15, 11}, 3, 6);
  cout << "Sum of all numbers between k1 and k2 smallest numbers: " << result << endl;

  result = SumOfElements::findSumOfElements(vector<int>{3, 5, 8, 7}, 1, 4);
  cout << "Sum of all numbers between k1 and k2 smallest numbers: " << result << endl;
}
