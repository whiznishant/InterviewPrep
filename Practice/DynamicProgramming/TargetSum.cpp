/*
Target Sum (hard)#
You are given a set of positive numbers and a target sum ‘S’. Each number should be assigned either a ‘+’ or ‘-’ sign. We need to find the total ways to assign symbols to make the sum of the numbers equal to the target ‘S’.
Example 1:#
Input: {1, 1, 2, 3}, S=1
Output: 3
Explanation: The given set has '3' ways to make a sum of '1': {+1-1-2+3} & {-1+1-2+3} & {+1+1+2-3}
Example 2:#
Input: {1, 2, 7, 1}, S=9
Output: 2
Explanation: The given set has '2' ways to make a sum of '9': {+1+2+7-1} & {-1+2+7+1}
*/

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>

class TargetSum {
 public:
  int findTargetSubsetRecur(const vector<int>&num,int s,int currSum,
          int i,unordered_map<int,unordered_map<int,int>> & memo )
  {
    if(i >= num.size())
    {
      if(currSum == s)
        return 1;
      else
        return 0;
    }
    unordered_map<int,unordered_map<int,int>>::iterator it = memo.find(i);
    if(it != memo.end())
    {
      if( it->second.find(currSum) != it->second.end())
        return it->second[currSum];
    }

    int res = findTargetSubsetRecur(num,s,currSum + num[i],i+1, memo) + 
           findTargetSubsetRecur(num,s,currSum -num[i],i+1, memo);

    memo[i][currSum] =res;
    return res;
  }

  int findTargerSubsetsBottomUp(const vector<int> &num,int s)
  {
    /* This problem can be decomposed into count of subset sum 
    problem . In case of {1, 1, 2, 3} , with target sum X , 
    We need to divide this into two subsets like S1 = { 1,3 } and S2 = {1,2},
    such that S1 - S2 = {1+3} - {1,2} = X.

    S1 - S2 = X
    S1 - (Total - S1) = X
    S1 = (X + Total)/2 .
    Find number of subsets of Sum S1 
    */
    if(num.size() == 0)
        return 0;
    if(num.size() == 1)
    {
        if(num[0] == abs(s) )
            return 1;
        else
            return 0;
    }
    int total = 0;
    for(auto x:num)
        total += x;
    int tempTargetSum = (s + total);
    if( tempTargetSum % 2 != 0 )
        return 0;
    int targetSum = tempTargetSum/2;

    int dpTable[num.size()+1][targetSum+1];
    //Initialize
    for(int j=0; j<targetSum+1; j++ )
        dpTable[0][j] = 0;
    for(int i=0;i<num.size()+1;i++)
        dpTable[i][0] = 1;

    for(int i=1;i<num.size()+1;i++)
    {
        for(int j=1;j<targetSum+1;j++)
        {
            if(num[i-1] <= targetSum)
            {
                dpTable[i][j] = dpTable[i-1][j - num[i-1]] + dpTable[i-1][j];
            }
            else
            {
                dpTable[i][j] = dpTable[i-1][j];
            }
        }
    }
    return dpTable[num.size()][targetSum];
  }
  
  int findTargetSubsets(const vector<int> &num, int s) {
    // TODO: Write your code here 
    /* unordered_map<int,unordered_map<int,int>> memo;
    return findTargetSubsetRecur(num,s,0,0,memo);*/

    return findTargerSubsetsBottomUp(num,s);
  }
};

int main(int argc, char *argv[]) 
{
  TargetSum ts;
  vector<int> num = {0,0,0,0,0,0,0,0,1};
  cout << ts.findTargetSubsets(num, 1) << endl;
 /* vector<int> num = {1, 1, 2, 3};
  cout << ts.findTargetSubsets(num, 1) << endl;
  num = vector<int>{1, 2, 7, 1};
  cout << ts.findTargetSubsets(num, 9) << endl;*/
}