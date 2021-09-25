#include<iostream>
#include<vector>
#include<limits.h>
#include<deque>

using namespace std;

vector<int> maxSlidingWindowSum(vector<int> &nums, int k)
{
    deque<int> monotonicq;  // Strictly decreasing q . The largest element will be in front always 
    //Insert the initial window elements
    for(int i = 0;i < k; i++ )
    {
        while(!monotonicq.empty() && nums[i] >= nums[monotonicq.back()] )
            monotonicq.pop_back();
        
        //if the item is less than the back of the deque or if deque is empty then we push the element
        monotonicq.push_back(i);
    }
    vector<int> out;
    for(int winStart=0;winStart <= (nums.size() -k);winStart++)
    {
        int winEnd = winStart + k -1;
        //Remove out of window element
        while(!monotonicq.empty() && monotonicq.front() < winStart)
        {
            monotonicq.pop_front();
        }
        //If we find a bigger element now then we can use this bigger element
        //for subsequent windows all smaller elements are irrelevant .
        //So remove all smaller elements 
        while(!monotonicq.empty() && nums[winEnd] > nums[monotonicq.back()] )
        {
            monotonicq.pop_back();
        }
        monotonicq.push_back(winEnd);
        out.push_back(nums[monotonicq.front()]);
    }
    return out;
}

int main()
{
    vector<int>out;
    vector<int> nums1 ={1,3,-1,-3,5,3,6,7};
    vector<int> nums2 ={9,11};
    vector<int> nums4 ={1, 2, 3, 1, 4, 5, 2, 3, 6};
    vector<int> nums = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
    vector<int> nums3 = { 1, -1};
    vector<int> nums5 = { 1,3,1,2,0,5 };
    out = maxSlidingWindowSum(nums,1);
    for(auto x:out)
        cout<<x<<" ";
}
