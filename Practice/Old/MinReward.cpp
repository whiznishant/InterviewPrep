#include <vector>
#include <iostream>

using namespace std;
void FindLastIncreasingSequence(vector<int> &scores, int *rewards,int currIdx)
{
	cout <<endl<< "Called for "<<currIdx;
	int tempIdx = currIdx;
	while(tempIdx > 0)
	{
		if(scores[tempIdx] > scores[tempIdx-1])
		{
			break;
		}
		tempIdx--;
	}
	for(int i=tempIdx;i <= currIdx;i++)
    {
		rewards[i] = max(rewards[i], rewards[i]+1);
    }
}
int minRewards(vector<int> scores)
{
  // Write your code here.
	// Worst time complexity algorithm   O(n^2)
	// Start with 1 reward if reward becomes zero then go back to the last 
	// Increasing pair and increase all the awards to current by 1.
	int numStudents = scores.size();
	int rewards[numStudents];
	std::fill(&(rewards[0]),&(rewards[0]) + numStudents,0);	
	rewards[0] = 1;
	for(int s=1;s<numStudents;s++)
	{
		if(scores[s] < scores[s-1])
		{
			if(rewards[s-1] == 1)
			{
				//Find the last increasing sequence and increase all rewards
				FindLastIncreasingSequence(scores, rewards,s);
			}
			else
				rewards[s] = 1;
		}
		else 
		{
			rewards[s] = rewards[s-1] + 1;
		}
	}
	
	int total = 0;
	cout<<endl;
	for(int s=0;s< numStudents;s++)
	{
		cout<<" "<<rewards[s];
		total += rewards[s];
	}	 
    cout<<endl<<"Total :" << total;
  return total;
}



int main()
{
    minRewards({800, 400, 20, 10, 30, 61, 70, 90, 17, 21, 22, 13, 12, 11, 8, 4, 2, 1, 3, 6, 7, 9, 0, 68, 55, 67, 57, 60, 51, 661, 50, 65, 53});
    cout<<endl<<endl;
    return 0;
}