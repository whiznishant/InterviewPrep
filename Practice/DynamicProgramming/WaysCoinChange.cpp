using namespace std;

#include <iostream>
#include <vector>

int GetNumWaysTDRecur(vector<int> &coins,int targetSum,int idx)
{
    if(idx >= coins.size())
        return 0;
    if(targetSum < 0)
        return 0;
    if(targetSum == 0)
        return 1;
    
    int ways = 0;
    if(coins[idx] <= targetSum)
    {
        ways = GetNumWaysTDRecur(coins,targetSum-coins[idx],idx) + GetNumWaysTDRecur(coins,targetSum,idx+1);
    }
    else
    {
        ways = GetNumWaysTDRecur(coins,targetSum,idx+1);
    }
    return ways;
}

int GetNumWaysBUp(vector<int> &coins, int targetSum )
{
    int dpTable[coins.size()+1][targetSum+1];
    //Initialize the table

    for(int j=0;j<targetSum+1;j++)
        dpTable[0][j] = 0;
    for(int i=0;i<coins.size()+1;i++)
        dpTable[i][0] = 1;
    
    for(int i = 1; i < coins.size()+1; i++ )
    {
        for(int j= 1 ; j < targetSum+1; j++ )
        {
            if(coins[i-1] <= j )
            {
                dpTable[i][j] = dpTable[i][j-coins[i-1]] + dpTable[i-1][j];
            }
            else
            {
                dpTable[i][j] = dpTable[i-1][j];
            }
        }
    }
    return dpTable[coins.size()][targetSum];
}

int GetNumWaysBUpOpt1(vector<int> &coins, int targetSum )
{
    int dpTable[2][targetSum+1];
    //Initialize the table
    for(int j=0;j<targetSum+1;j++)
        dpTable[0][j] = 0;
    for(int i=0;i<2;i++)
        dpTable[i][0] = 1;   
    for(int i = 1; i < coins.size()+1; i++ )
    {
        for(int j= 1 ; j < targetSum+1; j++ )
        {
            if(coins[i-1] <= j )
            {
                dpTable[i%2][j] = dpTable[i%2][j-coins[i-1]] + dpTable[(i-1)%2][j];
            }
            else
            {
                dpTable[i%2][j] = dpTable[(i-1)%2][j];
            }
        }
    }
    return dpTable[1][targetSum];
}

int main(int argc, char *argv[]) 
{
  int targetSum = 5;
  vector<int> coins = {3,2,1};
  cout << endl<<"Num Ways TopDown = "<<GetNumWaysTDRecur(coins,targetSum,0)<<endl;
  cout << endl<<"Num Ways BotUp = "<<GetNumWaysBUp(coins,targetSum)<<endl;
  cout << endl<<"Num Ways BotUp Optimized 1 = "<<GetNumWaysBUpOpt1(coins,targetSum)<<endl;
  return 0;
}