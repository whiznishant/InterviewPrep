using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>


//Brute force
/*
class TripletWithSmallerSum {
 public:
  static int searchTriplets(vector<int> &arr, int target) {
    int count = 0;
    // TODO: Write your code here
    for(int i = 0;i < arr.size()-2; i++)
    {
      for(int j= i+1;j < arr.size()-1;j++)
      {
        for( int k=j+1;k< arr.size();k++)
        {
            if((arr[i]+ arr[j]+ arr[k]) < target)
              count++;
        }        
      }
    } 
    return count;
  }
};*/


int main(int argc, char *argv[]) {
  vector<int> vec = {-1, 0, 2, 3};
  cout << TripletWithSmallerSum::searchTriplets(vec, 3) << endl;
  vec = {-1, 4, 2, 1, 3};
  cout << TripletWithSmallerSum::searchTriplets(vec, 5) << endl;
}