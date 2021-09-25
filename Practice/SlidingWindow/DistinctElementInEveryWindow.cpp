/*
Count distinct elements in every window 
Easy Accuracy: 44.16% Submissions: 63963 Points: 2
Given an array of integers and a number K. Find the count of distinct elements in every window of size K in the array.

Example 1:

Input:
N = 7, K = 4
A[] = {1,2,1,3,4,2,3}
Output: 3 4 4 3
Explanation: Window 1 of size k = 4 is
1 2 1 3. Number of distinct elements in
this window are 3. 
Window 2 of size k = 4 is 2 1 3 4. Number
of distinct elements in this window are 4.
Window 3 of size k = 4 is 1 3 4 2. Number
of distinct elements in this window are 4.
Window 4 of size k = 4 is 3 4 2 3. Number
of distinct elements in this window are 3.
Example 2:

Input:
N = 3, K = 2
A[] = {4,1,1}
Output: 2 1
Your Task:
Your task is to complete the function countDistinct() which takes the array A[], the size of the array(N) and the window size(K) as inputs and returns an array containing the count of distinct elements in every contiguous window of size K in the array A[].

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= K <= 105
1 <= A[i] <= 105 , for each valid i

*/


using namespace std;
#include<limits.h>
#include <iostream>
#include <vector>
#include <unordered_map>


vector<int> FindDistinct(vector<int> &inp,int windowSize )
{
    int sz = inp.size();
    int start = 0;
    int end = windowSize-1;
    unordered_map<int,int> elementInWindow; 
    
    for(int i=0;i< windowSize;i++)
    {
        elementInWindow[inp[i]] += 1;
    }
    vector<int> out;
    out.push_back(elementInWindow.size());
    start = start + 1;
    while(start <= sz-windowSize)
    {
        //include element at end 
        elementInWindow[inp[start+ windowSize -1]] += 1; 
        //remove any element at start
        elementInWindow[inp[start-1]] -= 1;
        if(elementInWindow[inp[start-1]] == 0)
            elementInWindow.erase(inp[start-1]);
        
        out.push_back(elementInWindow.size());
        start = start + 1;    
    }
    return out;
}

void printVector(vector<int>& toPrint )
{
    cout<<endl<<"--------------------"<<endl;
    for(auto x:toPrint)
        cout<<x<<"  ";
    cout<<endl<<"--------------------"<<endl;
}

int main()
{
    vector<int> inp = { 1,2,1,3,4,2,3 } ;
    vector<int> out = FindDistinct(inp, 4);
    printVector(out);
    inp = {4,1,1};
    out = FindDistinct(inp,2);
    printVector(out);
   
    return 0;
}