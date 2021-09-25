#include <iostream>
#include <vector>

 using namespace std;

 //************** Top Down  ****************/
class Knapsack {
 public:
  vector<vector<int>> memoize;
  int solveKnapsackHelper(const vector<int> &profits,
                          const vector<int> &weights,
                          int capacity,
                          int len)
  {
    if(len == 0 || capacity == 0)
     return 0;
    if( memoize[len][capacity] != -1 )
      return memoize[len][capacity];

    int prof = 0;
    if(capacity >= weights[len-1])
    {      
      //either we can take it or not take it .
      prof =  max( solveKnapsackHelper(profits,weights,capacity,len-1),
                  profits[len-1] + solveKnapsackHelper(profits,weights,capacity-weights[len-1],len-1));
    }
    else
    {
      prof = solveKnapsackHelper(profits,weights,capacity,len-1);
    }
    
    memoize[len][capacity] = prof;
    return prof;    
  }
  
  int solveKnapsack(const vector<int> &profits, vector<int> &weights, int capacity) 
  {
    memoize.clear();
    memoize.resize(profits.size()+1);
    for (int i = 0; i < profits.size()+1; ++i)
      memoize[i].resize(capacity+1,-1);

    // TODO: Write your code here
    int res = solveKnapsackHelper(profits,weights,capacity, profits.size());
    return res;
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
