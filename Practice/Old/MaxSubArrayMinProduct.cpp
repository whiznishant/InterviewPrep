#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int MaximumSubArrayMinProduct(vector<int> &inp)
{        
    //Find the left bounds and right bounds for all the element
    //making it to be the least element in the subarray.

    // To do this we use strictly increasing monotonic stack 
    // As soon as we encounter an element which is smaller than current index element which we are 
    // looking at we start popping the stack . 
    
    // Indexes      [ 0 1 2 3 4 5 ]
    // INP          [ 3 1 5 6 4 2 ]
    // RightBounds  [ 0 5 3 3 4 5 ]  -- These are indexes
    // LeftBounds   [ 0 1 2 3 2 2 ]  -- These are indexes
    // RightBounds Indexes-- Just before Nearest right element which is smaller than the current  -- Till where in right we can expand so that my current element is smallest.
    // LeftBounds Indexes -- Coming from right -- we will check elements from right to left -- Just before we nearest left element which is smaller than the current 
    //                                                                                      -- Till where in right we can expand so that my current element is smallest.

    vector<int> monoIncrStack;
    int sz = inp.size();
    //Find the right bounds. // O(N)
    vector<int> rightBounds(sz,-1);
    for(int i=0; i < sz;i++ )
    {
        //Pop all indexes whose values are smaller than current element 
        while(!monoIncrStack.empty() && inp[i] < inp[monoIncrStack.back()])
        {
            int poppedIdx = monoIncrStack.back();
            monoIncrStack.pop_back();
            rightBounds[poppedIdx] = i-1; 
        }
        monoIncrStack.push_back(i);
    }
    while(!monoIncrStack.empty())
    {
        int poppedIdx = monoIncrStack.back();
        monoIncrStack.pop_back();
        rightBounds[poppedIdx] = sz-1; 
    }

    monoIncrStack.clear();
    //Find the left bounds   // O(N)
    vector<int> leftBounds(sz,-1);
    for(int i= sz-1;i>=0;i--)
    {
                //Pop all indexes whose values are smaller than current element 
        while(!monoIncrStack.empty() && inp[i] < inp[monoIncrStack.back()])
        {
            int poppedIdx = monoIncrStack.back();
            monoIncrStack.pop_back();
            leftBounds[poppedIdx] = i + 1; 
        }
        monoIncrStack.push_back(i);
    }
    while(!monoIncrStack.empty())
    {
        int poppedIdx = monoIncrStack.back();
        monoIncrStack.pop_back();
        leftBounds[poppedIdx] = 0  ; //  These were never popped as we finished looking at all the numbers to the left and we did not encounter any elements smaller than this.
    }

    //Find all the prefix sum   //O(N)
    vector<long> prefixSum(sz,0);
    prefixSum[0]= inp[0];
    for(int i=1;i < sz;i++)
    {
        prefixSum[i] = prefixSum[i-1] + inp[i];
    }

    //Now compute for each bounds MaxSubArrayMinProduct, the element at current index is the minimum element.  //O(N)
    long maxSubArrMinProduct = INT_MIN;
    for(int i=0;i < sz;i++)
    {
        long negationSum = 0;
        if(leftBounds[i] != 0 )
            negationSum = prefixSum[leftBounds[i]-1];
        long sum = prefixSum[rightBounds[i]] - negationSum;
        maxSubArrMinProduct = max(maxSubArrMinProduct, inp[i] * sum);
    }
    return maxSubArrMinProduct % (1000000007);   
}


int main()
{
    vector<int> inp1 = { 3,1,5,6,4,2 };  //60
    vector<int> inp2 = { 1,2,3,2 };  //16
    vector<int> inp = { 3,3,2,2,3,1,1,4,1,3 };  //26
    cout << MaximumSubArrayMinProduct(inp);

}