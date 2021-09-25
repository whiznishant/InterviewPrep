using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>

class TripletSumToZero {
 public:
  static vector<vector<int>> searchTriplets(vector<int> &arr) {
    vector<vector<int>> triplets;
    // TODO: Write your code here
    sort(arr.begin(),arr.end());
    for( int i=0;i < arr.size()-2;i++ )
    {
      if (i > 0 && arr[i] == arr[i - 1])  // skip the same elements
        continue;
      int left = i+1;
      int right = arr.size()-1;
      int target = 0 - arr[i];
      while ( left < right )
      {
        int leftrightSum = arr[left] + arr[right];
        if( target == leftrightSum )
        {
          triplets.push_back({arr[i],arr[left], arr[right]});
          left++;right--;
          while (left < right && arr[left] == arr[left - 1]) {
          left++; // skip the same elements
          }
          while (left < right && arr[right] == arr[right + 1]) {
          right--; // skip the same elements
          }
        }
        else if( leftrightSum < target )
        {
          left++;
        }
        else
        {
          right--;
        }
      }
    }
    return triplets;
  }
};

int main(int argc, char *argv[]) {
  vector<int> vec = {-5,-5, 1, 4, 1, 1,1,4};

  vector<vector<int>>result = TripletSumToZero::searchTriplets(vec);
  for (auto vec : result) {
    cout << "[";
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << "]";
  }


}


