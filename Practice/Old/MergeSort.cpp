//Merge sort with O(n) space and O(nlog(n)) time.

#include <vector>
#include <iostream>
using namespace std;

void mergeArrays(vector<int> *mainArray, int start,int mid, int end, vector<int>* auxArray)
{
	int leftIdx = start;
	int rightIdx = mid + 1;
	int mainIdx = start;
	
	while (leftIdx <= mid && rightIdx <= end)
	{
		if((*auxArray)[leftIdx] < (*auxArray)[rightIdx] )
		{
			(*mainArray)[mainIdx] = (*auxArray)[leftIdx];
			leftIdx++;mainIdx++;
		}
		else
		{
			(*mainArray)[mainIdx] = (*auxArray)[rightIdx];
			rightIdx++;mainIdx++;
		}
	}
	while(leftIdx <= mid)
	{
		(*mainArray)[mainIdx++] = (*auxArray)[leftIdx++];
	}
	
	while(rightIdx <= end)
	{
		(*mainArray)[mainIdx++] = (*auxArray)[rightIdx++];
	}	
}

void mergeSortHelper( vector<int> *mainArray, int start , int end , vector<int> *auxillaryArray)
{
	if(start == end)
		return;
	int mid = (start+end) /2;
	mergeSortHelper(auxillaryArray,start,mid,mainArray);
	mergeSortHelper(auxillaryArray,mid+1,end,mainArray);
	mergeArrays(mainArray,start,mid,end,auxillaryArray);
}

vector<int> mergeSort(vector<int> &array) {
  // Write your code here.
	if(array.size() <= 1)
		return array;
	vector<int> auxillaryArray(array);
	mergeSortHelper(&array,0,array.size()-1,&auxillaryArray);
  return array;
}


int main()
{
    vector<int> input = { 8, 9, 2, 1, 7, -1000, 3 };
    mergeSort(input);

    for(auto x:input)
        cout<<" "<<x;

}