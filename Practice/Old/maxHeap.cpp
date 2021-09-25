#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

vector<int> heapEle;

void swapData(int idx1,int idx2)
{
    int temp = heapEle[idx1];
    heapEle[idx1] = heapEle[idx2];
    heapEle[idx2] = temp;
}

void siftUp(int currIdx)
{
    int parentIdx = floor((currIdx - 1)/2 );
    if(parentIdx >= 0 && heapEle[currIdx] > heapEle[parentIdx])
    {
        swapData(currIdx,parentIdx);
        siftUp(parentIdx);
    }
}

void siftDown(int currIdx,int endIdx)
{
    int childIdx1 = 2*currIdx + 1;
    int childIdx2 = 2*currIdx + 2;

    int maxChildIdx;
    if(childIdx1 <= endIdx && childIdx2 <= endIdx) 
    {
        maxChildIdx = heapEle[childIdx1] > heapEle[childIdx2] ? childIdx1: childIdx2;
    }
    else if ( childIdx1 > endIdx )
    {
        maxChildIdx = childIdx2;
    }
    else
    {
        maxChildIdx = childIdx1;
    }

    if(maxChildIdx > endIdx )
    {
        return;
    }

    if(heapEle[currIdx] < heapEle[maxChildIdx])
    {
        swap(heapEle[currIdx],heapEle[maxChildIdx]);
        siftDown(maxChildIdx,endIdx);        
    }
}

int remove() 
{
    int ret = heapEle[0];
    heapEle[0] = heapEle[heapEle.size()-1];
    heapEle.erase( heapEle.begin() + (heapEle.size() -1) );
    siftDown(0,heapEle.size()-1);
    return ret;
}

void insert(int value)
{
    heapEle.push_back(value);
    siftUp(heapEle.size()-1);
}

void buildHeap()
{
    int heapSz = heapEle.size();
    int firstParentIdx = floor(((heapSz - 1) -1)/2);
    for(int parIdx = firstParentIdx;parIdx >=0;parIdx--)
    {
        siftDown(parIdx,heapSz-1);
    }
}


void inPlaceSort() //Assumes already constructed heap
{
    int sz = heapEle.size();
    for(int i = sz -1; i > 0; i--)
    {
        swapData(0,i);
        siftDown(0,i-1);
    }
}

int main()
{
    heapEle = { 48, 12, 24, 7, 8, -5, 24, 391, 24, 56, 2, 6, 8, 41 };
    buildHeap();
    insert(76);
    insert(87);
    
    for(int x:heapEle)
        cout<<x<<" ";
    cout<<endl;

    /*int sz = heapEle.size();
    for(int i=0;i<sz;i++)
        cout<<remove()<<" ";*/

    //Sort and destroy the heap :-) 
    inPlaceSort();
    for(int x:heapEle)
        cout<<x<<" ";
    cout<<endl;

    
}