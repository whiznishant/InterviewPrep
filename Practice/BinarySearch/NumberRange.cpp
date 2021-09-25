/*
Given an array of numbers sorted in ascending order, find the range of a given number ‘key’. The range of the ‘key’ will be the first and last position of the ‘key’ in the array.

Write a function to return the range of the ‘key’. If the ‘key’ is not present return [-1, -1].

Example 1:

Input: [4, 6, 6, 6, 9], key = 6
Output: [1, 3]
Example 2:

Input: [1, 3, 8, 10, 15], key = 10
Output: [3, 3]
Example 3:

Input: [1, 3, 8, 10, 15], key = 12
Output: [-1, -1]

*/
using namespace std;

#include <iostream>
#include <vector>
//My solution..  -- O(logN + R )  where R is range .. 
/*
class FindRange {
 public:
  static pair<int, int> findRange(const vector<int> &arr, int key) {
    pair<int, int> result(-1, -1);
    // TODO: Write your code here
    int s=0,e=arr.size()-1;
    int foundIdx = -1;
    while(s<=e)
    {
      int mid = s + (e-s)/2;
      if(arr[mid] == key)
      {
        foundIdx = mid;
        break;
      }
      if(key > arr[mid])
      {
        s = mid + 1;
      }
      else
      {
        e = mid -1;
      }
    }

    if(foundIdx != -1)
    {
      //Find left bounds
      int left = foundIdx;
      while( arr[left] == key && left >=0 )
        left--;
      left++;

      int right = foundIdx;
      while( arr[right] == key && right <= arr.size()-1 )
        right++;
      right--;
      result = make_pair(left,right);
    }
    return result;
  }
};*/


/* Educative solution */  --- O(log N)
class FindRange {
 public:
  static pair<int, int> findRange(const vector<int> &arr, int key) {
    pair<int, int> result(-1, -1);
    result.first = search(arr, key, false);
    if (result.first != -1) {  // no need to search, if 'key' is not present in the input array
      result.second = search(arr, key, true);
    }
    return result;
  }

 private:
  // modified Binary Search
  static int search(const vector<int> &arr, int key, bool findMaxIndex) {
    int keyIndex = -1;
    int start = 0, end = arr.size() - 1;
    while (start <= end) {
      int mid = start + (end - start) / 2;
      if (key < arr[mid]) {
        end = mid - 1;
      } else if (key > arr[mid]) {
        start = mid + 1;
      } else {  // key == arr[mid]
        keyIndex = mid;
        if (findMaxIndex) {
          start = mid + 1;  // search ahead to find the last index of 'key'
        } else {
          end = mid - 1;  // search behind to find the first index of 'key'
        }
      }
    }
    return keyIndex;
  }
};

int main(int argc, char *argv[]) {
  pair<int, int> result = FindRange::findRange(vector<int>{4, 6, 6, 6, 9}, 6);
  cout << "Range: [" << result.first << ", " << result.second << "]" << endl;
  result = FindRange::findRange(vector<int>{1, 3, 8, 10, 15}, 10);
  cout << "Range: [" << result.first << ", " << result.second << "]" << endl;
  result = FindRange::findRange(vector<int>{1, 3, 8, 10, 15}, 12);
  cout << "Range: [" << result.first << ", " << result.second << "]" << endl;
}
