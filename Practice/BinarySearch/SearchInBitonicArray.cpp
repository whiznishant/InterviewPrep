/*
Search Bitonic Array (medium)#
Given a Bitonic array, find if a given ‘key’ is present in it. An array is considered bitonic if it is monotonically increasing and then monotonically decreasing. Monotonically increasing or decreasing means that for any index i in the array arr[i] != arr[i+1].

Write a function to return the index of the ‘key’. If the ‘key’ is not present, return -1.

Example 1:
Input: [1, 3, 8, 4, 3], key=4
Output: 3

Example 2:
Input: [3, 8, 3, 1], key=8
Output: 1

Example 3:
Input: [1, 3, 8, 12], key=12
Output: 3

Example 4:
Input: [10, 9, 8], key=10
Output: 0
*/

using namespace std;

#include <iostream>
#include <vector>

class SearchBitonicArray {
 public:
  static int bsearch( const vector<int> &arr,int key,int s,int e )
  {
      bool asc = arr[s] < arr[e];
      while(s <= e)
      {
        int mid = s + (e-s)/2;
        if( arr[mid] == key )
            return mid;
       
        if ( asc )
        {
            if( arr[mid] < key )
                s = mid + 1;
            else
                e = mid - 1;
        }
        else
        {
            if( arr[mid] < key )
                e = mid - 1;                
            else
               s = mid + 1;
        }
      }
      return -1;
  }

  static int findBitonicArrayMax( const vector<int> &arr )
  {
      int s = 0, e = arr.size()-1;
      int maxElemIdx = -1;
      while(s <= e)
      {
          int mid = s + (e-s)/2;

          if( mid > 0 && mid < arr.size()-1 )
          {
            if( arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
                return mid;
          }
          if(arr[mid] > arr[mid-1]) //We are still in the increasing side.
          {
              maxElemIdx = mid; // this can be a potential result
              s = mid + 1;
          }
          else
          {
              e = mid - 1;
          }
      }
      return maxElemIdx;
  }

  static int search(const vector<int> &arr, int key) 
  {
      //Find the max index in bitonic array then we can bsearch both sides.
      int arrDiv = findBitonicArrayMax(arr);
      if(arrDiv == 0 || arrDiv == arr.size()- 1 ) // either we have strictly decreasing array or strictly increasing array.
      {
        return bsearch(arr,key,0,arr.size()-1);
      }
      else  // its in middle somewhere 
      {
        int res1 = bsearch(arr,key,0,arrDiv);
        int res2 = bsearch(arr,key,arrDiv,arr.size()-1);
        if(res1 != -1)
            return res1;
        if(res2 != -1)
            return res2;
      } 
      return -1;
  }

};

int main(int argc, char *argv[]) {
  cout << SearchBitonicArray::search(vector<int>{1, 3, 8, 4, 3}, 4) << endl;
  cout << SearchBitonicArray::search(vector<int>{3, 8, 3, 1}, 8) << endl;
  cout << SearchBitonicArray::search(vector<int>{1, 3, 8, 12}, 12) << endl;
  cout << SearchBitonicArray::search(vector<int>{10, 9, 8}, 10) << endl;
}


