using namespace std;

#include <iostream>
#include <limits.h>
#include <vector>

class ShortestWindowSort {
 public:
  static int sort(const vector<int>& arr) {
    // TODO: Write your code here
    int left = 0,right = arr.size()-1;
    int max = INT_MIN, min = INT_MAX;
    
    while ( left < arr.size()-1 && arr[left] <= arr[left+1] )
      left++;
    if( left == arr.size() - 1  )
      return 0; //array is already sorted.
    while( right >= 1 && arr[right] >= arr[right - 1] )
      right--;

    //Get max and min in subarray marked by left and right
    for(int i=left ; i<=right ; i++ )
    {
      if(arr[i] > max)
        max = arr[i];
      if(arr[i] < min)
        min = arr[i];
    }

    //extend the arr from the left
    int start = 0;
    while(start < left && min > arr[start])
      start++;
    
    int end = arr.size()-1;
    while(end > right && max < arr[end])
      end++;

    return end-start+1;
  }
};


int main(int argc, char* argv[]) {
  cout << ShortestWindowSort::sort(vector<int>{1, 3, 2, 0, -1, 7, 10}) << endl;

}