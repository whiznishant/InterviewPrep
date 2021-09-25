#include<iostream>
#include <vector>
using namespace std;

int LargestRectangleInHistogram(vector<int> &histogramBars) {
  // Write your code here.
	histogramBars.push_back(0);
	vector<int> trackedPosStack;
	int maxArea = 0;
	for(int i = 0;i < histogramBars.size();i++ )
	{				
		//We will be adding all the tracked heights in the stack 
		while( trackedPosStack.size() != 0 && histogramBars[i] <= histogramBars[trackedPosStack.back()])
		{
			// Popping the height which cannot be further extended as the next building height 
			// is lesser than the current
			int poppedBuildingIdx = trackedPosStack.back();
			trackedPosStack.pop_back();
			//compute the max area
			int leftbound = 0;
			if(trackedPosStack.size() > 0)
				leftbound = trackedPosStack.back() + 1; // ------------ The previous element in the stack is the next lowest element .
			int rightbound = i;
			int area = (rightbound - leftbound) * histogramBars[poppedBuildingIdx];
			maxArea = max(area,maxArea);
		}		
	//	if( trackedPosStack.size() == 0 || histogramBars[trackedPosStack.back()] <= histogramBars[i])
		{
			trackedPosStack.push_back(i);
		}
	}
  return maxArea;
}

int main()
{
    vector<vector<int>> testCases = {
        {1, 3, 3, 2, 4, 1, 5, 3, 2},  //Ans : 9
        {4, 4, 4, 2, 2, 1},             //Ans: 12
        {25, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},//Ans: 25
        {20, 2, 2, 2, 2, 2, 10, 5, 5, 5, 4, 4}//Ans: 24
    };

    for(auto x: testCases)
    {
        cout << LargestRectangleInHistogram(x) << endl;
    }
}
