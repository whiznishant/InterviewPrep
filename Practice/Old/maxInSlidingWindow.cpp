#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

//O(n2)
vector<int> maxSlidingWindow(vector<int> &inp,int k)
{
    int len = inp.size();
    if(len==0 || k == 0 || k>len)
        return {};
    int winStart = 0;
    int winEnd = winStart + k -1;
    vector<int> out;
    while(winEnd < len)
    {
        int winMax = INT_MIN;
        for(int i=0;i<k;i++)
        {
            if(inp[winStart+i]> winMax)
            {
                winMax = inp[winStart+i];
            }
        }
        out.push_back(winMax);
        winStart += 1;
        winEnd += 1;
    }
   
    return out;
}

int main()
{
    vector<int>out;
    vector<int> nums ={1,3,-1,-3,5,3,6,7};
    out = maxSlidingWindow(nums,3);
    for(auto x:out)
        cout<<x<<" ";
}
