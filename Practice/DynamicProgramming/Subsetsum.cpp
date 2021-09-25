using namespace std;

#include <iostream>
#include <vector>

class SubsetSum {
 public:
  //** Top Down 
  bool canPartitionHelper(const vector<int> &num,int sum, int len)
  {
    if(sum == 0)
      return true;

    if( sum < 0 || len == 0 )
      return false;

    bool res1;
    if(num[len-1] <= sum )
    {
      return (canPartitionHelper(num,sum-num[len-1],len -1) || canPartitionHelper(num,sum,len-1)) ;                
    } 
    else
      return canPartitionHelper(num,sum,len-1);    
  }
  virtual bool canPartition(const vector<int> &num, int sum) {
    // TODO: Write your code here

    return canPartitionHelper(num,sum,num.size());
  }
};

int main(int argc, char *argv[]) {
  SubsetSum ss;
  vector<int> num = {1, 2, 3, 7};
  cout << ss.canPartition(num, 6) << endl;
  num = vector<int>{1, 2, 7, 1, 5};
  cout << ss.canPartition(num, 10) << endl;
  num = vector<int>{1, 3, 4, 8};
  cout << ss.canPartition(num, 6) << endl;
}