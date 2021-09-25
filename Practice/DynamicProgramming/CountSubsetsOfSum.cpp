using namespace std;

#include <iostream>
#include <vector>

class SubsetSum {
 public:
    
    int countSubsetsRecursive( const vector<int> &num, int sumReqd, int currSum, int i,vector<vector<int>>& memo )
    {    
      if( sumReqd == currSum )
      {
        return 1;
      }

      if( i >= num.size() )
        return 0;

      if(memo[i][currSum] != -1)
        return memo[i][currSum];

      int res = 0;
      if(num[i] <= ( sumReqd - currSum))
      {
        res = countSubsetsRecursive(num,sumReqd,currSum+num[i],i+1,memo) + countSubsetsRecursive(num,sumReqd,currSum,i+1,memo);
      }
      else
      {
        res = countSubsetsRecursive(num,sumReqd,currSum,i+1,memo);        
      }
      memo[i][currSum] = res;
      return res;
    }

    int countSubsetsBottomUp(const vector<int> &num,int sum)
    {
      //Dp table will contain number of occurences found so far.
      vector<vector<int>>dpTable;
      dpTable.resize( num.size()+1,vector<int>(sum+1,-1));

      //Intialize
      //Rows -- 
      //With no elements it is imposible to create a sum, So 0 occurence.
      for(int j=0;j<sum+1;j++)
        dpTable[0][j] = 0;
      //We can hve 1 occurence for subsets with sum = 0 , to take no element
      for(int i=0;i<num.size()+1;i++)
        dpTable[i][0] = 1;
      
      for(int i=1;i<num.size()+1;i++)
      {
        for(int j=1;j<sum+1;j++)
        {
          if(num[i-1] <= j)
            dpTable[i][j] = dpTable[i-1][j-num[i-1]] + dpTable[i-1][j];
          else
            dpTable[i][j] = dpTable[i-1][j];
        }
      }
      return dpTable[num.size()][sum] ;
    }
    
    // Using only previous and next of the DP table.
    int countSubsetsBottomUpOptimized1(const vector<int> &num,int sum)
    {
      //Dp table will contain number of occurences found so far.
      vector<vector<int>>dpTable;
      dpTable.resize(2,vector<int>(sum+1,-1));

      //Intialize
      //Rows -- 
      //With no elements it is imposible to create a sum, So 0 occurence.
      for(int j=0;j<sum+1;j++)
        dpTable[0][j] = 0;
      //We can hve 1 occurence for subsets with sum = 0 , to take no element
      for(int i=0;i<2;i++)
        dpTable[i][0] = 1;
      
      for(int i=1;i<num.size()+1;i++)
      {
        for(int j=1;j<sum+1;j++)
        {
          if(num[i-1] <= j)
            dpTable[i%2][j] = dpTable[(i-1)%2][j-num[i-1]] + dpTable[(i-1)%2][j];
          else
            dpTable[i%2][j] = dpTable[(i-1)%2][j];
        }
      }
      return dpTable[num.size()%2][sum] ;
    }


    //using only one array
    int countSubsetsBottomUpOptimized2(const vector<int> &num,int sum)
    {
      //Dp table will contain number of occurences found so far.
      vector<int>dpTable;
      dpTable.resize( sum + 1, -1);
      //Intialize
      //Rows -- 
      dpTable[0] = 1;
      for(int j=1;j<sum+1;j++)
      {
        if(num[0] == j)
            dpTable[j] = 1;             //We already populated data based on num[o] here 
        else
            dpTable[j] = 0;
      }
      

      for(int i=1;i<num.size();i++)         //Here we can check from num[1] onwards ...
      {
        for(int j=sum;j>=1;j--)            //Reversing as we will require previously calculated i-1 
        {
          if(num[i] <= j)
            dpTable[j] = dpTable[j-num[i]] + dpTable[j];
        }
      }
      return dpTable[sum] ;
    }


    int countSubsets(const vector<int> &num,int sum) 
    {
        //TODO: Write - Your - Code
        /*vector<vector<int>> memo;
        memo.resize(num.size(),vector<int>(sum+1,-1));
        return countSubsetsRecursive(num,sum,0,0,memo);*/
        
        //return countSubsetsBottomUp(num,sum);

        //return countSubsetsBottomUpOptimized1(num,sum);
        return countSubsetsBottomUpOptimized2(num,sum);
    }
};

int main(int argc, char *argv[]) {
  SubsetSum ss;
  vector<int> num = {1, 1, 2, 3};
  cout << ss.countSubsets(num, 4) << endl;
  num = vector<int>{1, 2, 7, 1, 5};
  cout << ss.countSubsets(num,11) << endl;
}