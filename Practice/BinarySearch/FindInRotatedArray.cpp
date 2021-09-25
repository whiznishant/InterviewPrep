/* 
Search in Rotated Array (medium) #
Given an array of numbers which is sorted in ascending order and also rotated by some arbitrary number, find if a given ‘key’ is present in it.

Write a function to return the index of the ‘key’ in the rotated array. If the ‘key’ is not present, return -1. You can assume that the given array does not have any duplicates.

Example 1:

Input: [10, 15, 1, 3, 8], key = 15
Output: 1
Explanation: '15' is present in the array at index '1'.
    1   
    3   
    8   
    10   
    15   
 Original array:  
 Array after 2 rotations:  
    10   
    15   
    1   
    3   
    8   
Example 2:

Input: [4, 5, 7, 9, 10, -1, 2], key = 10
Output: 4
Explanation: '10' is present in the array at index '4'.
 Original array:  
    -1   
    2   
    4   
    5   
    7   
    9   
    10   
    4   
    5   
    7   
    9   
    10   
    -1   
    2   
 Array after 5 rotations:  
Solution #
The problem follows the Binary Search pattern. We can use a similar approach as discussed in Order-agnostic Binary Search and modify it similar to Search Bitonic Array to search for the ‘key’ in the rotated array.

After calculating the middle, we can compare the numbers at indices start and middle. This will give us two options:

If arr[start] <= arr[middle], the numbers from start to middle are sorted in ascending order.
Else, the numbers from middle+1 to end are sorted in ascending order.
Once we know which part of the array is sorted, it is easy to adjust our ranges. For example, if option-1 is true, we have two choices:

By comparing the ‘key’ with the numbers at index start and middle we can easily find out if the ‘key’ lies between indices start and middle; if it does, we can skip the second part => end = middle -1.
Else, we can skip the first part => start = middle + 1.
Let’s visually see this with the above-mentioned Example-2:

 Search 'key' = 10  
 By looking at the sorted part, from its start and end, we can conclude that the key can't be in the sorted part, hence start = middle +1  
 By looking at the sorted part, from its start and end, we can conclude that the key can't be in the sorted part, hence end = middle - 1  
 We have found the key!  
    4   
    5   
    7   
    9   
    10   
    -1   
    2   
    4   
    5   
    7   
    9   
    10   
    -1   
    2   
    4   
    5   
    7   
    9   
    10   
    -1   
    2   
 Since arr[start] <= arr[middle], we can conclude that all numbers from start --> middle are sorted in ascending order  
 Since arr[start] >  arr[middle], we can conclude that all numbers from middle --> end are sorted in ascending order  
Since there are no duplicates in the given array, it is always easy to skip one part of the array in each iteration. However, if there are duplicates, it is not always possible to know which part is sorted. We will look into this case in the ‘Similar Problems’ section.

*/



using namespace std;

#include <iostream>
#include <vector>

/*** Tried the same approach as bitonic array which works but Educative method is more 
Efficient **/
/*
class SearchRotatedArray {
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
}; */
class SearchRotatedArray {
 public:
  static int search(const vector<int> &arr, int key) 
  {
     //after each division we can see which part of the array we need to search
     //after each division one will be sorted other will be unsorted .
     //We can easily conclude which part needs to be searched, based on the key 
     //to be searched.
     int s = 0, e = arr.size()-1;
     while(s<=e)
     {
        int mid = s + (e-s)/2;
        if(arr[mid] == key)
            return mid;

        if(arr[s] < arr[mid])  // left half is sorted array
        {
            if(key >= arr[s] && key < arr[mid]) //if key is part of the sorted side
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        else                // Right side is sorted
        {
            if( key > arr[mid] && key <= arr[e] )
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }        

     }    
      return -1;
  }
};

int main(int argc, char* argv[]) {
  cout << SearchRotatedArray::search(vector<int>{10, 15, 1, 3, 8}, 15) << endl;
  cout << SearchRotatedArray::search(vector<int>{4, 5, 7, 9, 10, -1, 2}, 10) << endl;
}
