using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class Permutations {
 public:
  static void swap(int i, int j, vector<int> &nums)
  {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }
  /* ---- Recursive ----- */
 /* static void permutateHelper(int i,vector<int> &nums,vector<vector<int>>&result)
  {
    if( i == nums.size()-1 )
    {
      result.push_back(nums);
      return;
    }
    for(int j=i;j < nums.size();j++ )
    {
      swap(i,j,nums);
      permutateHelper(i+1,nums,result);
      swap(i,j,nums);
    }
  }*/

  /*  Iterative ----- */
  static void permutateHelper(vector<int> &nums, vector<vector<int>>&result )
  {
      result.push_back({});
      for(int i=0;i < nums.size();i++)
      {
          int currNum = nums[i];  // now insert this char to all the positions in existing permutations strings.
          int numPerm = result.size();
          for(int j=0; j < numPerm;j++ )
          {
              int sz = result[j].size();
              result[j].push_back(currNum);
              // Just like generating subset , keep pushing the digit to all positions in the existing sets in  out 
              for(int k=0;k<sz;k++)
              {
                  swap(k,sz,result[j]);
                  result.push_back(result[j]);
                  swap(k,sz,result[j]);
              }
          }   
      }
  }
  
  static vector<vector<int>> findPermutations(vector<int> nums) {
    vector<vector<int>> result;
    // TODO: Write your code here
    //permutateHelper(0,nums,result);   //Recursive
    permutateHelper(nums,result);  // Iterative
    return result;
  }


};

int main(int argc, char* argv[]) {
  vector<vector<int>> result = Permutations::findPermutations(vector<int>{1, 3, 5 });
  cout << "Here are all the " << result.size() <<" permutations: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
