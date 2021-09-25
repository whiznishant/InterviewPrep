/*Problem Statement#
Given an array of numbers sorted in ascending order, find the element in the array that has the minimum difference with the given ‘key’.

Example 1:

Input: [4, 6, 10], key = 7
Output: 6
Explanation: The difference between the key '7' and '6' is minimum than any other number in the array 
Example 2:

Input: [4, 6, 10], key = 4
Output: 4
Example 3:

Input: [1, 3, 8, 10, 15], key = 12
Output: 10
Example 4:

Input: [4, 6, 10], key = 17
Output: 10
*/

using namespace std;

#include <iostream>
#include <vector>

class MinimumDifference {
 public:
  static int searchMinDiffElement(const vector<int>& arr, int key) {
    // TODO: Write your code here
    if(key < arr[0])
      return arr[0];
    if(key > arr[arr.size()-1])
      return arr[arr.size()-1];

    int s=0,e=arr.size()-1;
    while(s<=e)
    {
      int mid = s + (e-s)/2;
      if(arr[mid] == key)
        return arr[mid];
      if(key > arr[mid])
      {
        s = mid + 1;
      }
      else
      {
        e = mid - 1;
      }
    }

    if(abs(key - arr[s]) < abs(key - arr[e]))
      return arr[s];
    else
      return arr[e];
  }
};

int main(int argc, char* argv[]) {
  cout << MinimumDifference::searchMinDiffElement(vector<int>{4, 6, 10}, 7) << endl;
  cout << MinimumDifference::searchMinDiffElement(vector<int>{4, 6, 10}, 4) << endl;
  cout << MinimumDifference::searchMinDiffElement(vector<int>{1, 3, 8, 10, 15}, 12) << endl;
  cout << MinimumDifference::searchMinDiffElement(vector<int>{4, 6, 10}, 17) << endl;
}
