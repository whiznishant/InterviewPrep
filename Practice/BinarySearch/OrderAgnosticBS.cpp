/*Problem Statement #
Given a sorted array of numbers, find if a given number ‘key’ is present in the array. Though we know that the array is sorted, we don’t know if it’s sorted in ascending or descending order. You should assume that the array can have duplicates.

Write a function to return the index of the ‘key’ if it is present in the array, otherwise return -1.

Example 1:

Input: [4, 6, 10], key = 10
Output: 2
Example 2:

Input: [1, 2, 3, 4, 5, 6, 7], key = 5
Output: 4
Example 3:

Input: [10, 6, 4], key = 10
Output: 0
Example 4:

Input: [10, 6, 4], key = 4
Output: 2
*/

using namespace std;

#include <iostream>
#include <vector>

class BinarySearch {
 public:

  static int searchRecur(const vector<int>& arr,int s,int e, int key, bool asc )
  {
    if(s == e)
    {
      if(key == arr[s])
        return s;
      else 
        return -1;
    }
    int mid = (s+e)/2; 
    if(arr[mid]== key)
      return mid;
    if( asc )
    {
      if (key > arr[mid])
       return searchRecur(arr,mid+1,e,key,asc);
      else
       return searchRecur(arr,s,mid,key,asc);
    }
    else
    {
      if (key > arr[mid])
        return searchRecur(arr,s,mid,key,asc);
      else
        return searchRecur(arr,mid+1,e,key,asc); 
    }
  }


  static int search(const vector<int>& arr, int key) {
    // TODO: Write your code here
    bool asc = arr[0] < arr[arr.size()-1];
    //return searchRecur( arr,0,arr.size(),key,asc); 
    //Non recursive version
    int s = 0;int e = arr.size()-1;
    while(s <= e)
    {
      int mid = s + ((e-s)/2);   // To prevent overflow if the size of arry = INT_MAX we should use this instead of (s+e)/2
      if(key == arr[mid])
        return mid;

      if(asc)
      {
         if(key > arr[mid]) 
            s=mid+1;
         else
            e = mid-1;
      }
      else
      {
         if(key > arr[mid]) 
          e = mid-1;
         else
          s=mid+1;           
      }
    }
    return -1;
  }
};

int main(int argc, char* argv[]) {
  cout << BinarySearch::search(vector<int>{4, 6, 10}, 10) << endl;
  cout << BinarySearch::search(vector<int>{1, 2, 3, 4, 5, 6, 7}, 5) << endl;
  cout << BinarySearch::search(vector<int>{10, 6, 4}, 10) << endl;
  cout << BinarySearch::search(vector<int>{10, 6, 4}, 4) << endl;
}

