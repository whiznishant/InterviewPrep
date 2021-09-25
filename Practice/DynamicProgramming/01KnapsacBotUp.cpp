#include <iostream>
#include <vector>

 using namespace std;

 //************** Bottom up  ******//////////////
class Knapsack {
 public:   
  vector<vector<int>> dpTable;

  int solveKnapsack(const vector<int> &profits, vector<int> &weights, int capacity) 
  {
    dpTable.clear();
    dpTable.resize(profits.size()+1);
    for (int i = 0; i < profits.size()+1; ++i)
      dpTable[i].resize(capacity+1,0);

    int n = profits.size();    
    for(int i=1;i<profits.size()+1;i++)
    {
        for(int j=1;j<capacity+1;j++)
        {
            //if the weight of current element/
            if( weights[i-1] <= j )
            {
                dpTable[i][j] = max( profits[i-1] + dpTable[i-1][j-weights[i-1]],  dpTable[i-1][j] );
            }
            else
            {
                dpTable[i][j] = dpTable[i-1][j];
            }
        }
    }

    return dpTable[profits.size()][capacity];
  }
};

int main(int argc, char *argv[]) {
  Knapsack ks;
  vector<int> profits = {1, 6, 10, 16};
  vector<int> weights = {1, 2, 3, 5};
  int maxProfit = ks.solveKnapsack(profits, weights, 6);
  cout << "Total knapsack profit ---> " << maxProfit << endl;
  maxProfit = ks.solveKnapsack(profits, weights, 7);
  cout << "Total knapsack profit ---> " << maxProfit << endl;
}
