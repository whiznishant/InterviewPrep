#include<iostream>
#include<vector>
using namespace std;


void mergeSortedArrays(vector<int> &pri, vector<int> &aux,int start,int mid , int end)
{
    int leftIdx = start;
    int leftEnd = mid;

    int rightIdx = mid + 1;
    int rightEnd = end;

    int sortIdx = start;
    while(leftIdx <= leftEnd && rightIdx <= rightEnd )
    {
        if(aux[leftIdx] < aux[rightIdx])
            pri[sortIdx++] = aux[leftIdx++];
        else
            pri[sortIdx++] = aux[rightIdx++];
    }
    while(leftIdx <= leftEnd)
    {
        pri[sortIdx++] = aux[leftIdx++];
    }    
    while(rightIdx <= rightEnd)
    {
        pri[sortIdx++] = aux[rightIdx++];
    }
}


void mergeSortHelper(vector<int> &pri, vector<int> &auxillary,int start,int mid, int end)
{
    if(start >= end)
        return;
    int midOfLeft = (start + mid)/2;
    int midOfRight = (mid+1+end) /2;
    mergeSortHelper(auxillary,pri,start,midOfLeft,mid);
    mergeSortHelper(auxillary,pri, mid+1,midOfRight,end);
    mergeSortedArrays(pri,auxillary,start,mid,end);
}

void mergeSort(vector<int> &array)
{
    vector<int> auxillary(array);
    int mid = auxillary.size()/2;
    mergeSortHelper( array,auxillary,0,mid,array.size()-1);
}


int main()
{
    vector<int> inp = { 8,-9,7,1,3,100,55,2,3 };
    mergeSort(inp);
    for(auto x: inp)
        cout<<" "<<x;
    cout<<endl;
}