using namespace std;

#include <iostream>
#include <vector>

class AllMissingNumbers {
 public:
  static vector<int> findNumbers(vector<int> &nums) {
    vector<int> missingNumbers;
    // TODO: Write your code here
    for(int i=0;i<nums.size();i++)
    {
      while(nums[i] != -1 && nums[i] != i+1 )
      {
        if(nums[nums[i]-1] == nums[i])
        {
          nums[i] = -1;
        }
        else
        {
          int temp = nums[i];
          nums[i] = nums[nums[i]-1];
          nums[temp-1] = temp;
        }
      }
    }

    for(int i=0;i< nums.size();i++ )
    {
      if(nums[i] == -1)
        missingNumbers.push_back(i+1);
    }

    return missingNumbers;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {2, 3, 1, 8, 2, 3, 5, 1};
  vector<int> missing = AllMissingNumbers::findNumbers(v1);
  cout << "Missing numbers: ";
  for (auto num : missing) {
    cout << num << " ";
  }
  cout << endl;
}