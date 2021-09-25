#include<iostream>
#include<vector>
#include<unordered_map>
#include<math.h>

using namespace std;

class Solution {
public:
    unordered_map<int,vector<int>> lookUpSetBits;
    Solution()
    {
        lookUpSetBits.insert(std::pair<int,vector<int>>(0,{}));
        int mask  = 1;
        int maxSubset = pow(2,12) - 1 ; // Constraint --  1 <= nums.length <= 12
        for(int i = 1;i <= maxSubset;i++)    
        {
            vector<int>setbits;
            // Need to check only 12 bits constraint --  1 <= nums.length <= 12
            for(int j = 0; j < 12;j++ )
            {
                if(i& mask<<j)
                    setbits.push_back(j);
            }
            lookUpSetBits.insert(std::pair<int,vector<int>>(i,setbits));
            setbits.clear();
        }
    }
    
    int subsetXORSum(vector<int>& nums) {       
        int sz = nums.size();
        int numOfSubsets = pow(2,sz) - 1;
        int AllSubsetXorSum = 0;
        for(int subset = 1; subset <= numOfSubsets; subset++  )
        {
            vector<int> currentEnabledBits = lookUpSetBits.at(subset);
            int currSubsetXor = currentEnabledBits.size() > 0 ? nums[currentEnabledBits[0]] : 0;
            for(int i=1;i< currentEnabledBits.size();i++)
            {
                currSubsetXor = currSubsetXor ^ nums[currentEnabledBits[i]];
            }   
            AllSubsetXorSum += currSubsetXor;
        }
        return AllSubsetXorSum;  
    }
};


int main()
{
    Solution A;

}