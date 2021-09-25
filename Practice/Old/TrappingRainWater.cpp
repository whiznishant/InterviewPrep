#include<iostream>
#include<vector>

using namespace std;
int trap(vector<int>& height) 
{
    int sz = height.size();
    vector<int> leftLargest(sz,0);
    //Find the largest elements to the left of each walls
    int largest = height[0];
    for(int i = 1; i < sz; i++)
    {
        if(height[i] > largest )
            largest = height[i];
        leftLargest[i] = largest;
    }

    //Find the largest elements to the right of each walls
    vector<int> rightLargest(sz,0);
    largest = height[sz-1];
    for(int i = sz - 2;i >= 0 ; i-- )
    {
        if(height[i] > largest )
            largest = height[i];
        rightLargest[i] = largest;
    }

    //Compute the volume of water at each locations.
    int sum = 0;
    for(int i = 1;i<sz-1;i++)   //1st and last wall cannot hold any water over their tops
    {
        int currWater= min(leftLargest[i],rightLargest[i]) - height[i];
        sum += currWater > 0 ? currWater:0;
    }
    return sum;
    
}


int main()
{
    vector<int> elevations = { 0,1,0,2,1,0,1,3,2,1,2,1 }; //6
    vector<int> elevations1 = { 4,2,0,3,2,5 }; //9
    cout << trap(elevations);
}