using namespace std;

#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>

class TripletSumCloseToTarget {
 public:
  static int searchTriplet(vector<int>& arr, int targetSum) {    
    // TODO: Write your code here
    int closestSumFound = INT_MAX;
    sort(arr.begin(),arr.end());
    for(int i=0; i < arr.size() - 2; i++)
    {
        int left = i+1;
        int right = arr.size() - 1;
        while( left < right )
        {
          int sum = arr[i] + arr[left] + arr[right];
          int currDiff = targetSum - sum;
          if(abs(currDiff) < abs(targetSum - closestSumFound))
            closestSumFound = sum ;

          if(currDiff == 0)          
            return 0;
          else if(currDiff > 0)  //Sum is still less , we need to increase.
            left++;
          else 
            right--;
        }
    }
    return closestSumFound;
  }
};

int main() 
{
  vector<int> vec = {-5,-10,5,8,70};
  cout << TripletSumCloseToTarget::searchTriplet(vec, 50) << endl;
}