#include<iostream>
#include<vector>
using namespace std;


/*int longestPeak(vector<int> array) 
{
    // Write your code here.
    int direction = 0; //1 means increasing -1 means decreasing
    int currDirection=0;
    int maxRun = 0;
    int run = 1;
    for(int i=0;i < array.size()-1;i++)
    {
        currDirection = array[i+1]>=array[i] ? 1:-1;
        if(direction == 0)
        {
            direction = currDirection;
        }
        else if ( direction != currDirection )
        {
            if(direction == -1 && currDirection == 1)
            {
                if(run > maxRun)
                    maxRun = run;
                run = 0;				
            }	
            direction = currDirection;			
        } 
        run += 1;
    }
    
   return maxRun;
}*/

int longestPeak(vector<int> array) {
  // Write your code here.
	if(array.size() == 0)
		return 0;
	
	int direction = 0; //1 means increasing -1 means decreasing
	int currDirection=0;
	int maxRun = 0;
	int run = 1;	
	
	for(int i=0;i < array.size()-1;i++)
	{
		currDirection = array[i+1]>=array[i] ? 1:-1;
		if(direction == 0 && currDirection == -1)
		{
			continue;
		}
        else if(direction == 0 && currDirection == 1)
        {
            direction = currDirection;
            continue;
        }
		else if ( direction != currDirection )
		{
			if(direction == -1 && currDirection == 1)
			{
				if(run > maxRun)
					maxRun = run;
				run = 0;				
			}	
			direction = currDirection;			
		} 
		run += 1;
	}
	if(run> maxRun)
		maxRun = run;
	
  return maxRun +1;
}


int main()
{
    vector<int> input = { 5, 4, 3, 2, 1, 2, 1 };
    cout<<endl<<endl<<longestPeak(input)<<endl;
}


