/*
Given a sorted number array and two integers ‘K’ and ‘X’, find ‘K’ closest numbers to ‘X’ in the array. Return the numbers in the sorted order. ‘X’ is not necessarily present in the array.

Example 1:
Input: [5, 6, 7, 8, 9], K = 3, X = 7
Output: [6, 7, 8]

Example 2:
Input: [2, 4, 5, 6, 9], K = 3, X = 6
Output: [4, 5, 6]

Example 3:
Input: [2, 4, 5, 6, 9], K = 3, X = 10
Output: [5, 6, 9]
*/

using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
/***  Heap way less optimal as we are not utilizing the fact that input array is sorted.
// O(NLogK + KLogK)
class KClosestElements {
 public:
  struct numCompare {
      private:
        int val;
      public:
        numCompare(int n):val(n){ }
        bool operator()( const int &x, const int &y) 
        { 
          return abs(x-val) <  abs(y-val);    
        }   
  };

  static vector<int> findClosestElements(const vector<int> &arr, int K, int X) {
    vector<int> result;
    // TODO: Write your code here
    numCompare nc(X);
    result.assign(arr.begin(),arr.begin()+K);
    make_heap(result.begin(),result.end(),nc);

    for(int i=K;i<arr.size();i++)
    {
       if(abs(arr[i]-X) < abs(result.front()-X))
       {
           pop_heap(result.begin(),result.end());
           result.pop_back();
           result.push_back(arr[i]);
           push_heap(result.begin(),result.end());
       }
    }
    sort_heap(result.begin(),result.end());
    return result;
  }
};
**/

class KClosestElements {
 public:  
  static vector<int> findClosestElements(const vector<int> &arr, int K, int X) 
  {
     deque<int> result; 
     int closest = findClosestIdx(arr,X);
     result.push_back(arr[closest]);
     int l=closest-1,r = closest +1;
     while(result.size()!= K)
     {
      int left_diff = INT_MAX, right_diff = INT_MAX;
      if(l >= 0 )
      {
          left_diff = abs(X-arr[l]);
      }
      if(r < arr.size())
      {
          right_diff = abs(X-arr[r]);
      }

      if( left_diff == right_diff == INT_MAX )
      {
        break;
      }
      else if ( left_diff < right_diff )
      {
        result.push_front(arr[l]);
        l--;
      }
      else
      {
        result.push_back(arr[r]);
        r++;
      }
     }
     vector<int> resultVec;
     std::move(result.begin(),result.end(),std::back_inserter(resultVec));
     return resultVec;
  }

  static int findClosestIdx(const vector<int> &arr,int X)
  {
    int s=0,e=arr.size()-1;
    while(s<=e)
    {
      int mid = s + (e-s)/2;
      if(arr[mid] == X)
        return mid;
      if( arr[mid] > X)
        e = mid -1;
      else
        s = mid + 1;
    }
    return s;
  }
};


int main(int argc, char *argv[]) {
  vector<int> result = KClosestElements::findClosestElements(vector<int>{5, 6, 7, 8, 9}, 3, 7);
  cout << "'K' closest numbers to 'X' are: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = KClosestElements::findClosestElements(vector<int>{2, 4, 5, 6, 9}, 3, 6);
  cout << "'K' closest numbers to 'X' are: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
