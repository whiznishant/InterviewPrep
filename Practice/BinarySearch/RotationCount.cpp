/*
Rotation Count (medium)#
Given an array of numbers which is sorted in ascending order and is rotated ‘k’ times around a pivot, find ‘k’.

You can assume that the array does not have any duplicates.

Example 1:

Input: [10, 15, 1, 3, 8]
Output: 2
Explanation: The array has been rotated 2 times.
*/
using namespace std;
#include <iostream>
#include <vector>

class RotationCountOfRotatedArray {
 public:
  static int countRotations(const vector<int>& arr) {
    // TODO: Write your code here
    // Index of the minimum element will be the number of rotations
    // Minimum element will be next to a maximum element so we can search for max element and then 
    // figure out the min element in a circular array.

    int s=0, e = arr.size()-1;
    int maxElemIdx = -1;
    while(s<=e)    
    {
        int mid = s + (e-s)/2;
        if( mid > 0 && mid < arr.size()-1 )
        {
            if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]) 
            {
                maxElemIdx = mid;
                break;
            }
        }

        if(arr[mid] >= arr[s]) //left is correctly sorted out, so our max will be on right side
        {
            maxElemIdx = mid;
            s = mid + 1;
        }
        else
        {
            e = mid -1; 
        }
    }
    if(maxElemIdx == arr.size()-1) // no rotation
    {
        return 0;
    }
    
    return maxElemIdx + 1; //min element will be next to max
  }
};

int main(int argc, char* argv[]) {
  cout << RotationCountOfRotatedArray::countRotations(vector<int>{10, 15, 1, 3, 8}) << endl;
  cout << RotationCountOfRotatedArray::countRotations(vector<int>{4, 5, 7, 9, 10, -1, 2}) << endl;
  cout << RotationCountOfRotatedArray::countRotations(vector<int>{1, 3, 8, 10}) << endl;
}



