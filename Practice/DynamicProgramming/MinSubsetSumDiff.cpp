using namespace std;

#include <iostream>
#include <vector>
#include <limits.h>


class PartitionSet {
 public:
  // TopDown backtracking 
  /*int minSubsetSumDiff(const vector<int> &num, int idx, int sum1, int sum2)
  {
    if(idx >= num.size())
      return abs(sum1-sum2);   
    int inc = minSubsetSumDiff(num,idx+1,sum1+num[idx],sum2);
    int exc = minSubsetSumDiff(num,idx+1,sum1,sum2+num[idx]);
    return min(inc,exc);
  }
  int canPartition(const vector<int> &num) { 
    // TODO: Write your code here
    return minSubsetSumDiff(num,0,0,0);
  } */

  /* Bottom up DP */
  int canPartition(const vector<int> &num)
  {
    int range = 0;
    for(auto x: num)
      range+=x;    
    
    int halfRange = range/2;
    bool dpTable[num.size()+1][halfRange+1];

    // Lets say subset 1 has sum S1 and subset 2 has sum S2
    // We can say S2 = Range - S1
    // Now our goal is to minimize S2 - S1 , assuming S2 is the larger sum
    // Which is equal to Range - S1 - S1 = Range - 2S1 
    // We need to minimize Range - 2S1. 
    // As we have assumed S1 as smaller sum of the two subset S1 & S2 , 
    // S1 will lie between 0 and Range/2.

    // So we will create a table similar to subset sum with sum
    // as range/2

    
    for (int j=0;j<halfRange+1;j++)
      dpTable[0][j] = false;   //getting a sum of i without any element  
    for (int i=0;i<num.size()+1;i++)
      dpTable[i][0] = true;    //getting a sum of 0 with all elements is possible with empty subset.

    for(int i=1;i<num.size()+1;i++)
    {
      for(int j=1;j<halfRange+1;j++)
      {
        if(num[i-1] <= j)
          dpTable[i][j] = dpTable[i-1][j-num[i-1]];
        else
          dpTable[i][j] = dpTable[i-1][j];
      }
    }

    //Search the last row for least Range-2S1 values for 
    //all the possible sums.

    int minDiff = INT_MAX;
    for(int j=1;j<halfRange+1;j++)
    {
      if(dpTable[num.size()][j] == true )
      {
        int tempDiff= range - 2*j;
        if(tempDiff < minDiff)
          minDiff = tempDiff;
      }
    }
    return minDiff;  
  }
};

int main(int argc, char *argv[]) {
  PartitionSet ps; 

  vector<int> num = {1, 2, 3, 9};
  cout << ps.canPartition(num) << endl;

  num = vector<int>{1, 2, 7, 1, 5};
  cout << ps.canPartition(num) << endl ;
  
  num = vector<int>{1, 3, 100, 4};
  cout << ps.canPartition(num) << endl;
}