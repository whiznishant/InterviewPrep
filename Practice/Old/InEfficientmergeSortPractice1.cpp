#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;



vector<int> mergeSortedArray(vector<int> &leftArray, vector<int> &rightArray)
{
    int leftSize = leftArray.size();
    int rightSize = rightArray.size();

    vector<int> out;
    int leftIdx = 0;int rightIdx = 0;
    while(leftIdx < leftSize && rightIdx < rightSize)
    {
        if(leftArray[leftIdx] < rightArray[rightIdx])
        {
            out.push_back(leftArray[leftIdx++]);
        }
        else
        {
            out.push_back(rightArray[rightIdx++]);
        }
    }

    while(leftIdx < leftSize)
    {
        out.push_back(leftArray[leftIdx++]);
    }

    while(rightIdx< rightSize)
    {
        out.push_back(rightArray[rightIdx++]);
    }

    return out;
}


vector<int> mergeSortHelper(vector<int> &inp)
{
    int sz = inp.size();
    if(sz == 1)
    {
        return { inp[0] };
    }
    int half = sz / 2;
    vector<int> leftArray(inp.begin(),inp.begin() + half);
    vector<int> rightArray(inp.begin() + half, inp.end());
    
    vector<int> leftSortedVec = mergeSortHelper(leftArray);
    vector<int> rightSortedVec = mergeSortHelper(rightArray);

    return mergeSortedArray(leftSortedVec , rightSortedVec);
}


vector<int> mergeSort(vector<int> &inp)
{
    vector<int> out = mergeSortHelper(inp);
    return out;
}


int main()
{
    vector<int> inp = { 8,5,2,9,5,6,3,-1000,INT_MIN };
    vector<int> out = mergeSort(inp);
    cout<<endl;
    for(auto x:out)
        cout<<" "<<x;
    
    cout<<endl;
}