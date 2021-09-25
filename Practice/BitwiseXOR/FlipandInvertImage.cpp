/*
Given a binary matrix representing an image, we want to flip the image horizontally, then invert it.

To flip an image horizontally means that each row of the image is reversed. For example, flipping [0, 1, 1] horizontally results in [1, 1, 0].

To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [1, 1, 0] results in [0, 0, 1].

*/


#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
  public:
    static vector<vector<int>> flipAndInvertImage(vector<vector<int>> arr) {
      //TODO: Write your code here
      int numRows = arr.size();
      int numCols = arr[0].size();
      for(int row= 0;row < numRows;row++)
      {
         for(int col =0;col < ceil(numCols/2.0);col++)
         {
           int temp = arr[row][col] ^ 1; 
           arr[row][col] = arr[row][numCols-1-col] ^ 1;
             arr[row][numCols-1-col] = temp;
         }
      }
      return arr;
    }

    static void print(const vector<vector<int>> arr) {
      for(int i=0; i < arr.size(); i++) {
        for (int j=0; j < arr[i].size(); j++) {
          cout << arr[i][j] << " ";
        }
        cout << endl;
      }
    }
};

int main(int argc, char* argv[]) {
  vector<vector<int>> arr = vector<vector<int>>{{1, 0, 1}, {1, 1, 1}, {0, 1, 1}};
  Solution::print(Solution::flipAndInvertImage(arr));
  cout << endl;
  return 0;
}