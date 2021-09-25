#include <vector>
#include <iostream>
using namespace std;

void swap(vector<int> &array,int idx1,int idx2)
{
	int temp = array[idx1];
	array[idx1] = array[idx2];
	array[idx2] = temp;
}

int partition(vector<int> &array, int low,int high)
{
	int pivot = low;
	low = low +1;
	while(low <= high )
	{				
		if(array[low] > array[pivot] &&  array[high] < array[pivot])
			swap(array,low,high);
		if(array[low] <= array[pivot])
			low++;
		if(array[high] >= array[pivot])
			 high--; 
	 }
	 swap(array,pivot,high);
	 return high;
}

void quickSort(vector<int> &array,int leftIdx,int rightIdx)
{
	if(leftIdx < rightIdx)
	{
		int pivot = partition(array,leftIdx,rightIdx);
		quickSort(array,leftIdx,pivot-1);
		quickSort(array,pivot+1,rightIdx);
	}
}

int main()
{
    vector<int> array = { 8, 5, 2, 9, 5, 6, 3 };
    quickSort(array,0,array.size()-1);
    cout<<endl;
    for(int x:array)
        cout<<"  "<<x;    
    cout<<endl;
}