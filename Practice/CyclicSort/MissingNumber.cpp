using namespace std;

#include <iostream>
#include <vector>

class MissingNumber {
 public:
  static int findMissingNumber(vector<int> &nums) {
    // TODO: Write your code here
    //Easy way 
    /* int sz = nums.size();
    int sumReq = sz*(sz+1)/2;
    int currSum = 0;
    for(auto n: nums)
      currSum += n;
    return sumReq-currSum; */
    int currIdx = 0;    
    while(currIdx < nums.size())
    {
      if(nums[currIdx] != currIdx && nums[currIdx] != nums.size())
      {
        int temp = nums[currIdx];
        nums[currIdx] = nums[nums[currIdx]];
        nums[temp] = temp;
      }
      else
        currIdx++;
    }

    for(int i=0;i<nums.size();i++)
    {
      if(nums[i] != i)
        return i;
    }

    return nums.size();

  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {4, 0, 3, 1};
  cout << MissingNumber::findMissingNumber(v1) << endl;
  v1 = {7, 3, 5, 2, 4, 6, 0, 1};
  cout << MissingNumber::findMissingNumber(v1) << endl;
}
