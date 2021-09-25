using namespace std;

#include <iostream>
#include <vector>

class CeilingFloorOfANumber {
 public:
  static int searchCeilingOfANumber(const vector<int>& arr, int key) {
    // TODO: Write your code here
    if( key < arr[0])
      return 0;
    if( key > arr[arr.size()-1])
      return -1;
    int s=0,e=arr.size()-1;
    while( s <= e )
    {
        int mid = s+((e-s)/2);
        if(arr[mid] == key)
          return mid;
        
        if(key > arr[mid])
        {
          s = mid+1;
        }
        else
        {
          e = mid-1;
        }
    }
    return s;
  }

    static int searchFloorOfANumber(const vector<int>& arr, int key) {
    // TODO: Write your code here
    if( key < arr[0])
      return -1;
    if( key > arr[arr.size()-1])
      return arr.size()-1;
    int s=0,e=arr.size()-1;
    while( s <= e )
    {
        int mid = s+((e-s)/2);
        if(arr[mid] == key)
          return mid;
        
        if(key > arr[mid])
        {
          s = mid+1;
        }
        else
        {
          e = mid-1;
        }
    }
    return e;
  }

};

int main(int argc, char* argv[]) {
  cout << CeilingFloorOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 10}, 6) << endl;
  cout << CeilingFloorOfANumber::searchCeilingOfANumber(vector<int>{1, 3, 8, 10, 15}, 12) << endl;
  cout << CeilingFloorOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 10}, 17) << endl;
  cout << CeilingFloorOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 10}, -1) << endl;
  cout << endl << endl;
  cout << CeilingFloorOfANumber::searchFloorOfANumber(vector<int>{4, 6, 10}, 6) << endl;
  cout << CeilingFloorOfANumber::searchFloorOfANumber(vector<int>{1, 3, 8, 10, 15}, 12) << endl;
  cout << CeilingFloorOfANumber::searchFloorOfANumber(vector<int>{4, 6, 10}, 17) << endl;
  cout << CeilingFloorOfANumber::searchFloorOfANumber(vector<int>{4, 6, 10}, -1) << endl;
}