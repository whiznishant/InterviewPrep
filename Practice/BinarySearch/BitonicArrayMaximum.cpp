/*
Problem Statement#
Find the maximum value in a given Bitonic array. An array is considered bitonic if it is monotonically increasing and then monotonically decreasing. Monotonically increasing or decreasing means that for any index i in the array arr[i] != arr[i+1].

Example 1:

Input: [1, 3, 8, 12, 4, 2]
Output: 12
Explanation: The maximum number in the input bitonic array is '12'.
Example 2:

Input: [3, 8, 3, 1]
Output: 8
Example 3:

Input: [1, 3, 8, 12]
Output: 12
Example 4:

Input: [10, 9, 8]
Output: 10
*/

///////////////****************** Revise again ************************ ///////////////


using namespace std;

#include <iostream>
#include <vector>

class MaxInBitonicArray {
 public:
  static int findMax(const vector<int>& arr) {
    int start = 0, end = arr.size() - 1;
    int result  = -1;
    while (start <= end)
    {
      int mid = start + (end - start) / 2;
      if( (mid < arr.size()-1  && mid >= 1 ) )
      {
        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
          return arr[mid];
      }
      if (arr[mid] > arr[mid - 1])
      {
        result = arr[mid];
        start = mid + 1;
      } 
      else 
      {
        end = mid - 1;
      }
    }
    
    return result;
  }
};

int main(int argc, char* argv[]) {
  cout << MaxInBitonicArray::findMax(vector<int>{1, 3, 8, 12, 4, 2}) << endl;
  cout << MaxInBitonicArray::findMax(vector<int>{3, 8, 3, 1}) << endl;
  cout << MaxInBitonicArray::findMax(vector<int>{1, 3, 8, 12}) << endl;
  cout << MaxInBitonicArray::findMax(vector<int>{10, 9, 8}) << endl;
}
